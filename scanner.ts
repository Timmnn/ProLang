import { TokenType } from "./types.ts";

export class Token {
   constructor(public type: string, public value?: string) {}
}

export function scan(srcCode: string): Token[] {
   let tokens: Token[] = [];

   srcCode = srcCode.replace(/ /g, "");

   let patterns: {
      [K in TokenType]: RegExp;
   } = {
      PLUS: /^\+/,
      MINUS: /^-/,
      MULTIPLY: /^\*/,
      DIVIDE: /^\//,
      NUMBER: /^[0-9]+/,
      LPAREN: /^\(/,
      RPAREN: /^\)/,
      NEWLINE: /^\n/,
      STRING: /^"[^"]*"/,
      COMMA: /^,/,
      LBRA: /^\{/,
      RBRA: /^\}/,
      COMPARISON: /^(==|!=|<=|>=|<|>)/,
      IF: /^if/,
      IDENTIFIER: /^[a-zA-Z_][a-zA-Z0-9_]*/,
   };

   let actions = {
      PLUS: () => new Token(TokenType.PLUS),
      MINUS: () => new Token(TokenType.MINUS),
      MULTIPLY: () => new Token(TokenType.MULTIPLY),
      DIVIDE: () => new Token(TokenType.DIVIDE),
      NUMBER: (value: string) => new Token(TokenType.NUMBER, value),
      LPAREN: () => new Token(TokenType.LPAREN),
      RPAREN: () => new Token(TokenType.RPAREN),
      IDENTIFIER: (value: string) => new Token(TokenType.IDENTIFIER, value),
      NEWLINE: () => new Token(TokenType.NEWLINE),
      STRING: (value: string) => new Token(TokenType.STRING, value.replace(/"/g, "")),
      COMMA: () => new Token(TokenType.COMMA),
      LBRA: () => new Token(TokenType.LBRA),
      RBRA: () => new Token(TokenType.RBRA),
      COMPARISON: (value: string) => new Token(TokenType.COMPARISON, value),
      IF: () => new Token(TokenType.IF),
   } as {
      [K in TokenType]: Function;
   };

   let code_left = srcCode;

   while (code_left.length > 0) {
      let found = false;
      for (let type in patterns) {
         let pattern = patterns[type as TokenType];
         let result = pattern.exec(code_left);
         if (result) {
            const action = actions[type as TokenType] as Function;
            const token = action(result[0]) as Token;

            tokens.push(token);
            code_left = code_left.slice(result[0].length);

            found = true;
            break;
         }
      }
      if (!found) {
         throw new Error("No matching token found for " + code_left);
      }
   }
   return tokens;
}
