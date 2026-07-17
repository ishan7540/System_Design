#include <bits/stdc++.h>

using namespace std;

class Random
{
    long long seed;
    long long A = 1023124134;
    long long C = 12083912;
    long long M = 123518103;

public:
    Random(long long s) : seed(s) {};
    unsigned long long next()
    {
        seed = (A * seed + C) % M;
        return seed;
    }
    int randInt(int min, int max)
    {
        unsigned long long raw_num = next();
        return min + (raw_num % (max - min + 1));
    }
}

int
main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}