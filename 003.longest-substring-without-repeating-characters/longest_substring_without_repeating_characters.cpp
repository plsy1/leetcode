int lengthOflongestSubstring(string s){
    if (s.size() == 0) return 0;
    unordered_set<char> lookup;
    int maxStr = 0;
    int left = 0;

    for (int i = 0; i < s.size(); ++i) {
        while (lookup.find(s[i]) != lookup.end()) {
            lookup.erase(s[left]);// 窗口内找到相同值，则删除
            ++left;
        }
        maxStr = max(maxStr, i - left + 1);
        lookup.insert(s[i]);//删除后再加回来，保证在窗口中同一值只出现一次
    }
    return maxStr;
}
