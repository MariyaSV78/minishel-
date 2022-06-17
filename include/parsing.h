/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:17:41 by msosnova          #+#    #+#             */
/*   Updated: 2022/03/10 21:59:59 by tjudlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <signal.h>
# include <linux/limits.h>
# include <sys/wait.h>
# include <errno.h>

extern int	g_error;

typedef struct s_lpars
{
	int				redirect_1;
	char			*file_1;
	char			**args;
	int				redirect_2;
	char			*file_2;
	int				fd1;
	int				fd2;
	int				pipe[2];
	struct s_lpars	*next;
	struct s_lpars	*prev;
	pid_t			pid;
}					t_lpars;

typedef struct s_shell
{
	char	*line;
	char	**envp;
	char	**envp2;
	int		nb_cmd;
	t_lpars	*first_token;
	int		is_error;
	int		is_space;
	int		heredoc_varign;
	char	*line_args;
	char	*tmp_line;
}			t_shell;

void	ft_parsing(t_shell *shell);
char	*ft_malloc(int *i, t_shell *shell, int start);
void	ft_merror(t_shell *shell, int i, char *str);
void	ft_merror2(int i, char *str);
int		ft_error(t_shell *shell);
t_lpars	*ft_new_lst(t_shell *shell);
t_lpars	*ft_lst_last(t_lpars *lst);
t_shell	*ft_init_shell(char **environ);
t_lpars	*ft_lst_add_back(t_lpars *lst, t_lpars *new);
void	ft_lst_clear(t_shell *shell, t_lpars *lst);
void	ft_print_lst(t_lpars *lst);
size_t	ft_strlcpy(char *a, const char *b, size_t c);
char	*ft_echo_dol(t_shell *shell, char *str);
char	*ft_insert_vars(t_shell *shell, char *str);
char	*ft_get_var(char *line, int *i);
char	*ft_get_sepvar(char *line, int *i, char ch1, char ch2);
char	*ft_put_var(char *out_line, char *var_name, char *rest, t_shell *shell);
int		check_parentheses(t_shell *shell, char *split, char **out_line, int *i);
void	ft_is_var(t_shell *shell);
char	*ft_is_quotes(int *i, t_shell *shell);
int		ft_is_redirect(t_shell *shell, char *line, int *i, t_lpars *last_token);
char	*ft_is_arg(t_shell *shell, int *i);
int		if_is_wordend(char *line, int *i);
int		ft_is_heredoc(char *heredoc, t_lpars *last_token, t_shell *shell);
char	*ft_is_file(char *line, char *tmp_line, int *i);
char	**ft_add_arg(char **args, char *tmp_line);
int		ft_args_last(t_lpars *tokens);
char	**ft_copy_tab2(char **args);
int		tab_len(char **args);
char	*ft_join_str(char *s1, char *s2);
int		ft_strcmp(const char *str_1, const char *str_2);
void	ft_exit(t_shell *shell);
void	ft_init_signal(void);
void	ft_init_signal2(void);
void	ft_ignore_signal(void);
void	ft_sighandler(int i);
void	ft_sighandler2(int i);
int		ft_checkopenfile(t_lpars *list, t_shell *shell);
char	**ft_get_paths(t_lpars *cmd, t_shell *shell);
void	ft_pipex(t_shell *shell, t_lpars *list);
void	ft_freetab2(char **tab);
char	**gettab(char const *s, char c);
void	ft_multpipes(t_shell *shell);
char	*ft_built_in_pwd(void);
int		ft_built_in_env(t_shell *shell, t_lpars *cmd, int exp);
int		ft_built_in_cd(char *path, t_shell *shell);
void	ft_built_in_export(t_shell *shell, char *arg);
int		ft_built_in_var(t_shell *shell, t_lpars *list);
int		ft_built_in_unset(t_shell *shell, char *arg, int pos);
int		ft_built_in_unset0(t_shell *shell, t_lpars *cmd, int pos);
int		ft_built_in_unvar(t_shell *shell, char *arg, int pos);
int		ft_built_in_echo(t_lpars *cmd);
void	ft_built_in_exit(t_shell *shell, t_lpars *tokens);
void	ft_get_fd_redirect(t_lpars *cmd);
int		ft_dup2(t_lpars *cmd);
int		ft_execute_bi(t_shell *shell, t_lpars *cmd);
void	ft_execute_ve(t_shell *shell, t_lpars *cmd);
int		ft_single_exec(t_shell *shell);
char	*ft_tolower2(char *txt);
int		ft_is_bi(t_lpars *cmd);
int		ft_poschar(char *str, char c);
char	*ft_echo_dol(t_shell *shell, char *str);
void	ft_errormsg(char *cmd, char *arg, char *msg);
int		ft_get_env(char *arg, t_shell *shell, int i);
int		ft_get_env2(char *arg, t_shell *shell, int i);
int		ft_dupfdcmd(t_lpars *cmd);
int		ft_get_fd(t_lpars *cmd, int i);
char	*ft_print_part2(t_shell *shell, int pos2, char *str, int pos0);
char	*ft_cly_br(char *out_line, char *split_i, t_shell *shell);
char	*ft_print_part(t_shell *shell, int pos2, char *str, int pos0);
int		ft_is_part(char c);
char	*ft_par_ext(t_shell *shell, char *str, int type);
char	*ft_iin_env(t_shell *shell, int pos, char *str, int posx);
char	*ft_iin_env2(t_shell *shell, int pos, char *str, int posx);
char	*ft_qm_oui(t_shell *shell, int pos, char *str);
char	*ft_qm_non(t_shell *shell, int pos, char *str, char *sub);
int		ft_bi_exp(t_shell *shell, t_lpars *cmd);

#endif
