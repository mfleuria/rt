#ifndef MLBX_H
# define MLBX_H

# include "includes.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_env;

int					my_key_funct(int keycode, t_env *e);
void				init_mlx(t_env *e, t_scene *my_scene);

#endif
