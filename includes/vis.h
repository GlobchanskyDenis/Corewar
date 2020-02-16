/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:06:39 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/15 19:36:32 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_H
# define VIS_H

# include "libft.h"
# include "get_next_line.h"
# include "SDL_ttf.h"
# include "SDL.h"
# include "vm.h"

typedef struct		s_theme
{
	SDL_Rect		rect0;
	SDL_Rect		rect1;
	SDL_Rect		rect2;
	SDL_Rect		rect3;
}					t_theme;

typedef struct		s_players
{
	SDL_Surface		*pl1;
	SDL_Surface		*pl1_sh;
	SDL_Surface		*pl2;
	SDL_Surface		*pl2_sh;
	SDL_Surface		*pl3;
	SDL_Surface		*pl3_sh;
	SDL_Surface		*pl4;
	SDL_Surface		*pl4_sh;
}					t_players;

typedef struct		s_lis
{
	int				posi;
	struct s_lis	*next;
}					t_lis;

typedef struct		s_game
{
	unsigned char	*field;
	unsigned char	*prev_field;
	short			*prev_owner;
	t_lis			*posi;
	int				cycle;
	int				processes;
	int				cycle_to_die;
	int				cycle_delta;
	int				nbr_live;
	int				max_checks;
	int				status;
}					t_game;

typedef struct		s_player_info
{
	char			*pl1_name;
	char			*pl2_name;
	char			*pl3_name;
	char			*pl4_name;
	char			*pl1_slogan;
	char			*pl2_slogan;
	char			*pl3_slogan;
	char			*pl4_slogan;
	char			**pl1_comm;
	char			**pl2_comm;
	char			**pl3_comm;
	char			**pl4_comm;
	SDL_Surface		*pic_com1;
	SDL_Surface		*pic_com2;
	SDL_Surface		*pic_com3;
	SDL_Surface		*pic_com4;
	SDL_Color		pl1_col;
	SDL_Color		pl2_col;
	SDL_Color		pl3_col;
	SDL_Color		pl4_col;

}					t_player_info;

typedef struct		s_core
{
	SDL_Window		*window;
	SDL_Surface		*screen_surface;
	SDL_Surface		*winner;
	SDL_Surface		*winner_frame;
	SDL_Surface		*strelochka;
	SDL_Surface		*text_surface;
	TTF_Font		*font_menu;
	TTF_Font		*font_field;
	TTF_Font		*font_name;
	t_players		*players;
	t_theme			*theme;
	t_player_info	*player_info;
	t_game			*game;
	int				*players_status;
	int				*status_status;
	int				screen_width;
	int				screen_height;
	int				status;
	SDL_Event		event;
	SDL_Color		text_color;
	int				col;
	int				number_players;
	int				number_theme;
	int				game_fon;
	int				l_alive;
}					t_core;

/*
** choose_players.c
*/

int					ft_find_str_players(t_core *core, char **str);
int					ft_create_theme_players(t_core *core);
int					ft_clear_fon(t_core *core);
int					ft_present_players_help(t_core *core);
int					ft_present_players(t_core *core);

/*
** choose_players_hh.c
*/

int					ft_cmp_vm(t_core *core, t_vm *vm, int orig);
void				ft_get_col(SDL_Color *col, int mycol);
int					ft_fill_players_array(t_core *core, int a, int b);
int					ft_present_players_help_h(t_core *core);
int					ft_right_players_number(t_core *core);

/*
** ft_load_players.c
*/

void				ft_load_players_1(t_core *core);
void				ft_load_players_2(t_core *core);
void				ft_load_players_3(t_core *core);
int					ft_load_players(t_core *core);

/*
** ft_load_players_info.c
*/

void				ft_load_players_info_11(t_core *core);
void				ft_load_players_info_1(t_core *core);
void				ft_load_players_info_21(t_core *core);
void				ft_load_players_info_2(t_core *core);
int					ft_load_players_info(t_core *core, t_vm *vm);

/*
** ft_load_players_info_h.c
*/

void				ft_load_players_info_31(t_core *core, t_vm *vm);
void				ft_load_players_info_3(t_core *core, t_vm *vm);

/*
** choose_players_h.c
*/

int					ft_players_fon(t_core *core);
int					ft_point_in_round_h(int x, int y, int r);
int					ft_point_in_round(int x, int y, int r);

/*
** ft_choose_players.c
*/

void				ft_choose_players_h(t_core *core);
int					ft_choose_players(t_core *core);

/*
** choose_theme.c
*/

int					ft_create_theme_rect(t_core *core);
int					ft_create_theme_text(t_core *core);
int					ft_create_instruments(t_core *core);

/*
** ft_choose_theme.c
*/

int					ft_choose_theme_1(t_core *core);
int					ft_choose_theme_2(t_core *core);
int					ft_choose_theme_3(t_core *core);
int					ft_choose_theme(t_core *core);

/*
** comments_help.c
*/

int					ft_is_ok(t_core *core, int i);
void				ft_next_comm_h(int *i, int j);
int					ft_next_comm(t_core *core);
int					ft_find_rect_sq(t_core *core, SDL_Rect *rect, int pl);
int					ft_find_rect_com(t_core *core, SDL_Rect *rect, int pl);

/*
** comments_help_h.c
*/

int					ft_prev_comm(int i, t_core *core);
int					ft_part_com(t_core *core, char **tmp, int i, char *comment);
int					ft_create_file_name_theme(char **file, \
						int theme, int pl, t_core *core);
void				ft_init_arr(char **arr);
int					ft_load_pic_com(t_core *core);

/*
** comments_help_hh.c
*/

void				ft_delete_prev_comm_h(t_core *core, int j);
int					ft_delete_prev_comm(t_core *core, int j);
void				ft_cpy_comment_h(int *i, \
						char **comment, int new_len, char **tmp);
char				*ft_cpy_comment(char **comment, int i, t_core *core);
int					ft_part_rect(SDL_Rect *r, SDL_Rect rect, int i, int count);

/*
** comments_help_hhh.c
*/

int					ft_find_local_end(char **comment, t_core *core);
void				ft_rect_for_text(SDL_Rect *rect_text, \
						SDL_Rect rect, int num);
void				ft_load_i_comment_h(t_core *core, int i, int pl, char *str);
int					ft_load_i_comment(t_core *core, int theme, int pl);

/*
** ft_new_hope.c
*/

void				ft_new_hope_h(SDL_Rect *r, SDL_Rect rect, int count);
void				ft_new_hope(t_core *core, SDL_Rect rect, char *comment);

/*
** ft_change_comment.c
*/

void				ft_change_comment_h(t_core *core, int i);
void				ft_change_comment_hh(t_core *core, int i);
int					ft_change_comment(t_core *core);

/*
** comments.c
*/

void				ft_load_comments_11(t_core *core);
void				ft_load_comments_1(t_core *core);
void				ft_load_comments_2(t_core *core);
void				ft_load_comments_21(t_core *core);
int					ft_load_comments(t_core *core);

/*
** comments_h.c
*/

void				ft_load_comments_3(t_core *core);
void				ft_load_comments_31(t_core *core);
int					ft_other(t_core *core);

/*
** draw_carriet.c
*/

void				ft_reget_col(SDL_Color col, int *mycol);
int					ft_delete_list(t_lis *list, t_core *core, t_vm *vm);
void				ft_draw_carriet_h(t_core *core);
int					ft_draw_carriet(t_core *core, t_vm *vm);
void				ft_draw_field_h(t_core *core, \
						t_vm *vm, int num, SDL_Rect *rect);

/*
** draw_field_help.c
*/

int					ft_get_rect(SDL_Rect *rect, int flag);
int					ft_get_symb(t_core *core, char **str, int flag);
void				ft_eql_col(SDL_Color *col1, SDL_Color col2);
void				ft_find_owner_col_h(t_core *core, short pl, int *a);
void				ft_find_owner_col_hh(t_core *core, \
						short pl, int *a, short max_pl);

/*
** ft_find_owner_col.c
*/

void				ft_find_owner_col_hhh(t_core *core, int a);
void				ft_find_owner_col_help(int pl, int *a);
void				ft_find_owner_col_hhhh(t_core *core, int *a, int pl);
void				ft_find_owner_col_help_h(t_core *core, int *a);
int					ft_find_owner_col(t_core *core, short pl, short max_pl);

/*
** draw_field.c
*/

void				ft_draw_field_hh(t_core *core, \
						t_vm *vm, int num, SDL_Rect *rect);
void				ft_draw_field_init(char **str, \
						SDL_Rect *rect, int *num, int *pr);
int					ft_draw_field_if(t_core *core, t_vm *vm, int num, int flag);
int					ft_draw_field_if1(t_core *core, \
						t_vm *vm, int num, int flag);
int					ft_draw_field(t_core *core, t_vm *vm, int flag);

/*
** draw_letter.c
*/

int					ft_get_symb_n(t_core *core, char **str, int n);
void				ft_draw_letter_h(SDL_Rect *rect, \
						t_core *core, int n, t_vm *vm);
void				ft_draw_letter_hh(t_core *core, int n, SDL_Rect rect);
int					ft_draw_letter(t_core *core, int n, t_vm *vm);
int					ft_draw_wall(t_core *core, int n);

/*
** end_game.c
*/

int					ft_game_over(t_core *core);
int					ft_funal_screen(t_core *core, t_vm *vm);
int					ft_strelochka(t_core *core, SDL_Rect rect);
int					ft_end_game_help(t_core *core, SDL_Rect rect);
int					ft_end_game(t_core *core, t_vm *vm);

/*
** error.c
*/

void				ft_error();
void				ft_error_ttf();
void				ft_success(t_core *core);
void				ft_sim_error();

/*
** ft_find_winner_file.c
*/

int					ft_find_winner_file(char **str, int theme, int pl);

/*
** free.c
*/

void				ft_free_core(t_core *core);

/*
** ft_del.c
*/

void				ft_delete_players(t_core *core);
void				ft_free_arr(char **arr);
void				ft_list_del(t_lis *list);

/*
** ft_free_player_info.c
*/

void				ft_free_player_info(t_core *core);

/*
** initial_core.c
*/

void				ft_empty_core(t_core *core);
int					ft_init_core(t_core *core, t_vm *vm);
void				ft_init_players(t_core *core);
void				ft_init_players_info(t_core *core);

/*
** theme_text.c
*/

int					ft_text_theme(t_core *core, char *str);
int					ft_text_fight(t_core *core, int fl);
int					ft_text_inter(t_core *core, int fl);
int					ft_text_disco(t_core *core, int fl);

/*
** game.c
*/

int					ft_game(t_core *core, t_vm *vm);

/*
** see_stat.c
*/

int					ft_see_stat(t_core *core, int x, int y, int num);
int					ft_present_status(t_core *core);
int					ft_fill_status_array(t_core *core, int a, int b);

/*
** main.c
*/

int					main_vis(t_vm *vm);

/*
** pause.c
*/

int					ft_draw_pause(t_core *core);
int					ft_redraw_pause(t_core *core, t_vm *vm);

/*
** present_winner.c
*/

int					ft_present_winner(t_core *core, t_vm *vm);

/*
** titres.c
*/

int					ft_titres(t_core *core);
int					ft_draw_titre(t_core *core, int y, char *aut);

/*
** status_change.c
*/

void				ft_render_text(t_core *core, \
						const char *str, SDL_Rect *rect);
void				ft_print_status_top(t_core *core, \
						SDL_Rect *rect, SDL_Color col, char *s);
void				ft_print_status_down(t_core *core, \
						SDL_Rect *rect, SDL_Color col, char *s);
void				ft_delete_status_top(t_core *core, \
						SDL_Rect *rect, char *slogan, int status);
void				ft_delete_status_down(t_core *core, \
						SDL_Rect *rect, char *slogan, int status);

/*
** players_game.c
*/

int					ft_reload_players(t_core *core);
int					ft_put_players(t_core *core);
void				ft_put_players_name(t_core *core, \
						SDL_Rect rect, int num, char *str);

/*
** put_field.c
*/

int					ft_put_field(t_core *core, t_vm *vm);

/*
** fon.c
*/

int					ft_game_fon(t_core *core, t_vm *vm);

/*
** defines.c
*/

int					ft_draw_defines(t_core *core);
int					ft_put_defines(t_core *core, t_vm *vm);

/*
** game_func.c
*/

void				ft_game_cycle(t_core *core, t_vm *vm, t_corewar *cw);
void				ft_see_defines(t_core *core, t_vm *vm);
void				ft_see_field(t_core *core, t_vm *vm);
void				ft_see_comment(t_core *core, int *schet);

/*
** game_event.c
*/

int					ft_game_event(t_core *core, t_vm *vm, int *a);

#endif
