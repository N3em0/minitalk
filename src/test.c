// #include <stdio.h>
// #include <string.h>

// void	binaryToAscii(const char *binaryString)
// {
// 	int		value;
// 	char	asciiChar;
// 	int		i;

// 	value = 0;
// 	i = 0;
// 	while (i < 8 && binaryString[i])
// 	{
// 		value = (value << 1) | (binaryString[i++] - '0');
// 	}
// 	asciiChar = (char)value;
// 	printf("char : %c, Valeur ascii : %d\n", asciiChar, value);
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 	{
// 		printf("utilisation : %s chaine_binaire\n", argv[0]);
// 		return (1);
// 	}
// 	binaryToAscii(argv[1]);
// 	return (0);
// }
int main (void)
{
	int c = 97;
	printf("%c", c);
	return 0;
}
