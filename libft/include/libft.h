/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:35:14 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/16 01:34:42 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	ft_putnbr_fd(int n, int fd);

#endif