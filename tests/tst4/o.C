class x {
public:
	static int a;
};
typedef x c;
namespace y {
	class x typedef q;
	class x static r;
	class x t;
	class x {
	public:
		static int b;
	};
	class x u;
	class ::x v;
	void f() {
		int i = t.a;
		int j = u.b;
		int k = v.a;
		int l = r.a;
		q s;
	}
}
