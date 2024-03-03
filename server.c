/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egolboyu <egolboyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:07:45 by egolboyu          #+#    #+#             */
/*   Updated: 2024/03/03 18:27:50 by egolboyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	n;
	static int	result;

	if (sig == SIGUSR1)
		result += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		write(1, &result, 1);
		n = 0;
		result = 0;
	}
}

int	main(void)
{
	int	i;

	i = 0;
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
