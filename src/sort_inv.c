/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:38:15 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 02:38:17 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_block_inv(t_stack *a, t_stack *b, int start, int end)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= b->n / 2)
		if (b->array[i] > start && b->array[i] <= end)
			break ;
	j = b->n;
	while (--j > b->n / 2)
		if (b->array[j] > start && b->array[j] <= end)
			break ;
	if (i <= b->n - j)
		while (i--)
			rm(a, b, 'b');
	else
		while (j++ < b->n)
			rrm(a, b, 'b');
	pm(a, b, 'a');
	if (a->n > 1)
		if (a->array[0] > a->array[1])
			sm(a, b, 'a');
}

static void	move_back_inv(t_stack *a, t_stack *b, int num)
{
	int	i;

	i = 0;
	while (a->array[i] != num)
		i++;
	if (i <= a->n / 2)
		while (i--)
			rm(a, b, 'a');
	else
		while (i++ < a->n)
			rrm(a, b, 'a');
	pm(a, b, 'b');
}

void	medium_sort_inv(t_stack *a, t_stack *b, int nb, int start)
{
	int	little;
	int	range;
	int	j;
	int	i;

	i = nb;
	range = (b->n - start + 1) / nb;
	little = start + (b->n - start + 1) % nb - 1;
	while (i--)
	{
		j = 0;
		while (j++ < range)
			move_block_inv(a, b, little + i * range, little + (i + 1) * range);
	}
	i = little;
	while (++i <= little + range * nb)
		move_back_inv(a, b, i);
}
