/**
*=======================================================================
*
*          FILE:  01_GTK_C_simple_form.c
* 
*         USAGE: ./01_GTK_C_simple_form.c
*
*   COMPILE TIP: 
*        gcc -o 01_GTK_C_simple_form 01_GTK_C_simple_form.c `pkg-config --cflags --libs gtk+-3.0`
* 
*   DESCRIPTION: The GTK3 / C code below will produce a simple form.
* 
*       OPTIONS: ---
*  REQUIREMENTS: GTK+, C, GCC
*          BUGS: ---
*         NOTES: ---
*        AUTHOR: Mahdi Bahmani 
*  ORGANIZATION: www.itstorage.co 
*       CREATED: 2020/03/30
*      REVISION: 1.0
*=======================================================================
**/
// http://zetcode.com/gui/gtk2/firstprograms/

#include <gtk/gtk.h>


/* main window (parent) */
int main(int argc, char *argv[]) {

	GtkWidget *window;
	
	/* Initialize the environment */
	gtk_init(&argc, &argv);
	
	/* Create Widgets */
	// Create a new window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	/* Register callbacks */
	g_signal_connect(window, "destroy",
	  G_CALLBACK(gtk_main_quit), NULL);
	  
	/* Pack everything and display */
	gtk_widget_show(window);
	
	/* GTK main loop */
	gtk_main();
	
	return 0;
}
