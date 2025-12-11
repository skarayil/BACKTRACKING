#include <string.h>
#include <unistd.h>

// 1. Yardımcı Fonksiyon: Stringi Yazdır
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

// ---------------------------------------------------------
//  KONTROL
// ---------------------------------------------------------
// String şu haliyle dengeli mi?
// Boşlukları görmezden gelerek sayar.
// ( : Sayacı artır
// ) : Sayacı azalt. Eğer sayaç eksiye düşerse geçersizdir.
int	ft_check(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
		{
			count--;
			if (count < 0)
				return (0);
		}
		i++;
	}
	return (count == 0);
}

// ---------------------------------------------------------
//  HEDEF BELİRLEME
// ---------------------------------------------------------
// En az kaç tane silmemiz lazım?
// Bu fonksiyon recursion'a girmeden önce hedefi belirler.
// left: Fazladan açık parantez sayısı
// right: Fazladan kapalı parantez sayısı
// Return: Toplam silinmesi gereken sayı
int	ft_removal(char *s)
{
	int	left;
	int	right;
	int	i;

	left = 0;
	right = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			left++;
		else if (s[i] == ')')
		{
			if (left > 0)
				left--;
			else
				right++;
		}
		i++;
	}
	return (left + right);
}

// ---------------------------------------------------------
// BACKTRACKING
// ---------------------------------------------------------
// s: String
// n: Toplam silinmesi gereken hedef sayı (must)
// removed: Şu ana kadar kaç tane sildik?
// idx: Hangi indeksteyiz? (Geriye dönmemek için)
void	ft_solve(char *s, int n, int removed, int index)
{
	int		i;
	char	backup;

	if (removed == n)
	{
		if (ft_check(s))
			ft_putstr(s);
		return ;
	}
	i = index;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == ')')
		{
			backup = s[i];
			s[i] = ' ';
			ft_solve(s, n, removed + 1, i + 1);
			s[i] = backup;
		}
		i++;
	}
}

// ---------------------------------------------------------
// MAIN FONKSİYONU
// ---------------------------------------------------------
int	main(int ac, char *av[])
{
	int	target;

	if (ac != 2)
		return (0);
	target = ftremoval(av[1]);
	ft_solve(av[1], target, 0, 0);
	return (0);
}
