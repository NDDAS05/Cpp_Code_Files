class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        std::sort(arr.begin(), arr.end());
        std::sort(dep.begin(), dep.end());
        
        int plat_need = 1;
        int maxPlat = 1;
        
        int i=1, j=0; // i points at arrival. First one is considered as it ahas to take a platform
        
        while(i<arr.size() && j<dep.size()){
            if(arr[i] <= dep[j]) {
                plat_need++;
                i++;
            }
            else if(arr[i] > dep[j]){
                plat_need--;
                j++;
            }
            
            
            maxPlat = std::max(maxPlat, plat_need);
        }
        
        return maxPlat;
        
    }
};
 