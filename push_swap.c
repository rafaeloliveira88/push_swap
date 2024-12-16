/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:27:02 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/13 15:40:44 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_lsti *stack_a;
            char *lista[] = {"push_swap", "1", "3", "9", "2" ,"-1", "6"};
    
    if(argc > 1)
    {
        if(ft_check_args(argc, argv))
        {
            int size = 6;
            stack_a = ft_init_stack_a(argc, argv);
            //stack_a = ft_init_stack_a(argc, argv);
            if(!stack_a)
            {
                ft_putendl_fd("Error", 2);
                return (0);
            }    
            ft_sort(&stack_a);
        }
        else
        {
            ft_putendl_fd("Error", 2);
            return (0);
        }
    }

}