#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H


//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_dlst
{
	void			*content;
    struct s_dlst  *prev;
	struct s_dlst	*next;
}					t_dlst;

t_dlst	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlst **lst, t_dlst *new_node);
t_dlst	*ft_dlstlast(t_dlst *lst);
int		ft_dlstsize(t_dlst *lst);
void	ft_dlstclear(t_dlst **lst, void (*del)(void *));
t_dlst	*ft_dlstpush(t_dlst **lst);
void	ft_dlstdelone(t_dlst *lst, void (*del)(void *));

void    ft_swap(t_dlst **lst);
void    ft_swapall(t_dlst **lst_x, t_dlst **lst_y);
void    ft_rotate(t_dlst **lst);
void    ft_rotateall(t_dlst **lst_x, t_dlst **lst_y);
void    ft_rrotate(t_dlst **lst);
void    ft_rrotateall(t_dlst **lst_x, t_dlst **lst_y);
void 	ft_push(t_dlst **lst_x, t_dlst **lst_y);

#endif //PUSH_SWAP_H