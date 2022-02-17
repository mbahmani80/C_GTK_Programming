/* header files */
#include <stdio.h>

// 05_C_Programming_read_user_values.c
/***************************************************************/
/* Function declarations at the beginning of a 
 * program are called prototypes. */
void add_two_numbers ();
/***************************************************************/
void add_two_numbers ()
{
/* Adds two received integer values then will print the result.*/

	int int1, int2, sum;			  /* declaration variables */
    printf("Enter first integer\n");
    scanf( "%d", &int1 );			        /* read an integer */
    printf("Enter second integer\n");
    scanf( "%d", &int2 );
    sum = int1 + int2;					  /* assignment of sum */
	printf ("Sum %d + %d = %d\n",int1,int2,sum);
}
/***************************************************************/
int main()
{

    add_two_numbers ();
    return 0;  /* indicate that the program ended successfully */
}
