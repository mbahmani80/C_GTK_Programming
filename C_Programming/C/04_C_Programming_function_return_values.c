/* header files */
#include <stdio.h>

/* From "The GNU C Programming Tutorial" with some changes */

// 04_C_Programming_function_return_values.c
/***************************************************************/
/* Function declarations at the beginning of a 
 * program are called prototypes. */
 
void add_two_numbers (int a, int b);
int calc_value (int bas, int quux);
/***************************************************************/
void add_two_numbers (int a, int b)
{
/* Adds a and b then will print the result.*/
int c;
c = a + b;
printf ("Sum %d + %d = %d\n",a,b,c);
}
/***************************************************************/
int calc_value (int bas, int quux)
{
/* This function returns a value. */	
return bas * quux;
}
/***************************************************************/
/* Main Program */
int main ()
{

	add_two_numbers (23, 5);
	add_two_numbers (calc_value (10, 50), 5);
	
		
    return 0;  /* indicate that the program ended successfully */
}
