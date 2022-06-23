#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
int main ()
{
  int i;
  
  
  printf ("Executing command pause...\n");
   system("pause");
   printf ("Executing command color...\n");
   system("color 01");
  printf ("Executing command dir...\n");
  system("dir");
  printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
    printf ("Executing command pause...\n");
   system("pause");
  printf ("Executing command cls...\n");
  system("cls");
  printf ("Executing command exit...\n");
	system("exit");
  
  return 0;
}