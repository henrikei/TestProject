#include "operator.h"

Operator::Operator(string filename, string operation)
{
    fstream file;
    string line, stringToSearch;
    file.open(filename);
    if (file.is_open()){
        while(getline(file,line)){
            stringToSearch += line +" ";
        }
    } else {
        cout << "Error: Could not open file " << filename << endl;
    }
    regex search("-?[0-9]+\\.?[0-9]*\\s+");
    sregex_iterator pos(stringToSearch.begin(), stringToSearch.end(), search);
    sregex_iterator end;
    for (;pos != end; pos++){
        m_numbers.push_back(atof(pos->str(0).c_str()));
    }

    if (operation == "subtraction"){
        subtractNumbers();
    } else if (operation == "multiplication"){
        multiplyNumbers();
    } else {
        addNumbers();
    }
}

void Operator::writeToFile(string filename)
{
    ofstream file;
    file.open(filename);
    if (file.is_open()){
        for (uint i = 0; i < m_answers.size(); i++){
            file << m_answers.at(i) << endl;
        }
    } else {
        cout << "Error: Could not write to file: " << filename << endl;
    }
    file.close();
}


void Operator::addNumbers()
{
    for (uint i = 0; i < m_numbers.size()/2; i++){
        m_answers.push_back(m_numbers.at(i) + m_numbers.at(i+1));
    }
}

void Operator::subtractNumbers()
{
    for (uint i = 0; i < m_numbers.size()/2; i++){
        m_answers.push_back(m_numbers.at(i) - m_numbers.at(i+1));
    }
}

void Operator::multiplyNumbers()
{
    for (uint i = 0; i < m_numbers.size()/2; i++){
        m_answers.push_back(m_numbers.at(i)*m_numbers.at(i+1));
    }
}
