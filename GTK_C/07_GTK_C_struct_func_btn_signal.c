/**
*=======================================================================
*
*          FILE:  07_GTK_C_struct_func_btn_signal.c
* 
*         USAGE: ./07_GTK_C_struct_func_btn_signal
*
*   COMPILE TIP: 
*        gcc -o 07_GTK_C_struct_func_btn_signal 07_GTK_C_struct_func_btn_signal.c `pkg-config --cflags --libs gtk+-3.0`
* 
*   DESCRIPTION: In This code a Struct is used to manipulate window widgets.
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
typedef struct _MyWindowData
{
	char *message;
	int countbtn1;
	int countbtn2;
	GtkWidget *label;
	GtkWidget *button1; 
	GtkWidget *button2;
	GtkWidget *button3;
    
}MyWindowData;
// =====================================================================
/* function declarations */
static void activate(GtkApplication* app, MyWindowData mwd, gpointer user_data);
void on_button1_clicked (GtkWidget *widget, gpointer user_data);
void on_button2_clicked(GtkWidget *widget, gpointer data);
void on_button3_clicked(GtkWidget *widget, gpointer data);
static void destroy(GtkWidget *widget, gpointer data);
// =====================================================================
/* Window function definition */
static void activate(GtkApplication* app, MyWindowData mwd, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *vbox;
	
	/* Set MyWindowData structure variables */
	mwd.message = "Passing pointer to structure of pointers to callback function\n";
	mwd.countbtn1 = 0;
	mwd.countbtn2 = 0;
	
	/* Create a new window, give it a title and display it to the user. */
	window = gtk_application_window_new (app);
	mwd.label = gtk_label_new ("Gtk.Button, Gtk.Label, Signal and function");
	mwd.button1 = gtk_button_new_with_label ("Run a Function---button1");
	mwd.button2 = gtk_button_new_with_label ("Change Label---button2");
	mwd.button3 = gtk_button_new_with_label ("exit---button3");
	vbox = gtk_box_new(TRUE, 1);
	
	/* Set attributes */
	gtk_window_set_title (GTK_WINDOW (window), "GNOME (GTK+) Form");
	gtk_window_set_default_size (GTK_WINDOW (window), 320, 100);
	
	/* Register callbacks */
	g_signal_connect (window, "destroy",
					  G_CALLBACK (destroy), &window);
	// Passing pointer to a structure of pointers to a callback function
	g_signal_connect (mwd.button1, "clicked",
					  G_CALLBACK (on_button1_clicked), &mwd);
	// Passing pointer to a structure of pointers to a callback function
	g_signal_connect (mwd.button2, "clicked",
					  G_CALLBACK (on_button2_clicked), &mwd);			  
	// When the button is clicked, destroy the window passed as an argument
	g_signal_connect (mwd.button3, "clicked",
					  G_CALLBACK (on_button3_clicked), window);
	
	/* Pack everything and display */
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_box_pack_start(GTK_BOX(vbox), mwd.label, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), mwd.button1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), mwd.button2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), mwd.button3, TRUE, TRUE, 0);
	gtk_widget_show_all (window);
	
	/* Hand control over to the main loop. */
	gtk_main();
}

// =====================================================================
/* function definition */
// Passing pointer to a structure of pointers to a callback function
void
on_button1_clicked (GtkWidget *widget, gpointer data)
{
    MyWindowData *MWD;
    MWD = (MyWindowData*) data;
    MWD->countbtn1 += 1;
    g_print("Button1 Clicked: %d\n %s\n",MWD->countbtn1,MWD->message);
}
// =====================================================================
/* function definition */
// Passing pointer to a structure of pointers to a callback function
void
on_button2_clicked (GtkWidget *widget, gpointer data)
{
	MyWindowData *MWD;
    MWD = (MyWindowData*) data;
    char str1[30] = "Button2 Clicked: ";
    char str2[5];
    MWD->countbtn2 += 1;
    sprintf(str2, "%d", MWD->countbtn2);
    strcat(str1, str2);
    gtk_label_set_text(GTK_LABEL(MWD->label), str1);
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

