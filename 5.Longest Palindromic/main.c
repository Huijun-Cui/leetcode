class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int index_store = 0;
        int cur_len;
        for(int i = 1;i<s.size();i++)
        {
            int index = 1;
            cur_len = 1;
            for(int j=i;j-index >=0 && j+index < s.size();index++)
            {
                if(s[j-index] == s[j+index]) cur_len +=2;
                else break;
            }
            if(cur_len > max)
            {
                max = cur_len;
                index_store = i;
                // cout<<i<<endl;
                // cout<<max<<endl;
            }
        }
        string s_out;
        for(int i = index_store-(max-1)/2;i<=index_store + (max-1)/2;i++)
        {
            //cout<<max<<endl;
            s_out = s_out +=s[i];
            //cout<<s[i]<<endl;
        }

        for(int i=0;i<s.size();i++)
        {
            cur_len = 0;
            int index = 0;
            // cout<<"the test string is : "<<s<<endl;
//             for(int j =i+1;j+index<s.size()&&i-index>=0;index++)
//             {
//                 cout<<"s[i] == "<<s[i]<<"  s[j] =="<<s[j]<<endl;
//                 if(s[i] == s[j])
//                 {
//                     cur_len +=2;
//                     index_store = i;
//                     cout<<"the length is "<<cur_len<<endl;

//                 }

//                 else break;
//             }
            int j  = i;
            do
            {
                // cout<<"s[i] == "<<s[i]<<"  s[j] =="<<s[j]<<endl;
                if(s[i] == s[j])
                {
                    cur_len +=2;
                    index_store = i;
                    // cout<<"the length is "<<cur_len<<endl;

                }

                else break;

            }while(j+index<s.size()&&i-index>=0);
            if(cur_len > max)
            {
                cout<<index_store<<endl;
                s_out = "";
                // cout<<"index_store is "<<index_store;
                // cout<<"cur len is "<<cur_len<<endl;
                for(int i =index_store - cur_len/2 +1;i <=index_store + cur_len/2;i++)
                {
                    s_out += s[i];
                }
                // cout<<"the s_out is : "<<s_out<<endl;
            }

        }




        return s_out;

    }
};
