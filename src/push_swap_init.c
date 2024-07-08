/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:46:58 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/06 20:33:23 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_ref	*ft_initstack(int argc, char *argv[], char stack_name)
{
	t_stack_ref	*stack_ref;
	t_stack		*node;
	int			i;

	stack_ref = ft_stacknewref(stack_name);
	i = 1;
	while (i < argc)
	{
		node = ft_stacknewnode(ft_atoi(argv[i]));
		if (!node)
		{
			ft_stackfree(&stack_ref);
			return (NULL);
		}
		ft_stackprepend(stack_ref, node);
		i++;
	}
	return (stack_ref);
}

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
