#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class TaskManager {
    priority_queue<pair<int, int>> tasks; // {priority, taskId}
    unordered_map<int, int> taskPriority; // taskId -> priority
    unordered_map<int, int> taskOwner;    // taskId -> userId

public:
    TaskManager(vector<vector<int>>& initialTasks) {
        for (const auto& task : initialTasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        tasks.push({priority, taskId});
        taskPriority[taskId] = priority;
        taskOwner[taskId] = userId;
    }

    void edit(int taskId, int newPriority) {
        tasks.push({newPriority, taskId});
        taskPriority[taskId] = newPriority;
    }

    void rmv(int taskId) {
        taskPriority[taskId] = -1; // Mark as removed
    }

    int execTop() {
        while (!tasks.empty()) {
            const auto task = tasks.top();
            tasks.pop();
            if (task.first == taskPriority[task.second]) {
                taskPriority[task.second] = -1; // Mark as executed
                return taskOwner[task.second];
            }
        }
        return -1; // No valid task found
    }
};

int main() {
    // Initial tasks: {userId, taskId, priority}
    vector<vector<int>> initialTasks = {
        {1, 101, 5},
        {2, 102, 3},
        {3, 103, 7}
    };

    TaskManager* manager = new TaskManager(initialTasks);

    // Add a new task
    manager->add(4, 104, 6);

    // Edit an existing task's priority
    manager->edit(102, 8); // taskId 102 now has priority 8

    // Remove a task
    manager->rmv(101); // taskId 101 is removed

    // Execute the top priority task
    int userId = manager->execTop();
    cout << "Executed task belongs to user: " << userId << endl;

    // Execute next top priority task
    userId = manager->execTop();
    cout << "Executed task belongs to user: " << userId << endl;

    delete manager;
    return 0;
}
