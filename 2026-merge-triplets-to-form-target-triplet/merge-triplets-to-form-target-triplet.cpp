class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>res(3);
        for(auto it:triplets){
            int x=it[0];
            int y=it[1];
            int z=it[2];
            if(x<=target[0] && y<=target[1] && z<=target[2]){
                res = {max(res[0],x),max(res[1],y),max(res[2],z)};
            }
        }
        return res==target;
    }
};