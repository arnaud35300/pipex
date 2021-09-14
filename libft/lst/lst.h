/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 00:04:47 by arguilla          #+#    #+#             */
/*   Updated: 2021/09/08 05:03:37 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

void	ft_lstclear(t_stack **lst, void (*del)(int));
t_stack	*ft_lstnew(int nb);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstiter(t_stack *lst, int (*f)(int));
void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(int));
void	ft_lstadd_back(t_stack **alst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int));

#endif
