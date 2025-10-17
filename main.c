#include "menu_system.h"

void *fn_1(void *a) {
	(void)a;

	printf("called %s\n", __FUNCTION__);

	return (NULL);
}

void *fn_2(void *a){
	(void)a;

	printf("called %s\n", __FUNCTION__);

	return (NULL);
}

void *fn_3(void *a){
	(void)a;
	t_menu_option options[] = {
		{"sub_option_a", fn_1},
		{"sub_option_b", fn_2},
	};

	t_menu *menu = menu_create("Menu 1", 2, options);

	return (menu);
}

int	main(void){
	t_menu_option options[] = {
		{"option_a", fn_1},
		{"option_b", fn_2},
		{"submenu_option_c", fn_3},
	};

	t_menu *menu = menu_create("Menu 1", 3, options);

	menu_navigate(menu);
	menu_free(menu);
}
