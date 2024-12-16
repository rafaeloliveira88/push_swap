#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H


//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_lsti
{
	int			c;
    struct s_lsti  *p;
	struct s_lsti	*n;
}					t_lsti;

typedef struct s_lst
{
	void *			c;
    struct s_lst  *p;
	struct s_lst	*n;
}					t_lst;

typedef struct s_data_container
{
    t_lsti *a;
    t_lsti *b;
    int min;
    int max;
    t_lst *lists_commands;
}	t_data_container;


t_lsti	*ft_lstinew(int content);
void	ft_lstiadd_front(t_lsti **lst, t_lsti *new_node);
t_lsti	*ft_lstilast(t_lsti *lst);
int		ft_lstisize(t_lsti *lst);
void	ft_lsticlear(t_lsti **lst);
t_lsti	*ft_lstipush(t_lsti **lst);
void	ft_lstidelone(t_lsti *lst);
void	ft_lstiadd_last(t_lsti **lst, t_lsti *new_node);

t_lst	*ft_lstnew(void *content);
void	ft_lstadd_front(t_lst **lst, t_lst *new_node);
t_lst	*ft_lstlast(t_lst *lst);
int		ft_lstsize(t_lst *lst);
void	ft_lstclear(t_lst **lst, void (*del)(void *));
t_lst	*ft_lstpush(t_lst **lst);
void	ft_lstdelone(t_lst *lst, void (*del)(void *));
void	ft_lstadd_last(t_lst **lst, t_lst *new_node);

void    ft_swap(t_lsti **lst, int stack, int print_command);
void    ft_swapall(t_lsti **lst_x, t_lsti **lst_y, int print_command);
void    ft_rotate(t_lsti **lst, int stack, int print_command);
void    ft_rotateall(t_lsti **lst_x, t_lsti **lst_y, int print_command);
void    ft_rrotate(t_lsti **lst, int stack, int print_command);
void    ft_rrotateall(t_lsti **lst_x, t_lsti **lst_y,int print_command);
void ft_push(t_lsti **lst_x, t_lsti **lst_y, int stack, int print_command);

int	ft_atoi(const char *str);
int	ft_atoic(const char *str, int *bigger);
int ft_isnumber(char *str);

int	ft_check_args(int size, char **args);
void ft_free_integer(void *content);

t_lsti *ft_init_stack_a(int size,char **args);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void ft_print_command(int command);
void ft_putnbr(int n);

void    ft_sort(t_lsti **a);

void ft_print_stack(t_lsti *stack);

#endif //PUSH_SWAP_H