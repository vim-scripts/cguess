class a {
	static int b;
	class c {
	public:
		int d();
	};
};
int a::c::d() {
	return b;
}
