/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:46:58 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 19:03:39 by mde-souz         ###   ########.fr       */
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

int	is_valid_arguments(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		return (0);
	while (argc-- > 1)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (i == 0 && (argv[argc][i] == '+' || argv[argc][i] == '-'))
				i++;
			if (!ft_isdigit(argv[argc][i]))
				return (0);
			i++;
		}
		if (ft_atoi(argv[argc]) > 2147483647
			|| ft_atoi(argv[argc]) < -2147483648)
			return (0);
		while (argc-- - 1 > 1)
		{
			if (!ft_strcmp(argv[argc], argv[argc - 1]))
				return (0);
		}
	}
	return (1);
}
