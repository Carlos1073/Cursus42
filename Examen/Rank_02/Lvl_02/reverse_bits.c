#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
	octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
	octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
	return (octet);
}

/*
unsigned char reverse_bits(unsigned char octet)
{
	octet = (octet * 0x0202020202ULL & 0x010884422010ULL) % 0x3ff;
	return (octet);
}
*/
int	main(void)
{
	unsigned char c;
	c = 't';

	c = reverse_bits(c);

	write(1, &c, 1);
	write(1, "\n", 1);
}