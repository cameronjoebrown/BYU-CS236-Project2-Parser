//
//  DatalogProgram.cpp
//  Project2
//
//  Created by Cam on 2/6/19.
//  Copyright © 2019 Cam Brown. All rights reserved.
//

#include "DatalogProgram.h"
#include <iostream>
#include <sstream>

DatalogProgram :: DatalogProgram(){
    schemes = vector<Predicate>();
    facts = vector<Predicate>();
    rules = vector<Rule>();
    queries = vector<Predicate>();
    domain = set<string>();
}

DatalogProgram :: ~DatalogProgram() {
    
}

string DatalogProgram :: toString() {
    stringstream ss;
    ss << "Success!";
    return ss.str();
}

vector<Predicate> DatalogProgram :: getSchemes(){
    return schemes;
}

vector<Predicate> DatalogProgram :: getFacts() {
    return facts;
}

vector<Rule> DatalogProgram :: getRules() {
    return rules;
}

vector<Predicate> DatalogProgram :: getQueries() {
    return queries;
}

set<string> DatalogProgram :: getDomain() {
    return domain;
}
