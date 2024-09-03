#include <bits/stdc++.h>

using namespace std;

 

vector<int> findFreeIntervals(vector<vector<int>> &schedules) {

    vector<pair<int, int>> intervals;

    

    for (const auto& schedule : schedules) {

        for (size_t i = 0; i < schedule.size(); i += 2) {

            intervals.emplace_back(schedule[i], schedule[i+1]);

        }

    }

 

    sort(intervals.begin(), intervals.end());

 

    vector<pair<int, int>> mergedIntervals;

    int currentStart = intervals[0].first;

    int currentEnd = intervals[0].second;

 

    for (size_t i = 1; i < intervals.size(); ++i) {

        if (intervals[i].first <= currentEnd) {

            currentEnd = max(currentEnd, intervals[i].second);

        } else {

            mergedIntervals.emplace_back(currentStart, currentEnd);

            currentStart = intervals[i].first;

            currentEnd = intervals[i].second;

        }

    }

    mergedIntervals.emplace_back(currentStart, currentEnd);

 

    vector<int> freeIntervals;

    int dayStart = 0;

    int dayEnd = 1e8;

 

    if (mergedIntervals[0].first > dayStart) {

        freeIntervals.push_back(dayStart);

        freeIntervals.push_back(mergedIntervals[0].first - 1);

    }

 

    for (size_t i = 1; i < mergedIntervals.size(); ++i) {

        if (mergedIntervals[i].first > mergedIntervals[i - 1].second + 1) {

            freeIntervals.push_back(mergedIntervals[i - 1].second + 1);

            freeIntervals.push_back(mergedIntervals[i].first - 1);

        }

    }

 

    if (mergedIntervals.back().second < dayEnd) {

        freeIntervals.push_back(mergedIntervals.back().second + 1);

        freeIntervals.push_back(dayEnd);

    }

 

    return freeIntervals;

}
