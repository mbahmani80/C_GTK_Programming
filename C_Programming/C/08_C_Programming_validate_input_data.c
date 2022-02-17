/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 08_C_Programming_validate_input_data.c
/***************************************************************/
/* Function declarations at the beginning of a 
 * program are called prototypes. */
void print_input_data ();
static void die ( char *msg );
/***************************************************************/
static void die ( char *msg )
{
  fprintf ( stderr, "%s\n", msg );
  exit ( EXIT_FAILURE );
}
/***************************************************************/
void print_input_data ()
{
/* Adds two received integer values then will print the result.*/

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
    //scanf( "%d", &age );
    if (scanf("%d",&age) != 1)
	{
		fprintf(stderr,"Input not recognised as an integer, please try again.\n");
		die ( "Invalid input" );
	}
	else
	{
	    printf("\n");printf("\n");       /* Prints two empty lines */
		printf("*********** Input data ***********\n");
		printf (" First Name: %s\n Last Name: %s\n Age: %d\n",fname,lname,age);
		printf("**********************************\n");
	}
}
/***************************************************************/
int main()
{

    print_input_data ();
    return 0;  /* indicate that the program ended successfully */
}
