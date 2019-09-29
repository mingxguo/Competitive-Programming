#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long int;
vector<ll> fib;

int main() {
	//prepare fibonacci
	fib.push_back(1);
	fib.push_back(1);
	for (int i = 2; i < 100000; ++i) {
		fib.push_back(fib[i - 2] + fib[i - 1]);
	}

	return 0;
}