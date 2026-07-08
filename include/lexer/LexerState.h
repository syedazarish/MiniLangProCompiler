#ifndef LEXER_STATE_H
#define LEXER_STATE_H

enum class LexerState
{
    Start,

    Identifier,

    Number,

    Float,

    String,

    Character,

    Operator,

    Delimiter,

    SingleLineComment,

    MultiLineComment,

    Whitespace,

    End,

    Error
};

#endif