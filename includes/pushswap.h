/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:28:27 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/30 22:44:51 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_ref
{
	t_stack	*bottom;
	t_stack	*top;
	char	name;
}	t_stack_ref;

typedef struct movements
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
} t_movement;

int	ft_atoi(const char *nptr);
t_stack_ref	*ft_stacknewref(char stack_name);
t_stack	*ft_stacknewnode(int nbr);
void	ft_stackpush(t_stack_ref *stack_ref, t_stack *new);
int		ft_stacksize(t_stack_ref *stack_ref);
void	ft_stackfree(t_stack_ref **stack_ref);
void	stackswaptop(t_stack_ref *stack_ref);
void	stackrotate_up(t_stack_ref *stack_ref);
void	stackrotate_down(t_stack_ref *stack_ref);
void	stackpushfromto(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to);
int		distance_from_top(t_stack_ref *stack_ref, t_stack *node);
int		is_adjust_to_max(t_stack *top, t_stack *bottom, int nbr_node);
int		is_adjust_to_min(t_stack *top, t_stack *bottom, int nbr_node);
int		is_adjust_to_center(t_stack *top, t_stack *bottom, int nbr_node);
int		adjust_stack_b(t_stack_ref *stack_ref, int nbr_node);
void	sort_stack_size3(t_stack_ref *stack_ref);
t_movement 	calculate_moves(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to, t_stack *node);
int	count_movements(t_movement movements);
t_movement	compare_moviments(t_movement movements_a, t_movement movements_b);
void	print_moviments(t_movement moviments, t_stack_ref *stack_ref_to);
void	execute_moviments(t_movement moviments, t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to);

void	push_all_sorted(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to);
#endif