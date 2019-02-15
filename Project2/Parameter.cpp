//
//  Parameter.cpp
//  Project2
//
//  Created by Cam on 2/6/19.
//  Copyright © 2019 Cam Brown. All rights reserved.
//

#include "Parameter.h"

Parameter :: Parameter() {
    type = "";
    value = "";
}

Parameter :: Parameter(string tokenType, string val) {
    type = tokenType;
    value = val;
}

Parameter :: ~Parameter() {
    
}

string Parameter :: getValue() {
    return value;
}

string Parameter :: getType() {
    return type;
}

string Parameter :: toString() {
    return "";
}
