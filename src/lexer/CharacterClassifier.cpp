#include "../../include/lexer/CharacterClassifier.h"

#include <cctype>

bool CharacterClassifier::isLetter(char ch)
{
    return std::isalpha(static_cast<unsigned char>(ch));
}

bool CharacterClassifier::isDigit(char ch)
{
    return std::isdigit(static_cast<unsigned char>(ch));
}

bool CharacterClassifier::isWhitespace(char ch)
{
    return std::isspace(static_cast<unsigned char>(ch));
}

bool CharacterClassifier::isOperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case '<':
        case '>':
        case '!':
        case '&':
        case '|':
        case '^':
        case '~':
            return true;

        default:
            return false;
    }
}

bool CharacterClassifier::isDelimiter(char ch)
{
    switch(ch)
    {
        case ';':
        case ',':
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
        case ':':
            return true;

        default:
            return false;
    }
}

bool CharacterClassifier::isIdentifierStart(char ch)
{
    return isLetter(ch) || ch == '_';
}

bool CharacterClassifier::isIdentifierPart(char ch)
{
    return isLetter(ch) ||
           isDigit(ch) ||
           ch == '_';
}