/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:32 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/06 22:26:26 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	main(int argc, char **argv)
{
    int i;
    
	if (argc != 3)
        return (0);
    i = atoi(argv[1]);
    printf("%d", i);
    kill(i, SIGTERM);
}
