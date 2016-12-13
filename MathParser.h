//
// Created by Benedikt on 13.12.2016.
//

#ifndef GITTERGAS_MATHPARSER_H
#define GITTERGAS_MATHPARSER_H

#include <string>

using namespace std;

class MathParser {
public:
    MathParser();

    double evalExpr(string exp);
};


#endif //GITTERGAS_MATHPARSER_H
