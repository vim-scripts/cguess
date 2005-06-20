struct str typedef tpdf;
struct str typedef tpd2;
struct str {
	int a;
};
class a {
	class b {};
/*	a (a&); * Constructor */
	tpdf (tpd2);
/*	tpdf (tpdf&); * Variable */
};
/*
a x:		variable
a (x):		error
a (int x):	function
(a):		error
(a) (x):	error
(a) (int x):	function
tpdf x:		variable
tpdf (x):	variable
tpdf (int x):	error
(tpdf):		error
(tpdf) (x):	error
(tpdf) (int x):	error

		class	type	id	cguess

t		ok	ok	var	ok
t x		var	var	error	var
t T		var	var	var	var
t (x)		error	var	error	var
t (T)		func	var	func	var and if t == parent, func
t (int x)	func	error	func	func
(t)		error	error	var	var
(t) (x)		error	error	error	func
(t) (T)		func	error	func	func
(t) (int x)	func	error	func	func


member_declaration:
	DECL_SPECIFIER_SEQ T_SEMIC
|	OBVIOUSLY_A_DECLARATOR T_SEMIC /not a list/
|	DECL_SPECIFIER_SEQ 

obviously_a_declarator:
	( something
|	* something
|	identifier something
;
*/
