#include <iostream>

using namespace std;

bool isPathExists(int sx, int sy, int tx, int ty)
{
    if(sx > tx || sy > ty)
        return false;
    if(sx==tx && sy==ty)
        return true;
    return (isPathExists(sx,sx+sy,tx,ty) || isPathExists(sx+sy,sy,tx,ty));
}

int main()
{
    unsigned int tcs=0;
    cin>>tcs;
    //Run through the tests
    bool result[tcs];
    for(int idx=0; idx<tcs; idx++)
    {
        int sx,sy,tx,ty;
        cin>>sx>>sy>>tx>>ty;
        result[idx] = isPathExists(sx,sy,tx,ty);
    }
    for(int idx=0; idx<tcs; idx++)
        cout<<(result[idx]?"True":"False")<<endl;
}
