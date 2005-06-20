%{
	#include <stdio.h>
%}
%token x y
%debug
%%

nested_x:
	x
|	y x
|	y s x
|	s x
;

s:
	x y
|	s x y
;
%%
int yylex() {
	char c[100];
	if (scanf("%s", c) < 1)
		return EOF;
	if (*c == 'x')
		return x;
	return y;
}
int yyerror(char *s) {
	printf("%s\n", s);
}
int main(int argc, char *argv[]) {
	yydebug = 0;
	return yyparse();
}
