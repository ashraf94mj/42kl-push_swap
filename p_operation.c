/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:20:07 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/02 12:35:59 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty	*/
void	pa(t_data *data, int display)
{
	t_list	*temp;

	if (data->stackb == NULL)
		return ;
	temp = data->stackb;
	data->stackb = data->stackb->next;
	temp->next = data->stacka;
	data->stacka = temp;
	if (display)
		ft_putendl_fd("pa", 1);
}

/*	pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty	*/
void	pb(t_data *data, int display)
{
	t_list	*temp;

	if (data->stacka == NULL)
		return ;
	temp = data->stacka;
	data->stacka = data->stacka->next;
	temp->next = data->stackb;
	data->stackb = temp;
	if (display)
		ft_putendl_fd("pb", 1);
}
