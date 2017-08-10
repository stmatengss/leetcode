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
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

			vector<Interval> res;
			if (intervals.size() == 0) {

				res.push_back(newInterval);
				return res;
			}

			intervals.push_back(Interval(1000000000, 1000000000));
			int len = intervals.size();
			int st1 = 0, st2 = 0;
			int start, end;

			for (int i = 0; i < len; i ++) {

				if (st1 == 0 && newInterval.start <= intervals[i].start ) {

					st1 ++;
					start = newInterval.start;
				} 
				if (st1 == 0 && newInterval.start <= intervals[i].end) {

					st1 ++;
					start = intervals[i].start;
				} 

				if (st2 == 0 && newInterval.end < intervals[i].start) {

					st2 ++;
					end = max(newInterval.end, intervals[i - 1].end);
					res.push_back(Interval(start, end));
				} 

				if ((st1 == 1 && st2 == 0) || i == len - 1)continue;
				res.push_back(intervals[i]);

			}
			return res; 
		}
};
