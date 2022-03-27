#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;



//快排模板
/*
const int n=100001;
int sz;
int a[];

void q_sort(int a[],int l,int r)
{


    if(l>=r)return;
    int x=a[l];
    int i=l-1;
    int j=r+1;
    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);
    }
    q_sort(a,l,j);
    q_sort(a,j+1,r);
}


int main()
{
    cin>>sz;
    for(int i=0;i<sz;i++)
    cin>>a[i];
    q_sort(a,0,sz-1);
    for(int i=0;i<sz;i++)cput<<a[i]<<' ';

}

*/



//归并模板
/*

const int n=100001;
int sz;
int a[];

int q_sort(int l,int r,int k)
{


    if(l>=r)return a[l];
    int x=a[l];
    int i=l-1;
    int j=r+1;
    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);
    }
    int sl=j-l+1;
    if(k<=sl)return q_sort(l,j,k);
    return q_sort(j+1,r,k-sl);
}

int k;
int main()
{
    cin>>sz>>k;
    for(int i=0;i<sz;i++)
    cin>>a[i];
    q_sort(0,sz-1,k);


}


*/

















/*
const int n = 100001;
int a[n];
int sz, m;



//二分

int main()
{
    cin >> sz >> m;
    for (int i = 0; i < sz; i++)cin >> a[i];

    while (m--)
    {
        int z;
        cin >> z;
        int l = 0, r = sz - 1;

        //查找出z第一次出现的位置
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= z) r = mid;     
            else l = mid + 1;
        }
        if (a[l] != z)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << ' ';
            int l = 0, r = sz - 1;


        //查找出z最后一次出现的位置
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= z)l = mid;
                else r = mid - 1;

            }
            cout << r << endl;
        }


    }
    return 0;



}

*/