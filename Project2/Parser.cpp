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
    tokenVector = myScanner.getVector();
    current = tokenVector.at(0);
}

Parser :: ~Parser() {
    
}

void Parser :: parse() {
    try {
        match(SCHEMES);
        match(COLON);
        scheme();
        schemeList();
        
        match(FACTS);
        match(COLON);
        factList();
        
        match(RULES);
        match(COLON);
        ruleList();
        
        match(QUERIES);
        match(COLON);
        query();
        queryList();
        
        cout << "Success!" << endl;
        // Print Structures and Domain
    }
    catch(Token error) {
        cout << "Failure!" << endl;
        current.printToken();
    }

    
    
}

void Parser :: match(TokenType t) {
    if(t == current.getTokenType()) {
        tokenVector.erase(tokenVector.begin() + 0);
        current = tokenVector[0];
    }
    else { // Error
        throw current;
    }
}

void Parser :: scheme() {
    //scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    match(ID);
    match(LEFT_PAREN);
    match(ID);
    if(current.getTokenType() == COMMA) {
        idList();
    }
    match(RIGHT_PAREN);
}
void Parser :: fact() {
    // fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    match(ID);
    match(LEFT_PAREN);
    match(STRING);
    if(current.getTokenType() == COMMA) {
        stringList();
    }
    match(RIGHT_PAREN);
    match(PERIOD);
}
void Parser :: rule() {
    // rule ->  headPredicate COLON_DASH predicate predicateList PERIOD
    
    parseHeadPredicate();
    r = Rule(p);
    match("COLON_DASH");
    parsePredicate();
    if (curr.getType() == "COMMA"){
        parsePredicateList();
    }
    match("PERIOD");
    data.addRule(r);
}
void Parser :: query() {
    // query -> predicate Q_MARK
}
void Parser :: schemeList() {
    // schemeList -> scheme schemeList | lambda
}
void Parser :: factList() {
    // factList -> fact factList | lambda
    
}
void Parser :: ruleList() {
    // ruleList ->  rule ruleList | lambda
    
}
void Parser :: queryList() {
    // queryList -> query queryList | lambda
    
}

void Parser :: idList() {
    match(COMMA);
    if (current.getTokenType() == ID){
        // Do something???
    }
    match(ID);
    if (current.getTokenType() == COMMA) {
        idList();
    }
}

void Parser :: stringList() {
    if(current.getTokenType() == ID){
        fact();
        if (current.getTokenType() == ID){
            factList();
        }
    }
}

void Parser :: headPredicate() {
    
}

void Parser :: predicate() {
    
}

void Parser :: predicateList(){
    
}

void Parser :: parameter() {
    
}

void Parser :: parameterList() {
    
}
