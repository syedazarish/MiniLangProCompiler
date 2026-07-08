#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <string>

#include "SourceLocation.h"

enum class DiagnosticSeverity
{
    Error,
    Warning,
    Note
};

class Diagnostic
{
private:

    DiagnosticSeverity severity;

    std::string code;

    std::string message;

    std::string suggestion;

    SourceLocation location;

public:

    Diagnostic();

    Diagnostic(
        DiagnosticSeverity severity,
        const std::string& code,
        const std::string& message,
        const std::string& suggestion,
        const SourceLocation& location
    );

    void print() const;
};

#endif