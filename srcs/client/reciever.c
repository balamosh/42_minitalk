/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reciever.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:25:20 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/27 12:25:21 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_reciever(int signal, siginfo_t *info, void *data)
{
	(void)info;
	(void)data;
	if (signal == SIGUSR2)
		g_flag = 1;
}
