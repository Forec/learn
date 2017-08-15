int rightmost_one(unsigned x) {
	return ~((~x + 1) | x) + 1;
}

int leftmost_one(unsigned x) {
	
}