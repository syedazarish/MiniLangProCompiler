#include "../../include/lexer/LexerConfig.h"

const std::unordered_set<std::string> LexerConfig::Keywords =
{
    "int",
    "float",
    "double",
    "bool",
    "char",
    "string",
    "void",
    "const",

    "if",
    "else",
    "for",
    "while",
    "do",
    "switch",
    "case",
    "default",

    "break",
    "continue",
    "return"
};

const std::unordered_set<std::string> LexerConfig::BooleanLiterals =
{
    "true",
    "false"
};

const std::unordered_set<char> LexerConfig::Operators =
{
    '+',
    '-',
    '*',
    '/',
    '%',
    '=',
    '<',
    '>',
    '!',
    '&',
    '|',
    '^',
    '~'
};

const std::unordered_set<char> LexerConfig::Delimiters =
{
    ';',
    ',',
    '(',
    ')',
    '{',
    '}',
    '[',
    ']',
    ':'
};