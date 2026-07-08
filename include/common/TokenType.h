#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

enum class TokenType
{
    // ===========================
    // Special Tokens
    // ===========================

    EndOfFile,
    Invalid,
    Unknown,

    // ===========================
    // Identifiers
    // ===========================

    Identifier,

    // ===========================
    // Literals
    // ===========================

    IntegerLiteral,
    FloatLiteral,
    DoubleLiteral,
    StringLiteral,
    CharacterLiteral,
    BooleanLiteral,

    // ===========================
    // Keywords
    // ===========================

    KW_Int,
    KW_Float,
    KW_Double,
    KW_Bool,
    KW_Char,
    KW_String,
    KW_Void,
    KW_Const,

    KW_If,
    KW_Else,
    KW_For,
    KW_While,
    KW_Do,
    KW_Switch,
    KW_Case,
    KW_Default,

    KW_Break,
    KW_Continue,
    KW_Return,

    // ===========================
    // Arithmetic Operators
    // ===========================

    Plus,
    Minus,
    Multiply,
    Divide,
    Modulus,

    Increment,
    Decrement,

    // ===========================
    // Assignment Operators
    // ===========================

    Assign,

    PlusAssign,
    MinusAssign,
    MultiplyAssign,
    DivideAssign,

    // ===========================
    // Relational Operators
    // ===========================

    Equal,
    NotEqual,

    LessThan,
    GreaterThan,

    LessEqual,
    GreaterEqual,

    // ===========================
    // Logical Operators
    // ===========================

    LogicalAnd,
    LogicalOr,
    LogicalNot,

    // ===========================
    // Bitwise Operators
    // ===========================

    BitAnd,
    BitOr,
    BitXor,
    BitNot,

    LeftShift,
    RightShift,

    // ===========================
    // Delimiters
    // ===========================

    LeftParenthesis,
    RightParenthesis,

    LeftBrace,
    RightBrace,

    LeftBracket,
    RightBracket,

    Comma,
    Semicolon,
    Colon,
    Dot,

    // ===========================
    // Comments
    // ===========================

    SingleLineComment,
    MultiLineComment
};

#endif