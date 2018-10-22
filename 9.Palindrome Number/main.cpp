class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<=9) return true;
        int num =0;
        int num_x = x;
        while(x)
        {
            num *=10;
            num += x % 10;
            x = x/10;

        }
        if(num == num_x) return true;
        else return false;

    }
};