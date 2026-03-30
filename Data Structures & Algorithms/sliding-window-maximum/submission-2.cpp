class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
         int n=nums.size();
        // for(int i=0;i+k<=n;i++){
        //    // for(int j=i;j<k;j++){
        //         int maxi=*max_element(nums.begin(),nums.begin()+i+k);
        //         res.push_back(maxi);
        //    // }
        // }
        deque<int>dq;
        for(int i=0;i<k;i++){
            while(dq.size()>0&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
         for(int i=k;i<n;i++){
            res.push_back(nums[dq.front()]);
            while(dq.size()>0&&dq.front()<=i-k){
                dq.pop_front();
            }  while(dq.size()>0&&nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
       
        } res.push_back(nums[dq.front()]);
        return res;
    }
};
