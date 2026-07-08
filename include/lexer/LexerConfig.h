#ifndef LEXER_CONFIG_H
#define LEXER_CONFIG_H

#include <unordered_set>
#include <string>

class LexerConfig
{
public:

    static const std::unordered_set<std::string> Keywords;

    static const std::unordered_set<std::string> BooleanLiterals;

    static const std::unordered_set<char> Operators;

    static const std::unordered_set<char> Delimiters;
};

#endif