//
//  Predicate.cpp
//  Project2
//
//  Created by Cam on 2/6/19.
//  Copyright © 2019 Cam Brown. All rights reserved.
//

#include "Predicate.h"

Predicate :: Predicate() {
    id = "";
    paramList = vector<Parameter>();
}

Predicate :: ~Predicate() {
    
}

Predicate :: Predicate(string ident) {
    id = ident;
    paramList = vector<Parameter>();
}

Predicate :: Predicate(string ident, vector<Parameter> pList) {
    id = ident;
    paramList = pList;
}

string Predicate :: getID() {
    return id;
}

vector<Parameter> Predicate :: getParameters() {
    return paramList;
}

void Predicate :: addParameter(Parameter param) {
    paramList.push_back(param);
}

string Predicate :: toString() {
    return "";
}
