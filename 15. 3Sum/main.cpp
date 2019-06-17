class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }

        }

        //Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i])
            i++;

    }

    return res;

}
};


# 我第二次做的时候，一直不能解决 tripe 是 unordered unique的问题，后来看了答案，原来是用排序的思想解决了
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ix_store = []
        result = []
        tup_dic = {}
        
        i,j = 0,0
        
        while i < len(nums):
            j = i+1
            while j < len(nums):
                if -(nums[i] + nums[j]) not in tup_dic:
                    tup_dic[-(nums[i] + nums[j])] = []
                tup_dic[-(nums[i]+nums[j])].append((i,j))
                j+=1
            i +=1
        for ix,item in enumerate(nums):
            if item in tup_dic:
                for _item in tup_dic[item]:
                    if _item[1] < ix:
                        result.append(list(_item) + [ix])
        return result
                    
