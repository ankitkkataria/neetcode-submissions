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
        sort(intervals.begin(), intervals.end(), [](const Interval&a, const Interval&b){
            return a.start > b.start;
        });
        
        map<int, int>hashmap;

        for(auto interval : intervals)  {
            hashmap[interval.start] += 1;
            hashmap[interval.end] -= 1;
        }

        int res = 0;
        int tempRes = 0;
        for(auto entry : hashmap) {
            tempRes += entry.second;
            res = max(res, tempRes);
        }
        return res;
    }
};
