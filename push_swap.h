/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:10:54 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 12:33:02 by mmohamma         ###   ########.fr       */
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
	t_list		*track;
	int			max_len;
	int			counter_a;
	int			counter_b;
	int			top_a;
	int			median_a;
	int			median_b;
}				t_data;

/*	push_swap.c	*/

void	push_swap(t_data *data);

/*	push_swap_big.c	*/

void	recursion_sort(t_data *data, t_list *list);

/*	utils_big.c	*/

t_list	*ft_lstadd_prev(t_list **lst, t_list *after, int number);
int		check_order(t_list *lst);
int		check_order(t_list *lst);
void	check_new_top(t_data *data);
int		int_in_stack(t_list *list, int median, int direction);

/*	rotate_big.c	*/

void	rotate(t_data *data, char c);
void	rotate_back_a(t_data *data);
void	rotate_back_b(t_data *data);

/*	optimize_moves.c	*/

void	optimize_moves_a(t_data *data);
void	optimize_moves_b(t_data *data);

/*	push_swap_small.c	*/

void	push_swap_small(t_data *data);

/*	utils.c	*/

t_list	*ft_lstlast_sec(t_list *lst);
int		find_biggest(t_list *lst);
int		find_smallest(t_list *lst);
int		check_stack(t_list *lst);
void	transform_list(t_data *data);

/*	validation.c	*/

int		create_stack(t_data *data, char **str);

/*	ops_s.c	*/

void	sa(t_data *data, int display);
void	sb(t_data *data, int display);
void	ss(t_data *data, int display);

/*	ops_p.c	*/

void	pa(t_data *data, int display);
void	pb(t_data *data, int display);

/*	ops_r.c	*/

void	ra(t_data *data, int display);
void	rb(t_data *data, int display);
void	rr(t_data *data, int display);

/*	ops_rr.c	*/

void	rra(t_data *data, int display);
void	rrb(t_data *data, int display);
void	rrr(t_data *data, int display);

#endif