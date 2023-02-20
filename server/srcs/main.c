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

void	*get_string(int sig)
{
	int		i;
	char 	c;

	i = 0;
	while (1)
	{
		c = 0;
		while (i < 8)
		{
			if (sig == SIGUSR1)
				c << 1;
			else if (sig == SIGUSR2)
			{
				c << 1;
				c += 1;
			}
		}
		if (c == '\0')
			return (0);
		else
			write(1, &c, 1);
	}
}

int	main(void)
{
	pid_t pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, get_string);
	signal(SIGUSR2, get_string);
	while (1)
		pause();
}