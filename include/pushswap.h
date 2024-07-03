/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:28:27 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/03 18:34:34 by mde-souz         ###   ########.fr       */
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

typedef struct moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_moves;

void		validate_args(int argc, char *argv[]);
t_stack_ref	*ft_stacknewref(char stack_name);
t_stack		*ft_stacknewnode(int nbr);
void		ft_stackprepend(t_stack_ref *stack_ref, t_stack *new);
int			ft_stacksize(t_stack_ref *stack_ref);
void		ft_stackfree(t_stack_ref **stack_ref);
void		ft_stack_reset(t_stack_ref *stack_ref);
int			ft_stack_issorted(t_stack_ref *stack_ref);
t_stack_ref	*ft_initstack(int argc, char *argv[], char stack_name);
t_moves		init_moves(void);
void		stackswaptop(t_stack_ref *stack_ref);
void		stackrotate_up(t_stack_ref *stack_ref);
void		stackrotate_down(t_stack_ref *stack_ref);
void		rotate_min_top(t_stack_ref *stack_ref);
void		rotate_max_top(t_stack_ref *stack_ref);
void		stackpushfromto(t_stack_ref *stack_ref_from,
				t_stack_ref *stack_ref_to);
int			distance_from_top(t_stack_ref *stack_ref, t_stack *node);
void		sort_stack_size3(t_stack_ref *stack_ref);
t_moves		calc_moves(t_stack_ref *stack_ref_a,
				t_stack_ref *stack_ref_b, t_stack *node);
int			count_moves(t_moves moves);
t_moves		compare_moves(t_moves moves_a, t_moves moves_b);
void		print_moves(t_moves moves, t_stack_ref *stack_ref_to);
void		execute_moves(t_moves moves,
				t_stack_ref *stack_a, t_stack_ref *stack_b);
#endif