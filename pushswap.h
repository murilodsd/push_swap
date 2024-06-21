/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:28:27 by mde-souz          #+#    #+#             */
/*   Updated: 2024/06/21 21:17:25 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

typedef struct s_list_ref
{
	t_list	*bottom;
	t_list	*top;
}	t_list_ref;


void	ft_lstswap(t_list_ref *lst_ref,t_list *previous, t_list *next);
t_list_ref	*ft_lstnewref(void);

#endif