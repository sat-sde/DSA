class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>c(n);
        for(int i=0;i<n;i++){
            c.push_back({position[i],((double)(target - position[i]) / speed[i])});
        }

        sort(c.begin(),c.end(),[](auto &a,auto &b){
            return a.first > b.first;
        });

        double prevtime=0;
        int fleet=0;
        for(auto it:c){
            if(it.second > prevtime){
                fleet++;
                prevtime=it.second;
            }
        }
        return fleet;
    }
};