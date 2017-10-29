#include "stdio.h"
#include "string.h"

#define MAX_STRING 128

void displayAnswer(int functionNumber, int functionAnswer, char *firstArgument, char *secondArgument, int thirdArgument);
int my_strcmp(char *firstArgument, char *secondArgument);
int my_strncmp(char *firstArgument, char *secondArgument, int n);
int my_strchr(char *firstArgument, int secondArgument);
void OptionsMessage();

/*
	Welcome message
	Ask user to choose which function
	ask for first argument
	ask for second argument
	calculate
	present results
*/
int main()
{
	letters();
	return 0;
	/* Init variables */
	short func_option, funcAnswer;
	int nBytes;
	char firstArgument[MAX_STRING], secondArgument[MAX_STRING];
	

	printf("\t\tWelcome to my_string proram!\n\n\n\t");
	OptionsMessage();
	/*While loop, showing options message and taking input from user
	  inside while loop options for getting rid of white spaces like 'enter'
	  */
	while ( gets(&func_option) )
	{
		switch (func_option)
		{
		default:
			printf("Wrong option, there is no %c option..\n", func_option);
			printf("Please, try again or type 'q' or 'Q' to exit.\n\n\n");
			break;
		case '1':
			printf("You have chosen strcmp!\n");
			printf("Please provide string arguments to chosen function.\n");
			printf("First argument: ");
			gets(firstArgument);
			printf("\nSecond argument: ");
			gets(secondArgument);
			funcAnswer = my_strcmp(firstArgument, secondArgument);
			displayAnswer(1, funcAnswer, firstArgument, secondArgument, -1);
			return funcAnswer;
			break;
		case '2':
			printf("You have chosen strncmp!\n");
			printf("Please provide string arguments to chosen function.\n");
			printf("First argument, is a string: ");
			gets(firstArgument);
			printf("\nSecond argument, is a string: ");
			gets(secondArgument);
			printf("\nThird argument, how many bytes to check: ");
			scanf("%d", &nBytes);
			funcAnswer = my_strncmp(firstArgument, secondArgument, nBytes);
			displayAnswer(2, funcAnswer, firstArgument, secondArgument, nBytes);
			return funcAnswer;
			break;
		case '3':
			printf("You have chosen strchr!\n");
			printf("Please provide string arguments to chosen function.\n");
			printf("First argument, string to look in: ");
			gets(firstArgument);
			printf("\nSecond argument, a char to look for: ");
			gets(secondArgument);
			funcAnswer = my_strchr(firstArgument, secondArgument[0]);
			displayAnswer(3, funcAnswer, firstArgument, secondArgument, -1);
			return funcAnswer;
			break;
		case 'q': case 'Q':
			return 0;
		}
		OptionsMessage();
	}
	return 0;
}


void OptionsMessage ( void )
{
	printf("Please select one of the following functions to run:\n");
	printf("1) strcmp\n");
	printf("2) strncmp\n");
	printf("3) strchr\n\n\t");
}

void displayAnswer(int functionNumber, int functionAnswer, char *firstArgument, char *secondArgument, int thirdArgument)
{
	printf("\n\n\n\n\n");
	switch (functionNumber)
	{
	case 1: /*strcmp function answer*/
		printf("Function that ran was 'strcmp'\n");
		printf("First argument: %s\n", firstArgument);
		printf("Second argument: %s\n", secondArgument);
		printf("Function answer was: %d\n", functionAnswer);
		break;
	case 2: /*strncmp function answer*/
		printf("Function that ran was 'strncmp'\n");
		printf("First argument: %s\n", firstArgument);
		printf("Second argument: %s\n", secondArgument);
		printf("Third argument: %d\n", thirdArgument);
		printf("Function answer was: %d\n", functionAnswer);

		break;
	case 3: /*strchr function answer*/
		printf("Function that ran was 'strchr'\n");
		printf("First argument: %s\n", firstArgument);
		printf("Second argument: %s\n", secondArgument);
		printf("Function answer was: %d\n", functionAnswer);
		break;
	default:
		break;
	}
	return;
}

int my_strcmp(char *firstArgument, char *secondArgument)
{
	int i;
	for (i = 0; i < strlen(firstArgument) && i < strlen(secondArgument); i++)
	{
		if (firstArgument[i] - secondArgument[i] == 0)
		{
			continue;
		}
		else
		{
			return (firstArgument[i] - secondArgument[i] > 0) ? 1 : -1;
		}
	}
	/* Need to test if one of strings bigger than the other*/
	/* If strings equal and got to this line it means they are equal*/
	if (strlen(firstArgument) == strlen(secondArgument))
	{
		return 0;
	}
	/* string with different sizes */
	if (strlen(firstArgument) > strlen(secondArgument))
	{
		return 1;
	}
	/* otherwise the second string longer */
	return -1;
}

/* compare between two string up to 'n'th char */
/* 'mari'
   'mari ' */
int my_strncmp (char *firstArgument, char *secondArgument, int n)
{
	int i;
	for (i = 0; i < n && i < strlen(firstArgument) && i < strlen(secondArgument); i++)
	{
		if (firstArgument[i] - secondArgument[i] == 0) /* same character */
		{
			continue;
		}
		else
		{
			return (firstArgument[i] - secondArgument[i] > 0) ?  1 : -1  ;
		}
	}
	if (i == n || (i == strlen(firstArgument) && i == strlen(secondArgument))) /* equal strings*/
	{
		return 0;
	}
	if (i == strlen(firstArgument)) /* first argument length less than second */
	{
		return -1;
	}
	return 1; /* first string length is bigger */
}



int my_strchr (char *firstArgument, int secondArgument)
{
	int i;
	
	for (i = 0; i < strlen(firstArgument); i++)
	{
		if (firstArgument[i] == secondArgument)
		{
			return i;
		}
	}
	return -1;
}