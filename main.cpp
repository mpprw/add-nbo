#include <stdio.h> // for printf
#include <stdint.h>

uint32_t my_ntohs(uint32_t a) {
	return (a & 0xff) << 24 | (a & 0xff00) << 8 | (a & 0xff0000) >> 8 | (a & 0xff000000) >> 24;
}


int main(int argc, char **argv) {
	FILE *fp1, *fp2;
	uint32_t first, second;

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	fread(&first, sizeof(first), 1, fp1);
	fread(&second, sizeof(second), 1, fp2);

	first = my_ntohs(first);
	second = my_ntohs(second);
	uint32_t result = first + second;

	printf("%d(%#x) + %d(%#x) = %d(%#x)\n", first, first, second, second, result, result);

	return 0;
}


