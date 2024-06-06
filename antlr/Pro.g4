grammar Pro;		
prog:	statement+ EOF ;
function_declaration : ID ID '(' ')' block ;

expr_list: expr (',' expr)* ;
expr:	expr ('*'|'/'|'+'|'-') expr
    |	INT
    |	ID
    |  '-' expr
    |  function_call
    |  array_construction
    |  CHAR
    |  STRING
    ;
assignment: ID ASSIGN expr ;
statement: assignment | expr | function_declaration ;
function_call: (ID '(' ')') | (ID '(' expr_list ')') ;

INT     : [0-9]+ ;
CHAR    : '\'' ( 'a'..'z' | 'A'..'Z' | ' ' | ',' ) '\'' ;
STRING : '"' ( ESCAPE_SEQ | ~["\\] )* '"' ;

fragment ESCAPE_SEQ
    : '\\' [btnr"\\]
    ;ID      : [a-zA-Z]+ ;
array_construction   : '[' expr_list ']' ;
ASSIGN  : '=' ;
WS      : [ \t]+ -> skip ;
NEWLINE : [\r\n]+ -> skip;
block: '{' statement* '}' ;
