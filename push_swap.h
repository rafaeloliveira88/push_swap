/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:09:02 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/26 18:10:48 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lsti
{
	int				c;
	struct s_lsti	*p;
	struct s_lsti	*n;
}					t_lsti;

typedef struct s_lst
{
	void			*c;
	struct s_lst	*p;
	struct s_lst	*n;
}					t_lst;

typedef struct s_data_container
{
	t_lsti			*a;
	t_lsti			*b;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	t_lst			*lists_commands;
}					t_data_container;

t_lsti				*ft_lstinew(int content);
void				ft_lstiadd_front(t_lsti **lst, t_lsti *new_node);
t_lsti				*ft_lstilast(t_lsti *lst);
int					ft_lstisize(t_lsti *lst);
void				ft_lsticlear(t_lsti **lst);
t_lsti				*ft_lstipush(t_lsti **lst);
void				ft_lstidelone(t_lsti *lst);
void				ft_lstiadd_last(t_lsti **lst, t_lsti *new_node);

t_lst				*ft_lstnew(void *content);
void				ft_lstadd_front(t_lst **lst, t_lst *new_node);
t_lst				*ft_lstlast(t_lst *lst);
int					ft_lstsize(t_lst *lst);
void				ft_lstclear(t_lst **lst, void (*del)(void *));
t_lst				*ft_lstpush(t_lst **lst);
void				ft_lstdelone(t_lst *lst, void (*del)(void *));
void				ft_lstadd_last(t_lst **lst, t_lst *new_node);

void				ft_swap(t_lsti **lst, int stack, int print_command);
void				ft_swapall(t_lsti **lst_x, t_lsti **lst_y,
						int print_command);
void				ft_rotate(t_lsti **lst, int stack, int print_command);
void				ft_rotateall(t_lsti **lst_x, t_lsti **lst_y,
						int print_command);
void				ft_rrotate(t_lsti **lst, int stack, int print_command);
void				ft_rrotateall(t_lsti **lst_x, t_lsti **lst_y,
						int print_command);
void				ft_push(t_lsti **lst_x, t_lsti **lst_y, int stack,
						int print_command);

int					ft_atoi(const char *str);
int					ft_atoi_check_integer(const char *str, int *bigger);
int					ft_isnumber(char *str);

int					ft_check_args(int size, char **args);
void				ft_free_integer(void *content);

t_lsti				*ft_init_stack_a(int size, char **args);

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_print_command(int command);
void				ft_putnbr(int n);

void				ft_sort(t_lsti **a);

void				ft_print_stack(t_lsti *stack);

void				ft_sort_three(t_lsti **s);
void				ft_sort_two(t_lsti **a);
void				ft_sort_four(t_data_container *dc);

int				ft_init_sort(t_data_container *dc);
void				ft_sort(t_lsti **a);
void				ft_sort_turk(t_data_container *dc);

void				ft_rot_a_min_top(t_data_container *dc);
void				ft_push_all_elements(t_data_container *dc);
// void ft_rot_a_untill_min(t_data_container *dc);
// void ft_rot_a_untill_max(t_data_container *dc);
int					ft_rot_a_between_min_max(t_data_container *dc);
void				ft_update_min_max_a(t_data_container *dc);
void				ft_execute_cheapest(t_data_container *dc);
int					ft_get_cheapest(t_data_container *dc);
void				ft_free(void *ptr);
void				ft_execute_operation(int operation, t_data_container *dc);
void				ft_update_min_max_b(t_data_container *dc);
void				ft_calculate_cheapest(t_data_container *dc);
t_lsti				*ft_cheap_aux(t_data_container *dc, int index);
void				ft_check_match_operations(t_lsti **temp, t_lsti **cmd);
void				ft_insert_cmd_list(t_lsti **temp, t_lsti **cmd, int i);
t_lsti				*ft_choose_rotate_a(t_data_container *dc, int index);
void				ft_choose_rot_a_aux(t_data_container *dc, int ind, int r,
						t_lsti **cmds);
void				ft_rotate_b_untill_push(t_data_container *dc,
						t_lsti **commands);
int					ft_rotate_b_untill_push_aux(t_data_container *dc);
void				ft_rotate_b_untill_top_max(t_data_container *dc,
						t_lsti **commands);


void	ft_free_all(t_data_container *dc);

int ft_check_sorted(t_lsti * lst);

#endif // PUSH_SWAP_H