class DetectSquares {
public:
    map<pair<int,int>,int>mpp;
    DetectSquares() {}
    
    void add(vector<int> point) {
        mpp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
         int x=point[0];
        int y=point[1];
        int cnt=0;
        for(auto it:mpp){
            int px=it.first.first;
            int py=it.first.second;

            int dx=px-x;
            int dy=py-y;
            if(dx==0 || abs(dx)!=abs(dy)){
                continue;
            }
            int x1=x;
            int y1=py;
            int x2=px;
            int y2=y;
            if(mpp.count({x1,y1}) && mpp.count({x2,y2})){
                cnt+= it.second * mpp[{x1,y1}] * mpp[{x2,y2}];
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */