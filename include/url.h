#ifndef __URL_H__
#define __URL_H__

#define	__URL_PROTOCOL_SIZE	10
#define	__URL_USERNAME_SIZE	32
#define	__URL_PASSWORD_SIZE	32
#define	__URL_HOSTNAME_SIZE	80
#define	__URL_QUERY_SIZE		80
#define  __URL_MAXERROR_SIZE	500

typedef struct URL{
	char	*original;
	char	*protocol;
	char	*username;
	char	*password;
	char	*hostname;
	char	*query;
	char  *errorStr;
	int   errno;
	bool  initialized;
	bool  isParsed;
	int unsigned short port;
} Url;

Url newUrl();
int initializeUrl(const char *str, Url *url);
int parseUrl(Url *url);
void debugUrl(Url *url);

#endif /* __URL_H__ */
