class TimeMap {
public: 

    unordered_map<string, vector<pair<string, int>>> keyValMap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyValMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (keyValMap.find(key) == keyValMap.end()) {
            return "";
        }
        vector<pair<string, int>> &values = keyValMap[key];

        if (values[0].second > timestamp) {
            return "";
        }
        int min = 0, max = values.size()-1;
        while (min < max) {
            int mid = min + (max-min+1)/2;
            if (timestamp < values[mid].second) {
                max = mid - 1;
            } else {
                min = mid;
            }
        }

        return values[min].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */