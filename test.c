#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char	*str;
	int		rd;

	str = get_next_line(0);
	printf("%s\n", str);
}