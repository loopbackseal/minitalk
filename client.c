/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:16:14 by yohwang           #+#    #+#             */
/*   Updated: 2022/06/09 22:54:12 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(pid_t spid, char letter)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (letter >> bit & 1)
			kill(spid, SIGUSR1);
		else
			kill(spid, SIGUSR2);
		usleep(40);
	}
}

void	send_msg(pid_t spid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
		send_byte(spid, msg[i++]);
}

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc != 3)
	{
		print_word("Pass 2 arguments. [PID] [MESSAGE]\n");
		return (0);
	}
	spid = ft_atoi(argv[1]);
	send_msg(spid, argv[2]);
	return (0);
}
