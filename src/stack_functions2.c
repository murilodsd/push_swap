/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:10:46 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/08 17:05:40 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_stackprepend(t_stack_ref *stack_ref, t_stack *new)
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
		stack_ref->bottom->previous = new;
		new->next = stack_ref->bottom;
		new->previous = NULL;
		stack_ref->bottom = new;
	}
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

int	ft_stack_issorted(t_stack_ref *stack_ref)
{
	t_stack	*tmp;

	tmp = stack_ref->bottom;
	while (tmp->next)
	{
		if (tmp->nbr < tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	rotate_max_top(t_stack_ref *stack_ref)
{
	int		i;
	t_stack	*top;

	if (ft_stacksize(stack_ref) < 2)
		return ;
	top = stack_ref->top;
	i = 0;
	while (top->nbr < stack_ref->bottom->nbr)
	{
		i++;
		top = top->previous;
	}
	while (stack_ref->top->nbr < stack_ref->bottom->nbr)
	{
		if (ft_stacksize(stack_ref) - i >= i)
		{
			stackrotate_up(stack_ref);
			write(1, "rb\n", 3);
		}
		else
		{
			stackrotate_down(stack_ref);
			write(1, "rrb\n", 4);
		}
	}
}

void	rotate_min_top(t_stack_ref *stack_ref)
{
	int		i;
	t_stack	*top;

	top = stack_ref->top;
	i = 0;
	while (top->nbr > stack_ref->bottom->nbr)
	{
		i++;
		top = top->previous;
	}
	while (stack_ref->top->nbr > stack_ref->bottom->nbr)
	{
		if (ft_stacksize(stack_ref) - i >= i)
		{
			stackrotate_up(stack_ref);
			write(1, "ra\n", 3);
		}
		else
		{
			stackrotate_down(stack_ref);
			write(1, "rra\n", 4);
		}
	}
}
