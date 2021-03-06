class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Only really have to search if there's more than 2 elements...
        if(nums.size() > 2){
            // So... the known solution is to use a hashmap with the stored differences...
            map<int,int> summer; // <number,index>
            for(int i=0;i<nums.size();i++){
                int theDiff = target-nums[i];
                if(summer.find(theDiff)==summer.end()){
                    summer[nums[i]]=i;
                } else {
                    return {summer[theDiff],i};
                }
            }
        }
        //If there's only 2 elements, obviously that's the answer then...
        return {0,1};
    }
};

