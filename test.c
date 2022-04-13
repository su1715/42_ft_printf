#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_print_string(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

static int	ft_digit_len(int n)
{
	int	temp;
	int	len;

	temp = n;
	len = 0;
	if (n < 0)
		len = 1;
	while (temp / 10)
	{
		len++;
		temp /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = ft_digit_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		if (n == -2147483648)
		{
			res[len--] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (n / 10)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	res[len--] = n + '0';
	return (res);
}

int	ft_print_HEX(size_t num)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_print_HEX(num / 16);
	num %= 16;
	len += ft_print_char("0123456789ABCDEF"[num]);
	return len;
}

int	ft_print_hex(size_t num)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_print_hex(num / 16);
	num %= 16;
	len += ft_print_char("0123456789abcdef"[num]);
	return len;
}

int	ft_print_pointer(void *ptr)
{
	int			len;
	size_t	num;

	len = 0;
	num = (size_t)ptr;
	len += write(1, "0x", 2);
	len += ft_print_HEX(num);
	return (len);
}

int	ft_print_decimal(int num)
{
	int	len;

	len += ft_print_string(ft_itoa(num));
	return len;
}

int	ft_print_unsigned(unsigned int num) {
	int	len;

	len = 0;
	if (num >= 10)
		len += ft_print_unsigned(num / 10);
	num %= 10;
	len += ft_print_char("0123456789"[num]);
	return (len);
}

int main() {
	int a = 0;
	int len = 0;
	// printf("%p\n", &a);
	// len = ft_print_pointer(&a);
	// printf("%d\n", len);
	// len = ft_print_decimal(2147483647);
	// printf(" %d\n", len);
	unsigned int k = -1;
	printf("%d\n", (int)2147483648);
	ft_print_decimal(-2147483648);
	//ft_print_unsigned(k);
}