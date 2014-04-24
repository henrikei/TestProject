#include <iostream>
#include "operator/operator.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 4){
        cout << "Error: Executable needs 3 variables." << endl;
        exit(EXIT_FAILURE);
    }
    Operator op(argv[1], argv[2]);
    op.writeToFile(argv[3]);
    return 0;
}

