public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /**
        // Initialize vector
        // Idea was slow and straightforward
        vector<int> sum;
        // Nested for loop to go through everything
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    sum.insert(sum.begin(), i);
                    sum.insert(sum.begin(), j);
                }
            }
        }
        // Return sum
        return sum;
        */
        // Initialize hash map
        unordered_map<int, int> map;
        // Initialize vector
        vector<int> sum;
        
        // Insert elements
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        // Check if complement exists and return
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(map.find(complement) != map.end() && map[complement] != i) {
                sum.insert(sum.begin(), map[complement]);
                sum.insert(sum.begin(), i);
                return sum;
            }
            //map[nums[i]] = i;
        }
        return sum;
    }
};
