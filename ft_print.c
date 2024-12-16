/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:01:33 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/12 18:33:10 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void ft_print_stack(t_lsti *stack)
{
	int size;
	if(stack)
	{
		size = ft_lstisize(stack);	
		ft_putstr_fd("STACK:\n",1);
		while(size-- != 0)
		{
			printf("%d\n", stack->c);
			stack = stack->n;
		}	
	}
}



void ft_print_command(int command)
{
	if(command == 0)
		ft_putendl_fd("sa", 1);
	else if(command == 1)
		ft_putendl_fd("sb", 1);
	else if(command == 2)
		ft_putendl_fd("ss", 1);
	else if(command == 3)
		ft_putendl_fd("pa", 1);
	else if(command == 4)
		ft_putendl_fd("pb", 1);
	else if(command == 5)
		ft_putendl_fd("ra", 1);
	else if(command == 6)
		ft_putendl_fd("rb", 1);
	else if(command == 7)
		ft_putendl_fd("rr", 1);
	else if(command == 8)
		ft_putendl_fd("rra", 1);
	else if(command == 9)
		ft_putendl_fd("rrb", 1);
	else if(command == 10)
		ft_putendl_fd("rrr", 1);
}


void ft_putnbr(int nbr) {
	long n = nbr;
	if (n < 0) {
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= 10) {
		ft_putnbr(n / 10);
	}
	ft_putchar_fd((n % 10) + '0', 1);

}

