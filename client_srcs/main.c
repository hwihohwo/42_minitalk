/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:22:27 by marvin            #+#    #+#             */
/*   Updated: 2023/02/20 12:22:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_sig(pid_t pid, char *str)
{
	int		shift;
	int		i;
	char	sav;

	i = 0;
	while (1)
	{
		shift = 7;
		while (shift >= 0)
		{
			sav = str[i];
			sav >>= shift;
			if (sav % 2 == 0)
				kill(pid, SIGUSR1);
			else if (sav % 2 == 1)
				kill(pid, SIGUSR2);
			shift--;
			usleep(30);
		}
		if (str[i] == '\0')
			return ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("wrong input\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 100 || pid > 99998)
	{
		ft_printf("wrong pid\n");
		exit(1);
	}
	send_sig(pid, argv[2]);
	return (0);
}
