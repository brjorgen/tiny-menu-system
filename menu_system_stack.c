#include <stdio.h>
#include <stdlib.h>
#include "menu_system_stack.h"

/* When using the stack based implementation, your job is to define */
/* the structure of your menu, like illustrated in main() */

void	menu_display(t_menu *menu){
	system("clear"); /* we don't care about Windows, here. */
	printf("== %s ==\n", menu->name);
	for (int i = 0; i < menu->options_count; ++i) {
		printf("%s %s\n", i == menu->selected_index ? ">" : " ", menu->options[i].name);
	}
	printf("\nUse W/S to navigate, Enter to select, Q to go back.\n");
}

void menu_navigate(t_menu *menu) {
	while (1) {
		menu_display(menu);

		int c = getchar();
		while (getchar() != '\n'); /* flush */

		if (c == 'q' || c == 'Q')
			return;
		else if ((c == 'w' || c == 'W') && menu->selected_index > 0)
			menu->selected_index--;
		else if ((c == 's' || c == 'S') && menu->selected_index < menu->options_count - 1)
			menu->selected_index++;
		else if (c == '\n' || c == '\r') {
			t_menu_option *opt = &menu->options[menu->selected_index];
			if (opt->type == MENU_OPTION_SUBMENU && opt->submenu)
				menu_navigate(opt->submenu);
			else if (opt->type == MENU_OPTION_ACTION && opt->action)
				opt->action(NULL);
			else
				return; /* Returns to parent menu */
		}
	}
}
