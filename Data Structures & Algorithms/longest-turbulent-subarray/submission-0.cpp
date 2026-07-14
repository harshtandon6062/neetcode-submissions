class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 1) return 1;

        int max_size = 1;
        int l = 0, r = 1;

        while (r < arr.size()) {
            // Handle equal adjacent elements
            if (arr[r] == arr[r - 1]) {
                max_size = max(max_size, r - l);
                l = r;
                r++;
                continue;
            }

            bool less_than = arr[r] < arr[r - 1];

            while (r < arr.size() && (less_than ^ (arr[r] > arr[r - 1]))) {
                r++;
                less_than = !less_than;

                // Stop if next pair is equal
                if (r < arr.size() && arr[r] == arr[r - 1])
                    break;
            }

            max_size = max(max_size, r - l);
            l = r - 1;
        }

        return max_size;
    }
};