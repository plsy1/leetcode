class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordCount(wordList.begin(), wordList.end());
    if (wordCount.find(endWord) == wordCount.end()) return 0;
    unordered_set<string> beginSet{beginWord}, endSet{endWord};
    int res = 1;

    while (!beginSet.empty()) {
      unordered_set<string> nextSet;
      ++res;
      for (auto& word : beginSet) wordCount.erase(word);
      for (auto& word : beginSet) {
        for (int i = 0; i != word.size(); ++i) {
          string curWord = word;
          for (int j = 'a'; j <= 'z'; ++j) {
            curWord[i] = j;
            if (endSet.find(curWord) != endSet.end()) return res;
            if (wordCount.find(curWord) != wordCount.end())
              nextSet.insert(curWord);
          }
        }
      }
      beginSet = nextSet;
      if (beginSet.size() > endSet.size()) swap(beginSet, endSet);
    }
    return 0;
  }
};
