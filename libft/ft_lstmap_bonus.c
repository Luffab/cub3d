/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:24:46 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/03 15:15:04 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

v_list	*ft_lstmap(v_list *lst, void *(*f)(void *))
{
	v_list	*cour;
	v_list	*deb;

	cour = malloc(sizeof(v_list));
	deb = cour;
	while (lst)
	{
		if (lst->content)
			cour->content = f(lst->content);
		if (lst->next)
		{
			cour->next = malloc(sizeof(v_list));
			cour = cour->next;
		}
		else
			cour->next = NULL;
		lst = lst->next;
	}
	return (deb);
}
