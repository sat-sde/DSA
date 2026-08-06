class Solution {
public:
    int ischeck(int n){
        int p=1;
        while(n>0){
            int ld=n%10;
            p*=ld;
            n/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while(ischeck(n) % t != 0){
            n++;
        }
        return n;
    }
};