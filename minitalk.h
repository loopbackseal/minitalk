/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohwang <yohwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:25:24 by yohwang           #+#    #+#             */
/*   Updated: 2022/06/09 16:34:46 by yohwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_stamp
{
	char	*str;
	pid_t	pid;
}	t_stamp;

void		print_word(char *str);
void		print_num(int n);
long long	count_len(long long n);
long long	calc_len(long long n);
long long	is_overflow(long long result, long long minus, long long overflow);
long long	is_minus(char c);
int			is_digit(int c);
int			ft_atoi(const char	*str);
#endif
