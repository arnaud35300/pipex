/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:24:53 by arguilla          #+#    #+#             */
/*   Updated: 2021/08/23 23:46:02 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new element of a list with the content.
**
** @param	content		=> the content of the new element.
**
** @return	void.
*/

t_stack	*ft_lstnew(int nb)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->nb = nb;
	return (elem);
}
