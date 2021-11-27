#ifndef CLIENT_H
# define CLIENT_H

#define _XOPEN_SOURCE 700

# include <signal.h>
# include "libft.h"

unsigned char	g_flag;

int		ft_sender(pid_t pid, char *str);
void	ft_reciever(int signal, siginfo_t *info, void *data);

#endif