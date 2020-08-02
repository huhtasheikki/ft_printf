/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:17:37 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/07/27 19:52:43 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*ptr_alst;

	ptr_alst = *alst;
	while (ptr_alst)
	{
		ft_lstdel(&ptr_alst, del);
		ptr_alst = ptr_alst->next;
	}
	*alst = NULL;
}
