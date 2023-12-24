#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(int amount, const vector<pair<int, int>>& coinInfo)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (const auto& coin : coinInfo)
    {
        int coinDenomination = coin.first;
        int coinCount = coin.second;

        for (int j = coinDenomination; j <= amount; ++j)
        {
            if (dp[j - coinDenomination] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - coinDenomination] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        return -1;
    }
    else {
        return dp[amount];
    }
}

int main()
{
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int numCoins;
    cout << "Enter the number of different coin denominations: ";
    cin >> numCoins;

    vector<pair<int, int>> coinInfo;

    cout << "Enter the coin denominations and counts:" << endl;
    for (int i = 0; i < numCoins; ++i)
    {
        int denomination, count;
        cout << "Coin " << i + 1 << " denomination: ";
        cin >> denomination;
        cout << "Coin " << i + 1 << " count: ";
        cin >> count;
        coinInfo.emplace_back(denomination, count);
    }

    int result = minCoins(amount, coinInfo);

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
