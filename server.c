/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:45 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/06 22:28:06 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#define TRUE 1

int	main(void)
{
    printf("%d\n", getpid());
	while (TRUE)
		usleep(1000);
    return (0);
}
