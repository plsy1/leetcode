#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s) {
  map<char,int> nums;
  int result = 0;
  nums.insert(map<char,int>::value_type('I',1));
  nums.insert(map<char,int>::value_type('V',5));
  nums.insert(map<char,int>::value_type('X',10));
  nums.insert(map<char,int>::value_type('L',50));
  nums.insert(map<char,int>::value_type('C',100));
  nums.insert(map<char,int>::value_type('D',500));
  nums.insert(map<char,int>::value_type('M',1000));
  for(int i = 0;i<s.length();++i) {
    if(nums[s[i]] >= nums[s[i+1]])
      result += nums[s[i]];
    else {
      result += (nums[s[i+1]] - nums[s[i]]);
      ++i;
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {
  string s = "MCMXCIV";
  int result = romanToInt(s);
  cout << result;
  return 0;
}
