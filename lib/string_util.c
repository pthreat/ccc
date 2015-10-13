#include <ctype.h>
#include <stdargs.h>
#include <stddef.h>
#include <string.h>
#include "../include/string_util.h"

void replace_control_characters(char *str, size_t len,char *replacement){

	unsigned char *r	= (unsigned char *)replacement;
	unsigned char *s	= (unsigned char *)str;
	unsigned char *e	= (unsigned char *)str + len;

	if (!str||!replacement) {

		return;

	}

	unsigned int rlen	=	strlen(replacement);

	while (s < e) {

		if (iscntrl(*s)){

			memcpy(s,replacement,rlen);

		}

		s++;

	}

}

void substr_ptr(char *str, int start, ...){

	int length	=	strlen(str);

	if(start > length){

		return;

	}

	int i			=	0;
	char *temp	=	calloc(length,sizeof(char));

	for(i=0;i<length,i++){
		
	}

}

