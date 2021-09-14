/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:39:03 by arguilla          #+#    #+#             */
/*   Updated: 2021/08/23 23:50:36 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applicates function on each element of the lst list.
**
** @param	lst		=> the list to browse.
** @param	f		=> the function to apply to each element.
**
** @return	void.
*/

void	ft_lstiter(t_stack *lst, int (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst->next)
	{
		f(lst->nb);
		lst = lst->next;
	}
	f(lst->nb);
}
