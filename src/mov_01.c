/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:10:12 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 04:34:57 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_move(t_stack *stack)
{
	int	temp;

	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
}

void	r_move(t_stack *stack)
{
	int	temp;
	int	i;

	i = -1;
	temp = stack->array[0];
	while (++i < stack->n - 1)
		stack->array[i] = stack->array[i + 1];
	stack->array[i] = temp;
}

void	rr_move(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->n;
	temp = stack->array[stack->n - 1];
	while (--i > 0)
		stack->array[i] = stack->array[i - 1];
	stack->array[i] = temp;
}

void	p_move(t_stack *stack_1, t_stack *stack_2)
{
	int	temp;
	int	i;

	i = -1;
	temp = stack_1->array[0];
	while (++i < stack_1->n - 1)
		stack_1->array[i] = stack_1->array[i + 1];
	stack_1->n--;
	i = stack_2->n;
	while (i-- > 0)
		stack_2->array[i + 1] = stack_2->array[i];
	stack_2->array[0] = temp;
	stack_2->n++;
}
