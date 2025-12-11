#include <stdlib.h>
#include <unistd.h>

// Yazdırma fonksiyonu
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

// ---------------------------------------------------------
//  SIRALAMA (bubble sort)
// ---------------------------------------------------------
// Giriş stringini alfabetik sıraya sokan fonksiyon (Bubble Sort)
// Sıralamazsak alfabetik çıktı alamayız.
void	ft_sort(char *s, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] > s[j])
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// ---------------------------------------------------------
//  BACKTRACKING
// ---------------------------------------------------------
// s:      Sıralanmış kaynak string (örn: "abc")
// res:    Sonucu inşa ettiğimiz geçici dizi (örn: "b..")
// used:   Hangi harfleri kullandığımızı tutan 1/0 dizisi
// depth:  Şu an kaçıncı karakteri yerleştiriyoruz?
// len:    Stringin toplam uzunluğu
void	ft_solve(char *s, char *res, int *used, int depth, int len)
{
	int	i;

	if (depth == len)
	{
		res[depth] = '\0';
		ft_putstr(res);
		return ;
	}
	i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			res[depth] = s[i];
			ft_solve(s, res, used, depth + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

// ---------------------------------------------------------
// MAIN FONKSİYONU
// ---------------------------------------------------------
int	main(int ac, char *av[])
{
	int		len;
	int		*used;
	char	*res;
	int		i;

	if (ac != 2)
		return (0);
	len = 0;
	while (av[1][len])
		len++;
	ft_sort(av[1], len);
	used = (int *)malloc(sizeof(int) * len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!used || !res)
		return (1);
	i = 0;
	while (i < len)
		used[i++] = 0;
	ft_solve(av[1], res, used, 0, len);
	free(used);
	free(res);
	return (0);
}
