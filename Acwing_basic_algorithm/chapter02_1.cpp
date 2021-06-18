#include <iostream>
#include <string.h>

using namespace std;



int main() {
    char c[30];
    string str = "1234";

    strcpy(c,str.c_str());

    cout << c;

}
