#!/bin/bash

gcc main.c -o $1 -lGL -lGLU -lglut -L/usr/X11R6/lib -lX11 -lm -g
