
void parseCmdLineArguments(int argc, char **argv){

	int c					=	0;
	int verbose_flag	=	0;

	while(true){

		struct option long_options[] = {

			/* These options set a flag. */
			{"verbose", no_argument,&verbose_flag, 1},
			{"url",     no_argument,0, 'u'},
			{0, 0}

		};

		/* getopt_long stores the option index here. */
		int option_index = 0;

		c = getopt_long (argc, argv, "u:v:",long_options, &option_index);

		/* Detect the end of the options. */
		if (c == -1)
			break;

		switch (c){

			case 0:
				/* If this option set a flag, do nothing else now. */
				if (long_options[option_index].flag != 0)
					break;
				printf ("option %s", long_options[option_index].name);
				if (optarg)
					printf (" with arg %s", optarg);
				printf ("\n");
				break;

			case 'v':
				puts("verbose is on");
			break;

			case 'u':
				printf ("Option URL with value `%s'\n", optarg);
				break;

			case '?':
				/* getopt_long already printed an error message. */
				break;

			default:
				abort();
		}
	}

	if(verbose_flag){

		puts ("verbose flag is set");

	}

	/* Print any remaining command line arguments (not options). */
	if (optind < argc){

		printf ("non-option ARGV-elements: ");
		while (optind < argc)
			printf ("%s ", argv[optind++]);
		putchar ('\n');

	}

}

