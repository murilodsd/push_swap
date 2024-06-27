/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:55:42 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/27 20:30:17 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_ref	*ft_stacknewref(char stack_name)
{
	t_stack_ref	*stack_ref;

	stack_ref = (t_stack_ref *)malloc(sizeof(t_stack_ref));
	if (!stack_ref)
		return (NULL);
	stack_ref->bottom = NULL;
	stack_ref->top = NULL;
	stack_ref->size = 0;
	stack_ref->stack_name = stack_name;
	return (stack_ref);
}

t_stack	*ft_stacknewnode(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}
void	ft_stackadd_top(t_stack_ref *stack_ref, t_stack *new)
{
	if (!stack_ref || !new)
		return ;
	if (!(stack_ref->bottom))
	{
		stack_ref->bottom = new;
		stack_ref->top = new;
	}	
	else
	{
		stack_ref->top->next = new;
		new->previous = stack_ref->top;
		new->next = NULL;
		stack_ref->top = new;
	}
}
void	ft_stackadd_bottom(t_stack_ref *stack_ref, t_stack *new)
{
	if (!stack_ref || !new)
		return ;
	if (!(stack_ref->bottom))
	{
		stack_ref->bottom = new;
		stack_ref->top = new;
	}	
	else
	{
		stack_ref->bottom->previous = new;
		new->next = stack_ref->bottom;
		new->previous = NULL;
		stack_ref->bottom = new;
	}
}
int	ft_stacksize(t_stack_ref *stack_ref)
{
	int	count;
	t_stack	*tmp;
	
	tmp = stack_ref->bottom;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_stackswaptop(t_stack_ref *stack_ref)
{
	if (ft_stacksize(stack_ref) < 2)
		return;
	stack_ref->top->next = stack_ref->top->previous;
	stack_ref->top->previous->previous->next = stack_ref->top;
	stack_ref->top->previous = stack_ref->top->previous->previous;
	stack_ref->top->next->previous = stack_ref->top;
	stack_ref->top->next->next = NULL;
	stack_ref->top = stack_ref->top->next;
}

void	ft_stackrotate_up(t_stack_ref *stack_ref)
{
	t_stack *current_bottom;
	t_stack *current_top;
	
	if (!stack_ref)
		return;
	if (stack_ref->bottom == stack_ref->top)
		return;
	current_bottom = stack_ref->bottom;
	current_top = stack_ref->top;
	//NEW TOP
	stack_ref->top = stack_ref->top->previous;
	stack_ref->top->next = NULL;
	//NEW BOTTOM
	stack_ref->bottom = current_top;
	stack_ref->bottom->previous = NULL;
	stack_ref->bottom->next = current_bottom;	
	//OLD BOTTOM
	current_bottom->previous = stack_ref->bottom;
}

void	ft_stackrotate_down(t_stack_ref *stack_ref)
{
	t_stack *current_bottom;
	t_stack *current_top;
	
	if (!stack_ref)
		return;
	if (stack_ref->bottom == stack_ref->top)
		return;
	current_bottom = stack_ref->bottom;
	current_top = stack_ref->top;
	//NEW BOTTOM
	stack_ref->bottom = stack_ref->bottom->next;
	stack_ref->bottom->previous = NULL;
	//NEW TOP
	stack_ref->top = current_bottom;
	stack_ref->top->previous = current_top;
	stack_ref->top->next = NULL;
	//OLD TOP	
	current_top->next = stack_ref->top;
}

void	ft_stack_reset(t_stack_ref *stack_ref)
{
	stack_ref->bottom = NULL;
	stack_ref->top = NULL;
}
void	ft_stackpush(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{	
	if (!stack_ref_from || !stack_ref_to || stack_ref_from == stack_ref_to || ft_stacksize(stack_ref_from) == 0)
		return;
	if (ft_stacksize(stack_ref_to) > 0)
		stack_ref_to->top->next = stack_ref_from->top;
	else
		stack_ref_to->top = stack_ref_from->top;
	if (ft_stacksize(stack_ref_from) > 1)
	{
		stack_ref_from->top = stack_ref_from->top->previous;
		stack_ref_from->top->next = NULL;
	}
	else
		ft_stack_reset(stack_ref_from);
	if (stack_ref_to->bottom)
	{
		stack_ref_to->top->next->previous = stack_ref_to->top;
		stack_ref_to->top = stack_ref_to->top->next;
	}
	else
	{
		stack_ref_to->bottom = stack_ref_to->top;
		stack_ref_to->top->previous = NULL;
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
void	stack_bottom_print(t_stack_ref *stack_ref)
{
	t_stack	*tmp;

	tmp = stack_ref->bottom;
	while (tmp)
	{
		printf("%d",tmp->nbr);
		tmp = tmp->next;
	}
	if (stack_ref->top && stack_ref->bottom)
		printf("\nTop: %d Bottom: %d",stack_ref->top->nbr,stack_ref->bottom->nbr);
	printf("\ntamanho da lista: %d\n\n",ft_stacksize(stack_ref));
}
void	sort_stack_size3(t_stack_ref *stack_ref)
{
	//MAIOR NO MEIO
	if (stack_ref->top->nbr < stack_ref->top->previous->nbr && stack_ref->bottom->nbr < stack_ref->top->previous->nbr)
	{
		ft_stackrotate_down(stack_ref);
		write(1, "rr", 2);
		write(1, &(stack_ref->stack_name), 1);
		write(1, "\n", 1);
	}
	//MAIOR NO TOP
	else if (stack_ref->top->nbr > stack_ref->top->previous->nbr && stack_ref->top->nbr > stack_ref->bottom->nbr)
	{
		ft_stackrotate_up(stack_ref);
		write(1, "r", 1);
		write(1, &(stack_ref->stack_name), 1);
		write(1, "\n",1);
	}
	//MAIOR NA BASE, MAS OS OUTROS TROCADOS
	if (stack_ref->top->nbr > stack_ref->top->previous->nbr)
	{
		ft_stackswaptop(stack_ref);
		write(1, "s", 1);
		write(1, &(stack_ref->stack_name), 1);
		write(1, "\n", 1);
	}
}
int	distance_from_top(t_stack_ref *stack_ref, t_stack *node)
{
	int	i;
	t_stack *node_down_rotate;
	
	node_down_rotate = node;
	i = 0;
	while (node != stack_ref->top && node_down_rotate != stack_ref->top)
	{
		i++;
		node = node->next;
		if (node_down_rotate != stack_ref->bottom)
			node_down_rotate = node_down_rotate->previous;
		else
			node_down_rotate = stack_ref->top;
	}
	if (node == stack_ref->top)
		return (i);
	return (-i);
}

int is_adjust_to_max(t_stack *top, t_stack *bottom, int nbr_node)
{
	int	nbr_top;
	int	nbr_bottom;

	nbr_top = top->nbr;
	nbr_bottom = bottom->nbr;
	return (nbr_node >= nbr_top && nbr_top >= nbr_bottom);
}

int is_adjust_to_min(t_stack *top, t_stack *bottom, int nbr_node)
{
	int	nbr_top;
	int	nbr_bottom;

	nbr_top = top->nbr;
	nbr_bottom = bottom->nbr;
	return (nbr_node <= nbr_bottom && nbr_top >= nbr_bottom);
}

int is_adjust_to_center(t_stack *top, t_stack *bottom, int nbr_node)
{
	int	nbr_top;
	int	nbr_bottom;

	nbr_top = top->nbr;
	nbr_bottom = bottom->nbr;
	return (nbr_node <= nbr_bottom && nbr_node >= nbr_top);
}

int	adjust_stack_b(t_stack_ref *stack_ref, int nbr_node)
{
	int	i;
	t_stack *top;
	t_stack *bottom;
	
	top = stack_ref->top;
	bottom = stack_ref->bottom;
	i = 0;
	while (!(is_adjust_to_max(top, bottom, nbr_node) || is_adjust_to_min(top, bottom, nbr_node) || is_adjust_to_center(top, bottom, nbr_node)))
	{
		i++;
		bottom = top;
		top = top->previous;
	}
	if (ft_stacksize(stack_ref) - i >= i)
		return (i);
	return (i - ft_stacksize(stack_ref));
}

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
	optimized_moves.ra += (moves_to_the_top > 0 && stack_ref_from->stack_name == 'a') * moves_to_the_top;
	optimized_moves.ra += (moves_to_adjuste > 0 && stack_ref_to->stack_name == 'a') * moves_to_adjuste;
	optimized_moves.rra -= (moves_to_the_top < 0 && stack_ref_from->stack_name == 'a') * moves_to_the_top;
	optimized_moves.rra -= (moves_to_adjuste < 0 && stack_ref_to->stack_name == 'a') * moves_to_adjuste;
	optimized_moves.rb += (moves_to_the_top > 0 && stack_ref_from->stack_name == 'b') * moves_to_the_top;
	optimized_moves.rb += (moves_to_adjuste > 0 && stack_ref_to->stack_name == 'b') * moves_to_adjuste;
	optimized_moves.rrb -= (moves_to_the_top < 0 && stack_ref_from->stack_name == 'b') * moves_to_the_top;
	optimized_moves.rrb -= (moves_to_adjuste < 0 && stack_ref_to->stack_name == 'b') * moves_to_adjuste;
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
	write(1, &(stack_ref_to->stack_name), 1);
	write(1, "\n" , 1);
}

void	execute_moviments(t_movement moviments, t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{
	t_stack_ref *stack_ref_a;
	t_stack_ref *stack_ref_b;

	if (stack_ref_from->stack_name == 'a')
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

void	push_all_sorted(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{
	t_stack	*node_rotate;
	t_stack	*node_reverse_rotate;
	t_movement less_moviments;
	t_movement moviments;
	int	i;

	while (ft_stacksize(stack_ref_from) > 0 || (stack_ref_to->stack_name == 'a' && ft_stacksize(stack_ref_from) > 0))
	{
 		// printf("Lista A:\n");
		// stack_top_print(stack_ref_from);
		// printf("Lista B:\n");
		// stack_top_print(stack_ref_to);
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
		}
		execute_moviments(less_moviments, stack_ref_from, stack_ref_to);
		ft_stackpush(stack_ref_from, stack_ref_to);
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
	if (ft_stacksize(stack_ref) - i >= i)
	{
		while (i--)
		{
			ft_stackrotate_up(stack_ref);
			write(1, "rb\n", 3); 
		}
	}
	else
	{
		while (ft_stacksize(stack_ref) - i++)
		{
			ft_stackrotate_down(stack_ref);
			write(1, "rrb\n", 4); 
		}
	}
}

void	push_all_back_to_a(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{
	while (ft_stacksize(stack_ref_from))
	{
		ft_stackpush(stack_ref_from, stack_ref_to);
		write(1, "pa\n", 3);
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
	//sort_stack_size3(stack_ref_a);
	//printf("Ajustando lista b:\n");
	rotate_max_top(stack_ref_b);
	//printf("Lista A:\n");
	//stack_top_print(stack_ref_a);
	//printf("Lista B:\n");
	//stack_top_print(stack_ref_b);
	//push_all_sorted(stack_ref_b, stack_ref_a);
	push_all_back_to_a(stack_ref_b, stack_ref_a);
	//printf("Lista A:\n");
	// stack_top_print(stack_ref_a);
	// printf("Lista B:\n");
	// stack_top_print(stack_ref_b);
/* 	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);
	node_rotate = stack_ref_a->top;
	less_moviments = calculate_moves(stack_ref_a, stack_ref_b, node_rotate);
	execute_moviments(less_moviments, stack_ref_a, stack_ref_b);
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);
	node_reverse_rotate = stack_ref_a->bottom;
	less_moviments = calculate_moves(stack_ref_a, stack_ref_b, node_reverse_rotate);
	execute_moviments(less_moviments, stack_ref_a, stack_ref_b);
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);
	node_rotate = stack_ref_a->top;
	less_moviments = calculate_moves(stack_ref_a, stack_ref_b, node_rotate);
	execute_moviments(less_moviments, stack_ref_a, stack_ref_b);
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);
	node_rotate = stack_ref_a->top;
	less_moviments = calculate_moves(stack_ref_a, stack_ref_b, node_rotate);
	execute_moviments(less_moviments, stack_ref_a, stack_ref_b);
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);
	while (ft_stacksize(stack_ref_b) > 0)
		ft_stackpush(stack_ref_b,stack_ref_a);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b); */
	return (0);
}
/* int main(int argc , char *argv[])
{
	t_stack_ref	*stack_ref_a;
	t_stack_ref	*stack_ref_b;
	t_stack		*node1;
	t_stack		*node2;
	t_stack		*node3;

	//LISTA A
	stack_ref_a = ft_initstack(argc,argv);
	//LISTA B
	stack_ref_b = ft_stacknewref();
	node1 = ft_stacknewnode(3);
	ft_stackadd_top(stack_ref_b,node1);
	node2 = ft_stacknewnode(1);
	ft_stackadd_bottom(stack_ref_b,node2);
	node3 = ft_stacknewnode(4);
	ft_stackadd_bottom(stack_ref_b,node3);
	
	
	printf("Lista A inicializada:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B inicializada:\n");
	stack_top_print(stack_ref_b);

	printf("\nSORT B SIZE 3:\n");
	sort_stack_size3(stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);
	
	ft_stackswaptop(stack_ref_a);
	printf("SWAP A:\n");
	stack_top_print(stack_ref_a);
	
	printf("ROTATE_UP:\n");
	ft_stackrotate_up(stack_ref_a);
	stack_top_print(stack_ref_a);
	
	printf("ROTATE_DOWN:\n");
	ft_stackrotate_down(stack_ref_a);
	stack_top_print(stack_ref_a);

	printf("\nPUSH TO A:\n");
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);

	printf("\nPUSH TO A:\n");
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);

	printf("\nSORT A SIZE 3:\n");
	sort_stack_size3(stack_ref_a);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);

	ft_stackswaptop(stack_ref_b);
	printf("SWAP B:\n");
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);

	printf("\nPUSH TO A:\n");
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);

	printf("\nPUSH TO A:\n");
	ft_stackpush(stack_ref_a,stack_ref_b);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);

	printf("\nPUSH TO B:\n");
	ft_stackpush(stack_ref_b,stack_ref_a);
	printf("Lista A:\n");
	stack_top_print(stack_ref_a);
	printf("Lista B:\n");
	stack_top_print(stack_ref_b);
	printf("Distancia do node 2 para o top: %d\n", distance_from_top(stack_ref_b,node3));
	printf("Distancia do node 3 para o top: %d\n", distance_from_top(stack_ref_b,node1));
	printf("Distancia do node 1 para o top: %d\n", distance_from_top(stack_ref_b,node2));
	printf("Rodar quantas vezes B para encaixar o top de a: %d\n", adjust_stack_b(stack_ref_b, stack_ref_a->top->nbr));
	printf("Rodar quantas vezes B para encaixar o segundo top de a: %d\n", adjust_stack_b(stack_ref_b, stack_ref_a->top->previous->nbr));
	
	return 0;
} */
