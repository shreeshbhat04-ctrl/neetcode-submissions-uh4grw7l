class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>minh;int K;
    KthLargest(int k, vector<int>& nums) {
      for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size()>k)minh.pop();
        }
        K=k;
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size()>K)minh.pop();
        return minh.top();
    }
};
