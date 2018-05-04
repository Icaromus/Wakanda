#include "Field.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
//#include "Character.h"/
using namespace std;


int main() {
    
    Field f(15, 15);
    f.generateRandomField();
    f.printField();


    return 0;
}
