#include <stdio.h>


#define YES 1
#define NO 0
#define ASCII_SMALL_BIG_LETTER 32


int main(void)
{
	char oneChar;
	short newSentence, isInsideQuotes;
	isInsideQuotes= NO;
	newSentence = YES;
	
	/* reading line from stdin, writing chars to 'line' variable */
	while (( oneChar = getchar()) != EOF)
	{
		/* double quotes, beginning and end marker */
		if(oneChar == '"')
		{
			printf("%c", oneChar);
			if (isInsideQuotes == YES)
			{
				isInsideQuotes = NO;
			}
			else
			{
				isInsideQuotes = YES;
			}
			if (newSentence == YES)
			{
				newSentence = NO;
			}
			continue;
		}
		/* White spaces */
		if (oneChar == ' ' || oneChar == '\t' || oneChar == '\n')
		{
			if (isInsideQuotes == YES || newSentence == NO)
			{
				printf("%c", oneChar);
			}
			continue;
		}
		
		

		/* numbers NOT inside quotes to be skipped */
		if (oneChar >= '0' && oneChar <= '9')
		{
			continue;
		}
		/* dot, end of sentence if NOT inside quotes */
		if (oneChar == '.')
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

		/* new sentence, not inside quotes */
		if (newSentence == YES && isInsideQuotes == NO)
		{
			/* small letters */
			if (oneChar >= 'a' && oneChar <= 'z')
			{
				printf("%c", oneChar - ASCII_SMALL_BIG_LETTER);
				newSentence = NO;
				continue;
			}
			else
			{
				printf("%c",oneChar);
				newSentence = NO;
				continue;
			}
		}
		/* Capital letters inside quotes, 
		 * small letters must be elsewhere */
		 if(oneChar >= 'A' && oneChar <= 'z')
		 {
			 if(isInsideQuotes == YES)
			 {
				 if(oneChar >= 'a' && oneChar <= 'z')
				 {
					 printf("%c", oneChar - ASCII_SMALL_BIG_LETTER);
				 }
				 else
				 {
					 printf("%c", oneChar);
				 }
			 }
			 else
			 {
				 if (oneChar >= 'a' && oneChar <= 'z')
				 {
					 printf("%c", oneChar);
				 }
				 else
				 {
					 printf("%c", oneChar + ASCII_SMALL_BIG_LETTER);
				 }
			 }
			 continue;
		 }
		
		/* all letters not inside quotes or new sentance must be small */
		if (newSentence == NO && isInsideQuotes == NO)
		{
			if (oneChar >= 'A' && oneChar <= 'Z')
			{
				printf("%c", oneChar + ASCII_SMALL_BIG_LETTER);
			}
			else /* prints all other cahracters including small letters */
			{
				printf("%c", oneChar);
			}
			continue;
		}
		/* anything else , epsecially signs*/
		printf("%c", oneChar);
	}
	return 0;
}
