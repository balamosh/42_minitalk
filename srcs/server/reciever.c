/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reciever.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:44:02 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/27 10:22:07 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	ft_reciever_reset(t_reciever *tab, t_string *str)
{
	ft_string_free(str);
	tab->c = 0;
	tab->bit = 0;
}

static void	ft_reciever_new_byte(t_reciever *tab, t_string *str)
{
	if (tab->c == '\0')
	{
		write(1, str->ptr, str->size);
		write(1, "\n", 1);
		ft_reciever_reset(tab, str);
	}
	else if (!ft_string_push_back(str->ptr, tab->c))
	{
		ft_print_error(0, "Cannot allocate memoty.\n");
		ft_reciever_reset(tab, str);
	}
	else
	{
		tab->c = 0;
		tab->bit = 0;
	}
}

void	ft_reciever(int signal, siginfo_t *info, void *data)
{
	static t_reciever	tab = (t_reciever){0, 0, 0};
	static t_string		str = (t_string){NULL, 0, 0};

	(void)data;
	(void)info;
	(void)str;
	if (signal == SIGUSR2)
		tab.c = tab.c | (1 << tab.bit);
	if (++tab.bit == 8)
		ft_reciever_new_byte(&tab, &str);
	kill(info->si_pid, SIGUSR2);
}
