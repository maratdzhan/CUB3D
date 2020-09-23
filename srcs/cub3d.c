/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iunity <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:30:41 by iunity            #+#    #+#             */
/*   Updated: 2020/09/21 22:04:55 by iunity           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	build_environment(char *carg, int param)
{
	if (parse_config(*carg))
		return(write(2,'SOME ERROR TILL PARSING\n', 24));
}

void	create_environment(char *carg, int param)
{
	build_environment(carg, param);
}

void	init(char *carg, int param)
{
	create_environment
}

int		main(int argc, char **args)
{
	if (argc == 3 && (ft_is_save(args[2])))
		init(args[1], 1);
	else if (argc == 2)
		init(args[1], 0);
	else
		write(2, "IAC. Terminating\n", 17); 
	return (0);
}
