class Solution {
public:
bool isPalindrome(string s) {
    if (s.empty()) return true;
    string temp;

    for (char c : s) {
        if (isdigit(c) || isalpha(c))
            temp += tolower(c);
    }
    int j = temp.size() - 1;

    for (int i = 0; i != temp.size(); ++i) {
        if (temp[i] != temp[j--])
            return false;
    }
    return true;
}
};
