/* Braindead tokenizer... Beats having the scene hardcoded in a header file. */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../header/includes.h"

int tokenizer(char *file, scene *myScene)
{

        myScene->numMaterials = 5;
        //char *delim_1 = "=";
        //char *delim_2 = ",";

        int material_index = 0, sphere_index = 0, light_index = 0;

        //char *error = NULL;
        char *line;
        char **line2;
        int fd;
        int i;
        fd = open(file, O_RDONLY);

        if (fd == -1) 
        {
                ft_putstr("File not found. \n");
                return -1;
        }
        else 
                ft_putstr("File scene OK. \n");


        while(get_next_line(fd, &line) != 0)
        {
                if (ft_strcmp(line,"Scene{") == 0)
                {
                        while (line[0]!= '}')
                        {
                                get_next_line(fd, &line);
                                /* Number of materials */
                                if (line[0] == '\t' && line[1] == 'm') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->numMaterials = ft_atoi(line);
                                        myScene->materials = (material *)ft_memalloc(myScene->numMaterials * sizeof(material));
                                        ft_putstr("\nNumber of materials: ");
                                        ft_putnbr(myScene->numMaterials);
                                }
                                /* Number of Spheres */
                                if (line[0] == '\t' && line[1] == 's')
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->numSpheres = ft_atoi(line);
                                        myScene->spheres = (sphere *)ft_memalloc(myScene->numSpheres * sizeof(sphere));
                                        ft_putstr("\nNumber of Spheres: ");
                                        ft_putnbr(myScene->numSpheres);
                                }
                                /* Number of Lights */
                                if (line[0] == '\t' && line[1] == 'l') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->numLights = ft_atoi(line);
                                        myScene->lights = (light *)ft_memalloc(myScene->numLights * sizeof(light));
                                        ft_putstr("\nNumber of Lights: ");
                                        ft_putnbr(myScene->numLights);
                                }
                                /* Image width */
                                if (line[0] == '\t' && line[1] == 'w') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->width = ft_atoi(line);
                                        ft_putstr("\nImage width: ");
                                        ft_putnbr(myScene->width);
                                }
                                /* Image height */
                                if (line[0] == '\t' && line[1] == 'h') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->height = ft_atoi(line);
                                        ft_putstr("\nImage height: ");
                                        ft_putnbr(myScene->height);
                                }

                        }
                        ft_putchar('\n');
                } 
                if (ft_strcmp(line,"Material{") == 0)
                {
                        while (line[0]!= '}')
                        {
                                get_next_line(fd, &line);
                                /* Diffuse */
                                if (line[0] == '\t' && line[1] == 'd' && line[2] == 'i') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        line2 = ft_strsplit(line, ',');
                                        /* Get three values */
                                        myScene->materials[material_index].diffuse.red = ft_atof(line2[0]);
                                        myScene->materials[material_index].diffuse.green = ft_atof(line2[1]);
                                        myScene->materials[material_index].diffuse.blue = ft_atof(line2[2]);
                                        i = 0;
                                        while(line2[i] != NULL)
                                        {
                                                ft_putstr(" Diffuse: ");
                                                ft_putfnbr(ft_atof(line2[i]));
                                                i++;
                                        }
                                }
                                //ft_putchar('\n');
                                /* Reflection */
                                if (line[0] == '\t' && line[1] == 'r' && line[2] == 'e') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->materials[material_index].reflection = ft_atof(line);
                                        ft_putstr(" Reflection: ");
                                        ft_putfnbr(myScene->materials[material_index].reflection);
                                }
                        }
                        material_index++;
                        ft_putchar('\n');
                }
                if (strcmp(line,"Sphere{") == 0) 
                {
                        while (line[0]!= '}') 
                        {
                                get_next_line(fd, &line);
                                /* Position */
                                if (line[0] == '\t' && line[1] == 'p') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        line2 = ft_strsplit(line, ',');
                                        /* Get three values */
                                        myScene->spheres[sphere_index].pos.x = ft_atof(line2[0]);
                                        myScene->spheres[sphere_index].pos.y = ft_atof(line2[1]);
                                        myScene->spheres[sphere_index].pos.z = ft_atof(line2[2]);
                                        i = 0;
                                        while(line2[i] != NULL)
                                        {
                                                ft_putstr(" Position: ");
                                                ft_putnbr(ft_atof(line2[i]));
                                                i++;
                                        }
                                }
                                /* Radius */
                                if (line[0] == '\t' && line[1] == 'r' && line[2] == 'a') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->spheres[sphere_index].radius = ft_atof(line);
                                        ft_putstr(" Radius: ");
                                        ft_putnbr(myScene->spheres[sphere_index].radius);
                                }
                                /* Material */
                                if (line[0] == '\t' && line[1] == 'm') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        myScene->spheres[sphere_index].material = ft_atoi(line);
                                        ft_putstr(" Material: ");
                                        ft_putnbr(myScene->spheres[sphere_index].material);
                                }
                        }
                        sphere_index++;
                        ft_putchar('\n');
                }
                /* Lights */
                if (strcmp(line,"Light{") == 0) 
                {
                        while (line[0]!= '}') 
                        {
                                get_next_line(fd, &line);
                                /* Position */
                                if (line[0] == '\t' && line[1] == 'p') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        line2 = ft_strsplit(line, ',');
                                        /* Get three values */
                                        myScene->lights[light_index].pos.x = ft_atof(line2[0]);
                                        myScene->lights[light_index].pos.y = ft_atof(line2[1]);
                                        myScene->lights[light_index].pos.z = ft_atof(line2[2]);
                                        i = 0;
                                        while(line2[i] != NULL)
                                        {
                                                ft_putstr(" Position: ");
                                                ft_putnbr(ft_atof(line2[i]));
                                                i++;
                                        }
                                }
                                /* Colour */
                                if (line[0] == '\t' && line[1] == 'c') 
                                {
                                        line = ft_strchr(line, '=');
                                        line++;
                                        line2 = ft_strsplit(line, ',');
                                        /* Get three values */
                                        myScene->lights[light_index].intensity.red = ft_atof(line2[0]);
                                        myScene->lights[light_index].intensity.green = ft_atof(line2[1]);
                                        myScene->lights[light_index].intensity.blue = ft_atof(line2[2]);
                                        i = 0;
                                        while(line2[i] != NULL)
                                        {
                                                ft_putstr(" Colour: ");
                                                ft_putnbr(ft_atof(line2[i]));
                                                i++;
                                        }
                                }
                        }
                        light_index++;
                        ft_putchar('\n');
                }

        }
        return 0;
}
