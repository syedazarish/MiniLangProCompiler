#include <iostream>
#include <vector>

#include "../include/lexer/Lexer.h"
#include "../include/parser/Parser.h"

int main()
{
    std::string source = R"(

int age = 20;
float cgpa = 3.75;
bool passed = true;

age=21;

)";

    Lexer lexer(source);

    std::vector<Token> tokens = lexer.tokenize();
    Parser parser(tokens);

parser.parse();

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
std::cout << "\nParsing Completed Successfully!" << std::endl;

    return 0;
}