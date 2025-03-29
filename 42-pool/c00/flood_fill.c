typedef struct s_flood
{
    int x;
    int y;
}       t_flood;


void fill(char **map, t_flood size, t_flood current, char to_fill)
{
    if (current.y < 0 || current.x < 0 || current.y >= size.y || current.x >= size.x || map[current.y][current.x] != to_fill)
        return ;
    map[current.y][current.x] = 'F';
    fill(map, size, (t_flood){current.x - 1, current.y}, to_fill);
    fill(map, size, (t_flood){current.x + 1, current.y}, to_fill);
    fill(map, size, (t_flood){current.x, current.y - 1}, to_fill);
    fill(map, size, (t_flood){current.x, current.y + 1}, to_fill);
}

void flood_fill(char **map, t_flood size, t_flood begin)
{
    fill(map, size, begin, map[begin.y][begin.x]);
}

/*#include <stdio.h>
#include <stdlib.h>

void print_tab(char **a, t_flood size)
{
    int i;
    int j;
    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            printf("%c ", a[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

char** make_area(char **a, t_flood size)
{
    char **res;
    int  i, j;

    res = malloc(sizeof(char *) * size.y);
    i = 0;
    while (i < size.y)
    {
        res[i] = malloc(sizeof(char *) * (size.x + 1));
        j = 0;
        while (j < size.x)
        {
            res[i][j] = a[i][j * 2];
            j++;
        }
        i++;
    }
    return (res);
}

int main(void)
{
	t_flood size = {8, 5};
	t_flood begin = {0, 0};
    char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"0 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};

    area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}*/
