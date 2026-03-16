#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long rhombusSum(int i,int j,int k,vector<vector<int>>& grid){
        if(k==0) return grid[i][j];

        long long s=0;

        int r=i,c=j;

        for(int t=0;t<k;t++){
            s+=grid[r+t][c-t];
        }

        r=i+k;
        c=j-k;
        for(int t=0;t<k;t++){
            s+=grid[r+t][c+t];
        }

        r=i+2*k;
        c=j;
        for(int t=0;t<k;t++){
            s+=grid[r-t][c+t];
        }

        r=i+k;
        c=j+k;
        for(int t=0;t<k;t++){
            s+=grid[r-t][c-t];
        }

        return s;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        set<long long> st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                st.insert(grid[i][j]);

                for(int k=1;;k++){

                    if(i+2*k>=m || j-k<0 || j+k>=n) break;

                    st.insert(rhombusSum(i,j,k,grid));
                }
            }
        }

        vector<int> ans;

        for(auto it=st.rbegin();it!=st.rend() && ans.size()<3;it++){
            ans.push_back(*it);
        }

        return ans;
    }
};