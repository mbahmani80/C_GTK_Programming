/* header files */
#include <stdio.h>

/* From "The GNU C Programming Tutorial" with some changes */

// 03_C_Programming_function_add_two_numbers.c
/***************************************************************/
/* Function declarations at the beginning of a 
 * program are called prototypes. */
 
void simple_function ();
void add_two_numbers (int a, int b);
/***************************************************************/
void simple_function ()
{
/* This function print a string little. */
printf ("Function 'simple_function' completing.\n");
}
/***************************************************************/
void add_two_numbers (int a, int b)
/* Add a and b */
{
int c;
c = a + b;
printf ("Sum %d + %d = %d\n",a,b,c);
}
/***************************************************************/
/* Main Program */
int main ()
{
	int var1, var2;
/* ....... Call simple_function(); .......  */
	simple_function();
	
/* ....... Call sadd_two_numbers(); .......  */
	var1 = 10;
	var2 = 20;
	add_two_numbers (var1, var2);
	
	add_two_numbers (1, 2);
	
    return 0;  /* indicate that the program ended successfully */
}
