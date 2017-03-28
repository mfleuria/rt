
#ifndef _MLBX_H_
#define _MLBX_H_

/* Width and height of out image */
#define WIDTH  800
#define HEIGHT 600

# include "scene.h"

typedef struct		s_env
{
	void			*mlx; //init mlx
	void			*win; //init fenetre
	void			*img; //init image
	char			*data;// zone memoire de l'image
	int				bpp;// bits par pixels
	int				size_line;//taille d'une ligne
	int				endian;
}					t_env;

int					my_key_funct(int keycode, t_env *e); 
void				init_mlx(t_env *e, scene *myScene);

#endif /* _MLBX_H_ */