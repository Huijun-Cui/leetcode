class Solution {
public:
    int reverse(int x) {
        int min,max,base = 1;
        min = -1 * base;
        max = base -1;
        long tmp = 0;
        while(x)
        {
            tmp *= 10;
            tmp += x%10;
            x = x/10;
        }
        //cout<<"tmp == : "<<tmp<<endl;
        if(tmp <INT_MIN || tmp > INT_MAX) return 0;
        return tmp;


    }
};