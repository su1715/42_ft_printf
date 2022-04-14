#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
	char	*str;

	str = malloc(INT_MAX + 2L);
	for (long i = 0; i < INT_MAX + 1L; i++)
		str[i] = '1';
	str[INT_MAX + 1L] = '\0';
	printf("%d\n", ft_printf("%s\n", str));
}