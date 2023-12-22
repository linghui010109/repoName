#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minCoins(int amount, const vector<int>& coins)
{
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	for (int i : coins)
	{
		for (int j = i; j <= amount; j++)
		{
			if (dp[j - 1] != INT_MAX)
			{
				dp[j] = min(dp[j],dp[j-i]+1);
			}
			
		}
	}
	return (dp[amount]==INT_MAX)?-1:dp[amount];
}

int main()
{
	int amount = 63;
	vector<int> coins = { 1,5,10,25 };

	int result = minCoins(amount, coins);

	if (result != -1)
	{
		cout << "The minimum number of coins to make " << amount << " cents is: " << result << " coins" << endl;
	}
	else
	{
		cout << "Unable to make " << amount << " cents" << endl;
	}

	return 0;
}
