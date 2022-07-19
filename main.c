/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:47:26 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/19 15:58:40 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

////////////for checking stack after operations and answer. remmbr to remove
void	print_stack(t_data *data)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = data->stacka;
	temp2 = data->stackb;
	printf("a\tb\n----------\n");
	while (ft_lstsize(temp1) || ft_lstsize(temp2))
	{
		if (temp1 && temp2)
		{
			printf("%d\t%d\n", temp1->content, temp2->content);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1 && temp2 == NULL)
		{
			printf("%d\t-\n", temp1->content);
			temp1 = temp1->next;
		}
		else if (temp1 == NULL && temp2)
		{
			printf("-\t%d\n", temp2->content);
			temp2 = temp2->next;
		}
	}
	printf("---------------\n");
}
/////////////////

void	init_data(t_data *data)
{
	data->stacka = NULL;
	data->stackb = NULL;
	data->track = NULL;
	data->max_len = 0;
	data->top_a = 0;
	data->counter_a = 0;
	data->counter_b = 0;
	data->median_a = 0;
	data->median_b = 0;
	return ;
}

void	free_data(t_data *data)
{
	if (data->stacka)
		ft_lstclear(&data->stacka);
	if (data->stackb)
		ft_lstclear(&data->stackb);
	if (data->track)
		ft_lstclear(&data->track);
}

void	error(t_data *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		return (0);
	}
	init_data(&data);
	if (create_stack(&data, ++argv) == 1)
		error(&data);
	if (check_stack(data.stacka) == 0)
		push_swap(&data);
	free_data(&data);
	return (0);
}
