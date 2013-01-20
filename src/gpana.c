/* -*- mode: C -*- */
#include "gpana.h"

/* Global Variables */
GpanaWindow *gw;

/* file chooser */
G_MODULE_EXPORT
gint cb_create_file_choose_window(GtkWidget *w,
				  gpointer  data)
{
  puts("File Chooser\n");
  gw->w_file_choose = GTK_WIDGET(gtk_builder_get_object(gw->builder,
							"filechooserdialog1"));
  gtk_widget_show(gw->w_file_choose);
  return 0;
}

/* Drawarea */
G_MODULE_EXPORT
gint cb_quit_main_window(GtkWidget	*w,
			 gpointer	 data)
{
  printf("Bye-Bye\n");
  gtk_main_quit();
  return 0;
}

G_MODULE_EXPORT
gint cb_expose(GtkWidget	*widget,
	       GdkEventExpose	*e,
	       gpointer		 data)
{
  GdkPixbuf	*pixbuf;
  GdkPixbuf	*bg;
  GdkPixmap	*map;
  gint		 w, h;

  pixbuf = gdk_pixbuf_new_from_file("test.jpg", NULL);
    
  w  = gdk_pixbuf_get_width(pixbuf);
  h  = gdk_pixbuf_get_height(pixbuf);
  bg = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, w, h);
  gdk_pixbuf_composite_color(pixbuf, bg,
			     0, 0, w, h, 0, 0, 1.0, 1.0,
			     GDK_INTERP_BILINEAR, 255, 0, 0, 16,
			     0xaaaaaa, 0x555555);
  gdk_pixbuf_render_pixmap_and_mask(bg, &map, NULL, 255);
  gtk_widget_set_size_request(widget, 100, 100);
  gdk_window_set_back_pixmap(widget->window, map, FALSE);
  gdk_window_clear(widget->window);
 
  g_object_unref(bg);
  g_object_unref(map);

  return TRUE;
}

/* About Window */
G_MODULE_EXPORT
gint cb_quit_about_window(GtkWidget *w,
			  gpointer data)
{
  static int status = TRUE;

  if (status == TRUE){
    printf("Good Luck!\n");
    gtk_widget_hide(gw->w_about);
    status = FALSE;
  } else {
    printf("Hi!\n");
    gtk_widget_show(gw->w_about);
    status = TRUE;
  }

  return 0;
}

G_MODULE_EXPORT
gint cb_create_about_window(GtkWidget *w,
			    gpointer data)
{

  gw->w_about = GTK_WIDGET(gtk_builder_get_object(gw->builder, "aboutdialog1"));
  gtk_widget_show(gw->w_about);

  return 0;
}

int main(int argc, char *argv[])
{

  /* GtkWidget   *main,*about;  */
  /* GtkBuilder  *builder;	     */
  GError      *gerr = NULL;

  gw = g_slice_new(GpanaWindow);
  gtk_init(&argc, &argv);
  gw->builder = gtk_builder_new();
  gtk_builder_add_from_file(gw->builder, "gpana.glade", &gerr);

  gw->w_main = GTK_WIDGET(gtk_builder_get_object(gw->builder, "window1"));
  gw->w_about= GTK_WIDGET(gtk_builder_get_object(gw->builder, "aboutdialog1"));
  gtk_builder_connect_signals(gw->builder, (gpointer *)NULL);
  gtk_widget_show(gw->w_main);
  gtk_main();

  g_slice_free(GpanaWindow, gw);
  return 0;
}

