/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:46:13 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/03 15:14:08 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(v_list **lst, void (*del)(void *))
{
	v_list	*cour;

	cour = *lst;
	while (cour)
	{
		del(cour->content);
		free(cour);
		cour = cour->next;
	}
	*lst = NULL;
}
