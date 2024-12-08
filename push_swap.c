/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjose-ma <rjose-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:27:02 by rjose-ma          #+#    #+#             */
/*   Updated: 2024/12/08 16:46:26 by rjose-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{

    t_dlst *n1 = ft_dlstnew((void *)1);
    t_dlst *n2 = ft_dlstnew((void *)2);
    t_dlst *n3 = ft_dlstnew((void *)3);
    t_dlst *n4 = ft_dlstnew((void *)4);
    t_dlst *n5 = ft_dlstnew((void *)5);

    t_dlst *list;
    list = NULL;
    t_dlst *list2;
    list2 = NULL;

    
    ft_dlstadd_front(&list, n1);
    ft_dlstadd_front(&list, n2);
    ft_dlstadd_front(&list, n3);
    ft_dlstadd_front(&list, n4);
    ft_dlstadd_front(&list, n5);
    
    t_dlst *curr = list;

    ft_push(&list, &list2);
    ft_push(&list, &list2);
    ft_push(&list, &list2);


    printf("A stack A:\n");
    curr = list;
    while(curr && (curr->next) && (curr->next) != list)
    {
        printf("elemento: %d\n", curr->content);
        curr = curr->next;
    }
    if(curr)
        printf("elemento: %d\n", curr->content);
    
    printf("A stack B:\n");
    curr = list2;
    while(curr && (curr->next) && (curr->next) != list2)
    {
        printf("elemento: %d\n", curr->content);
        curr = curr->next;
    }
    if(curr)
        printf("elemento: %d\n", curr->content);

    ft_rotateall(&list, &list2);

     printf("A stack A:\n");
    curr = list;
    while(curr && (curr->next) && (curr->next) != list)
    {
        printf("elemento: %d\n", curr->content);
        curr = curr->next;
    }
    if(curr)
        printf("elemento: %d\n", curr->content);
    
    printf("A stack B:\n");
    curr = list2;
    while(curr && (curr->next) && (curr->next) != list2)
    {
        printf("elemento: %d\n", curr->content);
        curr = curr->next;
    }
    if(curr)
        printf("elemento: %d\n", curr->content);

    if(!list)
        printf("estou a null");
    //ft_dlstremovefirst(&list);
    
}