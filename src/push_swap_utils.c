/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:09:03 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/30 20:33:41 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	distance_from_top(t_stack_ref *stack_ref, t_stack *node)
{
	int	i;
	t_stack *node_down_rotate;

	node_down_rotate = node;
	i = 0;
	while (node != stack_ref->top && node_down_rotate != stack_ref->top)
	{
		i++;
		node = node->next;
		if (node_down_rotate != stack_ref->bottom)
			node_down_rotate = node_down_rotate->previous;
		else
			node_down_rotate = stack_ref->top;
	}
	if (node == stack_ref->top)
		return (i);
	return (-i);
}

int is_adjust_to_max(t_stack *top, t_stack *bottom, int nbr_node)
{
	int	nbr_top;
	int	nbr_bottom;

	nbr_top = top->nbr;
	nbr_bottom = bottom->nbr;
	return (nbr_node >= nbr_top && nbr_top >= nbr_bottom);
}

int is_adjust_to_min(t_stack *top, t_stack *bottom, int nbr_node)
{
	int	nbr_top;
	int	nbr_bottom;

	nbr_top = top->nbr;
	nbr_bottom = bottom->nbr;
	return (nbr_node <= nbr_bottom && nbr_top >= nbr_bottom);
}

int is_adjust_to_center(t_stack *top, t_stack *bottom, int nbr_node)
{
	int	nbr_top;
	int	nbr_bottom;

	nbr_top = top->nbr;
	nbr_bottom = bottom->nbr;
	return (nbr_node <= nbr_bottom && nbr_node >= nbr_top);
}

int	adjust_stack_b(t_stack_ref *stack_ref, int nbr_node)
{
	int	i;
	t_stack *top;
	t_stack *bottom;
	
	top = stack_ref->top;
	bottom = stack_ref->bottom;
	i = 0;
	while (!(is_adjust_to_max(top, bottom, nbr_node) || is_adjust_to_min(top, bottom, nbr_node) || is_adjust_to_center(top, bottom, nbr_node)))
	{
		i++;
		bottom = top;
		top = top->previous;
	}
	if (ft_stacksize(stack_ref) - i >= i)
		return (i);
	return (i - ft_stacksize(stack_ref));
}
