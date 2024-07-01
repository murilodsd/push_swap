/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:10:46 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 13:25:48 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_stack_reset(t_stack_ref *stack_ref)
{
	stack_ref->bottom = NULL;
	stack_ref->top = NULL;
}

void	ft_stackprepend(t_stack_ref *stack_ref, t_stack *new)
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