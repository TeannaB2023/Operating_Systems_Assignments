# list/Makefile
#
# Makefile for list implementation and test file.
#
# Teanna Barrett @02924893

list: main.c list.c
	gcc -o list main.c list.c -I. 