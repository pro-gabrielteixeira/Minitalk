/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:45 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/13 23:17:31 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"



void    sig_handler(int signal)
{
	static char	c;
	static int	i;
	
	if (!c)
		c = 0;
	if (!i)
		i = 0;
	if (signal == SIGUSR1)
		c = (c << 1);
	else if (signal == SIGUSR2)
		c = (c << 1) | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
    printf("%d\n", getpid());
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
	while (TRUE)
		pause();
    return (0);
}
