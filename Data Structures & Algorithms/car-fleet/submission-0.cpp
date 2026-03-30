class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>car;
        int n=position.size();
        for(int i=0;i<n;i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.rbegin(),car.rend());
        vector<double>st;
        for(auto& p:car){
            st.push_back((double)(target-p.first)/p.second);
            if(st.size()>=2 && st.back()<=st[st.size()-2]){
                st.pop_back();
            }
        }
        return st.size();
    }
};
