// Calculator.h
// WS09 in-lab
//Name: Daryan Chan
//ID 113973192
//Section NCC

#ifndef SDDS_CALCULATOR_H
#define SDDS_CALCULATOR_H

namespace sdds {
	template <typename T, int N>
	class Calculator {
		T results[N];
	public:
		Calculator() {
			for (int i = 0; i < N; i++)
				results[i] = '\0';
		}

		void add(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
				results[i] = arr1[i] + arr2[i];
		}

		void subtract(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
				results[i] = arr1[i] - arr2[i];
		}

		void multiply(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
				results[i] = arr1[i] * arr2[i];
		}

		void divide(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
				results[i] = arr1[i] / arr2[i];
		}

		std::ostream& display(std::ostream& os) const {
			int i = 0;
			for (i = 0; i < N - 1; i++)
				os << results[i] << ",";
			os << results[i] << std::endl;
			return os;
		}

		Calculator& operator+=(const T* arr) {
			for (int i = 0; i < N; i++)
				results[i] += arr[i];
			return *this;
		}

		Calculator& operator-=(const T* arr) {
			for (int i = 0; i < N; i++)
				results[i] -= arr[i];
			return *this;
		}

		Calculator& operator*=(const T* arr) {
			for (int i = 0; i < N; i++)
				results[i] *= arr[i];
			return *this;
		}

		Calculator& operator/=(const T* arr) {
			for (int i = 0; i < N; i++)
				results[i] /= arr[i];
			return *this;
		}
	};
}

#endif
