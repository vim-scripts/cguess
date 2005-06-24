struct a {
	union {
		int b;
		int c;
	};
	int d = b;
};
