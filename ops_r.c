/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:28:28 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/08 19:56:48 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one	*/
void	ra(t_data *data, int display)
{
	t_list	*temp;

	if (ft_lstsize(data->stacka) < 2)
		return ;
	temp = data->stacka;
	data->stacka = temp->next;
	ft_lstlast(data->stacka)->next = temp;
	temp->next = NULL;
	if (display)
		ft_putendl_fd("ra", 1);
}

/*	rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one	*/
void	rb(t_data *data, int display)
{
	t_list	*temp;

	if (ft_lstsize(data->stackb) < 2)
		return ;
	temp = data->stackb;
	data->stackb = temp->next;
	ft_lstlast(data->stackb)->next = temp;
	temp->next = NULL;
	if (display)
		ft_putendl_fd("rb", 1);
}

/*	rr : ra and rb at the same time */
void	rr(t_data *data, int display)
{
	ra(data, 0);
	rb(data, 0);
	if (display)
		ft_putendl_fd("rr", 1);
}
