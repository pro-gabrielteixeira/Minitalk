/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:32 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/13 23:38:21 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void    string_handler(char *str, int t_pid)
{
    int i;
    int j;
    int res;

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
            usleep(200);
        }
        j++;
    }
            
}

int	main(int argc, char **argv)
{
	if (argc != 3)
        return (0);
    string_handler(argv[2], atoi(argv[1]));
    printf("PID recebido: %d\nMensagem: %s\n", atoi(argv[1]), argv[2]);
}
