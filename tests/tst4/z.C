int a;
int b();
namespace c {
	int d;
	int b() {
		return a + d;
	}
	int ::b() {
		return a + d;
	}
};
