/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:56:30 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/29 14:28:35 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	rra(t_data *data, int display)
// void	rrb(t_data *data, int display)
// void	rrr(t_data *data, int display)


/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
void	sa(t_data *data, int display)
{
	int		temp;

	if (ft_lstsize(data->stacka) < 2)
		return ;
	temp = data->stacka->content;
	data->stacka->content = data->stacka->next->content;
	data->stacka->next->content = temp;
	if (display)
		ft_putendl_fd("sa", 1);
}

/*	sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.	*/
void	sb(t_data *data, int display)
{
	int		temp;

	if (ft_lstsize(data->stackb) < 2)
		return ;
	temp = data->stackb->content;
	data->stackb->content = data->stackb->next->content;
	data->stackb->next->content = temp;
	if (display)
		ft_putendl_fd("sb", 1);

}

/*	ss : sa and sb at the same time	*/
void	ss(t_data *data, int display)
{
	sa(data, 0);
	sb(data, 0);
	if (display)
		ft_putendl_fd("ss", 1);
}
