/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:55:42 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/21 21:51:10 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list_ref	*ft_lstnewref(void)
{
	t_list_ref	*lst_ref;

	lst_ref = (t_list_ref *)malloc(sizeof(t_list_ref));
	if (!lst_ref)
		return (NULL);
	lst_ref->bottom = NULL;
	lst_ref->top = NULL;
	return (lst_ref);
}

t_list	*ft_lstnewnode(int nbr)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}
void	ft_lstadd_top(t_list_ref *lst_ref, t_list *new)
{
	if (!lst_ref || !new)
		return ;
	if (!(lst_ref->bottom))
	{
		lst_ref->bottom = new;
		lst_ref->top = new;
	}	
	else
	{
		lst_ref->top->next = new;
		new->previous = lst_ref->top;
		new->next = NULL;
		lst_ref->top = new;
	}
}
void	ft_lstadd_bottom(t_list_ref *lst_ref, t_list *new)
{
	if (!lst_ref || !new)
		return ;
	if (!(lst_ref->bottom))
	{
		lst_ref->bottom = new;
		lst_ref->top = new;
	}	
	else
	{
		lst_ref->bottom->previous = new;
		new->next = lst_ref->bottom;
		new->previous = NULL;
		lst_ref->bottom = new;
	}
}


void	ft_lstswap(t_list_ref *lst_ref,t_list *previous, t_list *next)
{
	if (!previous || !next)
		return;
	
	t_list *tmp_next;
	t_list *tmp_previous;

	if (lst_ref->bottom == previous)
		lst_ref->bottom = next;
	if (lst_ref->top->nbr == 3)
		lst_ref->top = previous;
	tmp_previous = previous->previous;//1
	previous->previous = next;//3
	previous->next = next->next;//NULL
	next->previous = tmp_previous;//1
	next->next = previous;//2
}
#include <stdio.h>
void	lst_print(t_list *top)
{
	while (top)
	{
		printf("%d",top->nbr);
		top = top->previous;
	}
}
int main(int argc, char const *argv[])
{
	t_list_ref	*lst_ref;
	t_list		*node;

	lst_ref = ft_lstnewref();
	node = ft_lstnewnode(2);
	ft_lstadd_bottom(lst_ref,node);
	node = ft_lstnewnode(3);
	ft_lstadd_top(lst_ref,node);
	node = ft_lstnewnode(1);
	ft_lstadd_bottom(lst_ref,node);
	lst_print(lst_ref->top);
	printf("\n");
	ft_lstswap(lst_ref, lst_ref->top->previous, lst_ref->top);
	lst_print(lst_ref->top);
	return 0;
}
