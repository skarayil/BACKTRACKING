#include <stdlib.h>
#include <unistd.h>

// Global değişken: N sayısını her fonksiyona taşımamak için buraya koyduk.
int		g_n;

// Sayıları yazdırmak için yardımcı fonksiyon
void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

// ---------------------------------------------------------
// ÇÖZÜMÜ YAZDIRMA
// ---------------------------------------------------------
// board dizisi sütunları, içindeki değerler satırları temsil eder.
// Örnek: board[0] = 2 -> 0. Sütundaki vezir 2. Satırda.
void	ft_print(int *board)
{
	int	i;

	i = 0;
	while (i < g_n)
	{
		if (i > 0)
			write(1, " ", 1);
		ft_putnbr(board[i]);
		i++;
	}
	write(1, "\n", 1);
}

// ---------------------------------------------------------
// KISITLAMA - GÜVENLİK KONTROLÜ
// ---------------------------------------------------------
// "col" sütununa ve "row" satırına vezir koyarsam,
// sol taraftaki önceki vezirler beni yer mi?
int	ft_safe(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (abs(board[i] - row) == abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

// ---------------------------------------------------------
//  BACKTRACKING
// ---------------------------------------------------------
// col: Şu an kaçıncı sütunu çözmeye çalışıyoruz?
void	ft_solve(int *board, int col)
{
	int	row;

	if (col == g_n)
	{
		ft_print(board);
		return ;
	}
	row = 0;
	while (row < g_n)
	{
		if (ft_safe(board, col, row))
		{
			board[col] = row;
			ft_solve(board, col + 1);
		}
		row++;
	}
}

// ---------------------------------------------------------
// MAIN FONKSİYONU
// ---------------------------------------------------------
int	main(int ac, char *av[])
{
	int	board[g_n];

	if (ac != 2)
		return (0);
	g_n = atoi(av[1]);
	if (g_n <= 0)
		return (0);
	ft_solve(board, 0);
	return (0);
}
