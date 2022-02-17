// GTK_C_gtk_thread_progressbar.c
// gcc -Wall -g GTK_C_gtk_thread_progressbar.c -o GTK_C_gtk_thread_progressbar `pkg-config --cflags --libs gtk+-2.0 gthread-2.0` -lpthread && ./GTK_C_gtk_thread_progressbar

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <gtk/gtk.h>

GtkWidget* button;
GtkWidget* progressbar;
double fraction=0.0;
pthread_t a_thread;
pthread_mutex_t mutex;



void destroy(GtkWidget* widget, gpointer data){
gtk_main_quit();
}



void* threadfunc(void* arg){
pthread_mutex_lock(&mutex);
printf("threadfunc: new thread got mutex and has started execution..\n");
double fr=0.0;
int i=0;
char str[10];
gdk_threads_enter(); fr = gtk_progress_bar_get_fraction((GtkProgressBar*) progressbar); gdk_threads_leave();
for(i=0; i < 5; i++){
fr +=0.01;
if(fr > 1.0)
fr = 1.0;
gdk_threads_enter();
gtk_progress_bar_set_fraction((GtkProgressBar*) progressbar, fr);
sprintf(str, "%.0f%%", fr * 100.0);
gtk_progress_bar_set_text ((GtkProgressBar*) progressbar, str);
gdk_threads_leave();
usleep(500000);
}

pthread_mutex_unlock(&mutex);
return NULL;
}



void buttonclicked(GtkWidget* widget, gpointer data){
int res;
printf("buttonclicked: creating new thread ..\n");
res = pthread_create(&a_thread, NULL, threadfunc, NULL);
if(res != 0){
perror("thread creation failed");
exit(-1);
}
}



int main(int argc, char* argv[]){
g_thread_init(NULL);
gdk_threads_init();
gtk_init(&argc, &argv);

pthread_mutex_init(&mutex, NULL);

GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_signal_connect(GTK_OBJECT (window), "destroy",
GTK_SIGNAL_FUNC(destroy), NULL);

gtk_container_set_border_width(GTK_CONTAINER (window), 10);

/* add a button to do something usefull */
GtkWidget* vbox1 = gtk_vbox_new( 0, 2);
button = gtk_button_new_with_label("0");
progressbar = gtk_progress_bar_new();

gtk_signal_connect(GTK_OBJECT (button), "clicked",
GTK_SIGNAL_FUNC(buttonclicked), NULL);

gtk_container_add(GTK_CONTAINER(window), vbox1);
gtk_container_add(GTK_CONTAINER(vbox1), progressbar);
gtk_container_add(GTK_CONTAINER(vbox1), button);

/* show everything */
gtk_widget_show_all(window);

/* main loop */
gdk_threads_enter();
gtk_main ();
gdk_threads_leave();
return 0;
}
