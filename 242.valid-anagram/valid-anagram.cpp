bool isAnagram(string s,string t){
  if(s.size() != t.size())
    return false;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  if(s == t)
    return true;
  else
    return false;
}

bool isAnagram(string s,string t){
  if(s.size() != t.size())
    return false;
  int temp[26] = {0};
  for(int i = 0;i!=s.size();++i)
  {
    temp[s[i] - 'a']++;
    temp[t[i] - 'a']--;
  }
  for(int i = 0;i!=26;++i)
    if(temp[i] != 0)
      return false;
    return true;
}
