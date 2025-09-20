#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Router {
private:
    int size;
    unordered_map<long long, vector<int>> packets;
    unordered_map<int, vector<int>> counts;
    queue<long long> q;

    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    int lowerBound(vector<int>& list, int target) {
        return (int)(lower_bound(list.begin(), list.end(), target) - list.begin());
    }

    int upperBound(vector<int>& list, int target) {
        return (int)(upper_bound(list.begin(), list.end(), target) - list.begin());
    }

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);

        if (packets.find(key) != packets.end())
            return false;

        if ((int)packets.size() >= size)
            forwardPacket();

        packets[key] = {source, destination, timestamp};
        q.push(key);
        counts[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};

        long long key = q.front();
        q.pop();

        vector<int> packet = packets[key];
        packets.erase(key);

        int dest = packet[1];
        counts[dest].erase(counts[dest].begin());  // remove earliest timestamp

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if (it == counts.end() || it->second.empty())
            return 0;

        vector<int>& list = it->second;

        int left = lowerBound(list, startTime);
        int right = upperBound(list, endTime);

        return right - left;
    }
};

int main() {
    Router router(3);  // memory limit of 3 packets

    // Add packets
    cout << "Add packet 1: " << router.addPacket(1, 2, 100) << endl;
    cout << "Add packet 2: " << router.addPacket(1, 2, 200) << endl;
    cout << "Add packet 3: " << router.addPacket(2, 3, 150) << endl;
    cout << "Add packet 4 (triggers forward): " << router.addPacket(3, 2, 250) << endl;

    // Get count of packets to destination 2 between time 100 and 300
    cout << "Count to destination 2 between 100 and 300: " << router.getCount(2, 100, 300) << endl;

    // Forward a packet
    vector<int> forwarded = router.forwardPacket();
    if (!forwarded.empty()) {
        cout << "Forwarded packet: source=" << forwarded[0]
             << ", destination=" << forwarded[1]
             << ", timestamp=" << forwarded[2] << endl;
    }

    // Final count check
    cout << "Count to destination 2 between 100 and 300: " << router.getCount(2, 100, 300) << endl;

    return 0;
}
