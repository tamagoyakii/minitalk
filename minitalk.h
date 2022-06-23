/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:30:13 by jihyukim          #+#    #+#             */
/*   Updated: 2022/06/21 16:01:36 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct sigaction	t_sigact;
typedef struct s_info
{
	unsigned char	*str;
	pid_t			server_pid;
}				t_info;

void	error_exit(char *str);
void	print_pid(int is_server);

#endif