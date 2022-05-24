#include <iostream>
#include <vector>

using namespace std;

struct Function {
    void resize(int k) {
        data.resize(k, vector<int>(k));
    }

    int operator ()(int x, int y) {
        if (x == 0) {
            return y;
        }
        if (y == 0) {
            return x;
        }
        return data[x - 1][y - 1];
    }

    vector<vector<int>> data;
};

istream& operator >>(istream& in, Function& func) {
    for (auto& i : func.data) {
        for (int& j : i) {
            in >> j;
        }
    }
    return in;
}

struct Segment {
    int left;
    int right;
};

int n, m, k, t;
vector<int> arr;
vector<Segment> segments;
Function func;

struct Result {
    Result() = default;

    Result(int x)
        : result(k + 1)
    {
        for (int i = 0; i <= k; ++i) {
            result[i] = func(i, x);
        }
    }

    Result(const Result& left, const Result& right)
        : result(k + 1)
    {
        for (int i = 0; i <= k; ++i) {
            result[i] = right.result[left.result[i]];
        }
    }

    std::vector<int> result;
};

typedef struct Node* pNode;
struct Node {
    pNode child_left;
    pNode child_right;
    int left;
    int right;
    Result res;

    Node(int left, int right)
        : child_left(nullptr)
        , child_right(nullptr)
        , left(left)
        , right(right)
    {
        if (right - left == 1) {
            res = Result(arr[left]);
        } else {
            child_left = new Node(left, right + left >> 1);
            child_right = new Node(right + left >> 1, right);
            res = Result(child_left->res, child_right->res);
        }
    }

    ~Node() {
        if (child_left) {
            delete child_left;
        }
        if (child_right) {
            delete child_right;
        }
    }

    int get(int left, int right, int left_value = 0) const {
        if (this->left >= right || this->right <= left) {
            return left_value;
        }
        if (this->left >= left && this->right <= right) {
            return res.result[left_value];
        }
        left_value = child_left->get(left, right, left_value);
        return child_right->get(left, right, left_value);
    }
};

int main() {
    cin >> n >> m >> k >> t;
    arr.resize(n);
    segments.resize(m);
    func.resize(k);

    for (int& i : arr) {
        cin >> i;
    }

    for (auto& s : segments) {
        cin >> s.left >> s.right;
    }

    for (int req = 0; req < t; ++req) {
        cin >> func;

        pNode root = new Node(0, n);
        int sum = 0;
        for (auto& s : segments) {
            sum += root->get(s.left - 1, s.right);
        }
        cout << sum << endl;

        delete root;
    }

    return 0;
}
