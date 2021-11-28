/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:28:33 by sotherys          #+#    #+#             */
/*   Updated: 2021/11/28 14:09:32 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

//#define _XOPEN_SOURCE 700

# include <signal.h>
# include "libft.h"

typedef struct s_reciever
{
	t_bool	recieved;
	t_bool	busy;
}				t_reciever;

t_reciever	g_status;

int		ft_sender(pid_t pid, char *str);
void	ft_reciever(int signal, siginfo_t *info, void *data);

#endif
