/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:23:11 by tyavroya          #+#    #+#             */
/*   Updated: 2024/04/14 19:23:14 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>

int	ft_printf(const char *prm, ...);
int	ft_print(va_list args, const char *prm);
int	ft_putnbr_base_ptr(unsigned long long nbr, const char *base, size_t len);
int	ft_putnbr_base(unsigned int nbr, const char *base, size_t len);
int	ft_signed_putnbr(long long n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_checker(int c);

#endif // FT_PRINTF_H
