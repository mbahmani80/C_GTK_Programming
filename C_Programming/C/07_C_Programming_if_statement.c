/* header files */
#include <stdio.h>

// 07_C_Programming_if_statement.c
/***************************************************************/
/* Function declarations at the beginning of a 
 * program are called prototypes. */
void if_statement_example ();
void if_else_statement_example();
void nested_if_else_statement_example();
void condition_expression1_expression2();
/***************************************************************/
void if_statement_example ()
{

	int my_number;			          /* declaration variables */
    
    printf("Enter a number:");			      /* read a number */
    scanf( "%d", &my_number );
	if (my_number == 0) printf ("The number is zero.\n");
	if (my_number > 0) printf ("The number is positive.\n");
	if (my_number < 0) printf ("The number is negative.\n");
}
/***************************************************************/
void if_else_statement_example()
{

	int my_number;			          /* declaration variables */
    
    printf("Enter a number:");			      /* read a number */
    scanf( "%d", &my_number );
	if (my_number > 0)
	{
		printf ("The number is positive.\n");
	}
	else
	{
		printf ("The number is zero or negative.\n");
	}
}
/***************************************************************/
void nested_if_else_statement_example()
{

	int my_number;			          /* declaration variables */
    
    printf("Enter a number:");			      /* read a number */
    scanf( "%d", &my_number );
	if (my_number > 0)
	{
		printf ("The number is positive.\n");
	}
	else
	{
		if (my_number < 0){
			printf ("The number is negative.\n");
		}
		else
		{
			if (my_number == 0){
				printf ("The number is zero.\n");
			}
		}
	}
}
/***************************************************************/
// (condition) ? expression1 : expression2;
void condition_expression1_expression2()
{
	int my_number;			          /* declaration variables */
	int zero = 0;
    
    printf("Enter a number:");			      /* read a number */
    scanf( "%d", &my_number );
    
    (my_number >= zero) 
    ? printf("The number is zero or greater than.\n") 
    : printf ("The number is negative.\n");

	
}
/***************************************************************/
int main()
{
	printf ("Calls if_statement_example ();\n");
    if_statement_example ();
    
    printf("**********************************\n");
    
    printf ("Calls if_else_statement_example();\n");
    if_else_statement_example();
    
    printf("**********************************\n");
    
    printf ("Calls nested_if_else_statement_example();\n");
    nested_if_else_statement_example();
    
    printf("**********************************\n");
    
    printf ("Calls condition_expression1_expression2();\n");
    condition_expression1_expression2();
    
    return 0;  /* indicate that the program ended successfully */
}
