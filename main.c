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

int main(int argc, char **argv){

	Url u = newUrl("http://www.google.com/?q=ansi");
	debugUrl(&u);

}

