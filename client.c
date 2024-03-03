/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egolboyu <egolboyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:07:28 by egolboyu          #+#    #+#             */
/*   Updated: 2024/03/03 18:32:27 by egolboyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_printf(const char *str, ...);
int	ft_atoi(char *str);

void	signal_giver(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c << i) & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	a;

	a = 0;
	i = -1;
	if (argc != 3)
	{
		ft_printf("%s", "Incorrect usage, try ./client <PID> <MESSAGE>\n");
		ft_printf("%s", "Message needs to be in double quotes!");
		exit (-1);
	}
	while (argv[1][a] != '\0')
	{
		if (!(argv[1][a] >= '0' && argv[1][a] <= '9'))
		{
			ft_printf("%s", "PID must be a number!");
			exit (-1);
		}
		a++;
	}
	while (argv[2][++i])
		signal_giver(ft_atoi(argv[1]), argv[2][i]);
	return (0);
}
