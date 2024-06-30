/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:50:17 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/30 22:39:03 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_ref	*ft_stacknewref(char stack_name)
{
	t_stack_ref	*stack_ref;

	stack_ref = (t_stack_ref *)malloc(sizeof(t_stack_ref));
	if (!stack_ref)
		return (NULL);
	stack_ref->bottom = NULL;
	stack_ref->top = NULL;
	stack_ref->name = stack_name;
	return (stack_ref);
}

t_stack	*ft_stacknewnode(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	ft_stackpush(t_stack_ref *stack_ref, t_stack *new)
{
	if (!stack_ref || !new)
		return ;
	if (!(stack_ref->bottom))
	{
		stack_ref->bottom = new;
		stack_ref->top = new;
	}
	else
	{
		stack_ref->top->next = new;
		new->previous = stack_ref->top;
		new->next = NULL;
		stack_ref->top = new;
	}
}

int	ft_stacksize(t_stack_ref *stack_ref)
{
	int		count;
	t_stack	*tmp;

	tmp = stack_ref->bottom;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_stackfree(t_stack_ref **stack_ref)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!stack_ref || !*stack_ref)
		return ;
	tmp = (*stack_ref)->bottom;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*stack_ref);
	*stack_ref = NULL;
}
