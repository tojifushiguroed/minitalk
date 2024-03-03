/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egolboyu <egolboyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:05:03 by seemil            #+#    #+#             */
/*   Updated: 2024/03/03 18:02:59 by egolboyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig_num, siginfo_t *info, void *context)
{
	static int	result;
	static int	shift;
	int			pid;

	(void)context;
	pid = info -> si_pid;
	if (sig_num == SIGUSR1)
		result += 1 << (7 - shift);
	shift++;
	if (shift == 8)
	{
		write(1, &result, 1);
		result = 0;
		shift = 0;
		kill(pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("\nWELCOME TO SERVER\n\nSERVER PID : %d\n", getpid());
	ft_printf("\n...Waiting for signal...\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
