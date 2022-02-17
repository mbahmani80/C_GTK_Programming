/**
*=======================================================================
*
*          FILE:  05_GTK_C_h_layout.c
* 
*         USAGE: ./05_GTK_C_h_layout
*
*   COMPILE TIP: 
*        gcc -o 05_GTK_C_h_layout 05_GTK_C_h_layout.c `pkg-config --cflags --libs gtk+-3.0`
* 
*   DESCRIPTION: The GTK3 Form Horizontal layout example.
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
/* function definition */
static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *label;
  GtkWidget *hbox;
  GtkWidget *button1; 
  GtkWidget *button2;
  GtkWidget *button3;

  /* Create Widgets */
  // Create a new window
  window = gtk_application_window_new (app);
  button1 = gtk_button_new_with_label ("Left");
  button2 = gtk_button_new_with_label ("Center");
  button3 = gtk_button_new_with_label ("Right");
  label = gtk_label_new ("GTK+ Form Horizontal layout example:");
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  
  /* Set attributes */
  gtk_window_set_title (GTK_WINDOW (window), "GNOME (GTK+) Form");
  gtk_window_set_default_size (GTK_WINDOW (window), 320, 100);
  
  /* Pack everything and display */
  gtk_container_add(GTK_CONTAINER(window), hbox);
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), button1, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), button2, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), button3, TRUE, TRUE, 0);
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
  app = gtk_application_new (NULL, G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
