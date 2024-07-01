/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:53:45 by mde-souz          #+#    #+#             */
/*   Updated: 2024/07/01 13:26:36 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stackswaptop(t_stack_ref *stack_ref)
{
	if (!stack_ref)
		return ;
	if (ft_stacksize(stack_ref) < 2)
		return ;
	stack_ref->top->next = stack_ref->top->previous;
	stack_ref->top->previous->previous->next = stack_ref->top;
	stack_ref->top->previous = stack_ref->top->previous->previous;
	stack_ref->top->next->previous = stack_ref->top;
	stack_ref->top->next->next = NULL;
	stack_ref->top = stack_ref->top->next;
}

void	stackrotate_up(t_stack_ref *stack_ref)
{
	t_stack	*current_bottom;
	t_stack	*current_top;

	if (!stack_ref)
		return ;
	if (stack_ref->bottom == stack_ref->top)
		return ;
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

void	stackrotate_down(t_stack_ref *stack_ref)
{
	t_stack	*current_bottom;
	t_stack	*current_top;

	if (!stack_ref)
		return ;
	if (stack_ref->bottom == stack_ref->top)
		return ;
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

void	stackpushfromto(t_stack_ref *stack_ref_from, t_stack_ref *stack_ref_to)
{
	if (!stack_ref_from || !stack_ref_to
		|| stack_ref_from == stack_ref_to || ft_stacksize(stack_ref_from) == 0)
		return ;
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
