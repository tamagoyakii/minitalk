/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:04:10 by jihyukim          #+#    #+#             */
/*   Updated: 2022/06/18 18:54:21 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	init_sigaction(void);

static void	finish_and_wait(pid_t client_pid)
{
	write(1, "\n", 1);
	kill(client_pid, SIGUSR2);
	init_sigaction();
}

static void	confirm_and_print(int signo, siginfo_t *info, void *context)
{
	static int				bit_received;
	static unsigned char	res;

	(void) signo;
	(void) context;
	bit_received++;
	if (signo == SIGUSR1)
		res &= ~(1 << (8 - bit_received));
	if (signo == SIGUSR2)
		res |= 1 << (8 - bit_received);
	if (bit_received == 8)
	{
		bit_received = 0;
		if (!res)
		{
			res = 0;
			finish_and_wait(info->si_pid);
			return ;
		}
		write(1, &res, 1);
		res = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	check_connection(int signo, siginfo_t *info, void *context)
{
	t_sigact	sigact;

	(void) signo;
	(void) context;
	ft_putendl_fd("Connection Success!", 1);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = confirm_and_print;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		error_exit("[Error] SERVER: Sigaction failed");
	kill(info->si_pid, SIGUSR1);
}

static void	init_sigaction(void)
{
	t_sigact	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = check_connection;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		error_exit("[Error] Sigaction failed.");
}

int	main(void)
{
	print_pid(1);
	init_sigaction();
	while (1)
		pause();
}
