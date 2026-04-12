class CustomComparator {
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            if (a.second < b.second) {
                return true;
            } else if (a.second == b.second) {
                return a.first > b.first;
            }
            return false;
        } 
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomComparator> pq;
        map<int, int> freq;
        for (int i = 0; i < tasks.size(); i++) {
            if (freq.find(tasks[i]-'A') == freq.end()) {
                freq[tasks[i]-'A'] = 1;
            } else {
                freq[tasks[i]-'A']++;
            }
        }
        for (auto u : freq) {
            pq.push({u.first, u.second});
        }

        int multiple = 0;

        while (!pq.empty()) {
            vector<pair<int, int>> temp;
            for (int i = 0; i <= n; i++) {
                pair<int, int> top = pq.top();
                pq.pop();
                cout << top.first + 'A' << " " << top.second << endl;
                if (top.second > 1) {
                    temp.push_back({top.first, top.second - 1});
                }
                if (pq.empty()) {
                    if (temp.empty()) {
                        return (n+1)*multiple + i + 1;
                    }
                    break;
                }
            }
            multiple++;
            for (int i = 0; i < temp.size(); i++) {
                pq.push({temp[i].first, temp[i].second});
            }
        }

        return (n+1)*multiple;
    }
};