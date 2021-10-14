/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 03:03:10 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 02:43:02 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a' || c == 's')
		s_move(a);
	if (c == 'b' || c == 's')
		s_move(b);
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a' || c == 'r')
		r_move(a);
	if (c == 'b' || c == 'r')
		r_move(b);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rrm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a' || c == 'r')
		rr_move(a);
	if (c == 'b' || c == 'r')
		rr_move(b);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	pm(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
		p_move(b, a);
	else
		p_move(a, b);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
