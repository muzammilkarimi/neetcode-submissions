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
        // sort(intervals.begin(),intervals.end(), [](auto& x, auto& y) {
        //     return x.start < y.start;
        // });
        map<int,int> mp;
        for(int i=0; i<intervals.size();i++){
            mp[intervals[i].start]++;
            mp[intervals[i].end]--;
        }
        int ans = 0,count=0;
        for(const auto& i:mp){
            count+=i.second;
            ans = max(ans,count);
        }
        return ans;
    }
};
