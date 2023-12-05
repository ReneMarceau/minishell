/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:54:45 by rene              #+#    #+#             */
/*   Updated: 2023/12/03 19:57:15 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "parse.h"

bool    handle_syntax_error(t_token *token_list)
{
    if (is_valid_token(token_list) == false)
    {
        if (token_list->type != PIPE)
        {
            if (token_list->next == NULL)
                return (print_error_syntax(ERR_SYNTAX, "newline", 2), false);
            else
                return (print_error_syntax(ERR_SYNTAX, token_list->next->token, 2), false);
        }
        return (print_error_syntax(ERR_SYNTAX, token_list->token, 2), false);   
    }
    return (true);
}
