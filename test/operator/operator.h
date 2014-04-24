#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <fstream>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;


class Operator
{
public:
    Operator(string filename, string operation="addition");
    void writeToFile(string filename);
private:
    void addNumbers();
    void subtractNumbers();
    void multiplyNumbers();
    vector<double> m_numbers;
    vector<double> m_answers;
};

#endif // OPERATOR_H
