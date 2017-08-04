/**
 *  * Definition for an interval.
 *   * struct Interval {
 *
 *    *     int start;
 *     *     int end;
 *      *     Interval() : start(0), end(0) {
 *      }
 *       *     Interval(int s, int e) : start(s), end(e) {
 *       }
 *        * };
 *         */
class Solution {

	public:
		vector<Interval> merge(vector<Interval>& intervals) {

			vector<Interval> res;
			if (intervals.size() == 0) {

				return res;
			} else if (intervals.size() == 1) {

				return intervals;
			}

			sort(intervals.begin(), intervals.end(), [](Interval x, Interval y){

					return x.start < y.start;  
					});

			int len = intervals.size();
			int now = 0;
			int end = intervals[now].end;
			for (int i = 1; i < len; i ++ ) {

				if (intervals[i].start > end) {

					res.push_back(Interval(intervals[now].start, end));
					now = i;
					end = intervals[now].end;
				} else {

					end = max(end, intervals[i].end);
				}
			}
			res.push_back(Interval(intervals[now].start, end));
			return res;
		}
};
