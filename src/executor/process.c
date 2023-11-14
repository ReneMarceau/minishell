/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:58:00 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/13 10:25:11 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void    wait_all(pid_t *pids, int nb_cmds)
{
    int i;
    
    i = 0;
    while (i < nb_cmds)
    {
        waitpid(pids[i], &g_exit_status, 0);
        i++;
    }
}
