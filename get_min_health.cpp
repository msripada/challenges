#include <iostream>
#include <vector>

using namespace std;

void get_min_path(int *a, int m, int n,vector<vector<int>> &comb,int i, int j, vector<int> path = {})
{
    if(i>m || j> n)
        return;

    //reached last node
    if(i == m-1 && j == n-1)
    {
        path.push_back(*((a+i*n)+j));
        comb.push_back(path);
        return;
    }
    //copy the node
    path.push_back(*((a+i*n)+j));
    //Move right
    get_min_path(a,m,n,comb,i,j+1,path);
    //Move down
    get_min_path(a,m,n,comb,i+1,j,path);
}
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    vector<vector<int>> path;
    get_min_path(*a,m,n,path,0,0);
    int least_val = 0, fin_path=-1;
    for(int i=0;i<path.size();i++)
    {
        int cnt=0;
        cout<<"Path-"<<i+1<<" :";
        //for(auto it=path[i].begin();it!=path[i].end();it++)
        for(int j=0;j<path[i].size();j++)
        {
            cout<<path[i][j]<<", ";
            cnt+= path[i][j];
        }
        cout<<"\t ******* health count "<<cnt<<endl;
        if(i==0 || least_val > abs(cnt))
        {
            least_val = abs(cnt) + 1;
            fin_path = i;
        }
    }
    cout<<"\n\nMin possible path["<<fin_path<<"] : ";
    for(int i=0;i<path[fin_path].size();i++)
        cout<<path[fin_path][i]<<" ";
    cout<<" ******* Minimum health needed - "<<least_val<<endl;
}
