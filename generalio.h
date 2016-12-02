/******************************************
*                                         *
*               PROTCAD                   *
*     PROTein Computer Assisted Design    *
*                                         *
*          Copyright 2002,2011            *
*        Christopher Mark Summa           *
*                 and                     *
*     The University of New Orleans       *
*       New Orleans, LA 70148             *
*                                         *
******************************************/

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

#ifndef PCGENERALIO_H
#define PCGENERALIO_H

namespace PCGeneralIO
{
    std::string getEnvironmentVariable ( const std::string& _evname );

    std::string charToString ( char* cPointer );

    std::string intToString ( int _theInteger );

    bool compareToDelimiters ( const std::string& _s );

    bool compareToDelimiter ( const std::string& _s, const std::string& _delimiter );

    bool contains ( const std::string& _full, const std::string& _sub);

    std::vector<std::string> parseString ( const std::string& _s, const unsigned int _fieldWidth = 0 );

    std::vector<std::string> splitString ( const std::string& _s, const std::string& _delimiter );

    // NOTE: THIS IS NOT A FULLY FUNCTIONAL REGULAR EXPRESSION ENGINE
    // I HAVE ONLY IMPLEMENTED THE BITS I NEEDED FOR FUNCTIONALITY IN THE PROTCAD PACKAGE
    std::vector<std::string> splitStringWithRegex ( const std::string& _s, const std::string& _regex );

    std::vector<std::string> tokenizeString ( const std::string& _s );

    float stringToReal ( const std::string& _s );

    int stringToInt ( const std::string& _s );

    bool stringToBool ( const std::string& _s );

    std::string stripLeadingAndTrailingDelimiter ( const std::string& _s, const std::string& _delimiter );

    std::string stripLeadingAndTrailingSpaces ( const std::string& _s );

    std::string removeAllWhitespace( const std::string& _s);

    std::string stripQuotationMarks ( const std::string& _s );

    bool isNumeric ( const std::string& _s );

    bool hasNonWhitespaceCharacters( const std::string& _s );

    std::vector<unsigned int> findAllInstancesInString ( const std::string& _bigString,
                          const std::string& _searchString );

    std::string stringToUpper ( const std::string& _original );

    std::string stringToLower ( const std::string& _original );

    std::string getUserInputWithPrompt( const std::string& _prompt);

// these are currently not fully implented and are merely helpers for other methods - do not use!!!!
/*
    bool matchSubstring (const string& _bigstring, const string& _searchstring );

    bool matchRegex ( const string& _bigstring, const string& _regexstring );
*/

    void user_wait ( );
}
#endif
