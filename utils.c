/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:03:17 by jihyukim          #+#    #+#             */
/*   Updated: 2022/06/21 16:00:51 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(char *str)
{
	ft_putendl_fd(str, 1);
	exit(1);
}

void	print_pid(int is_server)
{
	pid_t	pid;

	pid = getpid();
	if (is_server)
		ft_putstr_fd("Server PID: ", 1);
	else
		ft_putstr_fd("Client PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
}
