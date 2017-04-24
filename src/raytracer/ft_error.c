#include "../../header/includes.h"

void            ft_error(int index)
{
    if (index == 1)
    {
	      ft_putstr("Usage : ./rtv1 <filename>\n");
		    exit (-1);
    }
    else if (index == 2)
    {
        ft_putstr("error02");
	    exit(-1);
    }
}