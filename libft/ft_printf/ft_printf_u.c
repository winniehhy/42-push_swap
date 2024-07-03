/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:46:46 by hheng             #+#    #+#             */
/*   Updated: 2024/07/03 08:42:38 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_u_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int num)
{
	char	*str;
	int		i;

	i = get_u_numlen(num);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (--i >= 0)
	{
		str[i] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

int	ft_print_u(unsigned int num)
{
	char	*str;

	if (num == 0)
		return (ft_print_c('0'));
	str = ft_itoa_unsigned(num);
	ft_print_s(str);
	free(str);
	return (get_u_numlen(num));
}
