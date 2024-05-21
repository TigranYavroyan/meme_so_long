/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:25:06 by tyavroya          #+#    #+#             */
/*   Updated: 2024/04/14 19:25:07 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_signed_putnbr(long long n)
{
	if (n < 0)
	{
		return (ft_putchar('-') + ft_putnbr_base(-n, "0123456789", 10));
	}
	return (ft_putnbr_base(n, "0123456789", 10));
}
