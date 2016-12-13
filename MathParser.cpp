//
// Created by Benedikt on 13.12.2016.
//

#include "MathParser.h"
#include <cmath>

MathParser::MathParser() {
}

double MathParser::evalExpr(string exp) {
    for (unsigned int i = 0; i < exp.length(); i++) {
        if (exp.at(i) == '/') {
            return evalExpr(exp.substr(0, i)) / evalExpr(exp.substr(i + 1, exp.length() - 1));
        } else if (exp.at(i) == 'w') {
            for (unsigned int j = 0; j < exp.length() - i; j++) {
                if (exp.at(i + j) == ')') {
                    if (exp.substr(i + j + 1, exp.length() - 1 - i - j).length() != 0) {
                        return sqrt(stod(exp.substr(i + 2, j - 2))) *
                               evalExpr(exp.substr(i + j + 1, exp.length() - 1 - i - j));
                    } else {
                        return sqrt(stod(exp.substr(i + 2, j - 2)));
                    }
                }
            }
            return false;
        } else if (exp.at(i) == '-') {
            return -1.0 * evalExpr(exp.substr(i + 1, exp.length() - 1));
        }
    }
    return stod(exp);
}