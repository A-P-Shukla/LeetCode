#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Convert "MM-DD" to day-of-year (1‑based)
    static int toDayOfYear(const string& date) {
        static const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int month = stoi(date.substr(0, 2));
        int day   = stoi(date.substr(3, 2));
        int dayOfYear = day;
        for (int m = 1; m < month; ++m) {
            dayOfYear += monthDays[m-1];
        }
        return dayOfYear;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int aStart = toDayOfYear(arriveAlice);
        int aEnd   = toDayOfYear(leaveAlice);
        int bStart = toDayOfYear(arriveBob);
        int bEnd   = toDayOfYear(leaveBob);

        int overlapStart = max(aStart, bStart);
        int overlapEnd   = min(aEnd,   bEnd);
        if (overlapStart > overlapEnd) return 0;
        return overlapEnd - overlapStart + 1;
    }
};