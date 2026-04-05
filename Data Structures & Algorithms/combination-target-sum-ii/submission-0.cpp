class Solution {
public:
//set<vector<int>>s;
void getall(vector<int>& candidates,int start,vector<int>&combin,vector<vector<int>>&ans, int target){
    //if(i==candidates.size()||target<0){return;}not required
    if(target==0){
          ans.push_back(combin);
        return;}
        for(int i=start;i<candidates.size();i++){
            if(i>start&&candidates[i]==candidates[i-1])continue;// this skips duplicates
           if(candidates[i]>target)break;
           combin.push_back(candidates[i]);
           getall(candidates,i+1,combin,ans,target-candidates[i]);
           combin.pop_back(); 
        }
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>combin;
         getall(candidates,0,combin,ans,target);
        return ans;
        
    }
};