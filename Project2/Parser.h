//
//  Parser.h
//  Project2
//
//  Created by Cam on 2/6/19.
//  Copyright © 2019 Cam Brown. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include "Token.h"
#include "Scanner.h"

using namespace std;

class Parser {
public:
    Parser(string fileName);
    ~Parser();
    void parse();
    void match(TokenType t);
    void scheme();
    void fact();
    void rule();
    void query();
    void schemeList();
    void factList();
    void ruleList();
    void queryList();
    void idList();
    void stringList();
    void headPredicate();
    void predicate();
    void predicateList();
    void parameter();
    void parameterList();
    
    
private:
    Token current;
    vector<Token> tokenVector;
};


#endif // Parser_h
