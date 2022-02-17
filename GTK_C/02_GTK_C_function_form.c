/**
*=======================================================================
*
*          FILE:  02_GTK_C_function_form.c
* 
*         USAGE: ./02_GTK_C_function_form
*
*   COMPILE TIP: 
*        gcc -o 02_GTK_C_function_form 02_GTK_C_function_form.c `pkg-config --cflags --libs gtk+-3.0`
* 
*   DESCRIPTION: Using a function for creating a Gnome/GTK window.
* 
*       OPTIONS: ---
*  REQUIREMENTS: GTK+, C, GCC
*          BUGS: ---
*         NOTES: ---
*        AUTHOR: Mahdi Bahmani 
*  ORGANIZATION: www.itstorage.co 
*       CREATED: 2020/04/01
*      REVISION: 1.0
*=======================================================================
**/
// http://zetcode.com/gui/gtk2/firstprograms/
// https://tecnocode.co.uk/misc/platform-demos/hello-world.c.xhtml
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
  
  /* Create Widgets */
  // Create a new window
  window = gtk_application_window_new (app);
  
  /* Set attributes */
  gtk_window_set_title (GTK_WINDOW (window), "Welcome to GNOME (GTK+/C)");
  gtk_window_set_default_size (GTK_WINDOW (window), 320, 100);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  
  /* Pack everything and display */
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

