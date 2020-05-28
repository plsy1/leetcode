#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int space = numRows * 2 - 2;
    int index = 0;
    int len = s.length();
    int add = 0;
    string ret;

    for (int i = 0; i < numRows; ++i) {
        index = i;
        add = i * 2;
        while (index < len) {
            ret += s[index];
            add = space - add;
            index += (i == 0 || i == numRows - 1) ? space : add;
        }
    }
    return ret;
}
int main(int argc, char const * argv[]) {
    cout << convert("hello,world!", 3);
    return 0;
}
