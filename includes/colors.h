/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:47:55 by rene              #+#    #+#             */
/*   Updated: 2023/11/29 21:21:17 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/* ***** COLORS ***** */
# define RESET			"\001\033[0m\002"
# define BLACK			"\001\033[30m\002"
# define RED			"\001\033[31m\002"
# define LIGHT_RED		"\001\033[91m\002"
# define GREEN			"\001\033[32m\002"
# define LIGHT_GREEN	"\001\033[92m\002"
# define YELLOW			"\001\033[33m\002"
# define LIGHT_YELLOW	"\001\033[93m\002"
# define BLUE			"\001\033[34m\002"
# define LIGHT_BLUE		"\001\033[94m\002"
# define MAGENTA		"\001\033[35m\002"
# define LIGHT_MAGENTA	"\001\033[95m\002"
# define CYAN			"\001\033[36m\002"
# define LIGHT_CYAN		"\001\033[96m\002"
# define WHITE			"\001\033[37m\002"
# define GREY			"\001\033[90m\002"
# define LIGHT_GREY		"\001\033[37m\002"

# define BLACK_BOLD		"\001\033[1;30m\002"
# define RED_BOLD		"\001\033[1;31m\002"
# define GREEN_BOLD		"\001\033[1;32m\002"
# define YELLOW_BOLD	"\001\033[1;33m\002"
# define BLUE_BOLD		"\001\033[1;34m\002"
# define MAGENTA_BOLD	"\001\033[1;35m\002"
# define CYAN_BOLD		"\001\033[1;36m\002"
# define WHITE_BOLD		"\001\033[1;37m\002"

//# define HEREDOC_MSG	"\001\033[1;34m> \033[0m\002"
# define HEREDOC_MSG	"> "

//# define READLINE_MSG	"\033[1;36mminishell\033[34m$ \033[0m"
# define READLINE_MSG	"minishell$ "

#endif