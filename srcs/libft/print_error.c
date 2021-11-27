/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:53:25 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/27 13:21:21 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_colors.h"

int	ft_print_error(int code, const char *str)
{
	ft_putstr_fd(SH_FG_RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(SH_FG_RESET, 2);
	return (code);
}
