/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egolboyu <egolboyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:04:54 by seemil            #+#    #+#             */
/*   Updated: 2024/03/03 18:02:55 by egolboyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_counter;

void	ok_handler(int sig_num)
{
	if (sig_num == SIGUSR1)
		g_counter--;
	if (g_counter == 0)
		ft_printf("🥳.OKEY.MESSAGE RECEIVED🥳\n");
}

void	send_bit(int pid, char str)
{
	int	shift;

	shift = 0;
	while (shift < 8)
	{
		if ((str << shift) & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		shift++;
	}
}

int	main(int args, char **argv)
{
	char	*str;
	int		i;
	int		pid;

	i = 0;
	signal(SIGUSR1, ok_handler);
	if (args == 3)
	{
		pid = ft_atoi(argv[1]);
		g_counter = ft_strlen(argv[2]);
		str = argv[2];
		while (str[i])
		{
			send_bit(pid, str[i]);
			i++;
		}
	}
	else
		ft_printf("ERROR: invalid arguments.\n./client <PID> <message>");
	return (0);
}
