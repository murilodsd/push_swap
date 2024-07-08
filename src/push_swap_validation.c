/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:12:31 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/07 12:24:57 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	validate_numbers(t_stack_ref	*stack_ref)
{
	t_stack	*tmp;
	t_stack	*next;
	
	tmp = stack_ref->bottom;
	while (tmp->next)
	{
		next = tmp->next;
		while (next)
		{
			if (tmp->nbr == next->nbr)
				return (0);
			next = next->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

/* static void	show_error(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
} */

void	free_arr_str(char ***arr_str)
{	
	int	i;
	
	if (*arr_str)
	{
		i = 0;
		while ((*arr_str)[i])
		{
			free((*arr_str)[i]);
			(*arr_str)[i++] = NULL;
		}
		free(*arr_str);
		*arr_str = NULL;	
	}
}

void	exit_free(t_stack_ref **stack_a, t_stack_ref **stack_b, char **str, char ***arr_str)
{
	if (stack_a != NULL)
		ft_stackfree(stack_a);
	if (stack_b != NULL)
		ft_stackfree(stack_b);
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	if (arr_str != NULL)
		free_arr_str(arr_str);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	split_args_init_stack(t_stack_ref **stack_ref, char ***splited_arg)
{
	int		i;
	int		j;
	t_stack	*node;
	
	i = 0;
	while((*splited_arg)[i])
		{
			j = 0;
			while ((*splited_arg)[i][j])
			{
				if (j == 0 && ((*splited_arg)[i][j] == '+' || (*splited_arg)[i][j] == '-'))
					j++;
				if (!ft_isdigit((*splited_arg)[i][j]))
					exit_free(stack_ref, NULL, NULL, splited_arg);
				j++;
			}
			if (ft_atoi((*splited_arg)[i]) > 2147483647
				|| ft_atoi((*splited_arg)[i]) < -2147483648)
				exit_free(stack_ref, NULL, NULL, splited_arg);
			node = ft_stacknewnode(ft_atoi((*splited_arg)[i]));
			if (!node)
				exit_free(stack_ref, NULL, NULL, splited_arg);
			ft_stackprepend(*stack_ref, node);
			i++;
		}
}

t_stack_ref	*validate_args(int argc, char *argv[], char stack_name)
{
	int		i;
	char	**splited_arg;
	t_stack_ref	*stack_ref;
	
	if (argc == 1)
		exit (EXIT_FAILURE);
	stack_ref = ft_stacknewref(stack_name);
	if (!stack_ref)
		exit (EXIT_FAILURE);
	i = 1;
	while (argc-- > 1)
	{
		ft_printf("arg %d é o %s\n", i, argv[i]);
		splited_arg = ft_split(argv[i], ' ');
		if (!splited_arg)
			exit_free(&stack_ref, NULL, NULL, NULL);
		if (!splited_arg[0])
			exit_free(&stack_ref, NULL, NULL, &splited_arg);
		split_args_init_stack(&stack_ref, &splited_arg);
		free_arr_str(&splited_arg);
		i++;
	}
	free_arr_str(&splited_arg);
	if (!validate_numbers(stack_ref))
		exit_free(&stack_ref, NULL, NULL, NULL);
	return (stack_ref);
}
