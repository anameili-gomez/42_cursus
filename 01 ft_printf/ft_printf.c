/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:51:31 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 13:19:25 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sorting(va_list args, const char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long long)));
	else if (c == 'i' || c == 'd')
		return (ft_print_integer(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_udecimal(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (format == NULL)
		return (0);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += ft_sorting(args, format[++i]);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
