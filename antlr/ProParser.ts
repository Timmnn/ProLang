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
	public static readonly T__11 = 12;
	public static readonly T__12 = 13;
	public static readonly COMMENT = 14;
	public static readonly INT = 15;
	public static readonly CHAR = 16;
	public static readonly STRING = 17;
	public static readonly ID = 18;
	public static readonly ASSIGN = 19;
	public static readonly WS = 20;
	public static readonly NEWLINE = 21;
	public static readonly EOF = Token.EOF;
	public static readonly RULE_prog = 0;
	public static readonly RULE_array_access = 1;
	public static readonly RULE_function_declaration = 2;
	public static readonly RULE_parameter = 3;
	public static readonly RULE_parameter_list = 4;
	public static readonly RULE_expr_list = 5;
	public static readonly RULE_expr = 6;
	public static readonly RULE_assignment = 7;
	public static readonly RULE_statement = 8;
	public static readonly RULE_return_statement = 9;
	public static readonly RULE_cast = 10;
	public static readonly RULE_function_call = 11;
	public static readonly RULE_block = 12;
	public static readonly RULE_array_construction = 13;
	public static readonly literalNames: (string | null)[] = [ null, "'['", 
                                                            "']'", "'('", 
                                                            "')'", "':'", 
                                                            "','", "'*'", 
                                                            "'/'", "'+'", 
                                                            "'-'", "'return'", 
                                                            "'{'", "'}'", 
                                                            null, null, 
                                                            null, null, 
                                                            null, "'='" ];
	public static readonly symbolicNames: (string | null)[] = [ null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             null, null, 
                                                             "COMMENT", 
                                                             "INT", "CHAR", 
                                                             "STRING", "ID", 
                                                             "ASSIGN", "WS", 
                                                             "NEWLINE" ];
	// tslint:disable:no-trailing-whitespace
	public static readonly ruleNames: string[] = [
		"prog", "array_access", "function_declaration", "parameter", "parameter_list", 
		"expr_list", "expr", "assignment", "statement", "return_statement", "cast", 
		"function_call", "block", "array_construction",
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
			this.state = 29;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			do {
				{
				{
				this.state = 28;
				this.statement();
				}
				}
				this.state = 31;
				this._errHandler.sync(this);
				_la = this._input.LA(1);
			} while ((((_la) & ~0x1F) === 0 && ((1 << _la) & 494602) !== 0));
			this.state = 33;
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
	public array_access(): Array_accessContext {
		let localctx: Array_accessContext = new Array_accessContext(this, this._ctx, this.state);
		this.enterRule(localctx, 2, ProParser.RULE_array_access);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 35;
			this.match(ProParser.ID);
			this.state = 36;
			this.match(ProParser.T__0);
			this.state = 37;
			this.match(ProParser.INT);
			this.state = 38;
			this.match(ProParser.T__1);
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
		this.enterRule(localctx, 4, ProParser.RULE_function_declaration);
		let _la: number;
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 40;
			this.match(ProParser.ID);
			this.state = 41;
			this.match(ProParser.ID);
			this.state = 42;
			this.match(ProParser.T__2);
			this.state = 44;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			if (_la===18) {
				{
				this.state = 43;
				this.parameter_list();
				}
			}

			this.state = 46;
			this.match(ProParser.T__3);
			this.state = 47;
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
	public parameter(): ParameterContext {
		let localctx: ParameterContext = new ParameterContext(this, this._ctx, this.state);
		this.enterRule(localctx, 6, ProParser.RULE_parameter);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 49;
			this.match(ProParser.ID);
			this.state = 50;
			this.match(ProParser.T__4);
			this.state = 51;
			this.match(ProParser.ID);
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
	public parameter_list(): Parameter_listContext {
		let localctx: Parameter_listContext = new Parameter_listContext(this, this._ctx, this.state);
		this.enterRule(localctx, 8, ProParser.RULE_parameter_list);
		let _la: number;
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 53;
			this.parameter();
			this.state = 58;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			while (_la===6) {
				{
				{
				this.state = 54;
				this.match(ProParser.T__5);
				this.state = 55;
				this.parameter();
				}
				}
				this.state = 60;
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
	// @RuleVersion(0)
	public expr_list(): Expr_listContext {
		let localctx: Expr_listContext = new Expr_listContext(this, this._ctx, this.state);
		this.enterRule(localctx, 10, ProParser.RULE_expr_list);
		let _la: number;
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 61;
			this.expr(0);
			this.state = 66;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			while (_la===6) {
				{
				{
				this.state = 62;
				this.match(ProParser.T__5);
				this.state = 63;
				this.expr(0);
				}
				}
				this.state = 68;
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
		let _startState: number = 12;
		this.enterRecursionRule(localctx, 12, ProParser.RULE_expr, _p);
		let _la: number;
		try {
			let _alt: number;
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 80;
			this._errHandler.sync(this);
			switch ( this._interp.adaptivePredict(this._input, 4, this._ctx) ) {
			case 1:
				{
				this.state = 70;
				this.match(ProParser.INT);
				}
				break;
			case 2:
				{
				this.state = 71;
				this.match(ProParser.T__9);
				this.state = 72;
				this.expr(8);
				}
				break;
			case 3:
				{
				this.state = 73;
				this.function_call();
				}
				break;
			case 4:
				{
				this.state = 74;
				this.array_access();
				}
				break;
			case 5:
				{
				this.state = 75;
				this.array_construction();
				}
				break;
			case 6:
				{
				this.state = 76;
				this.match(ProParser.ID);
				}
				break;
			case 7:
				{
				this.state = 77;
				this.match(ProParser.CHAR);
				}
				break;
			case 8:
				{
				this.state = 78;
				this.match(ProParser.STRING);
				}
				break;
			case 9:
				{
				this.state = 79;
				this.cast();
				}
				break;
			}
			this._ctx.stop = this._input.LT(-1);
			this.state = 87;
			this._errHandler.sync(this);
			_alt = this._interp.adaptivePredict(this._input, 5, this._ctx);
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
					this.state = 82;
					if (!(this.precpred(this._ctx, 10))) {
						throw this.createFailedPredicateException("this.precpred(this._ctx, 10)");
					}
					this.state = 83;
					_la = this._input.LA(1);
					if(!((((_la) & ~0x1F) === 0 && ((1 << _la) & 1920) !== 0))) {
					this._errHandler.recoverInline(this);
					}
					else {
						this._errHandler.reportMatch(this);
					    this.consume();
					}
					this.state = 84;
					this.expr(11);
					}
					}
				}
				this.state = 89;
				this._errHandler.sync(this);
				_alt = this._interp.adaptivePredict(this._input, 5, this._ctx);
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
		this.enterRule(localctx, 14, ProParser.RULE_assignment);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 90;
			this.match(ProParser.ID);
			this.state = 91;
			this.match(ProParser.ASSIGN);
			this.state = 92;
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
		this.enterRule(localctx, 16, ProParser.RULE_statement);
		try {
			this.state = 98;
			this._errHandler.sync(this);
			switch ( this._interp.adaptivePredict(this._input, 6, this._ctx) ) {
			case 1:
				this.enterOuterAlt(localctx, 1);
				{
				this.state = 94;
				this.assignment();
				}
				break;
			case 2:
				this.enterOuterAlt(localctx, 2);
				{
				this.state = 95;
				this.expr(0);
				}
				break;
			case 3:
				this.enterOuterAlt(localctx, 3);
				{
				this.state = 96;
				this.function_declaration();
				}
				break;
			case 4:
				this.enterOuterAlt(localctx, 4);
				{
				this.state = 97;
				this.return_statement();
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
	public return_statement(): Return_statementContext {
		let localctx: Return_statementContext = new Return_statementContext(this, this._ctx, this.state);
		this.enterRule(localctx, 18, ProParser.RULE_return_statement);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 100;
			this.match(ProParser.T__10);
			this.state = 101;
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
	public cast(): CastContext {
		let localctx: CastContext = new CastContext(this, this._ctx, this.state);
		this.enterRule(localctx, 20, ProParser.RULE_cast);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 103;
			this.match(ProParser.T__2);
			this.state = 104;
			this.match(ProParser.ID);
			this.state = 105;
			this.match(ProParser.T__3);
			this.state = 106;
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
	public function_call(): Function_callContext {
		let localctx: Function_callContext = new Function_callContext(this, this._ctx, this.state);
		this.enterRule(localctx, 22, ProParser.RULE_function_call);
		try {
			this.state = 116;
			this._errHandler.sync(this);
			switch ( this._interp.adaptivePredict(this._input, 7, this._ctx) ) {
			case 1:
				this.enterOuterAlt(localctx, 1);
				{
				{
				this.state = 108;
				this.match(ProParser.ID);
				this.state = 109;
				this.match(ProParser.T__2);
				this.state = 110;
				this.match(ProParser.T__3);
				}
				}
				break;
			case 2:
				this.enterOuterAlt(localctx, 2);
				{
				{
				this.state = 111;
				this.match(ProParser.ID);
				this.state = 112;
				this.match(ProParser.T__2);
				this.state = 113;
				this.expr_list();
				this.state = 114;
				this.match(ProParser.T__3);
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
	public block(): BlockContext {
		let localctx: BlockContext = new BlockContext(this, this._ctx, this.state);
		this.enterRule(localctx, 24, ProParser.RULE_block);
		let _la: number;
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 118;
			this.match(ProParser.T__11);
			this.state = 122;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			while ((((_la) & ~0x1F) === 0 && ((1 << _la) & 494602) !== 0)) {
				{
				{
				this.state = 119;
				this.statement();
				}
				}
				this.state = 124;
				this._errHandler.sync(this);
				_la = this._input.LA(1);
			}
			this.state = 125;
			this.match(ProParser.T__12);
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
		this.enterRule(localctx, 26, ProParser.RULE_array_construction);
		try {
			this.enterOuterAlt(localctx, 1);
			{
			this.state = 127;
			this.match(ProParser.T__0);
			this.state = 128;
			this.expr_list();
			this.state = 129;
			this.match(ProParser.T__1);
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
		case 6:
			return this.expr_sempred(localctx as ExprContext, predIndex);
		}
		return true;
	}
	private expr_sempred(localctx: ExprContext, predIndex: number): boolean {
		switch (predIndex) {
		case 0:
			return this.precpred(this._ctx, 10);
		}
		return true;
	}

	public static readonly _serializedATN: number[] = [4,1,21,132,2,0,7,0,2,
	1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,
	10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,4,0,30,8,0,11,0,12,0,31,1,0,1,
	0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,45,8,2,1,2,1,2,1,2,1,3,1,3,1,
	3,1,3,1,4,1,4,1,4,5,4,57,8,4,10,4,12,4,60,9,4,1,5,1,5,1,5,5,5,65,8,5,10,
	5,12,5,68,9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,81,8,6,1,
	6,1,6,1,6,5,6,86,8,6,10,6,12,6,89,9,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,3,
	8,99,8,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,
	1,11,1,11,1,11,3,11,117,8,11,1,12,1,12,5,12,121,8,12,10,12,12,12,124,9,
	12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,0,1,12,14,0,2,4,6,8,10,12,14,16,18,
	20,22,24,26,0,1,1,0,7,10,135,0,29,1,0,0,0,2,35,1,0,0,0,4,40,1,0,0,0,6,49,
	1,0,0,0,8,53,1,0,0,0,10,61,1,0,0,0,12,80,1,0,0,0,14,90,1,0,0,0,16,98,1,
	0,0,0,18,100,1,0,0,0,20,103,1,0,0,0,22,116,1,0,0,0,24,118,1,0,0,0,26,127,
	1,0,0,0,28,30,3,16,8,0,29,28,1,0,0,0,30,31,1,0,0,0,31,29,1,0,0,0,31,32,
	1,0,0,0,32,33,1,0,0,0,33,34,5,0,0,1,34,1,1,0,0,0,35,36,5,18,0,0,36,37,5,
	1,0,0,37,38,5,15,0,0,38,39,5,2,0,0,39,3,1,0,0,0,40,41,5,18,0,0,41,42,5,
	18,0,0,42,44,5,3,0,0,43,45,3,8,4,0,44,43,1,0,0,0,44,45,1,0,0,0,45,46,1,
	0,0,0,46,47,5,4,0,0,47,48,3,24,12,0,48,5,1,0,0,0,49,50,5,18,0,0,50,51,5,
	5,0,0,51,52,5,18,0,0,52,7,1,0,0,0,53,58,3,6,3,0,54,55,5,6,0,0,55,57,3,6,
	3,0,56,54,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,9,1,0,0,
	0,60,58,1,0,0,0,61,66,3,12,6,0,62,63,5,6,0,0,63,65,3,12,6,0,64,62,1,0,0,
	0,65,68,1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,11,1,0,0,0,68,66,1,0,0,0,
	69,70,6,6,-1,0,70,81,5,15,0,0,71,72,5,10,0,0,72,81,3,12,6,8,73,81,3,22,
	11,0,74,81,3,2,1,0,75,81,3,26,13,0,76,81,5,18,0,0,77,81,5,16,0,0,78,81,
	5,17,0,0,79,81,3,20,10,0,80,69,1,0,0,0,80,71,1,0,0,0,80,73,1,0,0,0,80,74,
	1,0,0,0,80,75,1,0,0,0,80,76,1,0,0,0,80,77,1,0,0,0,80,78,1,0,0,0,80,79,1,
	0,0,0,81,87,1,0,0,0,82,83,10,10,0,0,83,84,7,0,0,0,84,86,3,12,6,11,85,82,
	1,0,0,0,86,89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,13,1,0,0,0,89,87,1,
	0,0,0,90,91,5,18,0,0,91,92,5,19,0,0,92,93,3,12,6,0,93,15,1,0,0,0,94,99,
	3,14,7,0,95,99,3,12,6,0,96,99,3,4,2,0,97,99,3,18,9,0,98,94,1,0,0,0,98,95,
	1,0,0,0,98,96,1,0,0,0,98,97,1,0,0,0,99,17,1,0,0,0,100,101,5,11,0,0,101,
	102,3,12,6,0,102,19,1,0,0,0,103,104,5,3,0,0,104,105,5,18,0,0,105,106,5,
	4,0,0,106,107,3,12,6,0,107,21,1,0,0,0,108,109,5,18,0,0,109,110,5,3,0,0,
	110,117,5,4,0,0,111,112,5,18,0,0,112,113,5,3,0,0,113,114,3,10,5,0,114,115,
	5,4,0,0,115,117,1,0,0,0,116,108,1,0,0,0,116,111,1,0,0,0,117,23,1,0,0,0,
	118,122,5,12,0,0,119,121,3,16,8,0,120,119,1,0,0,0,121,124,1,0,0,0,122,120,
	1,0,0,0,122,123,1,0,0,0,123,125,1,0,0,0,124,122,1,0,0,0,125,126,5,13,0,
	0,126,25,1,0,0,0,127,128,5,1,0,0,128,129,3,10,5,0,129,130,5,2,0,0,130,27,
	1,0,0,0,9,31,44,58,66,80,87,98,116,122];

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


export class Array_accessContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public ID(): TerminalNode {
		return this.getToken(ProParser.ID, 0);
	}
	public INT(): TerminalNode {
		return this.getToken(ProParser.INT, 0);
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_array_access;
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
	public parameter_list(): Parameter_listContext {
		return this.getTypedRuleContext(Parameter_listContext, 0) as Parameter_listContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_function_declaration;
	}
}


export class ParameterContext extends ParserRuleContext {
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
    public get ruleIndex(): number {
    	return ProParser.RULE_parameter;
	}
}


export class Parameter_listContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public parameter_list(): ParameterContext[] {
		return this.getTypedRuleContexts(ParameterContext) as ParameterContext[];
	}
	public parameter(i: number): ParameterContext {
		return this.getTypedRuleContext(ParameterContext, i) as ParameterContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_parameter_list;
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
	public expr_list(): ExprContext[] {
		return this.getTypedRuleContexts(ExprContext) as ExprContext[];
	}
	public expr(i: number): ExprContext {
		return this.getTypedRuleContext(ExprContext, i) as ExprContext;
	}
	public function_call(): Function_callContext {
		return this.getTypedRuleContext(Function_callContext, 0) as Function_callContext;
	}
	public array_access(): Array_accessContext {
		return this.getTypedRuleContext(Array_accessContext, 0) as Array_accessContext;
	}
	public array_construction(): Array_constructionContext {
		return this.getTypedRuleContext(Array_constructionContext, 0) as Array_constructionContext;
	}
	public ID(): TerminalNode {
		return this.getToken(ProParser.ID, 0);
	}
	public CHAR(): TerminalNode {
		return this.getToken(ProParser.CHAR, 0);
	}
	public STRING(): TerminalNode {
		return this.getToken(ProParser.STRING, 0);
	}
	public cast(): CastContext {
		return this.getTypedRuleContext(CastContext, 0) as CastContext;
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
	public return_statement(): Return_statementContext {
		return this.getTypedRuleContext(Return_statementContext, 0) as Return_statementContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_statement;
	}
}


export class Return_statementContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public expr(): ExprContext {
		return this.getTypedRuleContext(ExprContext, 0) as ExprContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_return_statement;
	}
}


export class CastContext extends ParserRuleContext {
	constructor(parser?: ProParser, parent?: ParserRuleContext, invokingState?: number) {
		super(parent, invokingState);
    	this.parser = parser;
	}
	public ID(): TerminalNode {
		return this.getToken(ProParser.ID, 0);
	}
	public expr(): ExprContext {
		return this.getTypedRuleContext(ExprContext, 0) as ExprContext;
	}
    public get ruleIndex(): number {
    	return ProParser.RULE_cast;
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
