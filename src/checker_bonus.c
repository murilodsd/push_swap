/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 07:41:56 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/07 11:08:19 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_ra_rb_rr(char *instruction)
{
	if (!ft_strcmp(instruction, "ra\n"))
		return (1);
	if (!ft_strcmp(instruction, "rb\n"))
		return (1);
	if (!ft_strcmp(instruction, "rr\n"))
		return (1);
	return (0);
}

static int	is_rra_rrb_rrr(char *instruction)
{
	if (!ft_strcmp(instruction, "rra\n"))
		return (1);
	if (!ft_strcmp(instruction, "rrb\n"))
		return (1);
	if (!ft_strcmp(instruction, "rrr\n"))
		return (1);
	return (0);
}

void	execute(t_stack_ref *stack_a, t_stack_ref *stack_b, char **instruction)
{
	if (is_ra_rb_rr(*instruction))
	{
		if (ft_strcmp(*instruction, "rb\n"))
			stackrotate_up(stack_a);
		if (ft_strcmp(*instruction, "ra\n"))
			stackrotate_up(stack_b);
	}
	else if (is_rra_rrb_rrr(*instruction))
	{
		if (ft_strcmp(*instruction, "rrb\n"))
			stackrotate_down(stack_a);
		if (ft_strcmp(*instruction, "rra\n"))
			stackrotate_down(stack_b);
	}
	else if (!ft_strcmp(*instruction, "pa\n"))
		stackpushfromto(stack_b, stack_a);
	else if (!ft_strcmp(*instruction, "pb\n"))
		stackpushfromto(stack_a, stack_b);
	else if (!ft_strcmp(*instruction, "sa\n"))
		stackswaptop(stack_a);
	else if (!ft_strcmp(*instruction, "sb\n"))
		stackswaptop(stack_b);
	else
		exit_free(&stack_a, &stack_b, instruction, NULL);
}

int	main(int argc, char *argv[])
{
	char		*instruction;
	t_stack_ref	*stack_a;
	t_stack_ref	*stack_b;

	stack_a = validate_args(argc, argv, 'a');
	stack_b = ft_stacknewref('b');
	instruction = get_next_line(STDIN_FILENO);
	if (!stack_a || !stack_b || instruction)
		exit_free(&stack_a, &stack_b, &instruction, NULL);
	while (instruction)
	{
		execute(stack_a, stack_b, &instruction);
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (ft_stack_issorted(stack_a) && ft_stacksize(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	free(instruction);
	instruction = NULL;
	return (EXIT_SUCCESS);
}
