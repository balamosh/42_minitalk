#ifndef CLIENT_H
# define CLIENT_H

#define _XOPEN_SOURCE 700

# include <signal.h>
# include "libft.h"

unsigned char	g_flag;

int		is_pid_valid(pid_t pid);
int		send_string(int pid, char *str);
int		send_char(pid_t pid, char c);
void	serv_response(int signal, siginfo_t *info, void *data);

#endif