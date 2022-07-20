/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 02:13:46 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 12:02:14 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_swap_big(t_data *data);
static int		partition(t_data *data, int len, t_list **list);

/*	the function to execute the push_swap algortihm	*/
void	push_swap(t_data *data)
{
	if (ft_lstsize(data->stacka) <= 12)
	{
		push_swap_small(data);
		while (ft_lstsize(data->stackb) != 0)
			pa(data, 1);
	}
	else
		push_swap_big(data);
}

static void	push_swap_big(t_data *data)
{
	int		len;

	data->max_len = ft_lstsize(data->stacka);
	len = data->max_len;
	transform_list(data);
	while (ft_lstsize(data->stacka) > 3)
		len = partition(data, len, &data->track);
	push_swap_small(data);
	ft_lstadd_back(&data->track, ft_lstnew(0));
	data->top_a = data->stacka->content;
	recursion_sort(data, data->track->next);
	pa(data, 1);
}

/*almost similar to the other function but no time to change it dy*/
static int	partition(t_data *data, int len, t_list **list)
{
	int		median;

	len /= 2;
	median = data->max_len - len;
	while (int_in_stack(data->stacka, median, -1) == 1)
	{
		if (data->stacka->content <= median)
			pb(data, 1);
		else
			ra(data, 1);
	}
	if (*list == NULL)
		*list = ft_lstnew(median);
	else
		ft_lstadd_front(list, ft_lstnew(median));
	return (len);
}
