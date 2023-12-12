#include <iostream>
#include <vector>

using namespace std;

namespace sorting {

	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};

	stats selection_sort(vector<int> vec) {
		stats a;
		size_t size = vec.size();
		for (size_t j = 0; j < size; j++) {
			int min = vec[j];
			int min_ind = j;
			for (size_t i = j + 1; i < size; i++) {
				if (min >= vec[i]) {
					min = vec[i];
					min_ind = i;
				}
			}
			swap(vec[j], vec[min_ind]);
		}
		return a;
	}

	stats shaker_sort(vector<int> vec) {
		int Left = 1, Right = vec.size() - 1;
		while (Left <= Right)
		{
			for (int i = Right; i >= Left; i--)
				if (vec[i - 1] > vec[i]) {
					swap(vec[i], vec[i - 1]);
				}
			Left++;
			for (int i = Left; i <= Right; i++) {
				if (vec[i - 1] > vec[i]) {
					swap(vec[i], vec[i - 1]);
				}
			}
			Right--;
		}
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
	}

	stats comb_sort(std::vector<int> vec) {
		double factor = 1.2473309; 
		int step = vec.size() - 1;

		while (step >= 1)
		{
			for (int i = 0; i + step < vec.size(); i++)
			{
				if (vec[i] > vec[i + step])
				{
					std::swap(vec[i], vec[i + step]);
				}
			}
			step /= factor;
		}
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
	}
}