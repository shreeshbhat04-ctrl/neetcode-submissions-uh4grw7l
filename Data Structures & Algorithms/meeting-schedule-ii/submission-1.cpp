/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int cnt=1;
        sort(intervals.begin(),intervals.end(),[](auto& x,auto& y){
            return x.start<y.start;
        });
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(auto& in:intervals){
         if(!minheap.empty()&&minheap.top()<=in.start){
            minheap.pop();
         }
         minheap.push(in.end);
        }
        return minheap.size();
    }
};
