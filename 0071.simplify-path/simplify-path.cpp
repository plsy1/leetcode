class Solution {
 public:
  string simplifyPath(string path) {
    string res, tmp;
    vector<string> folder;
    istringstream is(path);
    while (getline(is, tmp, '/')) {
      if (tmp == "" || tmp == ".")
        continue;
      else if (tmp == "..") {
        if (!folder.empty()) folder.pop_back();
      } else
        folder.push_back(tmp);
    }
    if (folder.empty()) return "/";

    for (auto s : folder) {
      res += "/" + s;
    }
    return res;
  }
};
