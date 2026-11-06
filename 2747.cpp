class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // Sort logs by timestamp in ascending order
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
      
        int numQueries = queries.size();
      
        // Create pairs of (query_value, original_index) to maintain original order after sorting
        vector<pair<int, int>> queryPairs(numQueries);
        for (int i = 0; i < numQueries; ++i) {
            queryPairs[i] = {queries[i], i};
        }
      
        // Sort queries by value in ascending order
        sort(queryPairs.begin(), queryPairs.end());
      
        // Map to count requests per server within the time window
        unordered_map<int, int> serverRequestCount;
      
        // Result array to store answers in original query order
        vector<int> result(numQueries);
      
        // Two pointers for sliding window
        int leftPointer = 0;   // Points to the start of the time window
        int rightPointer = 0;  // Points to the end of the time window
      
        // Process each query in sorted order
        for (auto& [queryTime, originalIndex] : queryPairs) {
            // Calculate the left boundary of the time window [queryTime - x, queryTime]
            int windowStart = queryTime - x;
          
            // Add all logs with timestamp <= queryTime to the window
            while (rightPointer < logs.size() && logs[rightPointer][1] <= queryTime) {
                int serverId = logs[rightPointer][0];
                ++serverRequestCount[serverId];
                ++rightPointer;
            }
          
            // Remove all logs with timestamp < windowStart from the window
            while (leftPointer < logs.size() && logs[leftPointer][1] < windowStart) {
                int serverId = logs[leftPointer][0];
                --serverRequestCount[serverId];
              
                // Remove server from map if it has no requests in the window
                if (serverRequestCount[serverId] == 0) {
                    serverRequestCount.erase(serverId);
                }
                ++leftPointer;
            }
          
            // Calculate number of servers with no requests in the time window
            // Total servers - servers with at least one request
            result[originalIndex] = n - serverRequestCount.size();
        }
      
        return result;
    }
};
