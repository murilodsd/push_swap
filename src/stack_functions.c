/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:50:17 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/02 13:41:03 by mde-souz         ###   ########.fr       */
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
	stack_ref->name = stack_name;
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

int	ft_stacksize(t_stack_ref *stack_ref)
{
	int		count;
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

void	ft_stackfree(t_stack_ref **stack_ref)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!stack_ref || !*stack_ref)
		return ;
	tmp = (*stack_ref)->bottom;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*stack_ref);
	*stack_ref = NULL;
}

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
