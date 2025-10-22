/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfialho <brfialho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:12:58 by brfialho          #+#    #+#             */
/*   Updated: 2025/10/22 20:16:49 by brfialho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
 #define MAIN_H

# ifndef VALID_CHARS
#  define VALID_CHARS "01CEP"
# endif

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_char_counter
{
	size_t	c_count;
	size_t	e_count;
	size_t	p_count;
}	t_char_counter;

#endif