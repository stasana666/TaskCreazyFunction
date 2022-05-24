#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<int> arr(n);
    for (int& i : arr) {
        cin >> i;
    }
    vector<pair<int, int>> segments(m);
    for (auto& i : segments) {
        cin >> i.first >> i.second;
        --i.first;
    }
    for (int q = 0; q < t; ++q) {
        vector<vector<int>> func(k + 1, vector<int>(k + 1));
        for (int i = 1; i <= k; ++i) {
            func[0][i] = i;
            func[i][0] = i;
            for (int j = 1; j <= k; ++j) {
                cin >> func[i][j];
            }
        }
        int sum = 0;
        for (auto [left, right] : segments) {
            int res = 0;
            for (int i = left; i < right; ++i) {
                res = func[res][arr[i]];
            }
            sum += res;
        }
        cout << sum << endl;
    }
}
