#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks based on the difference (minimum - actual) in descending order.
        // This greedy approach ensures we tackle tasks with the largest "surplus"
        // requirements first, utilizing high initial energy effectively.
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int totalInitialEnergy = 0;
        int currentEnergy = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If current energy is less than what's required to start the task,
            // we must increase our initial energy pool.
            if (currentEnergy < minimum) {
                int deficit = minimum - currentEnergy;
                totalInitialEnergy += deficit;
                currentEnergy += deficit;
            }

            // Spend the actual energy required for the task.
            currentEnergy -= actual;
        }

        return totalInitialEnergy;
    }
};