/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:00:12 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/22 21:05:57 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "pushswap.h"

void	ft_stackswap(t_list_ref *lst_ref, t_list *node_a, t_list *node_b)
{
	t_list *tmp_node;
	
	if (ft_stacksize(lst_ref) < 2 || node_a == node_b)
		return;
	if (!node_a || !node_b || !lst_ref)
		return;
	//VERIFICA SE UM DOS DOIS A SEREM TROCADOS SAO BOTTOM OU TOP
	if (lst_ref->bottom == node_a)
		lst_ref->bottom = node_b;
	else if (lst_ref->top == node_a)
		lst_ref->top = node_b;
	if (lst_ref->bottom == node_b)
		lst_ref->bottom = node_a;
	else if (lst_ref->top == node_b)
		lst_ref->top = node_a;
	//SETAR A NO LUGAR DO B
	tmp_node = node_a->previous;
	if (node_a != node_b->previous)
		node_a->previous = node_b->previous;
	else
		node_a->previous = node_b;
	if (node_b != tmp_node)
		node_b->previous = tmp_node;
	else
		node_b->previous = node_a;
	tmp_node = node_a->next;
	if (node_a != node_b->next)
		node_a->next = node_b->next;
	else
		node_a->next = node_b;
	if (node_b != tmp_node)
		node_b->next = tmp_node;//2
	else
		node_b->next = node_a;
	//PASSAR OS QUE APONTAVAM PARA O B PARA APONTAR PARA O A
	if (node_a != lst_ref->bottom)
		node_a->previous->next = node_a;
	if (node_a != lst_ref->top)
		node_a->next->previous = node_a;
	//PASSAR OS QUE APONTAVAM PARA O A PARA APONTAR PARA O b
	if (node_b != lst_ref->bottom)
		node_b->previous->next = node_b;
	if (node_a != lst_ref->top)
		node_b->next->previous = node_b;
} */