class LFUCache {
public:
    int cap;
    int size;
    unordered_map<int,list<vector<int>>::iterator>mpp;
    map<int,list<vector<int>>>freq;//counter->{key,value,counter}
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    void makeMostFrequentlyUsed(int key){
        auto &vec=(*(mpp[key]));
        int value=vec[1];
        int f=vec[2];
        freq[f].erase(mpp[key]);
        if(freq[f].empty()) freq.erase(f);

        f++;
        freq[f].push_front({key,value,f});
        mpp[key]=freq[f].begin();
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        auto &vec=(*(mpp[key]));
        int value=vec[1];
        makeMostFrequentlyUsed(key);
        return value;
    }
    
    void put(int key, int value) {
        if(cap==0) return;

        if(mpp.find(key)!= mpp.end()){
            auto &vec=(*(mpp[key]));
            vec[1]=value;
            makeMostFrequentlyUsed(key);
        }else if(size<cap){
            size++;
            freq[1].push_front(vector<int>({key,value,1}));
            mpp[key]=freq[1].begin();
        }else{
            auto &kaun_sa_list=freq.begin()->second;
            int key_to_delete=kaun_sa_list.back()[0];
            kaun_sa_list.pop_back();

            if(kaun_sa_list.empty()){
                freq.erase(freq.begin()->first);
            }

            freq[1].push_front(vector<int>({key,value,1}));
            mpp.erase(key_to_delete);
            mpp[key]=freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */