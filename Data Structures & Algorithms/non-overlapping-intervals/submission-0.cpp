class Solution {
public:
    int f(vector<vector<int>>& intervals, int idx, int prev, vector<vector<int>>& dp) {
        if (idx == intervals.size()) return 0;
        if (dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int res = f(intervals, idx+1, prev, dp);
        if (prev == -1 || intervals[prev][1] <= intervals[idx][0]) {
            res = max(res, 1 + f(intervals, idx+1, idx, dp));
        }
        return dp[idx][prev+1] = res;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        vector<vector<int>> dp(intervals.size(), vector<int>(intervals.size()+1, -1));
        int maxNonOverlap = f(intervals, 0, -1, dp);
        return intervals.size() - maxNonOverlap;
    }
};
