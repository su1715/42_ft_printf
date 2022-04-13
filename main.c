#include "ft_printf.h"
#include <stdio.h>

int main() {
	int a = 0;
	ft_printf("%% %c %s %i %d %u %p %x %X \n",'z',"abcde",2147483648,2147483648,(unsigned int) -1, &a, 16, 16);
	printf("%% %c %s %i %d %u %p %x %X",'z',"abcde",2147483648,2147483648,(unsigned int) -1, &a, 16, 16);
}