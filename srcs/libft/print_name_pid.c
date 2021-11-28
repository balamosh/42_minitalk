/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:22:19 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/29 02:24:00 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_name_pid(const char *name, int pid)
{
	ft_putstr_fd(name, 1);
	write(1, "[", 1);
	ft_putstr_fd(SH_FG_CYAN, 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(SH_FG_RESET, 1);
	write(1, "]", 1);
}

void	ft_print_name_pid_head(const char *name, int pid)
{
	ft_print_name_pid(name, pid);
	write(1, " : ", 3);
}
