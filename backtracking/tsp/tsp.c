#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 11

typedef struct s_city
{
	float	x;
	float	y;
}			t_city;

t_city		g_cities[MAX];
float		g_dist[MAX][MAX];
int			g_used[MAX];
float		g_best_dist = 1e9;
int			g_n = 0;

// İki şehir arası mesafe hesaplama
float	ft_distance(t_city a, t_city b)
{
	return (sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2)));
}

// ---------------------------------------------------------
// BACKTRACKING
// ---------------------------------------------------------
// count: Kaç şehir gezdik?
// prev_city: En son hangi şehirdeydik?
// current_len: Şu ana kadar kat ettiğimiz yol
void	ft_dfs(int count, int prev_city, float current_len)
{
	int		i;
	float	total_len;

	if (current_len >= g_best_dist)
		return ;
	if (count == g_n)
	{
		total_len = current_len + g_dist[prev_city][0];
		if (total_len < g_best_dist)
			g_best_dist = total_len;
		return ;
	}
	i = 1;
	while (i < g_n)
	{
		if (!g_used[i])
		{
			g_used[i] = 1;
			ft_dfs(count + 1, i, current_len + g_dist[prev_city][i]);
			g_used[i] = 0;
		}
		i++;
	}
}

// ---------------------------------------------------------
// MAIN FONKSİYONU
// ---------------------------------------------------------
int	main(void)
{
	int i;
	int j;

	while (g_n < MAX && fscanf(stdin, "%f , %f", &g_cities[g_n].x,
			&g_cities[g_n].y) == 2)
		g_n++;

	i = 0;
	while (i < g_n)
	{
		j = 0;
		while (j < g_n)
		{
			g_dist[i][j] = ft_distance(g_cities[i], g_cities[j]);
			j++;
		}
		i++;
	}
	g_used[0] = 1;
	ft_dfs(1, 0, 0.0);
	fprintf(stdout, "%.2f\n", g_best_dist);
	return (0);
}