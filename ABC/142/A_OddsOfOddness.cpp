#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    double p = double(N - N / 2) / double(N);
    printf("%f\n", p);

    return 0;
}