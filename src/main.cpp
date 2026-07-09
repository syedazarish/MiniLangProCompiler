#include <iostream>
#include <vector>

#include "../include/lexer/Lexer.h"

int main()
{
    std::string source = R"(

int age = 20;
float cgpa = 3.75;
bool passed = true;

age++;

)";

    Lexer lexer(source);

    std::vector<Token> tokens = lexer.tokenize();

    std::cout << "Total Tokens : "
              << tokens.size()
              << std::endl;
              for (const Token& token : tokens)
{
    std::cout
        << token.toString()
        << "    "
        << token.getLexeme()
        << std::endl;
}

    return 0;
}