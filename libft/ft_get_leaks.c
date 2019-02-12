/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 09:18:09 by llejeune          #+#    #+#             */
/*   Updated: 2019/02/09 09:25:09 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_leaks(char *prog_name, char *str)
{
	char	*cmd;

	cmd = ft_strnew((ft_strlen("leaks ") + ft_strlen(prog_name))
			+ ft_strlen(" | grep 'total leaked bytes'"));
	cmd = ft_strcat(cmd, "leaks ");
	cmd = ft_strcat(cmd, prog_name);
	cmd = ft_strcat(cmd, " | grep 'total leaked bytes'");
	system(cmd);
	ft_putendl(str);
}
