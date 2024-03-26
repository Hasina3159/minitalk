#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>

int	    ft_atoi(const char *str);
int	    ft_strlen(char *s);
void	ft_printf(char *s);
void	char_to_signal(int c, int pid);
void	int_to_signal(int c, int pid);

#endif