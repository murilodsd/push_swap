/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:46:58 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/30 22:47:51 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_ref	*ft_initstack(int argc, char *argv[], char stack_name)
{
	t_stack_ref	*stack_ref;
	t_stack *node;
	int	i;
	
	stack_ref = ft_stacknewref(stack_name);
	i = 1;
	while (i < argc)
	{
		node = ft_stacknewnode(ft_atoi(argv[i]));
		ft_stackadd_bottom(stack_ref, node);
		i++;
	}
	return (stack_ref);
}

t_movement	init_moviments(void)
{
	t_movement movements;

	movements.ra = 0;
	movements.rb = 0;
	movements.rr = 0;
	movements.rra = 0;
	movements.rrb = 0;
	movements.rrr = 0;
	return (movements);
}