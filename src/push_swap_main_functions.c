/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:33:16 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/07 12:19:27 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push_all_sorted(t_stack_ref *stack_a, t_stack_ref *stack_b)
{
	t_stack	*node_rotate;
	t_stack	*node_reverse_rotate;
	t_moves	less_moves;
	t_moves	moves;
	int		i;

	while (ft_stacksize(stack_a) > 3)
	{
		less_moves = calc_moves(stack_a, stack_b, stack_a->top);
		node_rotate = stack_a->top->previous;
		node_reverse_rotate = stack_a->bottom;
		i = 1;
		while (i < count_moves(less_moves) && i <= ft_stacksize(stack_a) / 2)
		{
			moves = calc_moves(stack_a, stack_b, node_rotate);
			less_moves = compare_moves(less_moves, moves);
			moves = calc_moves(stack_a, stack_b, node_reverse_rotate);
			less_moves = compare_moves(less_moves, moves);
			i++;
			node_rotate = node_rotate->previous;
			node_reverse_rotate = node_reverse_rotate->next;
		}
		execute_moves(less_moves, stack_a, stack_b);
	}
}

static int	adjust_stack_a(t_stack_ref *stack_ref, int nbr_node)
{
	int		i;
	t_stack	*top;
	t_stack	*bottom;

	top = stack_ref->top;
	bottom = stack_ref->bottom;
	i = 0;
	while (!((nbr_node > bottom->nbr && bottom->nbr > top->nbr)
			|| (nbr_node < top->nbr && bottom->nbr > top->nbr)
			|| (nbr_node > bottom->nbr && nbr_node < top->nbr)))
	{
		i++;
		bottom = top;
		top = top->previous;
	}
	if (ft_stacksize(stack_ref) - i >= i)
		return (i);
	return (i - ft_stacksize(stack_ref));
}

static void	push_all_back_to_a(t_stack_ref *stack_b, t_stack_ref *stack_a)
{
	int	count_a_rotate;

	while (ft_stacksize(stack_b))
	{
		count_a_rotate = adjust_stack_a(stack_a, stack_b->top->nbr);
		while (count_a_rotate)
		{
			if (count_a_rotate > 0)
			{
				stackrotate_up(stack_a);
				write(1, "ra\n", 3);
				count_a_rotate--;
			}
			if (count_a_rotate < 0)
			{
				stackrotate_down(stack_a);
				write(1, "rra\n", 4);
				count_a_rotate++;
			}
		}
		stackpushfromto(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}

#include <stdio.h>
void	stack_top_print(t_stack_ref *stack_ref)
{
	t_stack	*tmp;

	tmp = stack_ref->top;
	while (tmp)
	{
		printf("%d ", tmp->nbr);
		tmp = tmp->previous;
	}
	if (stack_ref->top && stack_ref->bottom)
		printf("\nTop: %d Bottom: %d", stack_ref->top->nbr, stack_ref->bottom->nbr);
	printf("\ntamanho da lista: %d\n\n", ft_stacksize(stack_ref));
}

void	sort_a(t_stack_ref *stack_ref_a, t_stack_ref *stack_ref_b)
{
	while (ft_stacksize(stack_ref_a) > 3 && ft_stacksize(stack_ref_b) < 2)
	{
		stackpushfromto(stack_ref_a, stack_ref_b);
		write(1, "pb\n", 3);
	}
	push_all_sorted(stack_ref_a, stack_ref_b);
	if (ft_stacksize(stack_ref_a) == 3)
		sort_stack_size3(stack_ref_a);
	rotate_max_top(stack_ref_b);
	push_all_back_to_a(stack_ref_b, stack_ref_a);
	rotate_min_top(stack_ref_a);
}

int	main(int argc, char *argv[])
{
	t_stack_ref	*stack_ref_a;
	t_stack_ref	*stack_ref_b;

	stack_ref_a = validate_args(argc, argv, 'a');
	if (!stack_ref_a)
		return (EXIT_FAILURE);
	stack_top_print(stack_ref_a);
	if (ft_stack_issorted(stack_ref_a))
	{
		ft_stackfree(&stack_ref_a);
		return (EXIT_SUCCESS);
	}
	stack_ref_b = ft_stacknewref('b');
	if (!stack_ref_b)
		exit_free(&stack_ref_a, NULL, NULL, NULL);
	sort_a(stack_ref_a, stack_ref_b);
	//printf("tamanho a: %d\ntamanho b: %d\n",ft_stacksize(stack_ref_a),ft_stacksize(stack_ref_b));
	ft_stackfree(&stack_ref_a);
	ft_stackfree(&stack_ref_b);
	//stack_top_print(stack_ref_a);
	return (EXIT_SUCCESS);
}
