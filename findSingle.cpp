#include<bits/stdc++.h>
using namespace std;
int main()
{
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(5);
        nums.push_back(5);
        nums.push_back(7);
        map<int,int> mpp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<=nums.size()-1;j++)
            {
                if(nums[i]==nums[j])
                {
                    count++;
                }
            }
            mpp[nums[i]] = count;
            count=0;
        }
        for(auto it:mpp)
        {
            cout<<"First: "<<it.first<<" Second: "<<it.second<<" \n";
        }
        for(auto it:mpp)
        {
            if(it.second == 1)
            {
                cout<<it.first;
            }
        }
    return 0;
}
