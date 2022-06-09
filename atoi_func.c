/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:30:52 by yohwang           #+#    #+#             */
/*   Updated: 2022/06/09 16:32:08 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_digit(int c)
{
	if (c - 48 < 0 || c - 48 > 9)
		return (0);
	else
		return (c - 38);
}

long long	is_overflow(long long result, long long minus, long long overflow)
{
	if (overflow > result)
	{
		if (minus == 1)
			return (-1);
		else
			return (0);
	}
	else
		return (1);
}

long long	is_minus(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	long long		result;
	long long		overflow;
	long long		minus;
	int				i;
	char			*s;

	result = 0;
	i = 0;
	minus = 1;
	s = (char *)str;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '\0')
		return (0);
	if (s[i] == '-' || s[i] == '+')
		minus = is_minus(s[i++]);
	while (is_digit(s[i]) && s[i] != '\0')
	{
		overflow = result;
		result = result * 10;
		result = result + s[i++] - '0';
		if (is_overflow(result, minus, overflow) != 1)
			return (is_overflow(result, minus, overflow));
	}
	return (result * minus);
}
