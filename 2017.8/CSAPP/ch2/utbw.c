#include <stdio.h>

void show_bytes(char * p, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%x ", p[i]);
	}
}

int main() {
	short sx = -12345;
	unsigned short usx = sx;
	int x = sx;
	unsigned ux = usx;
	
	printf("sx = %d:\t", sx);
	show_bytes((char *)&sx, sizeof(short));
	
	printf("usx = %u:\t", usx);
	show_bytes((char *)&usx, sizeof(unsigned short));
	
	printf("x = %d:\t", x);
	show_bytes((char *)&x, sizeof(int));
	
	printf("ux = %u:\t", ux);
	show_bytes((char *)&ux, sizeof(unsigned));
	
	return 0;
}