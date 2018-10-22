
// this is code returns wrong answer,but the description is really unclear.

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        while(index<str.size() && str[index] == ' ') index +=1;
        if(index == str.size() || (!isdigit(str[index]) &&str[index] !='-'&&str[index]!='+')) return 0;
        if


        long num = 0;
        int flag = 1;
        if(str[index] == '-')
        {
            flag = -1;
            index +=1;
        }
        if(str[index] == '+')
        {
            flag = 1;
            index +=1;
        }
        while(index<str.size() && isdigit(str[index]))
        {
            num *= 10;
            num += str[index] - '0';
            index +=1;
        }
        if(num * flag > INT_MAX) return INT_MAX;
        if(num * flag < INT_MIN) return INT_MIN;
        return num * flag;

}
};
