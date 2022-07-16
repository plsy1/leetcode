vector<vector<int> > generate(int numRows) {
    vector<vector<int> > nums(numRows);

    if (numRows == 0)
        return nums;
    for (int i = 0; i != numRows; ++i) {
        for (int j = 0; j <= i; ++j ) {
            if (j == 0 || j == i)
                nums[i].push_back(1);
            else
                nums[i].push_back(nums[i - 1][j - 1] + nums[i - 1][j]);
        }
    }
    return nums;
}
