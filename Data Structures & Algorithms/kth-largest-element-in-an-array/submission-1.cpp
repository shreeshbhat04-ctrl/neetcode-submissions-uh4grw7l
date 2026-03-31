class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // return nums[n-k];
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
