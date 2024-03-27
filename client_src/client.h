/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:00:29 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/03/27 16:08:32 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# define DELAY 250

int	    ft_atoi(const char *str);
int	    ft_strlen(char *s);
void	ft_printf(char *s);
void	char_to_signal(int c, int pid);
void	int_to_signal(int c, int pid);

#endif