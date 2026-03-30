class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        // Choice: skip or take
        int take = nums[i] + solve(i - 2, nums, dp);
        int skip = solve(i - 1, nums, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: rob from 0 to n-2
        vector<int> a(nums.begin(), nums.end() - 1);
        vector<int> dp1(a.size(), -1);
        int case1 = solve(a.size() - 1, a, dp1);

        // Case 2: rob from 1 to n-1
        vector<int> b(nums.begin() + 1, nums.end());
        vector<int> dp2(b.size(), -1);
        int case2 = solve(b.size() - 1, b, dp2);

        return max(case1, case2);
    }
};
