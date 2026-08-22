class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1, num = n;

        while(num>0){
            s += num%10;
            p *= num%10;
            num /=10;
        }

        return n%(s+p)==0;
    }
};