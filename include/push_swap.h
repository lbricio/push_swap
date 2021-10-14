/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbricio- <lbricio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:49:20 by lbricio-          #+#    #+#             */
/*   Updated: 2021/10/14 04:57:36 by lbricio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int			n;
	int			*array;
}				t_stack;

//------------------------------------Uteis-------------------------------------
int		get_little(t_stack *stack);
int		ft_isdigit(int c);
int		ft_isspace(int c);
double	ft_atod(const char *nptr);
//------------------------------------------------------------------------------

//----------------------------Checando os Argumentos----------------------------
int		check_args(int n, char **args, t_stack *a, t_stack *b);
//------------------------------------------------------------------------------

//----------------------------------Movimentos----------------------------------
void	s_move(t_stack *stack);
void	r_move(t_stack *stack);
void	rr_move(t_stack *stack);
void	p_move(t_stack *stack_1, t_stack *stack_2);

void	sm(t_stack *a, t_stack *b, char c);
void	rm(t_stack *a, t_stack *b, char c);
void	rrm(t_stack *a, t_stack *b, char c);
void	pm(t_stack *a, t_stack *b, char c);
//------------------------------------------------------------------------------

//-----------------------------Funções de Ordenação-----------------------------
int		check_sort(t_stack *stack);
void	micro_sort(t_stack *a, t_stack *b);
void	little_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b, int nb);
void	medium_sort_inv(t_stack *a, t_stack *b, int nb, int start);
void	big_sort(t_stack *a, t_stack *b, int ns, int nb);
//------------------------------------------------------------------------------

#endif
