/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:00:34 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/07/31 12:18:54 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //REMOVE
#include "includes/ft_printf.h"

int		main(void)
{
	int				num;
	unsigned int	num2;

	num = 4000;
	num2 = 3000;

	printf("Moi X%7.8d", num);
	ft_printf("Moi X%7.8d", num);
//	while(1);
//	ft_printf("Moi %22.5d", num);

//	ft_printf("Moi %+-ll 4.2d", num2);
	return (0);
}
