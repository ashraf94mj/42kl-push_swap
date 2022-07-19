/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:10:54 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/19 15:58:32 by mmohamma         ###   ########.fr       */
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

//remeber to remove 
#include <stdio.h>
void	print_stack(t_data *data);

/*	push_swap.c	*/




/*	validation.c	*/

// int		check_input(t_data *data, char **str, int size);
int		create_stack(t_data *data, char **str);

/*	push_swap.c	*/

void	push_swap(t_data *data);

/*	push_swap_small.c	*/
void	push_swap_small(t_data *data);

/*	utils.c	*/

t_list	*ft_lstlast_sec(t_list *lst);
int		find_biggest(t_list *lst);
int		find_smallest(t_list *lst);
int		check_stack(t_list *lst);
void	transform_list(t_data *data);

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