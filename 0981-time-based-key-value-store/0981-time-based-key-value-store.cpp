class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()) return "";

        auto &v=mpp[key];
        int l=0;
        int h=v.size()-1;
        string ans="";
        while(l<=h){
            int m=l+(h-l)/2;
            if(v[m].first<=timestamp){
                ans=v[m].second;
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */