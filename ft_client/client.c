/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:32 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/16 01:33:56 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	end_sig(int s_pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(s_pid, SIGUSR1);
		usleep(100);
	}
}

void	string_handler(char *str, int t_pid)
{
	int	i;
	int	j;
	int	res;

	j = 0;
	while (str[j] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			res = (str[j] >> i) & 1;
			if (res == 0)
				kill(t_pid, SIGUSR1);
			else
				kill(t_pid, SIGUSR2);
			i--;
			usleep(100);
		}
	j++;
	}
}

int	main(int argc, char **argv)
{
	int	s_pid;

	if (argc != 3)
		return (0);
	s_pid = ft_atoi(argv[1]);
	string_handler(argv[2], s_pid);
	string_handler("\n", s_pid);
	end_sig(s_pid);
	return (0);
}
