class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if(divisor<0){
            divisor*=-1;
            dividend*=-1;
        }
        if(dividend>2147483647&&divisor==1)return 2147483647;
        return dividend/divisor;
    }
};