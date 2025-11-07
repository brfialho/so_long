/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:34:49 by brfialho          #+#    #+#             */
/*   Updated: 2025/11/03 20:03:08 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

int	pf_putptr(void *p);
int	pf_putstr(char *s);
int	pf_put(char c, void *s);
int	pf_instr(char *s, char c);
int	ft_printf(const char *s, ...);
int	pf_count_digits(int n, int base);
int	pf_put_n(int n, char *base, int len);
int	pf_count_long(t_ulong n, int base);
int	pf_count_unsigned(t_uint n, int base);
int	pf_put_un(t_uint n, char *base, int len);
int	pf_put_ul(t_ulong n, char *base, int len);

#endif