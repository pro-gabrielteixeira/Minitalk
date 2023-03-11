/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:45 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/11 23:30:36 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    sig_handler(int signal)
{
    if(signal == SIGUSR1)
        write(1, "0", 1);
    else if (signal == SIGUSR2)
        write(1, "1", 1);
}

int	main(void)
{
    // char    *str;

    // str = "Arroz";
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    printf("%d\n", getpid());
    // printf("%d", ft_strlen(str));
	while (TRUE)
		pause();
    return (0);
}
