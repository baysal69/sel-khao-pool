/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:11:41 by sara              #+#    #+#             */
/*   Updated: 2025/03/28 21:49:13 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	fft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void    free_mat(char **mat)
{
   int i;
    
   i = 0;
   if (!mat)
        return (free(mat));
    while (mat[i] != NULL)
    {
        free(mat[i]);
        i++;
    }
   free(mat);
}

int find_min_position(t_ps *stack)
{
    t_ps *tmp;
    int min;
    int current_pos;

    tmp = stack;
    min = tmp->num;
    current_pos = 0;
    while (tmp)
    {
        if (tmp->num < min)
            min = tmp->num;
        tmp = tmp->next;
        current_pos++;
    }
    return (min);
}

int	is_sorted(t_ps *stack)
{
	int num;
	t_ps *tmp;

	tmp = stack;
	num = 0;
	while (tmp && tmp->next)
	{
		if (tmp->num < tmp->next->num)
		{
			num = 1;
			tmp = tmp->next;
		}
		else 
			return (0);
	}
	return (num);
}