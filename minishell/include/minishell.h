/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguerre <caguerre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:08:47 by caguerre          #+#    #+#             */
/*   Updated: 2023/04/26 16:49:29 by caguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "colors.h"
# include "functions.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// VARIABLE GLOBAL

extern int		gbl_exit_code;

// MACROS

# define SUCCESS 0
# define FAILURE 1

# define CMD_NOT_FOUND 127

# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif

// STRUCTS

typedef struct s_fds
{
    char        *in_file;
    char        *out_file;
}   t_fds;

typedef struct s_command
{
    char        *command;
    char        **args;
    char        *path;
    t_fds       *fds;
}   t_command;

typedef struct s_data
{
	bool		interactive;
	t_command	*cmd;
	pid_t		pid;
}	t_data;

#endif