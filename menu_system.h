#ifndef _MENU_SYSTEM_H_
#define _MENU_SYSTEM_H_

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

typedef void *(*t_ptr_generic_function)(void *);

typedef struct	s_menu_option {
	char	*name;
	t_ptr_generic_function fn;
}		t_menu_option;

typedef struct s_menu {
	char *name;
	int options_count;
	int selected_index;
	t_menu_option *options;
}	       t_menu;

t_menu *menu_create(char *name, int options_count, t_menu_option *options);
void   menu_free(t_menu *menu);

//     Implement your own version of those.
void   menu_display(t_menu *menu);
void   menu_navigate(t_menu *menu);

#endif /* _MENU_SYSTEM_H_ */
