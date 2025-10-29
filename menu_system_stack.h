#ifndef _MENU_SYSTEM_H_
#define _MENU_SYSTEM_H_

typedef enum e_menu_option_type {
	MENU_OPTION_ACTION,
	MENU_OPTION_SUBMENU
}	     t_menu_option_type;

/* forward decl */
struct s_menu;

typedef struct s_menu_option {
	const char	   *name;
	t_menu_option_type type;
	void		   (*action)(void *);
	struct s_menu      *submenu;
}	       t_menu_option;

typedef struct s_menu {
	const char    *name;
	int	      options_count;
	int           selected_index;
	t_menu_option *options;
}	       t_menu;

void	menu_display(t_menu *menu);
void	menu_navigate(t_menu *current_menu);

#endif /* _MENU_SYSTEM_H_ */
