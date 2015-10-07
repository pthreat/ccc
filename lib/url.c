#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/colors.h"
#include "../include/log.h"
#include "../include/url.h"
#include "../include/string_util.h"


void debugUrl(Url *url){

	printf("Original:\t%s\n",url->original);
	printf("Protocol:\t%s\n",url->protocol);
	printf("Hostname:\t%s\n",url->hostname);
	printf("Query\t:\t%s\n",url->query);
	printf("Username:\t%s\n",url->username);
	printf("Password:\t%s\n",url->password);
	printf("Port:\t%d",url->port);

}

int initializeUrl(const char *str,Url *url){

		if(url->initialized == 1){

			return 0;

		}

		url->original		=	calloc(strlen(str),sizeof(char));
		url->protocol		=	calloc(__URL_PROTOCOL_SIZE,sizeof(char));
		url->username		=	calloc(__URL_USERNAME_SIZE,sizeof(char));
		url->password		=	calloc(__URL_PASSWORD_SIZE,sizeof(char));
		url->hostname		=	calloc(__URL_HOSTNAME_SIZE,sizeof(char));
		url->query			=	calloc(__URL_QUERY_SIZE,sizeof(char));
		url->errorStr		=	calloc(__URL_MAXERROR_SIZE,sizeof(char));
		url->initialized	=	1;
		url->errno        =  0;
		url->isParsed     =  0;
		url->port			=	0;

		memcpy(url->original,str,strlen(str));

		return 1;

}

int freeUrl(Url *url){
	free(url->original);
	free(url->protocol);
	free(url->username);
	free(url->password);
	free(url->hostname);
	free(url->query);
	free(url->errorStr);
	url->initialized	=	0;
	url->errno			=	0;
	url->isParsed		=	0;
	url->port			=	0;
}

Url newUrl(const char *str){

	Url url;
	initializeUrl(str,&url);
	parseUrl(&url);
	return url;

}

int parseUrl(Url *url){

	char *dname;
	char *buf;

	dname = (unsigned char *)url->original;

	replace_control_characters(dname,strlen(dname),"");

	//Parse protocol
	if ((buf = strchr(dname, ':')) != NULL) {

		int len = buf - dname;

		if(len + 1 > __URL_PROTOCOL_SIZE) {

			return false;

		}

		memcpy(url->protocol,dname,len);
		dname += len;

	}

	if (strncmp (dname, "://", 3) != false) {

		logError(dname,true);
		return false;

	}

	// :
	dname += 3;

	//Check if we have a username 

	if ((buf = strchr (dname, '@')) != NULL){

		int len = buf - dname;

		if (len + 1 > __URL_USERNAME_SIZE) {

			return false;

		}

		//Do we have a password?
		if ((buf = strchr (dname, ':')) != NULL){

			int len = buf - dname;

			if (len + 1 > __URL_USERNAME_SIZE) {

				return false;

			}

			memcpy(url->username,dname,len);

			dname += len+1;

			buf=strchr(dname,'@');

			len = buf - dname;

			if (len + 1 > __URL_PASSWORD_SIZE) {

				return false;

			}

			memcpy(url->password,dname,len);

			dname+= len+1;

		}else{

			memcpy(url->username,dname,len);
			dname+=len;

		}

	}

	if ((buf = strchr (dname, '/')) != NULL){

		int len = buf - dname;

		if (len + 1 > __URL_HOSTNAME_SIZE) {

			return false;

		}

		memcpy (url->hostname, dname, len);

		dname = buf + 1;

	}

	memcpy(url->query, dname, __URL_QUERY_SIZE);

	url->isParsed = 1;
	
	return 0;
}

