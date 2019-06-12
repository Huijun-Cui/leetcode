

# beat 30%  O(nlong(n))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> dict; // <number,index>
        int index = 0;
        int max = 0;
        int current_length = 0;
        int pre_index = 0;
        for(auto c:s)
        {

            if(dict.find(c) == dict.end())
            {
                dict[c] = index;
                current_length +=1;
                if(current_length > max)
                    max = current_length;
            }

            else
            {
                if((index - dict[c]) > max)
                    max = index - dict[c];


                int target_char_index = dict[c];

                for(int del_index = 0 + pre_index;del_index <= target_char_index;del_index++)
                {

                    dict.erase(s[del_index]);
                    current_length -=1;


                }


                pre_index = target_char_index + 1;
                dict[c] = index;
                current_length +=1;
                if(current_length > max)
                    max = current_length;



            }
            index +=1;
        }
        return max;

    }
};

beat 60% O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

# 网上的方法，真的好简洁 Python 60 ms, 93.45%

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
            
        d = {}
        
        max_len = 0
        cur_len = 0
        
        for i,c in enumerate(s):
            cur_len += 1
                
            if c in d:
                
                last_c_ind = d[c]
                t_len = i - last_c_ind
                
                if cur_len-1 >= t_len:
                    cur_len = t_len
            
            d[c] = i
            
            if cur_len > max_len:
                max_len = cur_len
                
            
        return max_len


# 我的python 方法 60ms

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        root_ix = -1
        cur_len = 0
        max_len = 0
        s2ix = {}
        for ix,item in enumerate(s):
            if item not in s2ix: 
                cur_len +=1
                if cur_len > max_len:
                    max_len = cur_len
                s2ix[item] = ix
            else:
                tmp_ix = s2ix[item] +1
                if tmp_ix > root_ix:
                    root_ix = tmp_ix
                    cur_len = ix - s2ix[item]
                else:
                    cur_len +=1
                if cur_len > max_len:
                        max_len = cur_len
                s2ix[item] = ix
        if cur_len > max_len:
            max_len = cur_len
            
        return max_len
                





