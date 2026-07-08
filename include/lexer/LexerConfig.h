#ifndef LEXER_CONFIG_H
#define LEXER_CONFIG_H

#include <unordered_set>
#include <unordered_map>
#include <string>
#include "../common/TokenType.h"

class LexerConfig
{
public:

    static const std::unordered_set<std::string> Keywords;

    static const std::unordered_set<std::string> BooleanLiterals;

    static const std::unordered_set<char> Operators;

    static const std::unordered_set<char> Delimiters;
    static const std::unordered_map<std::string, TokenType> KeywordMap;
};

#endif