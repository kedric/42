#include "malloc.h"

int main()
{
	char *ok;
	char *ok2;
	int i = 0;

		ok = (char *)malloc(sizeof(char) * 1);
		ok = (char *)malloc(sizeof(char) * 1);
		ok = (char *)malloc(sizeof(char) * 300);
		ok = (char *)malloc(sizeof(char) * 320);
		ok = (char *)malloc(sizeof(char) * 5002);
		ok2 = (char * )malloc(sizeof(char) * 6001);
		ok = (char * )malloc(sizeof(char) * 7000);
		ok = realloc(ok, 3001);
		i++;
		ft_putstr("\n\n\n");
		show_alloc_mem();
		ft_putstr("\n\n\n");
		free(ok2);
		free(ok);
		ft_putstr("\n\n\n");
		show_alloc_mem();
		ft_putstr("\n\n\n");
		ok = (char *)malloc(sizeof(char) * 3000);
		show_alloc_mem();

}
