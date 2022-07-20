/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:47:26 by mmohamma          #+#    #+#             */
/*   Updated: 2022/07/20 12:00:57 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data);
static void	free_data(t_data *data);
static void	error(t_data *data);

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

static void	init_data(t_data *data)
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

static void	free_data(t_data *data)
{
	if (data->stacka)
		ft_lstclear(&data->stacka);
	if (data->stackb)
		ft_lstclear(&data->stackb);
	if (data->track)
		ft_lstclear(&data->track);
}

static void	error(t_data *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
