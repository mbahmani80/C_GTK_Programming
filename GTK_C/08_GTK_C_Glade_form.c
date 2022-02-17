/**
*=======================================================================
*
*          FILE:  
* 				  08_GTK_C_Glade_form.c
* 				  glade/08_GTK_C_Glade_form.glade
* 
*         USAGE: ./08_GTK_C_Glade_form
*
*   COMPILE TIP: 
*   gcc -o 08_GTK_C_Glade_form 08_GTK_C_Glade_form.c -rdynamic `pkg-config --cflags --libs gtk+-3.0`
* 
* 
*   DESCRIPTION: This code consist of the following:
*                1- Designed GTK + UI with Glade
*                2- Using C a Structure to manipulate window widgets
*                3- Passing pointer to a structure of pointers to a callback function
*                4- How to make practical use of signals, events, callbacks, 
*                   and functions concepts.
* 
*       OPTIONS: ---
*  REQUIREMENTS: GTK+, C, GCC
*          BUGS: ---
*         NOTES: ---
*        AUTHOR: Mahdi Bahmani 
*  ORGANIZATION: www.itstorage.co 
*       CREATED: 2020/04/05
*      REVISION: 1.0
*=======================================================================
**/

#include <gtk/gtk.h>

// =====================================================================
/* Struct used to manipulate window widgets */
/* 
* We need a pointer to each of the labels in the project so that we 
* can get hold of the labels to change their text. 
*/
typedef struct _MyWindowData
{
	char *message;
	int countbtn1;
	GtkWidget *window1;
	GtkWidget *label1;
	GtkWidget *label2;
	GtkWidget *button1;
    
}MyWindowData;

// =====================================================================
/* function declarations */
static void activate(GtkApplication* app, MyWindowData mwd, gpointer user_data);
void on_button1_clicked(GtkWidget *widget, gpointer data);
static void destroy( GtkWidget *widget, gpointer data);
// =====================================================================
/* Window function definition */
static void activate(GtkApplication* app, MyWindowData mwd, gpointer user_data)
{
	GtkBuilder      *builder; 
    GtkWidget       *window;
    
    /* Set MyWindowData structure variables */
	mwd.message = "Passing pointer to structure of pointers to callback function\n";
	mwd.countbtn1 = 0;

	/* Import UI designed via Glade */
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/08_GTK_C_Glade_form.glade", NULL);
	
	/* get pointers to the Widgets */
	// get pointers to the two labels
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    mwd.window1 = window;
    mwd.button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    // get pointers to the two labels
    mwd.label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    mwd.label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
    
    /* Register callbacks */
    // Connecting the signals in the code
    gtk_builder_connect_signals(builder, NULL);
    // Passing pointer to a structure of pointers to a callback function
	g_signal_connect (mwd.button1, "clicked",
					 G_CALLBACK (on_button1_clicked), &mwd);
	g_signal_connect (window, "destroy",
					 G_CALLBACK (destroy), &window);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();
	
}
// =====================================================================
/* function definition */
// Passing pointer to a structure of pointers to a callback function
// called when button is clicked
// writes text to the first and secound label and increments a 
// count in the both of labes when it is clicked.
void on_button1_clicked(GtkWidget *widget, gpointer data)
{  
    MyWindowData *MWD;
    MWD = (MyWindowData*) data;
    char str1[30] = "Button1 Clicked: ";
    char str2[5];
    MWD->countbtn1 += 1;
    sprintf(str2, "%d", MWD->countbtn1);
    strcat(str1, str2);
    gtk_label_set_text(GTK_LABEL(MWD->label1), str1);
    gtk_label_set_text(GTK_LABEL(MWD->label2), str2);
    g_print("%s\n",str1);
    g_print("%s\n",str2);
}
// =====================================================================
/* function definition */
// called when window is closed
static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
}
// =====================================================================
/* main window (parent) */
int main(int argc, char **argv)
{
	GtkApplication *app;
	int status = 0;
	/* Initialize the environment */
	app = gtk_application_new("itstorage.co", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run(G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	
	return status;
}


