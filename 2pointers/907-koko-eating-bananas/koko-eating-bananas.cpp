class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //let k be bananas per hour
        int mink = 1; //storing minimum possible value of k
        int maxk = 0; //storing maximum possible value of k
        for(int i=0;i<n;i++){
            maxk = max(maxk, piles[i]);
        }

        int result = maxk; //storing possible answer so far

        while (mink <= maxk){
            int midk = mink + (maxk-mink)/2 ;
            long hours = 0; //total time to eat all bananas if speed is 'midk'
            for(int i=0;i<n;i++){
                hours += ceil(double(piles[i])/midk);
            }
            if(hours <= h){
                result = min(result, midk);
                maxk = midk - 1;
            }
            else{
                mink = midk + 1;
            }
        }
        return result;
    }
};