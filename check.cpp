#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <set>
#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	registerTestlibCmd(argc, argv);
    double score = 0;

    inf.readInt();
    inf.readInt();
    inf.readInt();
    int t = inf.readInt();

    int numbersCount = 0;
    while (!ans.seekEof() && !ouf.seekEof()) {
        long long j = ans.readLong();
        long long p = ouf.readLong();
        if (j == p) {
            score += 1.0;
        }
        ++numbersCount;
    }
    if (ans.seekEof() && numbersCount != t) {
        quitf(_fail, "jury: expected %d numbers found %d numbers", t, numbersCount);
    }
    if (ouf.seekEof() && numbersCount != t) {
        quitf(_pe, "expected %d numbers found %d numbers", t, numbersCount);
    }

    quitp(score, "participant's solution is ok");
    return 0;
}
