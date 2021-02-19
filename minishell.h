#ifndef MINISHELL_H
#define MINISHELL_H

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>
#define BUFFER_SIZE 32
#define COLOR_SIZE 7

#define TYPE_CD "cd"
#define TYPE_PWD "pwd"
#define TYPE_ECHO "echo"
#define TYPE_ENV "env"
#define TYPE_EXPORT "export"
#define TYPE_UNSET "unset"
#define SHELL_LVL "./minishell"
#define TYPE_EXITE "exit"

#define BLK "\e[1;30m"
#define RED "\e[1;31m"
#define GRN "\e[1;32m"
#define GRNN "\e[1;32m"
#define YEL "\e[1;33m"
#define BLU "\e[1;34m"
#define MAG "\e[1;35m"
#define CYN "\e[1;36m"
#define WHT "\e[0;37m"

int g_input_redirection;
int g_output_redirection;
int g_double_input_redirection;
int g_pipe;
char *g_double_redirection;
char *g_input_file;
char *g_output_file;
char *g_cwd;
char g_pwd[1024];

typedef struct s_style
{
	char pwd[1024];
} t_style;

typedef struct s_export
{
	char **tab;
} t_export;

typedef struct s_unset
{
	char **tab;
	int index;
} t_unset;

typedef struct s_dollar
{
	char *value;
} t_dollar;

typedef struct s_pipe
{
	char **args;
} t_pipe;

typedef struct s_echo
{
	char **args;
} t_echo;

typedef struct s_mini
{
	char *home;
	char *line;
	int dollar_num;
	char **args;
	char **sort_args;
	int exit_status;
	int exit;
	char shell_lvl;
	char **multi_command;
	char *path;
	char **envp_backup;
	char **new_envp;
	int pipe_fd[2];
	char *OLDPWD;
	int redirection;
	char *run_path;
	char **add_path;
	int ArgsLen[10];
	int STD;
	int check_pipe;
	int ArgsNum;
	char **envp_g;
	char cwd[PATH_MAX];
	t_export export;
	t_unset unset;
	t_dollar dollar;
	t_pipe pipe;
	t_style style;
	t_echo echo;
} t_mini;

void ft_remove_pipe_space(t_mini *mini, int i);
void ft_pipe(t_mini *mini, int i);
void ft_init_pipe(t_mini *mini);
void ft_get_pipe_args(t_mini *mini, int k);
int ft_check_pipe(t_mini *mini, char **envp, int i);
size_t	ft_first(char const *s1, char const *set, size_t j);
size_t	ft_last(char const *s1, char const *set, size_t j);
int get_next_line(const int fd, char **line, t_mini *mini);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strdup(const char *s1);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
void ft_putchar(char c);
void ft_putstr(char *str);
int char_test(char *command, char *str);
int ft_strcmp(const char *s1, const char *s2);
int ft_get_args_num(t_mini *mini);
int ft_get_args(t_mini *mini);
void ft_init(t_mini *mini);
int ft_ischar(char c);
void ft_exit(t_mini *mini);
char **ft_split(char const *s, char c);
void ft_cd(t_mini *mini);
void ft_echo(t_mini *mini);
void ft_get_path(t_mini *mini);
void ft_get_home(t_mini *mini, char **envp);
void ft_re_init(t_mini *mini);
void ft_run_command(t_mini *mini);
char **ft_strjoin2(char **s1, char *s2);
void ft_export(t_mini *mini);
void ft_sort_table(t_mini *mini);
char **ft_copy_env(t_mini *mini, char **envp);
char *ft_strcpy(char *dst, const char *src);
void ft_check_args(t_mini *mini);
void ft_unset(t_mini *mini);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char **ft_remove_unset(t_mini *mini, int index);
int ft_equal_check(t_mini *mini, char *arg);
void ft_dollar(t_mini *mini);
void ft_pwd(t_mini *mini);
void ft_input_redirection(t_mini *mini, int i);
void ft_output_redirection(t_mini *mini, int i);
void ft_double_input_redirection(t_mini *mini, int i);
void ft_check_multi_command(t_mini *mini);
void ft_old_pwd(t_mini *mini);
char *ft_strlcpy(char *dst, const char *src, int size);
void ft_check_pipe_command(t_mini *mini, int i);
int ft_check_redirection(t_mini *mini);
void ft_error(char *error_msg, char *command, char *line);
void ft_dup2(t_mini *mini);
void ft_command_2(t_mini *mini, char *command);
void ft_env(t_mini *mini);
void ft_pipe_run(t_mini *mini);
int ft_check_pipe(t_mini *mini, char **envp, int i);
void ft_init_pipe(t_mini *mini);
int ft_signal(t_mini *mini);
void ft_ctrl_c(int signum);
void start();
void ft_start_minishell(t_mini *mini);
void ft_dup2(t_mini *mini);
void ft_shell_lvl(t_mini *mini);
char **ft_split_1(char *s, char c, char c1);
int skip_quots(char *str, char c, int i);
void ft_sorte_args(t_mini *mini);
void ft_free_all(t_mini *mini);
void ft_skipe_quotes(t_mini *mini);
void ft_ctrl_anti(int signum);
int syn_error(t_mini *mini);

#endif