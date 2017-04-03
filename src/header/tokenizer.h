#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

int				tokenizer(char *file, scene *my_scene);
/*token_elem.c*/
void			token_material(char *line, scene *my_scene);
void			token_sphere(char *line, scene *my_scene);
void			token_light(char *line, scene *my_scene);
void			token_width(char *line, scene *my_scene);
void			token_height(char *line, scene *my_scene);
/*token_material*/
void		mat_diffuse(int mat_index, char *line, char **line2, scene *my_scene);
void		mat_reflec(int mat_index, char *line, scene *my_scene);
/*token_sphere*/
void			sphere_pos(int sphere_index, char *line, char **line2, scene *my_scene);
void			sphere_rad(int sphere_index, char *line, scene *my_scene);
void			sphere_mat(int sphere_index, char *line, scene *my_scene);
/*token_light*/
void			light_pos(int light_index, char *line, char **line2, scene *my_scene);
void			light_col(int light_index, char *line, char **line2, scene *my_scene);
/*token_detect*/
int				token_detect(int fd, char *line, char **line2, scene *my_scene);
#endif /* _TOKENIZER_H_ */