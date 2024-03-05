class Solution{
    public:
    int maxIndexDiff(int arr[], int n) 
    { 
        int left_min[n], right_max[n];
        left_min[0] = arr[0];
        right_max[n - 1] = arr[n - 1];
        // Build left_min and right_max arrays
        for (int i = 1; i < n; i++) {
            left_min[i] = min(left_min[i - 1], arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], arr[i]);
        }
        // Find the maximum difference
        int max_dist = -1, i = 0, j = 0;
        while (i < n && j < n) {
            if (left_min[i] <= right_max[j]) {
                max_dist = max(max_dist, j - i);
                j++;
            } else {
                i++;
            }
        }
    return max_dist;
    }
};
