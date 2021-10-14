/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:47:45 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 04:34:52 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stacks(int n, t_stack *a, t_stack *b)
{
	a->n = n;
	a->array = malloc(n * sizeof(int));
	if (!(a->array))
		return (1);
	b->n = 0;
	b->array = malloc(n * sizeof(int));
	if (!(b->array))
	{
		free(a->array);
		return (1);
	}
	return (0);
}

static void	error(t_stack *a, t_stack *b, int i)
{
	if (i)
	{
		free(a->array);
		free(b->array);
	}
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (init_stacks(argc - 1, &a, &b))
		error(&a, &b, 0);
	if (check_args(argc, argv, &a, &b))
		error(&a, &b, 1);
	if (check_sort(&a))
		return (0);
	if (a.n <= 3)
		micro_sort(&a, &b);
	else if (a.n <= 14)
		little_sort(&a, &b);
	else if (a.n <= 190)
		medium_sort(&a, &b, 6);
	else
		big_sort(&a, &b, 5, 6);
	return (0);
}
