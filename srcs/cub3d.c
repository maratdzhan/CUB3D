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
	param = 0;// blanket
	if (parse_config(carg))
	{
		write(1,"SOME ERROR TILL PARSING\n", 24);
		return;
	}
}

void	create_environment(char *carg, int param)
{
	ft_strlen(carg);
	build_environment(carg, param);
}

void	init(char *carg, int param)
{
	if (param == 1)
		ft_log("with save", 0);
	else
		ft_log("without saving",0);
	ft_log("used argument parameter:",0);
	ft_log(carg,1);
	create_environment(carg, param);
}

int		main(int argc, char **args)
{
	if (argc == 3 && (ft_is_save(args[2])))
		init(args[1], 1);
	else if (argc == 2)
		init(args[1], 0);
	else
		write(2, "Invlid Arguments Count. Terminating\n", 36); 
	return (0);
}
