#include <iostream>
#include <sstream>
using namespace std;
int myAtoi(string str) {
    int sb = 0;
    istringstream is(str);

    is >> sb;
    return sb;
}
int main(int argc, char const * argv[]) {
    cout << myAtoi("8848");
    return 0;
}
