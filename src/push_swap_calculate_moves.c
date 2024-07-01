/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc_moves.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:46:42 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 18:49:46 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	distance_from_top(t_stack_ref *stack_ref, t_stack *node)
{
	int		i;
	t_stack	*node_down_rotate;

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

static int	is_adjust(t_stack *top, t_stack *bottom, int nbr_node)
{
	int	nbr_top;
	int	nbr_bottom;

	nbr_top = top->nbr;
	nbr_bottom = bottom->nbr;
	if (nbr_node >= nbr_top && nbr_top >= nbr_bottom)
		return (1);
	else if (nbr_node <= nbr_bottom && nbr_top >= nbr_bottom)
		return (1);
	else if (nbr_node <= nbr_bottom && nbr_node >= nbr_top)
		return (1);
	else
		return (0);
}

static int	adjust_stack_b(t_stack_ref *stack_ref, int nbr_node)
{
	int		i;
	t_stack	*top;
	t_stack	*bottom;

	top = stack_ref->top;
	bottom = stack_ref->bottom;
	i = 0;
	while (!is_adjust(top, bottom, nbr_node))
	{
		i++;
		bottom = top;
		top = top->previous;
	}
	if (ft_stacksize(stack_ref) - i >= i)
		return (i);
	return (i - ft_stacksize(stack_ref));
}

t_moves	calc_moves(t_stack_ref *stack_ref_a,
	t_stack_ref *stack_ref_b, t_stack *node)
{
	t_moves	optimized_moves;
	int		moves_to_the_top;
	int		moves_to_adjust;

	optimized_moves = init_moves();
	moves_to_the_top = distance_from_top(stack_ref_a, node);
	moves_to_adjust = adjust_stack_b(stack_ref_b, node->nbr);
	while (moves_to_the_top < 0 && moves_to_adjust < 0)
	{
		optimized_moves.rrr++;
		moves_to_the_top++;
		moves_to_adjust++;
	}
	while (moves_to_the_top > 0 && moves_to_adjust > 0)
	{
		optimized_moves.rr++;
		moves_to_the_top--;
		moves_to_adjust--;
	}
	optimized_moves.ra += (moves_to_the_top > 0) * moves_to_the_top;
	optimized_moves.rra -= (moves_to_the_top < 0) * moves_to_the_top;
	optimized_moves.rb += (moves_to_adjust > 0) * moves_to_adjust;
	optimized_moves.rrb -= (moves_to_adjust < 0) * moves_to_adjust;
	return (optimized_moves);
}
