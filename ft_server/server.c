/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:04:45 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/15 23:24:53 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*add_char(char *c, char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!str)
	{
		new_str = (char *)malloc(sizeof(char) * 2);
		new_str[i++] = c[0];
		new_str[i] = '\0';
		return (new_str);
	}
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = c[0];
	new_str[i] = '\0';
	free(str);
	str = NULL;
	return (new_str);
}

void    sig_handler(int signal)
{
	static int	i = 0;
	static char	c = 0;
	static char	*str;
	
	if (signal == SIGUSR1)
		c = (c << 1);
	else if (signal == SIGUSR2)
		c = (c << 1) | 1;
	if (++i == 8)
	{
		if (c == 0)
		{
			i = 0;
			while (str && str[i] != '\0')
				write(1, &str[i++], 1);
			free(str);
			str = NULL;
		}
		else
			str = add_char(&c, str);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
    ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
	while (TRUE)
		pause();
    return (0);
}
