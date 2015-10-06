#ifndef __STDOUT_LOG 
#define __STDOUT_LOG 1

void resetTermColors(void);
void logWarning(const char *message, bool carriageReturn);
void logError(const char *message, bool carriageReturn);
void logSuccess(const char *message, bool carriageReturn);
void logInfo(const char *message, bool carriageReturn);
void logEmergency(const char *message, bool carriageReturn);
void logDebug(const char *message, bool carriageReturn);

#endif
