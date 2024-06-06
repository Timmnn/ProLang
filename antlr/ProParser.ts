// Generated from antlr/Pro.g4 by ANTLR 4.13.1
// noinspection ES6UnusedImports,JSUnusedGlobalSymbols,JSUnusedLocalSymbols

import {
	ATN,
	ATNDeserializer, DecisionState, DFA, FailedPredicateException,
	RecognitionException, NoViableAltException, BailErrorStrategy,
	Parser, ParserATNSimulator,
	RuleContext, ParserRuleContext, PredictionMode, PredictionContextCache,
	TerminalNode, RuleNode,
	Token, TokenStream,
	Interval, IntervalSet
} from 'antlr4';
// for running tests with parameters, TODO: discuss strategy for typed parameters in CI
// eslint-disable-next-line no-unused-vars
type int = number;

export default class ProParser extends Parser {
	public static readonly T__0 = 1;
	public static readonly T__1 = 2;
	public static readonly T__2 = 3;
	public static readonly T__3 = 4;
	public static readonly T__4 = 5;
	public static readonly T__5 = 6;
	public static readonly T__6 = 7;
	public static readonly T__7 = 8;
	public static readonly T__8 = 9;
	public static readonly T__9 = 10;
	public static readonly T__10 = 11;
	public static readonly INT = 12;
	public static readonly CHAR = 13;
	public static readonly STRING = 14;
	public static readonly ID = 15;
	public static readonly ASSIGN = 16;
	public static readonly WS = 17;
	public static readonly NEWLINE = 18;
	public static readonly EOF = Token.EOF;
	public static readonly RULE_prog = 0;
	public static readonly RULE_function_declaration = 1;
	public static readonly RULE_expr_list = 2;
	public static readonly RULE_expr = 3;
	public static readonly RULE_assignment = 4;
	public static readonly RULE_statement = 5;
	public static readonly RULE_function_call = 6;
	public static readonly RULE_array_construction = 7;
	public static readonly RULE_block = 8;
	public static readonly literalNames: (string | null)[] = [ null, "'('", 
                                                            "')'", "','", 
                                                            "'*'", "'/'", 
                                                            "'+'", "'-'", 
                                                            "'['", "']'", 
                                                            "'{'", "'}'", 
                                                            null, null, 
                                                            null, null, 
                                                            "'='" ];
	public static readonly symbolicNames: (string | null)[] = [ null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             "INT", "CHAR", 
                                                             "STRING", "ID", 
                                                             "ASSIGN", "WS", 
                                                             "NEWLINE" ];
	// tslint:disable:no-trailing-whitespace
	public static readonly ruleNames: string[] = [
		"prog", "function_declaration", "expr_list", "expr", "assignment", "statement", 
		"function_call", "array_construction", "block",
	];
	public get grammarFileName(): string { return "Pro.g4"; }
	public get literalNames(): (string | null)[] { return ProParser.literalNames; }
	public get symbolicNames(): (string | null)[] { return ProParser.symbolicNames; }
	public get ruleNames(): string[] { return ProParser.ruleNames; }
	public get serializedATN(): number[] { return ProParser._serializedATN; }

	protected createFailedPredicateException(predicate?: string, message?: string): FailedPredicateException {
		return new FailedPredicateException(this, predicate, message);
	}

	constructor(input: TokenStream) {
		super(input);
		this._interp = new ParserATNSimulator(this, ProParser._ATN, ProParser.DecisionsToDFA, new PredictionContextCache());
	}
	// @RuleVersion(0)
	public prog(): ProgContext {
		let localctx: ProgContext = new ProgContext(this, this._ctx, this.state);
		this.enterRule(localctx, 0, ProParser.RULE_prog);
		let _la: number;
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 19;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			do {
				{
				{
				this.state = 18;
				this.statement();
				}
				}
				this.state = 21;
				this._errHandler.sync(this);
				_la = this._input.LA(1);
			} while ((((_la) & ~0x1F) === 0 && ((1 << _la) & 61824) !== 0));
			this.state = 23;
			this.match(ProParser.EOF);
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}
	// @RuleVersion(0)
	public function_declaration(): Function_declarationContext {
		let localctx: Function_declarationContext = new Function_declarationContext(this, this._ctx, this.state);
		this.enterRule(localctx, 2, ProParser.RULE_function_declaration);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 25;
			this.match(ProParser.ID);
			this.state = 26;
			this.match(ProParser.ID);
			this.state = 27;
			this.match(ProParser.T__0);
			this.state = 28;
			this.match(ProParser.T__1);
			this.state = 29;
			this.block();
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}
	// @RuleVersion(0)
	public expr_list(): Expr_listContext {
		let localctx: Expr_listContext = new Expr_listContext(this, this._ctx, this.state);
		this.enterRule(localctx, 4, ProParser.RULE_expr_list);
		let _la: number;
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 31;
			this.expr(0);
			this.state = 36;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			while (_la===3) {
				{
				{
				this.state = 32;
				this.match(ProParser.T__2);
				this.state = 33;
				this.expr(0);
				}
				}
				this.state = 38;
				this._errHandler.sync(this);
				_la = this._input.LA(1);
			}
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}

	public expr(): ExprContext;
	public expr(_p: number): ExprContext;
	// @RuleVersion(0)
	public expr(_p?: number): ExprContext {
		if (_p === undefined) {
			_p = 0;
		}

		let _parentctx: ParserRuleContext = this._ctx;
		let _parentState: number = this.state;
		let localctx: ExprContext = new ExprContext(this, this._ctx, _parentState);
		let _prevctx: ExprContext = localctx;
		let _startState: number = 6;
		this.enterRecursionRule(localctx, 6, ProParser.RULE_expr, _p);
		let _la: number;
		try {
			let _alt: number;
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 48;
			this._errHandler.sync(this);
			switch ( this._interp.adaptivePredict(this._input, 2, this._ctx) ) {
			case 1:
				{
				this.state = 40;
				this.match(ProParser.INT);
				}
				break;
			case 2:
				{
				this.state = 41;
				this.match(ProParser.ID);
				}
				break;
			case 3:
				{
				this.state = 42;
				this.match(ProParser.T__6);
				this.state = 43;
				this.expr(5);
				}
				break;
			case 4:
				{
				this.state = 44;
				this.function_call();
				}
				break;
			case 5:
				{
				this.state = 45;
				this.array_construction();
				}
				break;
			case 6:
				{
				this.state = 46;
				this.match(ProParser.CHAR);
				}
				break;
			case 7:
				{
				this.state = 47;
				this.match(ProParser.STRING);
				}
				break;
			}
			this._ctx.stop = this._input.LT(-1);
			this.state = 55;
			this._errHandler.sync(this);
			_alt = this._interp.adaptivePredict(this._input, 3, this._ctx);
			while (_alt !== 2 && _alt !== ATN.INVALID_ALT_NUMBER) {
				if (_alt === 1) {
					if (this._parseListeners != null) {
						this.triggerExitRuleEvent();
					}
					_prevctx = localctx;
					{
					{
					localctx = new ExprContext(this, _parentctx, _parentState);
					this.pushNewRecursionContext(localctx, _startState, ProParser.RULE_expr);
					this.state = 50;
					if (!(this.precpred(this._ctx, 8))) {
						throw this.createFailedPredicateException("this.precpred(this._ctx, 8)");
					}
					this.state = 51;
					_la = this._input.LA(1);
					if(!((((_la) & ~0x1F) === 0 && ((1 << _la) & 240) !== 0))) {
					this._errHandler.recoverInline(this);
					}
					else {
						this._errHandler.reportMatch(this);
					    this.consume();
					}
					this.state = 52;
					this.expr(9);
					}
					}
				}
				this.state = 57;
				this._errHandler.sync(this);
				_alt = this._interp.adaptivePredict(this._input, 3, this._ctx);
			}
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.unrollRecursionContexts(_parentctx);
		}
		return localctx;
	}
	// @RuleVersion(0)
	public assignment(): AssignmentContext {
		let localctx: AssignmentContext = new AssignmentContext(this, this._ctx, this.state);
		this.enterRule(localctx, 8, ProParser.RULE_assignment);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 58;
			this.match(ProParser.ID);
			this.state = 59;
			this.match(ProParser.ASSIGN);
			this.state = 60;
			this.expr(0);
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}
	// @RuleVersion(0)
	public statement(): StatementContext {
		let localctx: StatementContext = new StatementContext(this, this._ctx, this.state);
		this.enterRule(localctx, 10, ProParser.RULE_statement);
		try {
			this.state = 65;
			this._errHandler.sync(this);
			switch ( this._interp.adaptivePredict(this._input, 4, this._ctx) ) {
			case 1:
				this.enterOuterAlt(localctx, 1);
				{
				this.state = 62;
				this.assignment();
				}
				break;
			case 2:
				this.enterOuterAlt(localctx, 2);
				{
				this.state = 63;
				this.expr(0);
				}
				break;
			case 3:
				this.enterOuterAlt(localctx, 3);
				{
				this.state = 64;
				this.function_declaration();
				}
				break;
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}
	// @RuleVersion(0)
	public function_call(): Function_callContext {
		let localctx: Function_callContext = new Function_callContext(this, this._ctx, this.state);
		this.enterRule(localctx, 12, ProParser.RULE_function_call);
		try {
			this.state = 75;
			this._errHandler.sync(this);
			switch ( this._interp.adaptivePredict(this._input, 5, this._ctx) ) {
			case 1:
				this.enterOuterAlt(localctx, 1);
				{
				{
				this.state = 67;
				this.match(ProParser.ID);
				this.state = 68;
				this.match(ProParser.T__0);
				this.state = 69;
				this.match(ProParser.T__1);
				}
				}
				break;
			case 2:
				this.enterOuterAlt(localctx, 2);
				{
				{
				this.state = 70;
				this.match(ProParser.ID);
				this.state = 71;
				this.match(ProParser.T__0);
				this.state = 72;
				this.expr_list();
				this.state = 73;
				this.match(ProParser.T__1);
				}
				}
				break;
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}
	// @RuleVersion(0)
	public array_construction(): Array_constructionContext {
		let localctx: Array_constructionContext = new Array_constructionContext(this, this._ctx, this.state);
		this.enterRule(localctx, 14, ProParser.RULE_array_construction);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 77;
			this.match(ProParser.T__7);
			this.state = 78;
			this.expr_list();
			this.state = 79;
			this.match(ProParser.T__8);
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}
	// @RuleVersion(0)
	public block(): BlockContext {
		let localctx: BlockContext = new BlockContext(this, this._ctx, this.state);
		this.enterRule(localctx, 16, ProParser.RULE_block);
		let _la: number;
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 81;
			this.match(ProParser.T__9);
			this.state = 85;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			while ((((_la) & ~0x1F) === 0 && ((1 << _la) & 61824) !== 0)) {
				{
				{
				this.state = 82;
				this.statement();
				}
				}
				this.state = 87;
				this._errHandler.sync(this);
				_la = this._input.LA(1);
			}
			this.state = 88;
			this.match(ProParser.T__10);
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return localctx;
	}

	public sempred(localctx: RuleContext, ruleIndex: number, predIndex: number): boolean {
		switch (ruleIndex) {
		case 3:
			return this.expr_sempred(localctx as ExprContext, predIndex);
		}
		return true;
	}
	private expr_sempred(localctx: ExprContext, predIndex: number): boolean {
		switch (predIndex) {
		case 0:
			return this.precpred(this._ctx, 8);
		}
		return true;
	}

	public static readonly _serializedATN: number[] = [4,1,18,91,2,0,7,0,2,
	1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,7,7,2,8,7,8,1,0,4,0,20,
	8,0,11,0,12,0,21,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,5,2,35,8,2,
	10,2,12,2,38,9,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,49,8,3,1,3,1,3,
	1,3,5,3,54,8,3,10,3,12,3,57,9,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,3,5,66,8,5,
	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,76,8,6,1,7,1,7,1,7,1,7,1,8,1,8,5,8,
	84,8,8,10,8,12,8,87,9,8,1,8,1,8,1,8,0,1,6,9,0,2,4,6,8,10,12,14,16,0,1,1,
	0,4,7,94,0,19,1,0,0,0,2,25,1,0,0,0,4,31,1,0,0,0,6,48,1,0,0,0,8,58,1,0,0,
	0,10,65,1,0,0,0,12,75,1,0,0,0,14,77,1,0,0,0,16,81,1,0,0,0,18,20,3,10,5,
	0,19,18,1,0,0,0,20,21,1,0,0,0,21,19,1,0,0,0,21,22,1,0,0,0,22,23,1,0,0,0,
	23,24,5,0,0,1,24,1,1,0,0,0,25,26,5,15,0,0,26,27,5,15,0,0,27,28,5,1,0,0,
	28,29,5,2,0,0,29,30,3,16,8,0,30,3,1,0,0,0,31,36,3,6,3,0,32,33,5,3,0,0,33,
	35,3,6,3,0,34,32,1,0,0,0,35,38,1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,5,
	1,0,0,0,38,36,1,0,0,0,39,40,6,3,-1,0,40,49,5,12,0,0,41,49,5,15,0,0,42,43,
	5,7,0,0,43,49,3,6,3,5,44,49,3,12,6,0,45,49,3,14,7,0,46,49,5,13,0,0,47,49,
	5,14,0,0,48,39,1,0,0,0,48,41,1,0,0,0,48,42,1,0,0,0,48,44,1,0,0,0,48,45,
	1,0,0,0,48,46,1,0,0,0,48,47,1,0,0,0,49,55,1,0,0,0,50,51,10,8,0,0,51,52,
	7,0,0,0,52,54,3,6,3,9,53,50,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,1,
	0,0,0,56,7,1,0,0,0,57,55,1,0,0,0,58,59,5,15,0,0,59,60,5,16,0,0,60,61,3,
	6,3,0,61,9,1,0,0,0,62,66,3,8,4,0,63,66,3,6,3,0,64,66,3,2,1,0,65,62,1,0,
	0,0,65,63,1,0,0,0,65,64,1,0,0,0,66,11,1,0,0,0,67,68,5,15,0,0,68,69,5,1,
	0,0,69,76,5,2,0,0,70,71,5,15,0,0,71,72,5,1,0,0,72,73,3,4,2,0,73,74,5,2,
	0,0,74,76,1,0,0,0,75,67,1,0,0,0,75,70,1,0,0,0,76,13,1,0,0,0,77,78,5,8,0,
	0,78,79,3,4,2,0,79,80,5,9,0,0,80,15,1,0,0,0,81,85,5,10,0,0,82,84,3,10,5,
	0,83,82,1,0,0,0,84,87,1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,88,1,0,0,0,
	87,85,1,0,0,0,88,89,5,11,0,0,89,17,1,0,0,0,7,21,36,48,55,65,75,85];

	private static __ATN: ATN;
	public static get _ATN(): ATN {
		if (!ProParser.__ATN) {
			ProParser.__ATN = new ATNDeserializer().deserialize(ProParser._serializedATN);
		}

		return ProParser.__ATN;
	}


	static DecisionsToDFA = ProParser._ATN.decisionToState.map( (ds: DecisionState, index: number) => new DFA(ds, index) );

}

export class ProgContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public EOF(): TerminalNode {
		return this.getToken(ProParser.EOF, 0);
	}
	public statement_list(): StatementContext[] {
		return this.getTypedRuleContexts(StatementContext) as StatementContext[];
	}
	public statement(i: number): StatementContext {
		return this.getTypedRuleContext(StatementContext, i) as StatementContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_prog;
	}
}


export class Function_declarationContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public ID_list(): TerminalNode[] {
	    	return this.getTokens(ProParser.ID);
	}
	public ID(i: number): TerminalNode {
		return this.getToken(ProParser.ID, i);
	}
	public block(): BlockContext {
		return this.getTypedRuleContext(BlockContext, 0) as BlockContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_function_declaration;
	}
}


export class Expr_listContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public expr_list(): ExprContext[] {
		return this.getTypedRuleContexts(ExprContext) as ExprContext[];
	}
	public expr(i: number): ExprContext {
		return this.getTypedRuleContext(ExprContext, i) as ExprContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_expr_list;
	}
}


export class ExprContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public INT(): TerminalNode {
		return this.getToken(ProParser.INT, 0);
	}
	public ID(): TerminalNode {
		return this.getToken(ProParser.ID, 0);
	}
	public expr_list(): ExprContext[] {
		return this.getTypedRuleContexts(ExprContext) as ExprContext[];
	}
	public expr(i: number): ExprContext {
		return this.getTypedRuleContext(ExprContext, i) as ExprContext;
	}
	public function_call(): Function_callContext {
		return this.getTypedRuleContext(Function_callContext, 0) as Function_callContext;
	}
	public array_construction(): Array_constructionContext {
		return this.getTypedRuleContext(Array_constructionContext, 0) as Array_constructionContext;
	}
	public CHAR(): TerminalNode {
		return this.getToken(ProParser.CHAR, 0);
	}
	public STRING(): TerminalNode {
		return this.getToken(ProParser.STRING, 0);
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_expr;
	}
}


export class AssignmentContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public ID(): TerminalNode {
		return this.getToken(ProParser.ID, 0);
	}
	public ASSIGN(): TerminalNode {
		return this.getToken(ProParser.ASSIGN, 0);
	}
	public expr(): ExprContext {
		return this.getTypedRuleContext(ExprContext, 0) as ExprContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_assignment;
	}
}


export class StatementContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public assignment(): AssignmentContext {
		return this.getTypedRuleContext(AssignmentContext, 0) as AssignmentContext;
	}
	public expr(): ExprContext {
		return this.getTypedRuleContext(ExprContext, 0) as ExprContext;
	}
	public function_declaration(): Function_declarationContext {
		return this.getTypedRuleContext(Function_declarationContext, 0) as Function_declarationContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_statement;
	}
}


export class Function_callContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public ID(): TerminalNode {
		return this.getToken(ProParser.ID, 0);
	}
	public expr_list(): Expr_listContext {
		return this.getTypedRuleContext(Expr_listContext, 0) as Expr_listContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_function_call;
	}
}


export class Array_constructionContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public expr_list(): Expr_listContext {
		return this.getTypedRuleContext(Expr_listContext, 0) as Expr_listContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_array_construction;
	}
}


export class BlockContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public statement_list(): StatementContext[] {
		return this.getTypedRuleContexts(StatementContext) as StatementContext[];
	}
	public statement(i: number): StatementContext {
		return this.getTypedRuleContext(StatementContext, i) as StatementContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_block;
	}
}
