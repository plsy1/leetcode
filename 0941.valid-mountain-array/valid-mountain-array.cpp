class Solution {
public:
    bool validMountainArray(vector<int>& A) {
      if(A.size() == 0) return false;
      int border = 0;
      for(int i = 0;i != A.size()-1;++i) {
        if(A[i] < A[i+1]) continue;
        else {
          border = i;
          break;
          }
      }
      if(border == 0) return false;
      for(int i = border;i != A.size()-1;++i) {
        if(A[i] <= A[i+1]) return false;
      }
      return true;
    }
};
