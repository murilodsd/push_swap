/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:40:34 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/30 22:42:52 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_movement 	calculate_moves(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to, t_stack *node)
{
	t_movement optimized_moves;
	int	moves_to_the_top;
	int	moves_to_adjuste;

	optimized_moves = init_moviments();
	moves_to_the_top = distance_from_top(stack_ref_from,node);
	moves_to_adjuste = adjust_stack_b(stack_ref_to,node->nbr);
	while (moves_to_the_top < 0 && moves_to_adjuste < 0)
	{
		optimized_moves.rrr++;
		moves_to_the_top++;
		moves_to_adjuste++;
	}
	while (moves_to_the_top > 0 && moves_to_adjuste > 0)
	{
		optimized_moves.rr++;
		moves_to_the_top--;
		moves_to_adjuste--;
	}
	optimized_moves.ra += (moves_to_the_top > 0
			&& stack_ref_from->name == 'a') * moves_to_the_top;
	optimized_moves.ra += (moves_to_adjuste > 0
			&& stack_ref_to->name == 'a') * moves_to_adjuste;
	optimized_moves.rra -= (moves_to_the_top < 0
			&& stack_ref_from->name == 'a') * moves_to_the_top;
	optimized_moves.rra -= (moves_to_adjuste < 0
			&& stack_ref_to->name == 'a') * moves_to_adjuste;
	optimized_moves.rb += (moves_to_the_top > 0
			&& stack_ref_from->name == 'b') * moves_to_the_top;
	optimized_moves.rb += (moves_to_adjuste > 0
			&& stack_ref_to->name == 'b') * moves_to_adjuste;
	optimized_moves.rrb -= (moves_to_the_top < 0
			&& stack_ref_from->name == 'b') * moves_to_the_top;
	optimized_moves.rrb -= (moves_to_adjuste < 0
			&& stack_ref_to->name == 'b') * moves_to_adjuste;
	return (optimized_moves);
}
int	count_movements(t_movement movements)
{
	int	count_mov_rotate;
	int	count_mov_reverse_rotate;

	count_mov_rotate = movements.ra + movements.rb + movements.rr;
	count_mov_reverse_rotate = movements.rra + movements.rrb + movements.rrr;
	return (count_mov_rotate + count_mov_reverse_rotate);
}
t_movement	compare_moviments(t_movement movements_a, t_movement movements_b)
{
	if (count_movements(movements_a) <= count_movements(movements_b))
		return (movements_a);
	return (movements_b);
}
void	print_moviments(t_movement moviments, t_stack_ref *stack_ref_to)
{
	while (moviments.ra--)
		write(1, "ra\n", 3);
	while (moviments.rb--)
		write(1, "rb\n", 3);
	while (moviments.rra--)
		write(1, "rra\n", 4);
	while (moviments.rrb--)
		write(1, "rrb\n", 4);
	while (moviments.rr--)
		write(1, "rr\n", 3);
	while (moviments.rrr--)
		write(1, "rrr\n", 4);
	write(1, "p", 1);
	write(1, &(stack_ref_to->name), 1);
	write(1, "\n" , 1);
}

void	execute_moviments(t_movement moviments, t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
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
	while (moviments.ra--)
		ft_stackrotate_up(stack_ref_a);
	while (moviments.rb--)
		ft_stackrotate_up(stack_ref_b);
	while (moviments.rra--)
		ft_stackrotate_down(stack_ref_a);
	while (moviments.rrb--)
		ft_stackrotate_down(stack_ref_b);
	while (moviments.rr--)
	{
		ft_stackrotate_up(stack_ref_b);
		ft_stackrotate_up(stack_ref_a);
	}
	while (moviments.rrr--)
	{
		ft_stackrotate_down(stack_ref_a);
		ft_stackrotate_down(stack_ref_b);
	}
}