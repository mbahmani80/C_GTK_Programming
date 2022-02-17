/**
*=======================================================================
*
*          FILE:  06_GTK_C_btn_signal.c
* 
*         USAGE: ./06_GTK_C_btn_signal
*
*   COMPILE TIP: 
*        gcc -o 06_GTK_C_btn_signal 06_GTK_C_btn_signal.c `pkg-config --cflags --libs gtk+-3.0`
* 
*   DESCRIPTION: The GTK3 / C code This code will be introducing 
*                the concept of Signals, events, and Callbacks.
* 
*       OPTIONS: ---
*  REQUIREMENTS: GTK+, C, GCC
*          BUGS: ---
*         NOTES: ---
*        AUTHOR: Mahdi Bahmani 
*  ORGANIZATION: www.itstorage.co 
*       CREATED: 2020/04/03
*      REVISION: 1.0
*=======================================================================
**/

#include <gtk/gtk.h>

// =====================================================================
/* function declarations */
static void activate (GtkApplication* app, gpointer user_data);
void on_button1_clicked (GtkWidget *widget, gpointer user_data);
void on_button2_clicked(GtkWidget *widget, gpointer data);
void on_button3_clicked(GtkWidget *widget, gpointer data);
static void destroy(GtkWidget *widget, gpointer data);
// =====================================================================
/* Window function definition */
static void
activate (GtkApplication* app,
          gpointer        user_data)
{

	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *label;
	GtkWidget *button1; 
	GtkWidget *button2;
	GtkWidget *button3;
	
	/* Create Widgets */
	// Create a new window, give it a title and display it to the user. */
	window = gtk_application_window_new (app);
	label = gtk_label_new ("Gtk.Button, Gtk.Label, Signal and function");
	button1 = gtk_button_new_with_label ("Run a Function---button1");
	button2 = gtk_button_new_with_label ("Change Label---button2");
	button3 = gtk_button_new_with_label ("exit---button3"); 
	vbox = gtk_box_new(TRUE, 1);
	
	/* Set attributes */
	gtk_window_set_title (GTK_WINDOW (window), "GNOME (GTK+) Form");
	gtk_window_set_default_size (GTK_WINDOW (window), 320, 100);
	
	/* Register callbacks */
	g_signal_connect (window, "destroy",
					  G_CALLBACK (destroy), &window);
	g_signal_connect (button1, "clicked",
					  G_CALLBACK (on_button1_clicked), NULL);
	g_signal_connect (button2, "clicked",
					  G_CALLBACK (on_button2_clicked), label );                
	// When the button is clicked, destroy the window passed as an argument
	g_signal_connect (button3, "clicked",
					  G_CALLBACK (on_button3_clicked), window);
	//g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
	
	/* Pack everything and display */
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button3, TRUE, TRUE, 0);
	gtk_widget_show_all (window);
	
	/* Hand control over to the main loop. */
	gtk_main();
	
}
// =====================================================================
/* function definition */
void
on_button1_clicked (GtkWidget *widget, gpointer data)
{
    g_print("Button1 Clicked:\n");
}
// =====================================================================
/* function definition */
void
on_button2_clicked (GtkWidget *widget, gpointer data)
{
	GtkWidget *label1;
    label1 = (GtkWidget*) data;

    gtk_label_set_text(GTK_LABEL(label1), "Button2 Clicked: ");
}
// =====================================================================
/* function definition */
void
on_button3_clicked (GtkWidget *widget, gpointer data)
{
	GtkWidget *win;
    win = (GtkWidget*) data;
	gtk_widget_destroy(win);
}
// =====================================================================
/* function definition */
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

