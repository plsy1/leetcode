class Solution {
public:
	bool isSubsequence(string s, string t) {
		auto ite = s.begin();
		for(auto c : t)
			if(c == *ite)   ++ite;
		return ite == s.end();
	}
};
