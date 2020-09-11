# list/Makefile
#
# Makefile for list implementation and test file.
#
# Earl Tankard, Jr.

list: main.c list.c
	gcc -o list main.c list.c
