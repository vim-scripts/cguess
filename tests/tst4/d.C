namespace b {
	namespace {
		char a = 'a';
	}
}

char c() {
	return b::a;
}
