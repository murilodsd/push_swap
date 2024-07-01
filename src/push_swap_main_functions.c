/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:33:16 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 16:09:17 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack_size3(t_stack_ref *stack_ref)
{
	if (ft_stacksize(stack_ref) != 3)
		return ;
	if (stack_ref->top->nbr < stack_ref->top->previous->nbr
		&& stack_ref->bottom->nbr < stack_ref->top->previous->nbr)
	{
		stackrotate_down(stack_ref);
		ft_printf("rr%c\n", stack_ref->name);
	}
	//MAIOR NO TOP
	else if (stack_ref->top->nbr > stack_ref->top->previous->nbr
		&& stack_ref->top->nbr > stack_ref->bottom->nbr)
	{
		stackrotate_up(stack_ref);
		ft_printf("r%c\n", stack_ref->name);
	}
	//MAIOR NA BASE, MAS OS OUTROS TROCADOS
	if (stack_ref->top->nbr > stack_ref->top->previous->nbr)
	{
		stackswaptop(stack_ref);
		ft_printf("s%c\n", stack_ref->name);
	}
}

void	push_all_sorted(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{
	t_stack		*node_rotate;
	t_stack		*node_reverse_rotate;
	t_movement	less_movements;
	t_movement	movements;
	int			i;

	while (ft_stacksize(stack_ref_from) > 3
		|| (stack_ref_to->name == 'a' && ft_stacksize(stack_ref_from) > 0))
	{
		less_movements = calculate_moves(stack_ref_from, stack_ref_to, stack_ref_from->top);
		node_rotate = stack_ref_from->top->previous;
		node_reverse_rotate = stack_ref_from->bottom;
		i = 1;
		while(i < count_movements(less_movements) && i <= ft_stacksize(stack_ref_from)/2)
		{
			movements = calculate_moves(stack_ref_from, stack_ref_to, node_rotate);
			less_movements = compare_movements(less_movements, movements);
			movements = calculate_moves(stack_ref_from, stack_ref_to, node_reverse_rotate);
			less_movements = compare_movements(less_movements, movements);
			i++;
			node_rotate = node_rotate->previous;
			node_reverse_rotate = node_reverse_rotate->next;
		}
		execute_movements(less_movements, stack_ref_from, stack_ref_to);
		print_movements(less_movements, stack_ref_to);
	}
}

void	rotate_max_top(t_stack_ref *stack_ref)
{
	int	i;
	t_stack *top;
	
	if (ft_stacksize(stack_ref) < 2)
		return ;
	top = stack_ref->top;
	i = 0;
	while (top->nbr < stack_ref->bottom->nbr)
	{
		i++;
		top = top->previous;
	}
	while (stack_ref->top->nbr < stack_ref->bottom->nbr)
	{
		if (ft_stacksize(stack_ref) - i >= i)
		{
			stackrotate_up(stack_ref);
			write(1, "rb\n", 3);
		}
		else
		{
			stackrotate_down(stack_ref);
			write(1, "rrb\n", 4); 	
		}
	}
}

void	push_all_back_to_a(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{
	int	count_a_rotate;
	
	count_a_rotate = 0;
	while (ft_stacksize(stack_ref_from))
	{
		while (stack_ref_from->top->nbr < stack_ref_to->bottom->nbr && count_a_rotate < 3)
		{
			stackrotate_down(stack_ref_to);
			write(1, "rra\n", 4);
			count_a_rotate++;
		}
		stackpushfromto(stack_ref_from, stack_ref_to);
		write(1, "pa\n", 3);
	}
	while (stack_ref_to->top->nbr > stack_ref_to->bottom->nbr)
	{
		stackrotate_down(stack_ref_to);
		write(1, "rra\n", 4);
		count_a_rotate++;
	}
}
#include <stdio.h>
void	stack_top_print(t_stack_ref *stack_ref)
{
	t_stack	*tmp;

	tmp = stack_ref->top;
	while (tmp)
	{
		printf("%d ",tmp->nbr);
		tmp = tmp->previous;
	}
	if (stack_ref->top && stack_ref->bottom)
		printf("\nTop: %d Bottom: %d",stack_ref->top->nbr,stack_ref->bottom->nbr);
	printf("\ntamanho da lista: %d\n\n",ft_stacksize(stack_ref));
}

int main(int argc , char *argv[])
{
	t_stack_ref *stack_ref_a;
	t_stack_ref *stack_ref_b;
	
	stack_ref_a = ft_initstack(argc, argv, 'a');
	stack_ref_b = ft_stacknewref('b');
	//printf("tamanho a: %d\ntamanho b: %d\n",ft_stacksize(stack_ref_a),ft_stacksize(stack_ref_b));
	while (ft_stacksize(stack_ref_a) > 3 && ft_stacksize(stack_ref_b) < 2)
	{
		stackpushfromto(stack_ref_a,stack_ref_b);
		write(1,"pb\n",3);
	}
	push_all_sorted(stack_ref_a, stack_ref_b);
	//printf("Ajustando size 3:\n");
	if (ft_stacksize(stack_ref_a) == 3)
		sort_stack_size3(stack_ref_a);
	//printf("Ajustando lista b:\n");
	//printf("Lista A:\n");
	//stack_top_print(stack_ref_a);
	//printf("Lista B:\n");
	//stack_top_print(stack_ref_b);
	//push_all_sorted(stack_ref_b, stack_ref_a);
	rotate_max_top(stack_ref_b);
	// printf("Lista A:\n");
	// stack_top_print(stack_ref_a);
	// printf("Lista B:\n");
	// stack_top_print(stack_ref_b);
	push_all_back_to_a(stack_ref_b, stack_ref_a);
	// stack_top_print(stack_ref_a);
	return (0);
}