/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:33:13 by arguilla          #+#    #+#             */
/*   Updated: 2021/08/23 23:29:55 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add new element at the start of the list.
**
** @param	alst	=> the list to modify.
** @param	new		=> the element to add at the start of the list.
**
** @return	void.
*/

void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
