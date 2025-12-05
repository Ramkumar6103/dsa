class Solution(){
    public:
    int sumMinElements(vector<int> &arr){
        int n = arr.size();
        vector<vector<int>> sub;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(j=i+1;j<n;j++){
                for(int k=i;k<=j;k++){
                    temp.push_back(arr[k]);
                }
                
            }   
        }
        return 0;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {3, 1, 2};
    cout<<sol.sumMinElements(arr)<<endl;
    return 0;
}