/*-------------------------------------------------------------------------
 * 
 *         FILES: GTK_C_fork_progressbar.c, GTK_C_fork_progressbar.glade 
 *         USAGE: ./GTK_C_fork_progressbar  
 *   DESCRIPTION: GTK+ C progressbar vfork example
 *       OPTIONS: ---
 *  REQUIREMENTS: GTK+, C, GCC, Glade           
 *          BUGS: ---
 *         NOTES: ---
 *        AUTHOR: Mahdi Bahmani 
 *  ORGANIZATION: www.itstorage.co 
 *       CREATED: Tue 07 Apr 2020 10:20:00
 *	 LAST CHANGE: Thu 09 Apr 2020 21:31:08
 *      REVISION: 1.0
 * 
 *-----------------------------------------------------------------------*/
 
/*------------------------------------------------------------------------- 

 Compile with:  

gcc  -Wall -g GTK_C_fork_progressbar.c \
-o GTK_C_fork_progressbar -rdynamic \
-lpthread `pkg-config --cflags --libs gtk+-3.0`

 *-----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <gtk/gtk.h>

GtkWidget *g_fork_btn;
GtkWidget *g_progress_bar1;
GtkWidget *g_progress_bar2;
GtkWidget *g_lbl_progress_bar1;
GtkWidget *g_lbl_progress_bar2;


// process bar's value to the new value
static gboolean fill_p_bar (gpointer   user_data)
{
	GtkWidget *progress_bar = user_data;
	
	/*Get the current progress*/
	gdouble fraction;
	fraction = gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR (progress_bar));
	
	/*Increase the bar by 10% each time this function is called*/
	fraction += 0.1;
	
	/*Fill in the bar with the new fraction*/
	gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR (progress_bar), fraction);
	
	/*Ensures that the fraction stays below 1.0*/
	if (fraction < 1.0) 
	return TRUE;
	
	return FALSE;
}


void fork_me(GtkWidget *widget, gpointer data)
{
	pid_t pid;
	int  p_pid, c_pid;
	char str_pid_c[40] = {0};
	char str_pid_p[40] = {0};
  
	pid = vfork();
	if(pid == -1)
	{
		/* fork() failed */
		fprintf(stdout, "fork() error");
		exit(-1);
	}
	else if(pid > 0)
	{
		/* parent */
		printf("PARENT: PID=%d PPID=%d\n",
			getpid(), getppid());
		p_pid = getpid();
		sprintf(str_pid_p, "%s" "%d","Parent PID = ",p_pid);
		//strcpy(str_pid_t , str_pid_p);
		g_timeout_add(100, fill_p_bar, g_progress_bar1);
	    gtk_label_set_text(GTK_LABEL(g_lbl_progress_bar1), str_pid_p);
		if (pid)
			wait(NULL);


	}
	else if(pid == 0)
	{
		/* child */
		printf("Forking...PID=%d\n", (int)pid);
		printf("CHILD: PID=%d PPID=%d\n",
		getpid(), getppid());
		c_pid = getpid();
		sprintf(str_pid_c, "%s" "%d", "Child proccess is Running ... PID = ",c_pid);
	    //strcpy(str_pid_t , str_pid_c);
		g_timeout_add(100, fill_p_bar, g_progress_bar2);
	    gtk_label_set_text(GTK_LABEL(g_lbl_progress_bar2), str_pid_c);
	    
	    fprintf(stderr, "Child proccess is Running ... PID = %d\n", c_pid);
		execlp("ls", "ls", "-CF", "/", NULL);
	    /* if exec() returns, there is something wrong */
	    perror("execlp");
	
	    /* exit child. note the use of _exit() instead of exit() */
		_exit(0);
	}
 
	gtk_widget_set_sensitive(g_fork_btn, FALSE);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
	GtkBuilder      *builder; 
	GtkWidget       *window;
	

	gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/GTK_C_fork_progressbar.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    
    //Connecting the signals in the code
    gtk_builder_connect_signals(builder, NULL);
    
    // get pointers to the two labels
    g_lbl_progress_bar1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_progress_bar1"));
    g_lbl_progress_bar2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_progress_bar2"));
    
    // get pointers to the two progressbars
    g_progress_bar1 = GTK_WIDGET(gtk_builder_get_object(builder, "progress_bar1"));
    g_progress_bar2 = GTK_WIDGET(gtk_builder_get_object(builder, "progress_bar2"));
    
    // get pointers to the button
    g_fork_btn = GTK_WIDGET(gtk_builder_get_object(builder, "fork_btn"));
         
	//g_signal_connect(button, "clicked", G_CALLBACK(fork_me), NULL);
	g_signal_connect(g_fork_btn, "clicked", G_CALLBACK(fork_me), NULL);
		  
	/* show everything */
	gtk_widget_show (window);
 
	/* main loop */
	gtk_main ();

exit(0);         
}
