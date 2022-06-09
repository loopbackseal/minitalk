/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:15:56 by yohwang           #+#    #+#             */
/*   Updated: 2022/06/09 22:54:43 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_signal(int signal)
{
	static char	byte;
	static char	bit;

	byte *= 2;
	if (signal == SIGUSR1)
		byte += 1;
	bit += 1;
	if (bit == 8)
	{
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	print_word("pid: ");
	print_num(getpid());
	print_word("\n");
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
	return (0);
}
