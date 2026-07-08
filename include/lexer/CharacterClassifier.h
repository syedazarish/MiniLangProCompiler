#ifndef CHARACTER_CLASSIFIER_H
#define CHARACTER_CLASSIFIER_H

class CharacterClassifier
{
public:

    static bool isLetter(char ch);

    static bool isDigit(char ch);

    static bool isWhitespace(char ch);

    static bool isOperator(char ch);

    static bool isDelimiter(char ch);

    static bool isIdentifierStart(char ch);

    static bool isIdentifierPart(char ch);
};

#endif