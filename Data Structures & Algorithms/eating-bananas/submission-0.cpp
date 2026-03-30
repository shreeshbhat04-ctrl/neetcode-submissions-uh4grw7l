class Solution {
public:
bool can(vector<int>&piles,int h,int k){
    long long hour=0;
    for(int x:piles){
        hour+=x/k;
        if(x%k!=0)hour++;
        if(hour>h)return false;
    }
    return hour<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1,end=*max_element(piles.begin(),piles.end()),ans=end;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(can(piles,h,mid)){
                ans=mid;
                end=mid-1;
            }else{
              st=mid+1;
            }
        }
        return ans;
    }
};
