class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> nextTask;
        vector<vector<int>> sortedTasks;
        for(int i = 0; i < tasks.size(); ++i) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(sortedTasks.begin(), sortedTasks.end());
        vector<int> tasksProcessingOrder;
        long long currTime = 0;
        int numTasks = 0;
        while (numTasks < tasks.size() || !nextTask.empty()) {
            if (nextTask.empty() && currTime < sortedTasks[numTasks][0]) {
                currTime = sortedTasks[numTasks][0];
            }
            while (numTasks < sortedTasks.size() && currTime >= sortedTasks[numTasks][0]) {
                nextTask.push({sortedTasks[numTasks][1], sortedTasks[numTasks][2]});
                numTasks++;
            }
            auto [processTime, index] = nextTask.top();
            nextTask.pop();
            currTime += processTime;
            tasksProcessingOrder.push_back(index);
        }
        return tasksProcessingOrder;
    }
};