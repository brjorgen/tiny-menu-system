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
    "stack_test")
	gcc main_stack.c menu_system_stack.c -o test_menu_system_stack
	;;
    "stack_clean")
	rm test_menu_system_stack
	;;
    "stack_fclean")
	rm libtinymenusystemstack.a test_menu_system_stack menu_system_stack.o
	;;

    "stack")
	gcc -c menu_system_stack.c -o menu_system_stack.o
	ar rcs libtinymenusystemstack.a menu_system_stack.o
	;;
    *)
	gcc -c menu_system.c -o menu_system.o
	ar rcs libtinymenusystem.a menu_system.o
	;;
esac
