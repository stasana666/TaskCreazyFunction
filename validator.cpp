#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100'000'000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 100'000'000, "m");
    inf.readSpace();
    int k = inf.readInt(1, 100, "k");
    inf.readSpace();
    int t = inf.readInt(1, 100, "t");
    inf.readEoln();
    inf.readInts(n, 1, k, "arr");
    inf.readEoln();
    for (int i = 0; i < m; ++i) {
        int left = inf.readInt(1, n, "left");
        inf.readSpace();
        inf.readInt(left, n, "right");
        inf.readEoln();
    }
    for (int q = 0; q < t; ++q) {
        for (int i = 0; i < k; ++i) {
            inf.readInts(k, 1, k, "mats");
            inf.readEoln();
        }
    }

    inf.readEof();
}
