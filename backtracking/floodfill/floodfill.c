#include <stdlib.h>
#include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

// 2D Array'i ekrana basmak için (Test amaçlı)
void	ft_print(char **tab, t_point size)
{
	int	i;

	i = 0;
	while (i < size.y)
	{
		ft_putstr(tab[i]);
		i++;
	}
}

// ---------------------------------------------------------
//  BACKTRACKING
// ---------------------------------------------------------
// Recursive (Özyinelemeli) doldurma fonksiyonu
// tab: harita, size: boyutlar, cur: şu anki nokta, to_fill: değişecek karakter
void	ft_fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (tab[cur.y][cur.x] != to_fill || tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';
	ft_fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	ft_fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	ft_fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	ft_fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	ft_floodfill(char **tab, t_point size, t_point begin)
{
	char	target_char;

	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	target_char = tab[begin.y][begin.x];
	ft_fill(tab, size, begin, target_char);
}

// ---------------------------------------------------------
//  KOPYALAMA
// ---------------------------------------------------------
// String'i Heap belleğine kopyalamak için yardımcı fonksiyon
char	*ft_make_row(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// ---------------------------------------------------------
// MAIN FONKSİYONU (TEST)
// ---------------------------------------------------------
// Derlemek için: gcc flood_fill.c -o flood_fill
// Çalıştırmak için: ./flood_fill
int	main(void)
{
	char **area;
	t_point size;
	t_point begin;
	int i;

	size.x = 5;
	size.y = 5;
	area = (char **)malloc(sizeof(char *) * size.y);
	area[0] = ft_make_row("11111");
	area[1] = ft_make_row("10001");
	area[2] = ft_make_row("10101");
	area[3] = ft_make_row("10001");
	area[4] = ft_make_row("11111");
	begin.x = 1;
	begin.y = 1;
	write(1, "--- ONCE ---\n", 13);
	ft_print(area, size);
	ft_floodfill(area, size, begin);
	write(1, "\n--- SONRA ---\n", 15);
	ft_print(area, size);
	i = 0;
	while (i < size.y)
		free(area[i++]);
	free(area);
	return (0);
}