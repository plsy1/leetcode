class MinStack {
 public:
  /** initialize your data structure here. */
  vector<int> nums;
  vector<int> min;
  MinStack() {}

  void push(int x) {
    nums.push_back(x);
    if (min.size() == 0)
      min.push_back(x);
    else if (x <= min[min.size() - 1])
      min.push_back(x);
  }

  void pop() {
    if (nums.size() == 0) return;
    if (nums[nums.size() - 1] == min[min.size() - 1]) min.pop_back();
    nums.pop_back();
  }

  int top() { return nums[nums.size() - 1]; }

  int getMin() { return min[min.size() - 1]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
