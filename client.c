/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:32 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/11 21:18:18 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    string_handler(char *str, int pid)
{
    int i;
    int j;
    int res;

    printf("%d", pid);
    j = 0;
    while (str[j] != '\0')
    {
        i = 0;
        while (i < 8)
        {
            res = str[j] >> i & 1;
            if (res == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            i++;
            usleep(1000);
        }
        j++;
    }
            
}

int	main(int argc, char **argv)
{
	if (argc != 3)
        return (0);
    string_handler(argv[2], atoi(argv[1]));
    printf("\nPID recebido: %d\nMensagem: %s\n", atoi(argv[1]), argv[2]);
}
