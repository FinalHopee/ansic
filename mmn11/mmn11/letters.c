#include <stdio.h>
#include <string.h>

#define MAX_LINE 128
#define YES 1
#define NO 0
#define ASCII_SMALL_BIG_LETTER 32

int getline(char line[], int max);
void translateLine(char line[]);

int main(void)
{
	char line[MAX_LINE];

	/* reading line from stdin, writing chars to 'line' variable */
	while (getline(line, MAX_LINE) > 0)
	{
		translateLine(line);
	}
	return 0;
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
	return i;
}


/* Translates provided line according to defined dictionary
Prints the translation to console */
void translateLine(char line[])
{
	int i;
	short isInsideQuotes, newSentence;
	newSentence = YES; /* marks a beginning of new sentance */
	isInsideQuotes = NO; /* flag for inside quotes */


	for (i = 0; i < strlen(line); i++)
	{
		/* new sentence, not inside quotes */
		if (newSentence == YES && isInsideQuotes == NO)
		{
			/* small letters */
			if (line[i] >= 'a' && line[i] <= 'z')
			{
				printf("%c", line[i] - ASCII_SMALL_BIG_LETTER);
				newSentence = NO;
				continue;
			}
			/* no white spaces in the beginning of sentence*/
			else if (line[i] == '\n' || line[i] == ' ' || line[i] == '\t')
			{
				continue;
			}
			else
			{
				printf("%c",line[i]);
				newSentence = NO;
				continue;
			}
		}
		/* Capital letters inside quotes, 
		 * small letters must be elsewhere */
		 if(line[i] >= 'A' && line[i] <= 'z')
		 {
			 if(isInsideQuotes == YES)
			 {
				 if(line[i] >= 'a' && line[i] <= 'z')
				 {
					 printf("%c", line[i] - ASCII_SMALL_BIG_LETTER);
				 }
				 else
				 {
					 printf("%c", line[i]);
				 }
			 }
			 else
			 {
				 if (line[i] >= 'a' && line[i] <= 'z')
				 {
					 printf("%c", line[i]);
				 }
				 else
				 {
					 printf("%c", line[i] + ASCII_SMALL_BIG_LETTER);
				 }
			 }
			 continue;
		 }
		/* double quotes, beginning and end marker */
		if(line[i] == '"')
		{
			printf("%c", line[i]);
			if (isInsideQuotes == YES)
			{
				isInsideQuotes = NO;
			}
			else
			{
				isInsideQuotes = YES;
			}
			continue;
		}
		/* numbers NOT inside quotes to be skipped */
		if (line[i] >= '0' && line[i] <= '9')
		{
			continue;
		}
		/* dot, end of sentence if NOT inside quotes */
		if (line[i] == '.')
		{
			if (isInsideQuotes == YES)
			{
				printf(".");
			}
			else
			{
				newSentence = YES;
				printf(".\n\n");
			}
			continue;
		}
		/* all letters not inside quotes or new sentance must be small */
		if (newSentence == NO && isInsideQuotes == NO)
		{
			if (line[i] >= 'A' && line[i] <= 'Z')
			{
				printf("%c", line[i] + ASCII_SMALL_BIG_LETTER);
			}
			else /* prints all other cahracters including small letters */
			{
				printf("%c", line[i]);
			}
			continue;
		}
	}
}
