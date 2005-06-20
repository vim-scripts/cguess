namespace a {
}
namespace b = a;
namespace a {
	int c, d = b::c;
}
