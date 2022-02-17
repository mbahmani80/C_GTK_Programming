/**
*=======================================================================
*
*          FILE:  
* 				  15_GTK_C_Glade_TreeView_ListStore.c
* 				  glade/15_GTK_C_Glade_TreeView_ListStore.glade
* 
*         USAGE: ./15_GTK_C_Glade_TreeView_ListStore
*
*   COMPILE TIP: 
*   gcc -o 15_GTK_C_Glade_TreeView_ListStore 15_GTK_C_Glade_TreeView_ListStore.c -rdynamic `pkg-config --cflags --libs gtk+-3.0`
* 
* 
*   DESCRIPTION: This code consist of the following:
* 
*       OPTIONS: ---
*  REQUIREMENTS: GTK+, C, GCC
*          BUGS: ---
*         NOTES: ---
*        AUTHOR: Mahdi Bahmani 
*  ORGANIZATION: www.itstorage.co 
*       CREATED: 12.06.2020
*      REVISION: 1.0
*=======================================================================
**/

#include <gtk/gtk.h>

// http://scentric.net/tutorial/sec-treemodel-remove-row.html
/******************************************************************
*
*  list_store_remove_nth_row
*
*  Removes the nth row of a list store if it exists.
*
*  Returns TRUE on success or FALSE if the row does not exist.
*
******************************************************************/

gboolean
list_store_remove_nth_row (GtkListStore *store, gint n)
{
	GtkTreeIter  iter;

	 g_return_val_if_fail (GTK_IS_LIST_STORE(store), FALSE);
	
	 /* NULL means the parent is the virtual root node, so the
	  *  n-th top-level element is returned in iter, which is
	  *  the n-th row in a list store (as a list store only has
	  *  top-level elements, and no children) */
	 if (gtk_tree_model_iter_nth_child(GTK_TREE_MODEL(store), &iter, NULL, n))
	 {
		gtk_list_store_remove(store, &iter);
		return TRUE;
	 }

	return FALSE;
}
