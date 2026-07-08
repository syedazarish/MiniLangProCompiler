#include "../../include/common/Diagnostic.h"

#include <iostream>

Diagnostic::Diagnostic()
{
}

Diagnostic::Diagnostic(
    DiagnosticSeverity severity,
    const std::string& code,
    const std::string& message,
    const std::string& suggestion,
    const SourceLocation& location)
{
    this->severity = severity;
    this->code = code;
    this->message = message;
    this->suggestion = suggestion;
    this->location = location;
}

void Diagnostic::print() const
{
    std::cout << "\n=================================\n";

    if(severity == DiagnosticSeverity::Error)
        std::cout << "ERROR\n";

    else if(severity == DiagnosticSeverity::Warning)
        std::cout << "WARNING\n";

    else
        std::cout << "NOTE\n";

    std::cout << "Code : " << code << std::endl;

    std::cout << "Message : "
              << message
              << std::endl;

    std::cout << "Line : "
              << location.getLine()
              << std::endl;

    std::cout << "Column : "
              << location.getColumn()
              << std::endl;

    std::cout << "Suggestion : "
              << suggestion
              << std::endl;

    std::cout << "=================================\n";
}