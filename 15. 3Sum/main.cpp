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
 
 
 
 这个题，我在做的时候，遇到一个麻烦是，要求unique result 。。。。。  我我记得这种问题一般都是进行排序


这个问题我知道要用排序的思想去解决，但是我不知道具体的代码该如何去写啊，比如:

```
-2,-1,-1,-1
```

可是写这部分代码，我总是写成O(n**3)的时间复杂度。郁闷。。。。

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums,nums+ nums.size());
        vector<vector<int>> ret;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0 and nums[i] ==nums[i-1]) continue;
            for(int j = i+1; j<nums.size();j++)
            {
                if(j>i+1 and nums[j] == nums[j-1]) continue;
                
                for(int k = j+1;k<nums.size();k++)
                {
                    if(k>j+1 and nums[k] == nums[k-1]) continue;
                    ......
                }
                
                
            }
            
        }
        return ret;
            
    }
};
```

我还是看看答案吧。。。。

以下是我的代码，ac真的好困难

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 and nums[i] ==nums[i-1]) continue;
            int target = -nums[i];
            if(target<0) return ret;
            
            int begin = i+1;
            int end = nums.size()-1;
            
            while(begin<end)
            {
                if(begin>i+1 and nums[begin] == nums[begin-1])
                {
                    begin++;
                    continue;
                }
                if(end<nums.size()-1 and nums[end] == nums[end+1])
                {
                    end--;
                    continue;
                }
                
                if(nums[begin] + nums[end] > target) end--;
                else if(nums[begin] + nums[end] < target) begin++;
                else
                {
                    ret.push_back(vector<int> {nums[i],nums[begin],nums[end]});
                    begin++;
                    end --;
                }
            }
            
        }
        return ret;
    }
};
```

写这个题，这么费劲的原因是，我一直想用2sum的思路去解决问题，但是2sum里面假定是没有重复的数字的。假如2sum里面是有重复数字的话，我们依然要用这个方法
