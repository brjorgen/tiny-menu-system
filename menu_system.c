#include "menu_system.h"

t_menu *menu_create(char *name, int options_count, t_menu_option *options){
	t_menu *menu = (t_menu *)malloc(sizeof(t_menu)); if (!menu) return (NULL);
	menu->name = strdup(name); if (!menu->name) return (NULL);
	menu->options = (t_menu_option *)malloc(sizeof(t_menu_option) * (options_count + 1)); if (!menu->options) return (NULL);
	menu->options_count = options_count;

	int i = 0;
	for (;i < options_count; ++i)
	{
		menu->options[i].name = strdup(options[i].name); if (!menu->options[i].name) break;
		menu->options[i].fn = options[i].fn;
	}
	
	if (i != options_count){
		for (int j = 0; j < i; ++j)
			free(menu->options[j].name);
		free(menu->options);
		free(menu->name);
		free(menu);
		return NULL;
	}

	menu->options[options_count] = (t_menu_option){0};

	return (menu);
}

void	menu_free(t_menu *menu){
	if (!menu) return;

	for (int i = 0; i < menu->options_count; ++i)
		free(menu->options[i].name);

	free(menu->name);
	free(menu->options);
	free(menu);
}

void	menu_display(t_menu *menu){
	system("clear"); // or "cls" on Windows
	printf("== %s ==\n", menu->name);
	for (int i = 0; i < menu->options_count; ++i) {
		printf("%s %s\n", i == menu->selected_index ? ">" : " ", menu->options[i].name);
	}
	printf("\nUse W/S to navigate, Enter to select, Q to go back.\n");
}

void	menu_navigate(t_menu *current_menu) {
	while (1) {
		menu_display(current_menu);

		int c = getchar();
		while (getchar() != '\n');

		if (c == 'q' || c == 'Q') {
			return ;
		} else if ((c == 'w' || c == 'W') && current_menu->selected_index > 0) {
			current_menu->selected_index--;
		} else if ((c == 's' || c == 'S') && current_menu->selected_index < current_menu->options_count - 1) {
			current_menu->selected_index++;
		} else if (c == '\n' || c == '\r') {
			if (!strncmp("submenu_", current_menu->options[current_menu->selected_index].name, strlen("submenu_")))
			{
				t_menu *submenu = current_menu->options[current_menu->selected_index].fn(NULL);
				menu_navigate(submenu);
				menu_free(submenu);
			}
			else
				current_menu->options[current_menu->selected_index].fn(NULL);
		}
	}
}
