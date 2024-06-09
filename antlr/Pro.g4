grammar Pro;		
prog:	statement+ EOF ;
array_access: ID '[' INT ']' ;
COMMENT : '//' ~[\r\n]* -> skip ;
function_declaration : ID ID '(' parameter_list? ')' block ;
parameter: ID':'ID ;
parameter_list: parameter (',' parameter)* ; // eg a:int, b:char
expr_list: expr (',' expr)* ;
expr:	expr ('*'|'/'|'+'|'-') expr
    |	INT
    |  '-' expr
    |  function_call
    |  array_access
    |  array_construction
    |  ID
    |  CHAR
    |  STRING
    |  cast
    ;
assignment: ID ASSIGN expr ;
statement: assignment | expr | function_declaration | return_statement ;
return_statement: 'return' expr ;

cast: '(' ID ')' expr ;



function_call: (ID '(' ')') | (ID '(' expr_list ')') ;

INT     : [0-9]+ ;
CHAR    : '\'' ( 'a'..'z' | 'A'..'Z' | ' ' | ',' ) '\'' ;
STRING : '"' ( ESCAPE_SEQ | ~["\\] )* '"' ;

fragment ESCAPE_SEQ
    : '\\' [btnr"\\]
    ;
ID      : [a-zA-Z_]+ ;
ASSIGN  : '=' ;
WS      : [ \t]+ -> skip ;
NEWLINE : [\r\n]+ -> skip;
block: '{' statement* '}' ;
array_construction   : '[' expr_list ']' ;
