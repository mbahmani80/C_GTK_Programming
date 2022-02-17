/* header files */
#include <stdio.h>

/* From "The GNU C Programming Tutorial" with some changes */

// 02_C_Programming_Simple_function.c
/***************************************************************/
void simple_function ()
{
/* This function print a string little. */
printf ("Function 'simple_function' completing.\n");
}
/***************************************************************/
/* Main Program */
int main ()
{
/* ....... Call simple_function(); .......  */
simple_function();
printf ("Function 'main' completing.\n");

    return 0;  /* indicate that the program ended successfully */
}
