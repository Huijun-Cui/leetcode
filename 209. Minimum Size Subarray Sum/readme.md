这个题有意思，有点像之前做过的连续数组最大值，但这个又有点不一样

这个就是用快慢指针来搞吧，开始撸代码

代码两次ac ,但是写的非常烂，因为我做做个题的时候，要求自己速度。 所以没有太顾上优雅

```
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        p_slow = p_fast = 0

        min_len = len(nums) + 1
        
        if len(nums) == 0:
            return 0
        
        acu_num = nums[0]

        while p_fast < len(nums):

            if acu_num < s:

                p_fast += 1
                if p_fast < len(nums):
                    acu_num += nums[p_fast]

            else:

                if p_fast - p_slow + 1 < min_len:
                    min_len = p_fast - p_slow + 1

                p_slow += 1


                acu_num -= nums[p_slow-1]

                if p_slow > p_fast:
                    p_fast = p_slow
                    if p_slow < len(nums):
                        acu_num = nums[p_slow]
        if min_len == len(nums) +1:
            return 0
        return min_len
```

我把代码再改了一下

```
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        
        min_len = len(nums) + 1
        
        
        
        if len(nums) == 0:
            return 0
        acu_num = nums[0]
        
        p_slow = p_fast = 0
        
        while p_fast < len(nums):
            
            if p_fast < p_slow:
                p_fast = p_slow
                acu_num = nums[p_slow]
            
            if acu_num < s:
                
                p_fast+=1
                if p_fast < len(nums):
                    acu_num +=nums[p_fast]
                continue
            else:
                
                if p_fast - p_slow + 1 < min_len:
                    min_len = p_fast - p_slow + 1
                
                p_slow +=1
                if p_slow >= len(nums):
                    break
                acu_num -= nums[p_slow-1]
        if min_len == len(nums)+1:
            return 0
        return min_len
```

代码就在一处简略了一下，看看网上代码是怎么写的吧 



看看下面这个代码，写的真的是太棒了，没有用快慢指针，也就不需要做边界判断，代码自然就简单了。唉 。。。佩服
```
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            ans = min(ans, i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
```