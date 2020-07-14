class Solution {
public:
vector<int> findSubstring(string s, vector<string>& words) {
    if (words.size() == 0) return {}; // 为空时返回
    unordered_map<string, int> wordcnt;// 哈希表,存储单词表中的单词,用于与下面的哈希表windows进行比较

    for (auto& w : words) {
        wordcnt[w]++;// 将每一单词所对应的value置为1
    }
    int len = words[0].size();// 单词的长度,因为所有单词均为等长的

    vector<int> ans;// 用于存放结果

    for (int i = 0; i < len; i++) {// 字符串起始位置有len个
        int left = i;
        int right = left;
        int cnt = 0;

        unordered_map<string, int> window;
        while (left + words.size() * len <= s.size()) {// 避免访问内存超界
            string temp = "";
            while (cnt < words.size()) {
                temp = s.substr(right, len);// 将每个单词逐个传入比较
                if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break; // 对照哈希表未存入或者重复出现break
                window[temp]++;// 计数加一
                cnt++;
                right += len;// 跳到下一单词位置,循环结束right位于字符串末尾
            }

            if (window == wordcnt) {// 将两个哈希表进行对照,相同则存入ans进行返回
                ans.push_back(left);
            }

            if (wordcnt.find(temp) != wordcnt.end()) {// 将第一个拿掉,下次循环多比较一次加上最后面的
                window[s.substr(left, len)]--;
                cnt--;
                left += len;
            } else {
                right += len;// 跳到下一单词位置
                left = right;//同上
                cnt = 0;// 计数重置
                window.clear();// 清空哈希表
            }
        }
    }
    return ans;
} // findSubstring
};
