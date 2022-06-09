/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:35:27 by yohwang           #+#    #+#             */
/*   Updated: 2022/06/09 15:41:11 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, str + i++, 1);
}

long long	count_len(long long n)
{
	long long	len;

	len = 1;
	while (n / 10 > 0)
	{
		len++;
		n = n / 10;
	}
	return (len - 1);
}

long long	calc_len(long long len)
{
	long long	ten;

	ten = 1;
	while (len-- > 0)
		ten = ten * 10;
	return (ten);
}

void	print_num(int n)
{
	char		c;
	long long	num;
	long long	len;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		num = -1LL * n;
	}
	else
		num = n;
	len = count_len(num);
	while (len > 0)
	{
		c = num / calc_len(len) + '0';
		write(1, &c, 1);
		num = num % calc_len(len);
		len--;
	}
	c = num + '0';
	write(1, &c, 1);
}
