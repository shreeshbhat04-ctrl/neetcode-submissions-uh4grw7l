class TimeMap {
public:
unordered_map<string,unordered_map<int,vector<string>>>stor;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        stor[key][timestamp].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if(!stor.count(key))return "";
        int latest=0;
        for(auto& [time,_]:stor[key]){
            if(time<=timestamp){
                latest=max(latest,time);
            }
        }
        return latest==0?"":stor[key][latest].back();
    }
};
