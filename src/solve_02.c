/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:39:18 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 04:34:44 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_block(t_stack *a, t_stack *b, int start, int end)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= a->n / 2)
		if (a->array[i] > start && a->array[i] <= end)
			break ;
	j = a->n;
	while (--j > a->n / 2)
		if (a->array[j] > start && a->array[j] <= end)
			break ;
	if (i <= a->n - j)
		while (i--)
			rm(a, b, 'a');
	else
		while (j++ < a->n)
			rrm(a, b, 'a');
	pm(a, b, 'b');
	if (b->n > 1)
		if (b->array[0] < b->array[1])
			sm(a, b, 'b');
}

static void	move_back(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	while (b->array[i] != num)
		i++;
	if (i <= b->n / 2)
		while (i--)
			rm(a, b, 'b');
	else
		while (i++ < b->n)
			rrm(a, b, 'b');
	pm(a, b, 'a');
}

void	medium_sort(t_stack *a, t_stack *b, int nb)
{
	int	little;
	int	range;
	int	j;
	int	i;

	i = -1;
	range = a->n / nb;
	little = get_little(a) - 1;
	while (++i < nb)
	{
		j = 0;
		while (j++ < range)
			move_block(a, b, little + i * range, little + (i + 1) * range);
	}
	if (a->n > 1)
	{
		if (a->n <= 3)
			micro_sort(a, b);
		else
			little_sort(a, b);
	}
	i = b->n + 1;
	while (--i)
		move_back(a, b, i);
}

void	big_sort(t_stack *a, t_stack *b, int ns, int nb)
{
	int	range;
	int	i;
	int	j;

	i = -1;
	range = a->n / ns;
	while (++i < ns - 1)
	{
		j = 0;
		while (j++ < range)
			move_block(a, b, i * range, (i + 1) * range);
		medium_sort_inv(a, b, nb, i * range + 1);
	}
	medium_sort(a, b, nb);
}
