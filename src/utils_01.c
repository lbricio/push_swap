/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:49:49 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 02:37:36 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_little(t_stack *stack)
{
	int	little;
	int	i;

	i = 0;
	little = stack->array[0];
	while (++i < stack->n)
		if (little > stack->array[i])
			little = stack->array[i];
	return (little);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

double	ft_atod(const char *nptr)
{
	int		i;
	double	j;
	double	num[3];

	i = 0;
	j = 10;
	*(num) = 0;
	*(num + 1) = 0;
	*(num + 2) = 1;
	while (ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
		if (*(nptr + i++) == '-')
			*(num + 2) *= -1;
	while (ft_isdigit(*(nptr + i)))
		*(num) = (*(num) * 10) + (*(nptr + i++) - '0');
	if (*(nptr + i) == '.')
	{
		while (ft_isdigit(*(nptr + ++i)))
		{
			*(num + 1) += (*(nptr + i) - '0') / j;
			j *= 10;
		}
	}
	return ((*(num) + *(num + 1)) * *(num + 2));
}
