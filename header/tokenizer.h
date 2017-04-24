#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "includes.h"

int				tokenizer(char *file, t_scene *my_scene);

void			token_material(char *line, t_scene *my_scene);
void			token_sphere(char *line, t_scene *my_scene);
void			token_plan(char *line, t_scene *my_scene);
void			token_cyl(char *line, t_scene *my_scene);
void			token_cone(char *line, t_scene *my_scene);
void			token_light(char *line, t_scene *my_scene);
void			token_width(char *line, t_scene *my_scene);
void			token_height(char *line, t_scene *my_scene);

void			mat_diffuse(int mat_index, char *line, t_scene *my_scene);
void			mat_reflec(int mat_index, char *line, t_scene *my_scene);

void			sphere_pos(int sphere_index, char *line, t_scene *my_scene);
void			sphere_rad(int sphere_index, char *line, t_scene *my_scene);
void			sphere_mat(int sphere_index, char *line, t_scene *my_scene);

void			light_pos(int light_index, char *line, t_scene *my_scene);
void			light_col(int light_index, char *line, t_scene *my_scene);

void			plan_normal(int p_index, char *line, t_scene *sc);
void			plan_offset(int p_index, char *line, t_scene *sc);
void			plan_mat(int p_index, char *line, t_scene *sc);

void			cyl_mat(int c_index, char *line, t_scene *my_scene);
void			cyl_axis(int c_index, char *line, t_scene *my_scene);
void			cyl_pos(int c_index, char *line, t_scene *my_scene);
void			cyl_radius(int c_index, char *line, t_scene *my_scene);

void			cone_mat(int c_index, char *line, t_scene *my_scene);
void			cone_axis(int c_index, char *line, t_scene *my_scene);
void			cone_apex(int c_index, char *line, t_scene *my_scene);
void			cone_angle(int c_index, char *line, t_scene *my_scene);

int				detect_sphere(int fd, char *line, t_scene *my_scene);
int				detect_mat(int fd, char *line, t_scene *my_scene);
int				token_detect(int fd, char *line, t_scene *my_scene);

int				ft_strchrstr(char *str, char *elem);
int				ft_len_tab(char **tab);
char			*ft_strcln(char *str);

#endif
