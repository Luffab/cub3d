/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatilly <fatilly@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:03:13 by fatilly           #+#    #+#             */
/*   Updated: 2021/05/03 15:14:14 by fatilly          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

v_list	*ft_lstnew(void *content)
{
	v_list	*new;

	new = malloc(sizeof(v_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
