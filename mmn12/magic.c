#include <stdio.h>

#define MAX_LINE 128

int getline(char line[], int max);
void translateLine(char line[]);

int main(void)
{
	char line[MAX_LINE];

	/* reading line from stdin, writing chars to 'line' variable */
	while ( getline(line, MAX_LINE) > 0 )
	{
		translateLine(line);
	}
	
}

/* reads line from STDIN, has MAX_LINE value defined per read */
int getline(char line[], int max)
{
	int c, i;
	i = 0;
	max -= 1;
	while (--max > 0 && (c = getchar()) != EOF)
	{
		line[i++] = c;
	}
	line[i] = '\0';
}


/* Translates provided line according to defined dictionary 
   Prints the translation to console */
void translateLine(char line[])
{
	int i;
	short isInsideQuotes, newSentence;
	isInsideQuotes = 0; /* flag for inside quotes */
	newSentence = 1; /* marks a beginning of new sentance */

	for (i = 0; i < strlen(line); i++)
	{
		/* new sentence, not inside quotes */
		if (newSentence == 1 && isInsideQuotes == 0)
		{
			/* small letters */
			if (line[i] >= 'a' && line[i] <= 'z')
			{
				printf("%s", line[i] - 32);
				newSentence = 0;
				continue;
			}
			/* no white spaces in the beginning of sentence*/
			if (line[i] == '\n' || line[i] == ' ' || line[i] == '\t')
			{
				continue;
			}
		}
		/* all letters not inside quotes or new sentance must be small */
		if (newSentence == 0 && isInsideQuotes == 0 && line[i] >= 'A' && line[i] <= 'z')
		{
			if (line[i] >= 'A' && line[i] <= 'Z')
			{
				printf("%s", line[i] + 32);
			}
			else
			{
				printf("%s", line[i]);
			}
			continue;
		}
		/* numbers NOT inside quotes to be skipped */
		if (line[i] >= '0' && line[i] <= '9')
		{
			if (isInsideQuotes == 1)
			{
				printf("%s", line[i]);
			}
			continue;
		}
		/* dot, end of sentence if NOT inside quotes */
		if (line[i] == '.')
		{
			if (isInsideQuotes == 1)
			{
				printf(".");
				continue;
			}
			newSentence = 1;
			printf(".\n\n");
			continue;
		}
		




		



	}



}









