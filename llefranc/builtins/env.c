/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:35:53 by llefranc          #+#    #+#             */
/*   Updated: 2020/10/09 11:32:28 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Returns 1 if there is an '=' inside the variable, 0 otherwise.
*/
int		there_is_equal(char *var)
{
	int		i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	if (var[i] == '=')
		return (1);
	return (0);
}

/*
** Prints all the environnement variables with values on stdout.
** Doesn't take arguments neither options.
*/
int		builtin_env(char **args, char **env)
{	
	if (*(args + 1)) //expected only env in **args >> so args[1] should be NULL (args is **char NULL terminated)
		return (error_msg("minishell: env: doesn't take options or arguments\n", 1));
	while (env && *env)
	{
		if (there_is_equal(*env))
			ft_printf("%s\n", *env); //print each env variable on stdout (only if there is an '=' inside)
		env++;
	}
	return (0);
}