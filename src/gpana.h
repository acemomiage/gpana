/* -*- mode: C -*- */

#ifndef __GPANA_H_
#define __GPANA_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>

#include "version.h"

#define MAX_FILE_NAME    1000

typedef struct _GpanaWindow GpanaWindow;
struct _GpanaWindow {
  /* Widget */
  GtkWidget   *w_main;
  GtkWidget   *w_about;
  GtkBuilder  *builder;
  GtkWidget   *w_file_choose;
  char       filename[MAX_FILE_NAME];
};

#endif
