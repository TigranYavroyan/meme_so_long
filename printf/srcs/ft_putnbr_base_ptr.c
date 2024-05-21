/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:24:34 by tyavroya          #+#    #+#             */
/*   Updated: 2024/04/14 19:24:36 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_base_ptr(unsigned long long nbr, const char *base, size_t len)
{
	if (nbr < len)
		return (write(1, base + nbr, 1));
	return (ft_putnbr_base_ptr(nbr / len, base, len)
		+ ft_putnbr_base_ptr(nbr % len, base, len));
}
