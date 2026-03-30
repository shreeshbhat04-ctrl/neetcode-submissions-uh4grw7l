class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int x:nums){
            freq[x]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto&p:freq){
            pq.push({p.second, p.first});
        }
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};