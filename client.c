/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:32 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/08 02:06:37 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void    handle_sigusr1(int signum)
{
    printf("Ola!\nSignum: %i\n", signum);
}

int	main(int argc, char **argv)
{
    int i;
    struct sigaction sa;
    
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = &handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
        return (0);
    i = atoi(argv[1]);
    printf("PID recebido: %d\n", i);
    kill(getpid(), SIGUSR1);
}
