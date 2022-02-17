/* header files */
#include <stdio.h>

// 06_C_Programming_print_user_input.c
/***************************************************************/
/* Function declarations at the beginning of a 
 * program are called prototypes. */
void print_input_data ();
/***************************************************************/
void print_input_data ()
{
	int age;			              /* declaration variables */
	char fname[20], lname[20];	      /* declaration variables */
	char temp;
	
    printf("Enter first name:");
    scanf("%[^\n]", fname );			    /* read first name */
    scanf("%c",&temp);       /* temp statement to clear buffer */
    
    printf("Enter last name:");
    scanf( "%[^\n]", lname );			     /* read last name */
    scanf("%c",&temp);       /* temp statement to clear buffer */   
    
    printf("Enter Age:");
    scanf( "%d", &age );
    
	printf("\n");printf("\n");       /* Prints two empty lines */
	printf("*********** Input data ***********\n");
	printf (" First Name: %s\n Last Name: %s\n Age: %d\n",fname,lname,age);
	printf("**********************************\n");

}
/***************************************************************/
int main()
{

    print_input_data ();
    return 0;  /* indicate that the program ended successfully */
}
