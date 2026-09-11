class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       int freq[10]={0};

       for(auto it:digits){
            freq[it]++;
       }

       int ans=0;

       for(int last=0;last<=8;last+=2){
            if(freq[last]==0) continue;
            freq[last]--;

            for(int first=1;first<=9;first++){
                if(freq[first]==0) continue;

                freq[first]--;

                for(int mid=0;mid<10;mid++){
                    if(freq[mid]>0){
                        ans++;
                    }
                }

                freq[first]++;
            }
            freq[last]++;
       }

       return ans;
    }
};