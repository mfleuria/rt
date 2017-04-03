#include "../header/includes.h"

int main(int argc, char *argv[]){

	ray r;
	t_env e;
	scene *my_scene = NULL;

	/* Scene */
	scene mine;
	mine.materials = NULL;
	mine.spheres = NULL;
	mine.lights = NULL;
	my_scene = &mine;

	if (argc != 2) 
	{
		ft_putstr("Usage : ./rtv1 <filename>\n");
		return -1;
	}

	/* Build the scene */
	if (tokenizer(argv[1], my_scene) == -1) 
		exit(-1);
	init_mlx(&e, my_scene);

	int x, y;
	for(y = 0; y < my_scene->height; y++)
	{
		for(x = 0; x < my_scene->width; x++)
		{	
			float red = 0;
			float green = 0;
			float blue = 0;

			int level = 0;
			float coef = 1.0;

			r.start.x = x;
			r.start.y = y;
			r.start.z = -2000;

			r.dir.x = 0;
			r.dir.y = 0;
			r.dir.z = 1;

			do {
				/* Find closest intersection */
				float t = 20000.0f;
				int currentSphere = -1;

				unsigned int i;
				for(i = 0; i < 3; i++)
				{
					if(intersect_ray_sphere(&r, &my_scene->spheres[i], &t))
						currentSphere = i;
				}
				if(currentSphere == -1) break;

				vector scaled = vector_scale(t, &r.dir);
				vector newStart = vector_add(&r.start, &scaled);

				/* Find the normal for this new vector at the point of intersection */
				vector n = vector_sub(&newStart, &my_scene->spheres[currentSphere].pos);
				float temp = vector_dot(&n, &n);
				if(temp == 0) break;

				temp = 1.0f / sqrtf(temp);
				n = vector_scale(temp, &n);

				/* Find the material to determine the colour */
				material currentMat = my_scene->materials[my_scene->spheres[currentSphere].material];

				/* Find the value of the light at this point */
				unsigned int j;
				for(j=0; j < 3; j++)
				{
					light currentLight = my_scene->lights[j];
					vector dist = vector_sub(&currentLight.pos, &newStart);
					if(!(vector_dot(&n, &dist) <= 0.0f))
					{
						float t = sqrtf(vector_dot(&dist,&dist));
						if(!(t <= 0.0f))
						{

							ray lightRay;
							lightRay.start = newStart;
							lightRay.dir = vector_scale((1/t), &dist);

							/* Calculate shadows */
							bool inShadow = FALSE;
							unsigned int k;
							for (k = 0; k < 3; ++k) {
								if (intersect_ray_sphere(&lightRay, &my_scene->spheres[k], &t)){
									inShadow = TRUE;
									break;
								}
							}
							if (!inShadow){
								/* Lambert diffusion */
								float lambert = vector_dot(&lightRay.dir, &n) * coef; 
								red += lambert * currentLight.intensity.red * currentMat.diffuse.red;
								green += lambert * currentLight.intensity.green * currentMat.diffuse.green;
								blue += lambert * currentLight.intensity.blue * currentMat.diffuse.blue;
							}
						}
					}
				}
				/* Iterate over the reflection */
				coef *= currentMat.reflection;

				/* The reflected ray start and direction */
				r.start = newStart;
				float reflect = 2.0f * vector_dot(&r.dir, &n);
				vector tmp = vector_scale(reflect, &n);
				r.dir = vector_sub(&r.dir, &tmp);

				level++;

			}while((coef > 0.0f) && (level < 15));

			/* ici on colorie dans la data */
			e.data[(x * 4) + (y * e.size_line) + 0] = (unsigned char)min(red * 255.0f, 255.0f);
			e.data[(x * 4) + (y * e.size_line) + 1] = (unsigned char)min(green * 255.0f, 255.0f);
			e.data[(x * 4) + (y * e.size_line) + 2] = (unsigned char)min(blue * 255.0f, 255.0f);
			e.data[(x * 4) + (y * e.size_line) + 3] = 0;
		}
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);/* on envoi l'image dans la fenetre */
	mlx_hook(e.win, 2, 3, my_key_funct, (void *)&e); // on recupe les events
	mlx_loop(e.mlx);
	return (0);
}
