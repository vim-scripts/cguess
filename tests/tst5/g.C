template <typename a>
class b {
public:
	template <typename c>
	class d {
	public:
		static int e;
	};
};
int printf(char *format, ...);
int main(int argc, char *argv[]) {
	b<int>::d<int> a0;
	b<int>::d<char> a1;
	b<char>::d<int> a2;
	b<char>::d<char> a3;
	a0.e = a1.e = a2.e = a3.e = 0;
	printf("%i %i %i %i\n", a0.e, a1.e, a2.e, a3.e);
	a0.e = 1;
	printf("%i %i %i %i\n", a0.e, a1.e, a2.e, a3.e);
	a1.e = 1;
	printf("%i %i %i %i\n", a0.e, a1.e, a2.e, a3.e);
	a2.e = 1;
	printf("%i %i %i %i\n", a0.e, a1.e, a2.e, a3.e);
	a3.e = 1;
	printf("%i %i %i %i\n", a0.e, a1.e, a2.e, a3.e);
}
