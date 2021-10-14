/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:07:08 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 02:38:59 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->n - 1)
		if (stack->array[i] > stack->array[i + 1])
			return (0);
	return (1);
}

void	micro_sort(t_stack *a, t_stack *b)
{
	if (check_sort(a))
		return ;
	else if (a->n == 2)
		sm(a, b, 'a');
	else
	{
		if (a->array[0] < a->array[1])
		{
			rrm(a, b, 'a');
			if (a->array[0] > a->array[1])
				sm(a, b, 'a');
		}
		else
		{
			if (a->array[0] < a->array[2])
				sm(a, b, 'a');
			else
			{
				rm(a, b, 'a');
				if (a->array[0] > a->array[1])
					sm(a, b, 'a');
			}
		}
	}
}

void	little_sort(t_stack *a, t_stack *b)
{
	int	little;
	int	i;
	int	j;

	i = 0;
	little = get_little(a);
	while (a->n != 3 && ++little && ++i)
	{
		j = 0;
		while (a->array[j] != little - 1)
			j++;
		if (j <= a->n / 2)
			while (j--)
				rm(a, b, 'a');
		else
			while (j++ < a->n)
				rrm(a, b, 'a');
		pm(a, b, 'b');
	}
	micro_sort(a, b);
	while (i--)
		pm(a, b, 'a');
}
