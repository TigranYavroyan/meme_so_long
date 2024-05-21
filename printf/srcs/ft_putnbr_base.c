/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:24:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/04/14 19:24:46 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, const char *base, size_t len)
{
	if (nbr < len)
		return (ft_putchar(base[nbr]));
	return (ft_putnbr_base(nbr / len, base, len)
		+ ft_putnbr_base(nbr % len, base, len));
}
