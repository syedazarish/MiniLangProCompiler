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
const std::unordered_map<std::string, TokenType>
LexerConfig::KeywordMap =
{
    {"int", TokenType::KW_Int},
    {"float", TokenType::KW_Float},
    {"double", TokenType::KW_Double},
    {"bool", TokenType::KW_Bool},
    {"char", TokenType::KW_Char},
    {"string", TokenType::KW_String},
    {"void", TokenType::KW_Void},
    {"const", TokenType::KW_Const},

    {"if", TokenType::KW_If},
    {"else", TokenType::KW_Else},
    {"for", TokenType::KW_For},
    {"while", TokenType::KW_While},
    {"do", TokenType::KW_Do},

    {"switch", TokenType::KW_Switch},
    {"case", TokenType::KW_Case},
    {"default", TokenType::KW_Default},

    {"break", TokenType::KW_Break},
    {"continue", TokenType::KW_Continue},
    {"return", TokenType::KW_Return}
};