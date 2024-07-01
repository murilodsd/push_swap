/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push_all_sorted_aux.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 08:57:00 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 13:21:09 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_movements(t_movement movements)
{
	int	count_mov_rotate;
	int	count_mov_reverse_rotate;

	count_mov_rotate = movements.ra + movements.rb + movements.rr;
	count_mov_reverse_rotate = movements.rra + movements.rrb + movements.rrr;
	return (count_mov_rotate + count_mov_reverse_rotate);
}
t_movement	compare_movements(t_movement movements_a, t_movement movements_b)
{
	if (count_movements(movements_a) <= count_movements(movements_b))
		return (movements_a);
	return (movements_b);
}
void	print_movements(t_movement movements, t_stack_ref *stack_ref_to)
{
	while (movements.ra--)
		write(1, "ra\n", 3);
	while (movements.rb--)
		write(1, "rb\n", 3);
	while (movements.rra--)
		write(1, "rra\n", 4);
	while (movements.rrb--)
		write(1, "rrb\n", 4);
	while (movements.rr--)
		write(1, "rr\n", 3);
	while (movements.rrr--)
		write(1, "rrr\n", 4);
	write(1, "p", 1);
	write(1, &(stack_ref_to->name), 1);
	write(1, "\n" , 1);
}
//AQUI ACHO QUE VOU MUDAR DE FROM PARA A E DE TO PARA B
void	execute_movements(t_movement movements, t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{
	t_stack_ref *stack_ref_a;
	t_stack_ref *stack_ref_b;

	if (stack_ref_from->name == 'a')
	{
		stack_ref_a = stack_ref_from;
		stack_ref_b = stack_ref_to;
	}
	else
	{
		stack_ref_b = stack_ref_from;
		stack_ref_a = stack_ref_to;
	}
	while (movements.ra--)
		stackrotate_up(stack_ref_a);
	while (movements.rb--)
		stackrotate_up(stack_ref_b);
	while (movements.rra--)
		stackrotate_down(stack_ref_a);
	while (movements.rrb--)
		stackrotate_down(stack_ref_b);
	while (movements.rr--)
	{
		stackrotate_up(stack_ref_b);
		stackrotate_up(stack_ref_a);
	}
	while (movements.rrr--)
	{
		stackrotate_down(stack_ref_a);
		stackrotate_down(stack_ref_b);
	}
	stackpushfromto(stack_ref_from, stack_ref_to);
}
