/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:28:27 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 13:30:57 by mde-souz         ###   ########.fr       */
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
	//ver possibilidade de mudar para ponteiro de char
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
void	ft_stackprepend(t_stack_ref *stack_ref, t_stack *new);
int		ft_stacksize(t_stack_ref *stack_ref);
void	ft_stackfree(t_stack_ref **stack_ref);
void	ft_stack_reset(t_stack_ref *stack_ref);
t_stack_ref	*ft_initstack(int argc, char *argv[], char stack_name);
t_movement	init_movements(void);
void	stackswaptop(t_stack_ref *stack_ref);
void	stackrotate_up(t_stack_ref *stack_ref);
void	stackrotate_down(t_stack_ref *stack_ref);
void	stackpushfromto(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to);
int		distance_from_top(t_stack_ref *stack_ref, t_stack *node);
void	sort_stack_size3(t_stack_ref *stack_ref);
t_movement 	calculate_moves(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to, t_stack *node);
int	count_movements(t_movement movements);
t_movement	compare_movements(t_movement movements_a, t_movement movements_b);
void	print_movements(t_movement movements, t_stack_ref *stack_ref_to);
void	execute_movements(t_movement movements, t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to);
#endif