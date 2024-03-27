/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:00:22 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/27 16:00:23 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_null(char *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
}

char	*ft_strjoin(char *s, char c)
{
	int		i;
	int		size;
	char	*final;

	size = ft_strlen(s);
	final = (char *)malloc(sizeof(char) * (size + 2));
	if (final == NULL)
		return (NULL);
	ft_null(s, size + 2);
	i = 0;
	while (i < size)
	{
		final[i] = s[i];
		i++;
	}
	final[i] = c;
	if (s != NULL)
		free(s);
	return (final);
}

static void	signal_to_str(int sig, siginfo_t *info, void *context)
{
	static int	n = 1;
	static char	c = 0;
	static int	size = 0;
	static char	*message = NULL;

	(void) context;
	(void) sig;
	(void) info;
	if (n <= 32)
	{
		size = size << 1;
		if (sig == SIGUSR2)
			size = size | 1;
		if (n == 32)
		{
			message = (char *)malloc(sizeof(char) * (size + 1));
			ft_null(message, size + 1);
		}
	}
	else
	{
		c = c << 1;
		if (sig == SIGUSR2)
			c = c | 1;
		if (n % 8 == 0)
		{
			if (c)
				message[(n / 8) - 5] = c;
			else
			{
				ft_printf(message);
				ft_printf("\n");
				free(message);
				kill(info->si_pid, SIGUSR1);
				n = 0;
				c = 0;
			}
		}
	}
	n++;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = signal_to_str;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	ft_printf("PID : ");
	ft_putnbr(pid);
	ft_printf("\n");
	while (1)
		pause();
}