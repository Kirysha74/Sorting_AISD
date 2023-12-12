#include <sorting/sorting.h>
#include <chrono>

using namespace sorting;

int main() {
	vector<int> vec;
	for (int i = 0; i < 100000; i++) {
		vec.push_back(rand());
	}
	auto start = chrono::steady_clock::now();
	comb_sort(vec);
	auto end = chrono::steady_clock::now();
	cout << "Elapsed time in seconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " sec";
	return 0;
}