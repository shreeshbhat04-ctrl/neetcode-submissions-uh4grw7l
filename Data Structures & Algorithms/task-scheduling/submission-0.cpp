class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26,0);
        for(char ta:tasks){
            cnt[ta-'A']++;
        }
        priority_queue<int>maxh;
        for(int x:cnt){
            if(x>0){
                maxh.push(x);
            }
        }
        int time=0;
        queue<pair<int,int>>q;
        while(!maxh.empty()||!q.empty()){
            time++;
            if(maxh.empty()){
                time=q.front().second;
            }else{
                int ct=maxh.top()-1;
                maxh.pop();
                if(ct>0){
                    q.push({ct,time+n});
                }
            }
            if(!q.empty()&&q.front().second==time){
                maxh.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
