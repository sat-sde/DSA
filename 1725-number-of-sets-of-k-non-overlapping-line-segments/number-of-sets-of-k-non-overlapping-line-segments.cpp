class Solution {
public:
    int M=1e9+7;
    int t[1001][1001];
    int solve(int n,int k,int i){
        if(n == k+1) return 1;
        if(k==0) return 1;
        if(i>=n) return 0;
        if(t[k][i]!=-1) return t[k][i];
        int skip=solve(n,k,i+1);
        int take=0;
        for(int j=i+1;j<n;j++){
            take+=(solve(n,k-1,j));
            take%=M;
        }
        return t[k][i]=(take+skip)%M;
    }
    int numberOfSets(int n, int k) {
        memset(t,-1,sizeof(t));
        return solve(n,k,0); 
    }
};