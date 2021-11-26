/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reciever.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:44:02 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/26 23:34:46 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "string.h"

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
	{
		//ft_string_push_back(str, tab.c);
		tab.c = 0;
		tab.bit = 0;
	}
}
