class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto got = m.find(target - nums[i]);
            if (got != m.end()) {
                vector<int> result {got->second, i};
                return result;
            } else {
                m[nums[i]] = i;
            }
        }
        return vector<int>{-1};
    }
};
