#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
bool is154pattern(vector<int>&nums)
{
    int n =nums.size();
    if (n <3)
    {
        return false;
    }
    if (n ==3)
    {
        return (nums[2] >nums[0] &&nums[2] <nums[1]);
    }
    int third = INT_MIN;
    stack<int>st;
    for (int i= n -1; i>=0; i--)
    {
        if (nums[i] < third)
            return true;
        while(!st.empty() &&nums[i] >st.top())
        {
            third =st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}
int main()
{
    cout<<"Shreshthi Tayal\n2100290120160\n";
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    cout<<"Enter the elements of the array : "<<endl;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    if(is154pattern(nums))
    {
        cout<<"Yes,there is a Largest Digit Pattern 154 in nums"<<endl;
    }
    else
    {
        cout<<"No,there is not a Largest Digit Pattern 154 in nums"<<endl;
    }
    return 0;
}
