class a {
public:
	int operator+(int x);
};
int a::operator+(int x) {
	return a::operator-(x);
}
