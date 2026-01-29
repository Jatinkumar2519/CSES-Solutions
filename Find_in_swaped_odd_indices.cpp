#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            cout << true;
            return 0;
        }

        if ((mid & 1) == 0)
        {
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
        {
            if (mid + 1 < n && arr[mid + 1] < target)
                left = mid + 1;
            else if (target < arr[mid - 1])
                right = mid - 1;
            else
            {
                int num = arr[mid];

                left = 0;
                right = n - 1;

                while (left <= right)
                {
                    mid = (left + right) / 2;

                    if ((mid & 1) == 0)
                    {
                        if (arr[mid] < num)
                            left = mid + 1;
                        else
                            right = mid - 1;
                    }
                    else
                    {
                        if (mid + 1 < n && arr[mid + 1] < num)
                            left = mid + 1;
                        else if (num < arr[mid - 1])
                            right = mid - 1;
                        else
                        {
                            if (arr[mid] == target)
                            {
                                cout << true;
                            }
                            else
                            {
                                cout << false;
                            }
                            return 0;
                        }
                    }
                }
                cout << false;
                return 0;
            }
        }
    }
    cout << false;
    return 0;
}