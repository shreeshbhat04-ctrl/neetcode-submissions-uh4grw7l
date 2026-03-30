class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n=num.size();
        int st=0,end=n-1;
        while(st<end){
            int sum=num[st]+num[end];
            if(sum==target){
                return{st+1,end+1};
            }else if(sum<target){
                st++;
            }else{
                end--;
            }
        }
        return {};
    }
};
