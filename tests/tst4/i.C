class x {
public:
	static int a;
};
namespace y {
	x;
	class x *u;
	class x {
	public:
		static int b;
	};
	void f() {
		int j = u->b;
	}
}
