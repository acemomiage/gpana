#!/bin/sh

gcc -Wall -o gpana $(pkg-config --cflags --libs gtk+-2.0 gmodule-2.0 libglade-2.0) gpana.c


