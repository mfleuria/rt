#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

int tokenizer(char *file, scene *myScene);
/*token_elem.c*/
void			token_material(char *line, scene *myscene);
void			token_sphere(char *line, scene *myscene);
void			token_light(char *line, scene *myscene);
void			token_width(char *line, scene *myscene);
void			token_height(char *line, scene *myscene);
/*token_material*/
void		mat_diffuse(int mat_index, char *line, char **line2, scene *myscene);
void		mat_reflec(int mat_index, char *line, scene *myscene);
/*token_sphere*/
void			sphere_pos(int sphere_index, char *line, char **line2, scene *myscene);
void			sphere_rad(int sphere_index, char *line, scene *myscene);
void			sphere_mat(int sphere_index, char *line, scene *myscene);
/*token_light*/
void			light_pos(int light_index, char *line, char **line2, scene *myscene);
void			light_col(int light_index, char *line, char **line2, scene *myscene);
#endif /* _TOKENIZER_H_ */