#!/bin/bash

case $1 in
    "test")
	gcc menu_system.c main.c -o test-menu-system
        ;;
    "clean")
	rm test-menu-system menu_system.o
	;;
    "fclean")
	rm libtinymenusystem.a test-menu-system menu_system.o
	;;
    *)
	gcc -c menu_system.c -o menu_system.o
	ar rcs libtinymenusystem.a menu_system.o
	;;
esac
