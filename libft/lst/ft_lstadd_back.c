/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:00:52 by arguilla          #+#    #+#             */
/*   Updated: 2021/08/23 23:29:32 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add new element at the end of the list.
**
** @param	alst	=> the list to modify.
** @param	new		=> the element to add at the end of the list.
**
** @return	void.
*/

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *alst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}
