//
//  main.cpp
//  Project 1
//
//  Created by Cam on 1/22/2019.
//  Copyright © 2019 Cameron Brown. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Scanner.h"
#include "Token.h"

using namespace std;

int main(int argc, char* argv[]){
    string fileName = argv[1];
    Scanner myScanner(fileName);
    myScanner.scan();
    myScanner.printVector();
    return 0;
}
