/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagomez <anagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:53:37 by anagomez          #+#    #+#             */
/*   Updated: 2025/02/04 14:52:18 by anagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_pointer(unsigned long long pointer);
int	ft_print_integer(int nb);
int	ft_print_udecimal(unsigned int nb);
int	ft_print_hex(unsigned int nb, int uplow);

int	ft_printf(const char *format, ...);

#endif
