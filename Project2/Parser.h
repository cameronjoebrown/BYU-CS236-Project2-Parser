//
//  Parser.h
//  Project2
//
//  Created by Cam on 2/6/19.
//  Copyright © 2019 Cam Brown. All rights reserved.
//

#ifndef Parser_h
#define Parser_h

#ifndef Token_h
#define Token_h

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include "Token.h"
#include "Scanner.h"

using namespace std;

class Parser {
public:
    Parser(string fileName);
    ~Parser();
    void parse();
    void match(TokenType t);
    void error();
    
    
private:
    
};

#endif /* Token_h */
#endif /* Parser_h */
