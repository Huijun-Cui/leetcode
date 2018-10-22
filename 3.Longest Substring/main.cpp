

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

