//
//  Parameter.h
//  Project2
//
//  Created by Cam on 2/6/19.
//  Copyright © 2019 Cam Brown. All rights reserved.
//

#ifndef Parameter_h
#define Parameter_h

#include <stdio.h>
#include <string>

using namespace std;

class Parameter {
public:
    Parameter();
    Parameter(string tokenType, string val);
    ~Parameter();
    string getValue();
    string getType();
    string toString();
    
private:
    string type;
    string value;
    
};

#endif /* Parameter_h */
