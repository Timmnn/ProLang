const ProLexer = require("./ProLexer.ts").default;
const ProParser = require("./ProParser.ts").default;
const ProListener = require("./ProListener.ts").default;
const fs = require("fs");
const antlr4 = require("antlr4").default;
const { DefaultErrorStrategy } = require("antlr4");
var clc = require("cli-color");

const example_files = fs.readdirSync("prolang_examples");
class ErrorListener extends antlr4.error.ErrorListener {
   constructor(errorCallback) {
      super();
      this.errorCallback = errorCallback;
   }

   syntaxError(recognizer, offendingSymbol, line, column, msg, e) {
      this.errorCallback(`line ${line}:${column} ${msg} ${offendingSymbol.text}`);
   }
}

const failed_examples = [];
for (const example_file_name of example_files) {
   function onError(msg) {
      failed_examples.push({ example_file_name, msg });
   }
   const example_file_path = `prolang_examples/${example_file_name}`;
   console.log(`Processing ${example_file_path}`);
   const input = fs.readFileSync(example_file_path, "utf-8");
   console.log("Input: '" + input + "'");
   const errorListener = new ErrorListener(onError);
   const chars = new antlr4.InputStream(input);
   const lexer = new ProLexer(chars);
   lexer.removeErrorListeners(); // remove default error listener
   lexer.addErrorListener(errorListener); // add custom error listener

   const tokens = new antlr4.CommonTokenStream(lexer);
   const parser = new ProParser(tokens);
   parser.removeErrorListeners(); // remove default error listener
   parser.addErrorListener(errorListener); // add custom error listener

   const tree = parser.prog();

   const printer = new ProListener();

   antlr4.tree.ParseTreeWalker.DEFAULT.walk(printer, tree);

   // Output tree:
   const tree_str = tree.toStringTree(parser.ruleNames);
   //console.log(tree_str);
   console.log(formatAst(tree_str));
   example_file_name !== example_files.at(-1) && console.log("-".repeat(80));
}

if (failed_examples.length > 0) {
   console.log("Failed examples:");
   for (const { example_file_name, msg } of failed_examples) {
      console.log(clc.red(`  ${example_file_name}: ${msg}`));
   }
}

function formatAst(ast: string) {
   const paren_colors = [
      clc.green,
      clc.yellow,
      clc.magenta,
      clc.cyan,
      clc.red,
      clc.blue,
      clc.white,
   ];

   let line_by_line = ast.split(" ").map(line => {
      // if ends with ')', insert newline
      if (line.endsWith(")")) {
         return line.replace(")", "\n)");
      }

      return line;
   });

   line_by_line = line_by_line.join("\n").split("\n");

   while (line_by_line.some(line => line.includes("))"))) {
      line_by_line = line_by_line
         .map(line => {
            line = line.replace("))", ")\n)");
            return line.split("\n");
         })
         .flat();
   }

   const indented_lines = [];

   let indent = 0;
   for (let i = 0; i < line_by_line.length; i++) {
      let line = line_by_line[i];
      const prev_line = line_by_line[i - 1];
      if (prev_line?.startsWith("(")) {
         indent += 1;
      }

      if (line.endsWith(")")) {
         indent -= 1;
      }

      line = paren_colors[indent % paren_colors.length](line);

      const indented_line = "   ".repeat(indent) + line;
      indented_lines.push(indented_line);
   }

   const formatted_ast = indented_lines.join("\n");
   return formatted_ast;
}
