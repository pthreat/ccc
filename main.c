#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "include/types.h"
#include "include/const.h"
#include "include/url.h"
#include "include/colors.h"
#include "include/log.h"
#include "include/cmd_parser.h"
#include "include/string_util.h"

int main(int argc, char **argv){

	substr("test string",0,1);
	Url u = newUrl("http://jim:123456@www.google.com/?q=ansi");
	debugUrl(&u);
	freeUrl(&u);

}

