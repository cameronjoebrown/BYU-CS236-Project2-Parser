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
    /* datalogProgram -> SCHEMES COLON scheme schemeList
                         FACTS COLON factList
                         RULES COLON ruleList
                         QUERIES COLON query queryList
     */
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
        
        match(END);
        
        cout << "Success!" << endl;
        // Print Structures and Domain
    }
    catch(Token error) {
        cout << "Failure!" << endl << "  ";
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
    headPredicate();
    match(COLON_DASH);
    predicate();
    if (current.getTokenType() == COMMA){
       predicateList();
    }
    match(PERIOD);
}
void Parser :: query() {
    // query -> predicate Q_MARK
    predicate();
    match(Q_MARK);
}
void Parser :: schemeList() {
    // schemeList -> scheme schemeList | lambda
    if (current.getTokenType() == ID){
        scheme();
    }
    if(current.getTokenType() == ID) {
        schemeList();
    }
}
void Parser :: factList() {
    // factList -> fact factList | lambda
    if(current.getTokenType() == ID){
        fact();
        if (current.getTokenType() == ID){
            factList();
        }
    }
}
void Parser :: ruleList() {
    // ruleList ->  rule ruleList | lambda
    if(current.getTokenType() == ID){
        rule();
        if (current.getTokenType() == ID){
            ruleList();
        }
    }
}
void Parser :: queryList() {
    // queryList -> query queryList | lambda
    if (current.getTokenType() == END){
        
    }
    else {
        query();
        if(current.getTokenType() == ID) {
            queryList();
        }
        else if(current.getTokenType() != END){
            //throw string(current.printTokens());
        }
        
    }
}

void Parser :: idList() {
    // idList -> COMMA ID idList | lambda
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
    // stringList -> COMMA STRING stringList | lambda
    match(COMMA);
    if (current.getTokenType() == STRING){
        //p.addParameter(Parameter(curr.getType(), curr.getValue()));
    }
    match(STRING);
    if (current.getTokenType() == COMMA) {
        stringList();
    }

}

void Parser :: headPredicate() {
    // headPredicate ->  ID LEFT_PAREN ID idList RIGHT_PAREN
    match(ID);
    match(LEFT_PAREN);
    if (current.getTokenType() == ID){
        //p.addParameter(Parameter(curr.getType(), curr.getValue()));
    }
    match(ID);
    if (current.getTokenType() == COMMA){
        idList();
    }
    match(RIGHT_PAREN);
}

void Parser :: predicate() {
    // predicate -> ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    match(ID);
    match(LEFT_PAREN);
    parameter();
    if (current.getTokenType() == COMMA){
        parameterList();
    }
    match(RIGHT_PAREN);
}

void Parser :: predicateList(){
    // predicateList -> COMMA predicate predicateList | lambda
    match(COMMA);
    predicate();
    if(current.getTokenType() == COMMA){
        predicateList();
    }
}

void Parser :: parameter() {
    //  parameter -> STRING | ID | expression
    if(current.getTokenType() == STRING || current.getTokenType() == ID){
        //p.addParameter(Parameter(curr.getType(), curr.getValue()));
        match(current.getTokenType());
    }
    if (current.getTokenType() == LEFT_PAREN){
        expression();
    }
}

void Parser :: parameterList() {
    // parameterList -> COMMA parameter parameterList | lambda
    match(COMMA);
    parameter();
    if(current.getTokenType() == COMMA){
        parameterList();
    }
}

void Parser :: expression() {
    // expression -> LEFT_PAREN parameter operator parameter RIGHT_PAREN
    match(LEFT_PAREN);
    parameter();
    operate();
    parameter();
    match(RIGHT_PAREN);
}

void Parser :: operate(){
    // operator -> ADD | MULTIPLY
    if (current.getTokenType() == ADD) {
        match(ADD);
    }
    if (current.getTokenType() == MULTIPLY) {
        match(MULTIPLY);
    }
}

