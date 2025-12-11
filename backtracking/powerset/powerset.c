#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Çözümü yazdırma fonksiyonu
void	ft_print(int *buffer, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d", buffer[i]);
		if (i < len - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

// ---------------------------------------------------------
// BACKTRACKING
// ---------------------------------------------------------
// arr:    Kaynak sayı dizisi
// size:   Dizinin toplam boyutu
// target: Ulaşmaya çalıştığımız hedef sayı
// idx:    Şu an dizinin kaçıncı elemanına karar veriyoruz?
// buffer: Seçtiğimiz sayıları tuttuğumuz geçici dizi
// b_len:  Buffer'da şu an kaç sayı var?
// sum:    Buffer'daki sayıların o anki toplamı
void	ft_solve(int *arr, int size, int target, int index, int *buffer,
		int b_len, int sum)
{
	if (index == size)
	{
		if (sum == target)
			ft_print(buffer, b_len);
		return ;
	}
	buffer[b_len] = arr[index];
	ft_solve(arr, size, target, index + 1, buffer, b_len + 1, sum + arr[index]);
	ft_solve(arr, size, target, index + 1, buffer, b_len, sum);
}

// ---------------------------------------------------------
// MAIN FONKSİYONU
// ---------------------------------------------------------
int	main(int ac, char *av[])
{
	int	target;
	int	*arr;
	int	*buffer;
	int	len;
	int	i;

	if (ac < 2)
		return (0);
	target = atoi(av[1]);
	len = ac - 2;
	arr = (int *)malloc(sizeof(int) * len);
	buffer = (int *)malloc(sizeof(int) * len);
	if (!arr || !buffer)
		return (1);
	i = 0;
	while (i < len)
	{
		arr[i] = atoi(av[i + 2]);
		i++;
	}
	solve(arr, len, target, 0, buffer, 0, 0);
	free(arr);
	free(buffer);
	return (0);
}
