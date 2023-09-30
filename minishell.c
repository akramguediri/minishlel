/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:06 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/30 14:15:59 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_init(char **env, t_env *envlist)
{
    int i = 0 ;
    while (*env[i])
    {
        lst_add_back();
    }
    
}
int main (char **env)
{
    t_env *envlist;

    envlist = NULL;
    ft_init(env, envlist);
}