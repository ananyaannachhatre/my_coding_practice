#include <bits/stdc++.h>
using namespace std;


bool isReach(vector<int> jump)
{
	int n = (int)jump.size();
	int reach = 1; // maximum stone that can be reached
	for (int i = 1; i <= n; i++)
	{
		if (reach >= i)
		{
			reach = max(reach, jump[i - 1] + i);
		}
	}
	return reach >= n;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> jump(n);
	for (auto &i : jump)
		cin >> i;

	if (isReach(jump))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}