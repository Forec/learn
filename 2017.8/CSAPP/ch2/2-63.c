int w = sizeof(int) << 3;

unsigned srl(unsigned x, int k) {
	unsigned xsra = (int x) >> k;
	return xsra & ((1 << (w - k)) - 1);
}

int sra(int x, int k) {
	int xsrl = (unsigned) x >> k;
	int sign = ((1 << (w - k - 1)) & xsrl) << 1;
	int mask = ~((1 << (w - k)) - 1);
	int higher = mask + (sign ^ (1 << (w - k)));
	return higher + xsrl;
}