
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
		int fleet = 0;
        if (n == 0) return 0;

		vector<pair<int, int>> cars;
		for (int i = 0; i < n; i++) {
			cars.push_back({position[i], speed[i]});
		}

		// Sort by position in descending order (closest to target first)
		sort(cars.begin(), cars.end(), greater<pair<int, int>>());
		// Print sorted cars
		double current_time = 0.0, max_time = 0.0;
		for (int i = 0; i < n; i++) {
			current_time = (double)(target - cars[i].first) / cars[i].second;
			if (current_time > max_time) {
				fleet++;
				max_time = current_time;
			}

		}

		return fleet;
    }
};
