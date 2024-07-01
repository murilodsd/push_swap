/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_all_sorted_aux.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:57:00 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 19:21:42 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_moves(t_moves moves)
{
	int	count_mov_rotate;
	int	count_mov_reverse_rotate;

	count_mov_rotate = moves.ra + moves.rb + moves.rr;
	count_mov_reverse_rotate = moves.rra + moves.rrb + moves.rrr;
	return (count_mov_rotate + count_mov_reverse_rotate);
}

t_moves	compare_moves(t_moves moves_a, t_moves moves_b)
{
	if (count_moves(moves_a) <= count_moves(moves_b))
		return (moves_a);
	return (moves_b);
}

void	print_moves(t_moves moves, t_stack_ref *stack_ref_to)
{
	while (moves.ra--)
		write(1, "ra\n", 3);
	while (moves.rb--)
		write(1, "rb\n", 3);
	while (moves.rra--)
		write(1, "rra\n", 4);
	while (moves.rrb--)
		write(1, "rrb\n", 4);
	while (moves.rr--)
		write(1, "rr\n", 3);
	while (moves.rrr--)
		write(1, "rrr\n", 4);
	write(1, "p", 1);
	write(1, &(stack_ref_to->name), 1);
	write(1, "\n", 1);
}

void	execute_moves(t_moves moves, t_stack_ref *stack_a, t_stack_ref *stack_b)
{
	print_moves(moves, stack_b);
	while (moves.ra--)
		stackrotate_up(stack_a);
	while (moves.rb--)
		stackrotate_up(stack_b);
	while (moves.rra--)
		stackrotate_down(stack_a);
	while (moves.rrb--)
		stackrotate_down(stack_b);
	while (moves.rr--)
	{
		stackrotate_up(stack_b);
		stackrotate_up(stack_a);
	}
	while (moves.rrr--)
	{
		stackrotate_down(stack_a);
		stackrotate_down(stack_b);
	}
	stackpushfromto(stack_a, stack_b);
}
