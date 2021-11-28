/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reciever.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:44:02 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/29 02:25:39 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	ft_reciever_reset(t_reciever *tab, t_string *str, int new_pid)
{
	ft_string_free(str);
	tab->c = 0;
	tab->bit = 0;
	tab->pid = new_pid;
}

static void	ft_reciever_new_byte(t_reciever *tab, t_string *str)
{
	if (tab->c == '\0')
	{
		ft_putstr_cd_fd("New message from ", SH_FG_GREEN, 1);
		ft_print_name_pid("client", tab->pid);
		write(1, "\n", 1);
		write(1, str->ptr, str->size);
		write(1, "\n", 1);
		ft_reciever_reset(tab, str, 0);
	}
	else if (!ft_string_push_back(str, tab->c))
	{
		ft_print_error(0, "Cannot allocate memoty\n");
		ft_reciever_reset(tab, str, 0);
	}
	else
	{
		tab->c = 0;
		tab->bit = 0;
	}
}

static void	ft_reciever_connection_lost(t_reciever *tab, \
										t_string *str, int new_pid)
{
	ft_print_error(0, "Connection lost to ");
	ft_print_name_pid("client", tab->pid);
	write(1, "\n", 1);
	ft_reciever_reset(tab, str, new_pid);
}

void	ft_reciever(int signal, siginfo_t *info, void *data)
{
	static t_reciever	tab = (t_reciever){0, 0, 0};
	static t_string		str = (t_string){NULL, 0, 0};

	(void)data;
	if (!tab.pid)
		tab.pid = info->si_pid;
	else if (tab.pid != info->si_pid)
	{
		if (kill(tab.pid, 0))
			ft_reciever_connection_lost(&tab, &str, info->si_pid);
		else
			return ((void)kill(info->si_pid, SIGUSR1));
	}
	if (signal == SIGUSR2)
		tab.c = tab.c | (1 << tab.bit);
	if (++tab.bit == 8)
		ft_reciever_new_byte(&tab, &str);
	if (kill(info->si_pid, SIGUSR2))
		ft_reciever_connection_lost(&tab, &str, 0);
}
