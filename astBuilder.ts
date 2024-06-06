import { TokenType } from "./types";
import { Token } from "./scanner";
const jsdom = require("jsdom");
const { JSDOM } = jsdom;

interface AstNode {
   type: AstNodeType | TokenType;
   children: AstNode[];
   value?: string;
}

enum AstNodeType {
   PROGRAM = "PROGRAM",
   NUMBER = "NUMBER",
   EXPRESSION = "EXPRESSION",
   PARAMETERS = "PARAMETERS", // expr, expr, expr
   PARAMETER_LIST = "PARAMETER_LIST", // (expr, expr, expr) or ()
   FUNCTION_CALL = "FUNCTION_CALL",
   FUNCTION_DEFINITION = "FUNCTION_DEFINITION",
   BOOLEAN_EXPRESSION = "BOOLEAN_EXPRESSION",
   IF_STATEMENT = "IF_STATEMENT",
}

export function buildAst(tokens: Token[]): AstNode {
   const nodes = tokens.map(
      token =>
         ({
            type: token.type,
            children: [],
            value: token.value,
         } as AstNode)
   );

   const rules = [
      {
         from: [
            [AstNodeType.NUMBER, TokenType.PLUS, AstNodeType.NUMBER],
            [AstNodeType.NUMBER, TokenType.MINUS, AstNodeType.NUMBER],
            [AstNodeType.NUMBER, TokenType.MULTIPLY, AstNodeType.NUMBER],
            [AstNodeType.NUMBER, TokenType.DIVIDE, AstNodeType.NUMBER],
         ],
         to: AstNodeType.NUMBER,
      },

      {
         from: [[AstNodeType.EXPRESSION, TokenType.NEWLINE, AstNodeType.EXPRESSION]],
         to: AstNodeType.EXPRESSION,
      },
      {
         from: [[TokenType.STRING], [AstNodeType.FUNCTION_CALL]],
         to: AstNodeType.EXPRESSION,
      },
      {
         from: [
            [AstNodeType.NUMBER, TokenType.COMPARISON, AstNodeType.NUMBER],
            [TokenType.IDENTIFIER, TokenType.COMPARISON, TokenType.IDENTIFIER],
            [TokenType.IDENTIFIER, TokenType.COMPARISON, AstNodeType.NUMBER],
            [AstNodeType.NUMBER, TokenType.COMPARISON, TokenType.IDENTIFIER],
         ],
         to: AstNodeType.BOOLEAN_EXPRESSION,
      },
      {
         from: [
            [AstNodeType.EXPRESSION, TokenType.COMMA, AstNodeType.EXPRESSION],
            [AstNodeType.PARAMETERS, TokenType.COMMA, AstNodeType.EXPRESSION],
         ],
         to: AstNodeType.PARAMETERS,
      },
      {
         from: [
            [
               TokenType.IF,
               TokenType.LPAREN,
               AstNodeType.BOOLEAN_EXPRESSION,
               TokenType.RPAREN,
               TokenType.LBRA,
               AstNodeType.EXPRESSION,
               TokenType.RBRA,
            ],
         ],
         to: AstNodeType.IF_STATEMENT,
      },
      {
         from: [[AstNodeType.IF_STATEMENT]],
         to: AstNodeType.EXPRESSION,
      },
      {
         from: [
            [
               TokenType.IDENTIFIER,
               AstNodeType.PARAMETER_LIST,
               TokenType.LBRA,
               AstNodeType.EXPRESSION,
               TokenType.RBRA,
            ],
         ],
         to: AstNodeType.FUNCTION_DEFINITION,
      },

      {
         from: [
            [TokenType.IDENTIFIER, AstNodeType.PARAMETER_LIST],
            [TokenType.IDENTIFIER, TokenType.LPAREN, TokenType.RPAREN],
            [TokenType.IDENTIFIER, TokenType.LPAREN, AstNodeType.EXPRESSION, TokenType.RPAREN],
         ],
         to: AstNodeType.FUNCTION_CALL,
      },
      {
         from: [[TokenType.LPAREN, AstNodeType.PARAMETERS, TokenType.RPAREN]],

         to: AstNodeType.PARAMETER_LIST,
      },

      {
         from: [[TokenType.LPAREN, TokenType.RPAREN]],
         to: AstNodeType.PARAMETER_LIST,
      },

      {
         from: [[TokenType.LPAREN, AstNodeType.PARAMETER_LIST, TokenType.RPAREN]],
         to: AstNodeType.EXPRESSION,
      },
      {
         from: [[AstNodeType.NUMBER]],
         to: AstNodeType.EXPRESSION,
      },

      {
         from: [[AstNodeType.EXPRESSION]],
         to: AstNodeType.PROGRAM,
      },
   ] as {
      from: (TokenType | AstNodeType)[][];
      to: AstNodeType;
   }[];

   while (nodes.length > 1 || nodes[0].type !== AstNodeType.PROGRAM) {
      let match_found = false;
      console.log("[", nodes.map(n => n.type).join(", "), "]");
      for (const rule of rules) {
         for (let from_combination of rule.from) {
            for (let offset = 0; offset <= nodes.length - from_combination.length; offset++) {
               const match = from_combination.every((type, i) => nodes[offset + i].type === type);
               if (match) {
                  match_found = true;

                  const newNode = {
                     type: rule.to,
                     children: nodes.slice(offset, offset + from_combination.length),
                     value: undefined,
                  };
                  nodes.splice(offset, from_combination.length, newNode);
                  break;
               }
            }
            if (match_found) {
               break;
            }
         }
         if (match_found) {
            break;
         }
      }

      if (!match_found) {
         throw new Error("No matching rule found for [" + nodes.map(n => n.type).join(", ") + "]");
      }
   }

   console.log("-----------------");
   console.log(JSON.stringify(beautifyAstFormat(nodes[0]), null, 3));
   console.log("-----------------");

   return nodes[0];
}

function beautifyAstFormat(ast: AstNode): Record<string, any> {
   const dom = new JSDOM(`<!DOCTYPE html><html><body></body></html>`);
   const document = dom.window.document;

   const visit = (node: AstNode, parent: HTMLElement) => {
      const element = document.createElement(node.type);
      if (node.value) {
         element.textContent = node.value;
      }
      parent.appendChild(element);
      node.children.forEach(child => visit(child, element));
   };

   visit(ast, document.body);

   const xml = dom.window.document.body.innerHTML;
   console.log(xml);

   return ast;
}
