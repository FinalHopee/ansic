#include <stdio.h>
#include <string.h>


int GetNumber()
{
        int number;
        char c;
        number = -1;

        while((c = getchar()) != EOF)
        {
                        if (c >= '0' && c <= '9')
                        {
                                                if (number != -1) /* Two digits numbers go here */
                                                {
                                                                                number = (number * 10) + c - ASCII_CHAR_TO_DIGIT;
                                                                        }
                                                else /* First time, one digit number*/
                                                {
                                                                                number = c - ASCII_CHAR_TO_DIGIT;
                                                                        }
                                        }
                        else if (c == ' ' || c == '\n' || c == '\t' || c == '\v' ||\
                                                     c == '\f' || c == '\r' || c == ',')
                        {
                                                if (number == -1) /* white spaces between numbers */
                                                {
                                                                          continue;
                                                                        }
                                                else
                                                {
                                                                                return number;
                                                                        }
                                        } /* end else if */
                        else /* Not numbers */
                        {
                                                printf("ERROR: Wrong input! Must be integer numbers only!\n\n");
                                                return('e'); /* exit program with error */
                                        }
                }
        return number;
}
