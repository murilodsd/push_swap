/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:55:42 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/22 22:15:35 by mde-souz         ###   ########.fr       */
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
int	ft_stacksize(t_list_ref *lst_ref)
{
	int	count;
	t_list	*tmp;

	count = 0;
	tmp = lst_ref->bottom;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_stackswaptop(t_list_ref *lst_ref)
{
	if (ft_stacksize(lst_ref) < 2)
		return;
	lst_ref->top->next = lst_ref->top->previous;
	lst_ref->top->previous->previous->next = lst_ref->top;
	lst_ref->top->previous = lst_ref->top->previous->previous;
	lst_ref->top->next->previous = lst_ref->top;
	lst_ref->top->next->next = NULL;
	lst_ref->top = lst_ref->top->next;
}

void	ft_lstrotate_up(t_list_ref *lst_ref)
{
	t_list *current_bottom;
	t_list *current_top;
	
	if (!lst_ref)
		return;
	if (lst_ref->bottom == lst_ref->top)
		return;
	current_bottom = lst_ref->bottom;
	current_top = lst_ref->top;
	//NEW TOP
	lst_ref->top = lst_ref->top->previous;
	lst_ref->top->next = NULL;
	//NEW BOTTOM
	lst_ref->bottom = current_top;
	lst_ref->bottom->previous = NULL;
	lst_ref->bottom->next = current_bottom;	
	//OLD BOTTOM
	current_bottom->previous = lst_ref->bottom;
}

void	ft_lstrotate_down(t_list_ref *lst_ref)
{
	t_list *current_bottom;
	t_list *current_top;
	
	if (!lst_ref)
		return;
	if (lst_ref->bottom == lst_ref->top)
		return;
	current_bottom = lst_ref->bottom;
	current_top = lst_ref->top;
	//NEW BOTTOM
	lst_ref->bottom = lst_ref->bottom->next;
	lst_ref->bottom->previous = NULL;
	//NEW TOP
	lst_ref->top = current_bottom;
	lst_ref->top->previous = current_top;
	lst_ref->top->next = NULL;
	//OLD TOP	
	current_top->next = lst_ref->top;
}
void	ft_push_a(t_list_ref *lst_ref_a, t_list_ref *lst_ref_b)
{	
	if (!lst_ref_a || !lst_ref_b || lst_ref_a == lst_ref_b || ft_stacksize(lst_ref_a) == 0)
		return;
	//OLD TOP B
	if (ft_stacksize(lst_ref_b) > 0)
		lst_ref_b->top->next = lst_ref_a->top;
	else
		lst_ref_b->top = lst_ref_a->top;
	//NEW TOP A
	if (ft_stacksize(lst_ref_a) > 1)
	{
		lst_ref_a->top = lst_ref_a->top->previous;
		lst_ref_a->top->next = NULL;
	}
	else
	{
		lst_ref_a->bottom = NULL;
		lst_ref_a->top = NULL;
	}
	//NEW TOP B
	if (lst_ref_b->bottom)
	{
		lst_ref_b->top->next->previous = lst_ref_b->top;
		lst_ref_b->top = lst_ref_b->top->next;
	}
	else
	{
		lst_ref_b->bottom = lst_ref_b->top;
		lst_ref_b->top->previous = NULL;
	}	
}

#include <stdio.h>
void	lst_top_print(t_list_ref *lst_ref)
{
	t_list	*tmp;

	tmp = lst_ref->top;
	while (tmp)
	{
		printf("%d",tmp->nbr);
		tmp = tmp->previous;
	}
	if (lst_ref->top && lst_ref->bottom)
		printf("\nTop: %d Bottom: %d",lst_ref->top->nbr,lst_ref->bottom->nbr);
	printf("\ntamanho da lista: %d\n",ft_stacksize(lst_ref));
}
void	lst_bottom_print(t_list_ref *lst_ref)
{
	t_list	*tmp;

	tmp = lst_ref->bottom;
	while (tmp)
	{
		printf("%d",tmp->nbr);
		tmp = tmp->next;
	}
	if (lst_ref->top && lst_ref->bottom)
		printf("\nTop: %d Bottom: %d",lst_ref->top->nbr,lst_ref->bottom->nbr);
	printf("\ntamanho da lista: %d\n",ft_stacksize(lst_ref));
}
int main(void)
{
	t_list_ref	*lst_ref_a;
	t_list_ref	*lst_ref_b;
	t_list		*node;

	//LISTA A
	lst_ref_a = ft_lstnewref();
	node = ft_lstnewnode(2);
	ft_lstadd_bottom(lst_ref_a,node);
	node = ft_lstnewnode(3);
	ft_lstadd_top(lst_ref_a,node);
	node = ft_lstnewnode(1);
	ft_lstadd_bottom(lst_ref_a,node);
	node = ft_lstnewnode(4);
	ft_lstadd_bottom(lst_ref_a,node);
	//LISTA B
	lst_ref_b = ft_lstnewref();
	
	
	printf("Lista A inicializada:\n");
	lst_top_print(lst_ref_a);
	printf("\nTop: %d Bottom: %d",lst_ref_a->top->nbr,lst_ref_a->bottom->nbr);
	printf("\ntamanho da lista: %d\n",ft_stacksize(lst_ref_a));
	printf("Lista B inicializada:\n");
	lst_top_print(lst_ref_b);
	
	ft_stackswaptop(lst_ref_a);
	printf("SWAP A:\n");
	lst_top_print(lst_ref_a);
	
	printf("ROTATE_UP:\n");
	ft_lstrotate_up(lst_ref_a);
	lst_top_print(lst_ref_a);
	
	printf("ROTATE_DOWN:\n");
	ft_lstrotate_down(lst_ref_a);
	lst_top_print(lst_ref_a);

	printf("\nPUSH A:\n");
	ft_push_a(lst_ref_a,lst_ref_b);
	printf("Lista A:\n");
	lst_top_print(lst_ref_a);
	printf("Lista B:\n");
	lst_top_print(lst_ref_b);

	printf("\nPUSH A:\n");
	ft_push_a(lst_ref_a,lst_ref_b);
	printf("Lista A:\n");
	lst_top_print(lst_ref_a);
	printf("Lista B:\n");
	lst_top_print(lst_ref_b);

	printf("\nPUSH A:\n");
	ft_push_a(lst_ref_a,lst_ref_b);
	printf("Lista A:\n");
	lst_top_print(lst_ref_a);
	printf("Lista B:\n");
	lst_top_print(lst_ref_b);

	printf("\nPUSH A:\n");
	ft_push_a(lst_ref_a,lst_ref_b);
	printf("Lista A:\n");
	lst_top_print(lst_ref_a);
	printf("Lista B:\n");
	lst_top_print(lst_ref_b);
	return 0;
}
