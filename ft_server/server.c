/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:45 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/13 01:11:05 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	base_conv(char *str)
{
	char	chr;
	int		i;
	int		pow;
	int		res;

	i = 0;
	pow = 1;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			res += pow;
		pow = pow * 2;
		i++;
	}
	chr = res;
	write(1, &chr, 1);
}

void	ft_print(char chr)
{
	static char	*str;
	int			i;
	
	if (!str)
	{
		str = (char*) malloc(sizeof(char) * 9);
		str[0] = chr;
		str[1] = '\0';
	}
	else
	{
		i = ft_strlen(str);
		str[i] = chr;
		str[i + 1] = '\0';
	}
	if (ft_strlen(str) == 8)
	{
		base_conv(str);
		free(str);
		str = NULL;
	}
}

void    sig_handler(int signal)
{
    if(signal == SIGUSR1)
		ft_print('0');
    else if (signal == SIGUSR2)
		ft_print('1');
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
