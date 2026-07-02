class TimeMap {
private: 
	unordered_map<string, vector<pair<string, int>>> map;
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
		map[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
		int left = 0;
		int right = map[key].size() - 1;
		string res;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (timestamp == map[key][mid].second)
				return map[key][mid].first;
			else if (timestamp < map[key][mid].second) {
				right = mid - 1;
			} else {
				res =  map[key][mid].first;
				left = mid + 1;
			}
		}

		return res;
    }
};
