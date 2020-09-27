#include<iostream>
#include<stack>

using namespace std;

int main()
{
    long long n,*arr;
    cin>>n;
    arr=new long long[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
     stack<long long > s;

    long long max_area = 0;
    long long tp;
    long long area_with_top;

    long long i = 0;
    while (i < n)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);

        else
        {
            tp = s.top();
            s.pop();

            area_with_top = arr[tp]*(s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = arr[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    cout<<max_area;
    return 0;
}
