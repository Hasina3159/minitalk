/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:00:26 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/27 16:00:27 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void    ft_str_to_signal(char *s, int pid)
{
	int	i;

    int_to_signal(ft_strlen(s), pid);
	i = 0;
	while (s[i])
	{
		char_to_signal(s[i], pid);
		i++;
	}
	usleep(DELAY);
	char_to_signal(0, pid);
}

void	received(int sig)
{
	(void) sig;
	ft_printf("Message Received Successfully!\n");
}

int main(int argc, char **argv)
{
	signal(SIGUSR1, received);
	if (argc == 3)
	{
		printf("SIZE : %d\n", ft_strlen(argv[2]));
		ft_str_to_signal(argv[2], ft_atoi(argv[1]));
	}
	pause();
    return (0);
}
