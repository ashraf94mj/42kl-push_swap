/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:21:25 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/30 02:23:42 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*	rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one	*/
void	rra(t_data *data, int display)
{
	t_list	*new_bottom;
	t_list	*new_top;

	if (ft_lstsize(data->stacka) < 2)
		return ;
	new_bottom = ft_lstlast_sec(data->stacka);
	new_top = ft_lstlast(data->stacka);
	new_top->next = data->stacka;
	data->stacka = new_top;
	new_bottom->next = NULL;
	if (display)
		ft_putendl_fd("rra", 1);	
}


/*	rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one	*/
void	rrb(t_data *data, int display)
{
	t_list	*new_bottom;
	t_list	*new_top;

	if (ft_lstsize(data->stackb) < 2)
		return ;
	new_bottom = ft_lstlast_sec(data->stackb);
	new_top = ft_lstlast(data->stackb);
	new_top->next = data->stackb;
	data->stackb = new_top;
	new_bottom->next = NULL;
	if (display)
		ft_putendl_fd("rrb", 1);	
}



/*	rrr : rra and rrb at the same time	*/
void	rrr(t_data *data, int display)

{
	rra(data, 0);
	rrb(data, 0);
	if (display)
		ft_putendl_fd("rrr", 1);	
}
