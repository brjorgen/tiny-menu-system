#include <stdio.h>
#include <stdlib.h>
#include "menu_system_stack.h"

/* --- actions --- */
void action_1(void *_) {
	printf("Action 1...\n");
	getchar();
}

void action_2(void *_) {
	printf("Action 2...\n");
	getchar();
}

void action_3(void *_) {
	printf("Action 3...\n");
	getchar();
}


void action_4(void *_) {
	printf("Action 4...\n");
	getchar();
}


void action_exit(void *_) {
	printf("exitting...\n");
	exit(0);
}


/* --- menus --- */
int main(void) {
	/* Define A menu like so. */
	/* You must define submenus BEFORE so they can be referenced in this one. */

	t_menu sub_menu = {
		.name = "A Submenu",
		.options_count = 2,
		.selected_index = 0,
		.options = (t_menu_option[]) {
			{
				.name           = "Do another thing",
				.type           = MENU_OPTION_ACTION,
				.action         = action_3,
				.submenu        = NULL
			},
			{
				.name           = "Back",
				.type           = MENU_OPTION_ACTION,
				.action         = NULL,  /* If the action is NULL, returns to parent menu */
				.submenu        = NULL
			},
		}
	};

	t_menu main_menu = {
		.name = "Main Menu",
		.options_count = 4,
		.selected_index = 0,
		.options = (t_menu_option[]) {
			{
				.name		= "Do a thing",
				.type		=  MENU_OPTION_ACTION,
				.action		= action_1,
				.submenu	= NULL
			},

			{
				.name		= "Do another thing",
				.type		= MENU_OPTION_ACTION,
				.action		= action_2,
				.submenu	= NULL
			},

			
			{
				.name		= "Enter a submenu",
				.type		= MENU_OPTION_SUBMENU,
				.action		= NULL,
				.submenu	= &sub_menu
			},
			{
				.name           = "Exit",
				.type           = MENU_OPTION_ACTION,
				.action         = action_exit,
				.submenu        = NULL
			},
		}
	};

	menu_navigate(&main_menu);
	return (0);
}
