/**
*=======================================================================
*
*          FILE:  03_GTK_C_hello.c
* 
*         USAGE: ./03_GTK_C_hello.c
*
*   COMPILE TIP: 
*        gcc -o 03_GTK_C_hello 03_GTK_C_hello.c `pkg-config --cflags --libs gtk+-3.0`
* 
*   DESCRIPTION: The GTK3 / C code below will produce a form with a label.
* 
*       OPTIONS: ---
*  REQUIREMENTS: GTK+, C, GCC
*          BUGS: ---
*         NOTES: ---
*        AUTHOR: Mahdi Bahmani 
*  ORGANIZATION: www.itstorage.co 
*       CREATED: 2020/04/02
*      REVISION: 1.0
*=======================================================================
**/

#include <gtk/gtk.h>
// =====================================================================
/* function declarations */
static void activate (GtkApplication* app, gpointer user_data);
// =====================================================================
/* Window function definition */
static void
activate (GtkApplication* app,
          gpointer        user_data)
{
	GtkWidget *window;
	GtkWidget *label;
	
	/* Create Widgets */
    // Create a new window
	window = gtk_application_window_new (app);
	label = gtk_label_new ("Hello GNOME!");
	
    /* Set attributes */
	gtk_window_set_title (GTK_WINDOW (window), "Welcome to GNOME");
	gtk_window_set_default_size (GTK_WINDOW (window), 320, 100);
	
	/* Pack everything and display */
	gtk_container_add (GTK_CONTAINER (window), label);
	gtk_widget_show_all (window);
}
// =====================================================================
/* main window (parent) */
int
main (int    argc,
      char **argv)
{
	GtkApplication *app;
	int status;
	
	/* Initialize the environment */
	// Create a new application
	app = gtk_application_new (NULL, G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	
	return status;
}
