import { scan } from "./scanner";
import { buildAst } from "./astBuilder";
import { toXML } from "jstoxml";
const fs = require("fs");

(function main(args: string[]) {
   if (args.length < 3) {
      console.log("Usage: ts-node compiler.ts <src_file>");
      process.exit(1);
   }

   const src_file = args[2];

   if (!fs.existsSync(src_file)) {
      console.log(`File ${src_file} does not exist`);
      process.exit(1);
   }

   const srcCode = fs.readFileSync(src_file, "utf-8");
   console.log("STEP 0:", srcCode);
   const tokens = scan(srcCode);
   console.log("STEP 1:", tokens);
   const ast = buildAst(tokens);
   console.log("STEP 2:", ast);

   const ast_json = JSON.stringify(ast, null, 3);

   //  convert json to xml
   const xml = toXML({ root: ast });

   console.log(xml);
})(process.argv);
