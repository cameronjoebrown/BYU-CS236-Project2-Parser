//
//  Parser.cpp
//  Project2
//
//  Created by Cam on 2/6/19.
//  Copyright © 2019 Cam Brown. All rights reserved.
//

#include "Parser.h"
#include <iostream>
#include <cctype>

using namespace std;

Parser :: Parser(string fileName) {
    Scanner myScanner(fileName);
    myScanner.scan();
}

Parser :: ~Parser() {
    
}

void Parser :: parse() {
    match(SCHEMES);
    match(COLON);
    parseScheme();
    parseSchemeList();
    
    match(FACTS);
    match(COLON);
    parseFactList();
    program.makeDomain();
    
    match(RULES);
    match(COLON);
    parseRuleList();
    
    match(QUERIES);
    match(COLON);
    parseQuery();
    parseQueryList();
    
    cout << "Success!\n" << program.toString();
}

void parser::match(TokenType t)
{
    if(tok.type == t)
    {
        tok = tokenList[0];
        tokenList.erase(tokenList.begin());
    }
    
    else
        error();
}

void parser::error()
{
    cout << "Failure!\n  "
    << tok.print() << endl;
    exit(EXIT_SUCCESS);
}
