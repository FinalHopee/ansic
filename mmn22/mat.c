

/* gets command, it should be first. */
int get_command(char *argv)
{
	static const char READ_MAT[] = 		"read_mat";
	static const char PRINT_MAT[] = 	"print_mat";
	static const char ADD_MAT[] = 		"add_mat";
	static const char SUB_MAT[] = 		"sub_mat";
	static const char MUL_MAT[] = 		"mul_mat";
	static const char MUL_SCALAR[] =    "mul_scalar";
	static const char STOP[] = 			"stop";
	unsigned cmd_len;
	cmd_len = strlen(argv);
	/* cleaning unneeded comma */ 
	printf("Command string length: %d\n", cmd_len);
	printf("Char at loc: %c\n", argv[cmd_len-1]);
	if(argv[cmd_len-1] == ',')
	{
		argv[cmd_len-1] = '\0';
	}
	
	printf("Got command, %s\n", argv);


	if(strcmp(READ_MAT, argv) == 0)
	{
		return 1;
	}
	else if(strcmp(PRINT_MAT, argv) == 0)
	{
		return 2;
	}
	else if(strcmp(ADD_MAT, argv) == 0)
	{
		return 3;
	}
	else if(strcmp(SUB_MAT, argv) == 0)
	{
		return 4;
	}
	else if(strcmp(MUL_MAT, argv) == 0)
	{
		return 5;
	}
	else if(strcmp(MUL_SCALAR, argv) == 0)
	{
		return 6;
	}
	else if(strcmp(STOP, argv) == 0)
	{
		return 7;
	}
	
	return -1;
}