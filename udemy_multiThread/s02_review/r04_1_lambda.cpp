#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


// using std::cout;
// using std::cin;


using namespace std;



int main(void)
{
    vector<int> vec{4,2,13,11,5,24,7};
    auto b = vec.begin();
    auto e = vec.end();
    cout<<"\n Lambda wowoow!!\n";

    int ile = count_if(b,e,[](int l){return(l%2);});
    cout<<"nieparzystych jest: "<<ile<<"\n";
    int k{0};
    for(int i=2; i<6; ++i)
    {
    int ile = count_if(b,e,[i,&k](int l)  { (k)+=i;return(l%2);});
    cout<<"dla i="<<i<<" nieparzystych jest: "<<ile<<"::: k wynosi: "<<k<<endl;
    }

    return 0;
}