/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:17:34 by marvin            #+#    #+#             */
/*   Updated: 2023/02/20 09:17:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	get_string(int sig)
{
	static int		i;
	static char		c;

	if (sig == SIGUSR1)
		c <<= 1;
	else if (sig == SIGUSR2)
	{
		c <<= 1;
		c += 1;
	}
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, get_string);
	signal(SIGUSR2, get_string);
	while (1)
		pause();
	return (0);
}
