namespace a {
	char b;
}

namespace c {
	using namespace a;
}

using namespace c;
char d = b;
