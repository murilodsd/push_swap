/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:46:58 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/08 17:05:48 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_moves	init_moves(void)
{
	t_moves	moves;

	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rrr = 0;
	return (moves);
}

void	ft_stack_reset(t_stack_ref *stack_ref)
{
	stack_ref->bottom = NULL;
	stack_ref->top = NULL;
}
