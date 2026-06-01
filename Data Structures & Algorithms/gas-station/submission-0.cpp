class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg = 0;
        for(int gas_ : gas) sumg+= gas_;
        int sumc = 0;
        for(int cost_ : cost) sumc+=cost_;
        if(sumg<sumc){
            return -1;
        }
        int cg = 0;
        int result = 0;
        for(int i = 0 ; i < gas.size() ;i++){
            cg = cg + gas[i]-cost[i];
            if(cg<0){
                result = i+1;
                cg = 0;
            }
        }
        return result;
    }
};
