class a {
	int b, c;
};
::a d();
::a (::d)();
::a (::d()) {
	::a e;
	return e;
}
