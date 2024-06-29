/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:28:27 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/29 22:42:25 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

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
	char	stack_name;
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
int	ft_stacksize(t_stack_ref *stack_ref);
void	ft_stackfree(t_stack_ref **stack_ref);

#endif