/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:20:58 by pciavald          #+#    #+#             */
/*   Updated: 2015/01/26 11:22:40 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "proto.h"

void	init_vars(t_avl **dir, t_avl **file, t_bool *first_pass);
void	init_len(int len[5]);
void	ft_sort_dir_file(t_data *data, char *param);
void	ft_sort_dir_end(t_data *data, t_avl *dir, t_avl *file);
void	ft_sort_params(t_data *data, char **params);
int		ft_cmp_name(void *c1, void *c2);
int		ft_cmp_date(void *c1, void *c2);
void	ft_param_del(void *content, size_t content_size);
void	ft_recursive(t_data *data, t_avl *head);
void	ft_print(t_data *data, t_avl *head, char *param, t_bool isdir);
void	ft_print_helper(t_avl *head, int len[5], t_bool isdir);
void	ft_print_full_param(t_avl *head, int len[4]);
void	ft_print_ls(t_avl *head, int len[4]);
void	ft_print_ls_rev(t_avl *head, int len[4]);
void	ft_print_link(t_param *param, int len_link);
void	ft_print_size(t_param *param, int len_size);
void	ft_print_user(t_param *param, int len_name);
void	ft_print_group(t_param *param, int len_group);
void	ft_print_time(time_t timestamp);
void	ft_print_param(t_avl *node);
void	ft_print_param_l(t_param *param);
void	ft_print_space(int len, int len_max);
int		ft_intlen(int nb);
char	ft_get_file_type(mode_t mode);
void	ft_error(int num_error, int type_error, char *param, t_bool b_exit);
void	ft_error_illegal_option(char *param);
void	ft_data_del(t_data *data);
t_data	*ft_data_new(int nb_params);
t_param	*ft_param_new(t_data *data, char *path, t_dirent *ep);
void	param_h(t_data *data, t_param **param, t_stat *file_stat, t_dirent *ep);
t_bool	ft_dir_isvalid(t_avl *tmp, char *name);
void	ft_add_file(t_data *data, char *path, t_dirent *ep, t_avl **file);
void	ft_add_dir(t_data *data, char *path, t_dirent *ep, t_avl **dir);
void	ft_sort_dir(t_data *data, char *param, t_bool alloc, t_bool last);
void	ft_ls(t_data *data);
void	ft_get_size(t_avl *head, int *size);
void	ft_max_len_link(t_avl *head, int *len);
void	ft_max_len_size(t_avl *head, int *len);
void	ft_max_len_user(t_avl *head, int *len);
void	ft_max_len_group(t_avl *head, int *len);
t_data	*ft_eval_option(char *s, t_data *data, int *opt);
t_data	*load_options(int argc, char **argv);

#endif
