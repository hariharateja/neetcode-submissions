class TimeMap {
public:
    map<string,map<int,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())
            return "";
        vector<int> times;

        for(auto p : mp[key]){
            times.push_back(p.first);
        }
        int left=0;
        int right=times.size()-1;

        int ans=-1;

        while(left<=right){

            int mid=left+(right-left)/2;

            if(times[mid] <= timestamp){

                ans=times[mid];
                left=mid+1;      // last valid
            }
            else{
                right=mid-1;
            }
        }

        if(ans==-1)
            return "";

        return mp[key][ans];
    }
};
