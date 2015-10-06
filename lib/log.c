#include <stdio.h>
#include "../include/types.h"
#include "../include/colors.h"
#include "../include/log.h"

void resetTermColors(void){

	printf("%s",COLOR_RESET);

}

void logWarning(const char *message,bool carriageReturn){

	resetTermColors();
	printf("%s[WW] %s",COLOR_YELLOW,message);

	if(carriageReturn){

		printf("\n");

	}

	resetTermColors();

}

void logError(const char *message,bool carriageReturn){

	resetTermColors();
	printf("%s[EE] %s",COLOR_RED,message);

	if(carriageReturn){

		printf("\n");

	}

	resetTermColors();

}

void logSuccess(const char *message, bool carriageReturn){

	resetTermColors();
	printf("%s[SS] %s",COLOR_GREEN,message);

	if(carriageReturn){

		printf("\n");

	}

	resetTermColors();

}

void logInfo(const char *message, bool carriageReturn){

	resetTermColors();
	printf("%s[II] %s",COLOR_LCYAN,message);

	if(carriageReturn){

		printf("\n");

	}

	resetTermColors();

}

void logEmergency(const char *message, bool carriageReturn){

	resetTermColors();
	printf("%s[!!] %s",COLOR_LRED,message);

	if(carriageReturn){

		printf("\n");

	}

	resetTermColors();

}

void logDebug(const char *message, bool carriageReturn){

	resetTermColors();
	printf("%s[DD] %s",COLOR_LPURPLE,message);

	if(carriageReturn){

		printf("\n");

	}

	resetTermColors();

}
