#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

int 			tokenizer(char *file, scene *my_scene);
/*token_elem.c*/
void			token_material(char *line, scene *my_scene);
void			token_light(char *line, scene *my_scene);
void			token_width(char *line, scene *my_scene);
void			token_height(char *line, scene *my_scene);
/*token_elem_compose.c*/
void			token_sphere(char *line, scene *my_scene);
void			token_plan(char *line, scene *my_scene);
void			token_cyl(char *line, scene *my_scene);
void			token_cone(char *line, scene *my_scene);
/*token_material*/
void		mat_diffuse(int mat_index, char *line, scene *my_scene);
void		mat_reflec(int mat_index, char *line, scene *my_scene);
/*token_sphere*/
void			sphere_pos(int sphere_index, char *line, scene *my_scene);
void			sphere_rad(int sphere_index, char *line, scene *my_scene);
void			sphere_mat(int sphere_index, char *line, scene *my_scene);
/*token_light*/
void			light_pos(int light_index, char *line, scene *my_scene);
void			light_col(int light_index, char *line, scene *my_scene);
/*token_plan*/
void			plan_normal(int p_index, char *line, scene *sc);
void			plan_offset(int p_index, char *line, scene *sc);
void			plan_mat(int p_index, char *line, scene *sc);
/*token_cylindre*/
void			cyl_mat(int c_index, char *line, scene *my_scene);
void			cyl_axis(int c_index, char *line, scene *my_scene);
void			cyl_pos(int c_index, char *line, scene *my_scene);
void			cyl_radius(int c_index, char *line, scene *my_scene);
/*token_cone*/
void			cone_mat(int c_index, char *line, scene *my_scene);
void			cone_axis(int c_index, char *line, scene *my_scene);
void			cone_apex(int c_index, char *line, scene *my_scene);
void			cone_angle(int c_index, char *line, scene *my_scene);
/*token_detect*/
int				token_detect(int fd, char *line, scene *my_scene);
/*token_detect_elem*/
int				detect_sphere(int fd, char *line, scene *my_scene);
int				detect_plan(int fd, char *line, scene *my_scene);
int				detect_cyl(int fd, char *line, scene *my_scene);
int				detect_cone(int fd, char *line, scene *my_scene);
/*token_utils*/
int				ft_strchrstr(char *str, char *elem);
int				ft_len_tab(char **tab);
char			*ft_strcln(char *str);

#endif /* _TOKENIZER_H_ */
