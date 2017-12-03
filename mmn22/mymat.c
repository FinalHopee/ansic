#include <stdio.h>
#include <string.h>
#include "mat.h"
#include "mat.c"
#include "getter.c"

void main ()
{
  int command;
  char *line;
  mat MAT_A;
  mat MAT_B;
  mat MAT_C;
  mat MAT_D;
  mat MAT_E;
  mat MAT_F;


  printf("\n\nWelcome to Matrix Calculator!\n");
  printf("================================================\n\n");
  while(1)
  {
  	get_line(line);
  	printf("The line is: %s\n", line);
  	command = get_command(line);

  	exit(0);


  }
  


}

void get_line(char *line)
{
	char *enter_command = "Enter Command: ";


	printf("%s", enter_command);
	scanf("%[^\n]%*c", &line);
}