/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:10:54 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/08 02:37:53 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_data
{
	t_list		*stacka;
	t_list		*stackb;
	int			*array;
}				t_data;

//remeber to remove 
#include <stdio.h>

void	print_stack(t_data *data);

/*	validation.c	*/

int		check_input(t_data *data, char **str, int size);

/*	push_swap.c	*/

void	push_swap(t_data *data);

/*	push_swap_small.c	*/
void	push_swap_three(t_data *data);
void	push_swap_small(t_data *data);

/*	s_operation.c	*/

void	sa(t_data *data, int display);
void	sb(t_data *data, int display);
void	ss(t_data *data, int display);

/*	p_operation.c	*/

void	pa(t_data *data, int display);
void	pb(t_data *data, int display);

/*	r_operation.c	*/

void	ra(t_data *data, int display);
void	rb(t_data *data, int display);
void	rr(t_data *data, int display);

/*	rr_operation.c	*/
void	rra(t_data *data, int display);
void	rrb(t_data *data, int display);
void	rrr(t_data *data, int display);

/*	utils.c	*/

t_list	*ft_lstlast_sec(t_list *lst);
int		find_biggest(t_list *lst);
int		find_smallest(t_list *lst);
int		check_stacks(t_list *lst);
void	transform_list(t_data *data);

#endif