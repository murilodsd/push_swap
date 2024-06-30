/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:33:16 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/30 21:05:21 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack_size3(t_stack_ref *stack_ref)
{
	//MAIOR NO MEIO
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
	t_movement	less_moviments;
	t_movement	moviments;
	int			i;

	while (ft_stacksize(stack_ref_from) > 3
		|| (stack_ref_to->name == 'a' && ft_stacksize(stack_ref_from) > 0))
	{
		less_moviments = calculate_moves(stack_ref_from, stack_ref_to, stack_ref_from->top);
		node_rotate = stack_ref_from->top->previous;
		node_reverse_rotate = stack_ref_from->bottom;
		i = 1;
		while(i < count_movements(less_moviments) && i <= ft_stacksize(stack_ref_from)/2)
		{
			moviments = calculate_moves(stack_ref_from, stack_ref_to, node_rotate);
			less_moviments = compare_moviments(less_moviments, moviments);
			moviments = calculate_moves(stack_ref_from, stack_ref_to, node_reverse_rotate);
			less_moviments = compare_moviments(less_moviments, moviments);
			i++;
			node_rotate = node_rotate->previous;
			node_reverse_rotate = node_reverse_rotate->next;
		}
		execute_moviments(less_moviments, stack_ref_from, stack_ref_to);
		stackpushfromto(stack_ref_from, stack_ref_to);
		print_moviments(less_moviments, stack_ref_to);
	}
}

void	rotate_max_top(t_stack_ref *stack_ref)
{
	int	i;
	t_stack *top;
	
	top = stack_ref->top;
	i = 0;
	while (top->nbr < stack_ref->bottom->nbr)
	{
		i++;
		top = top->previous;
	}
	while (ft_stacksize(stack_ref) - i >= i && i)
	{
		stackrotate_up(stack_ref);
		write(1, "rb\n", 3);
		i--;
	}
	while (ft_stacksize(stack_ref) - i++ && i)
	{
		stackrotate_down(stack_ref);
		write(1, "rrb\n", 4); 
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
			ft_stackrotate_down(stack_ref_to);
			write(1, "rra\n", 4);
			count_a_rotate++;
		}
		ft_stackpush(stack_ref_from, stack_ref_to);
		write(1, "pa\n", 3);
	}
	while (count_a_rotate < 3)
	{
		ft_stackrotate_down(stack_ref_to);
		write(1, "rra\n", 4);
		count_a_rotate++;
	}
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
		ft_stackpush(stack_ref_a,stack_ref_b);
		write(1,"pb\n",3);
	}
	push_all_sorted(stack_ref_a, stack_ref_b);
	//printf("Ajustando size 3:\n");
	sort_stack_size3(stack_ref_a);
	//printf("Ajustando lista b:\n");
	//printf("Lista A:\n");
	//stack_top_print(stack_ref_a);
	//printf("Lista B:\n");
	//stack_top_print(stack_ref_b);
	//push_all_sorted(stack_ref_b, stack_ref_a);
	rotate_max_top(stack_ref_b);
	push_all_back_to_a(stack_ref_b, stack_ref_a);
	return (0);
}