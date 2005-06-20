namespace a {
	namespace b {
		char c;
	}
}

namespace d {
	using namespace a::b;

	char e = c;
	char f = a::b::c;
	char g = a::c;
	char h = b::c;
}
