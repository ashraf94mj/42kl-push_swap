/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:58:10 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/30 18:59:55 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	function to check if stack A is sorted and stack B is empty	*/
int	check_stacks(t_data *data)
{
	int		val;
	t_list	*temp;

	if (data->stackb != NULL)
		return (0);
	if (data->stacka == NULL)
		return (1);
	val = data->stacka->content;
	temp = data->stacka->next;
	while (temp)
	{
		if (val > temp->content)
			return (0);
		val = temp->content;
		temp = temp->next;
	}
	printf("stacks sorted\n"); //////
	return (1);
}

/*	the function to execute the push_swap algortihm	*/
void	push_swap(t_data *data)
{
	
}
