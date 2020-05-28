int largestPerimeter(vector<int>& A){
    if (A.size() <= 2)
        return 0;
    sort(A.begin(), A.end());
    int len = A.size();
    int triangle;

    for (int i = len - 1; i != 1; --i) {
        int temp = A[i - 1] + A[i - 2];
        if (A[i] < temp) {
            triangle = A[i] + temp;
            return triangle;
        }
    }
    return 0;
}
