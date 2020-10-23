#ifndef QUICK_H
#define QUICK_H
#include "utils.h"
#include "insertion_sort.h"



template<typename T>
class quick_sort {

public:
	static void sort(T* a, int size, const comparator<T>& comp = fwd_comparator<T>()) {
		sort(a, 0, size - 1,comp);
	}
private:
	static void sort(T* a, int lo, int hi, const comparator<T>& comp) {
		if (hi <= lo) return;
		int j = partition(a, lo, hi,comp);
		sort(a, lo, j - 1,comp);
		sort(a, j + 1, hi,comp);
	}
	static int partition(T* a, int lo, int hi, const comparator<T>& comp) {
		int i = lo, j = hi + 1;

		while (true) {
			while (less(a[++i], a[lo])) {
				if (i == hi) break;
			}
			while (less(a[lo], a[--j])) {
				if (j == lo) break;
			}
			if (i >= j) break;
			exchange(a, i, j);
		}
		exchange(a, lo, j);
		return j;
	}
};

template<typename T>
class quick_sort_3way {
	static const int CUTOFF_ = 10;
public:
	static void sort(T* a, int size, const comparator<T>& comp = fwd_comparator<T>()) {
		sort(a, 0, size - 1, comp);
	}
private:
	static void sort(T* a, int lo, int hi, const comparator<T>& comp) {
		if (hi <= lo) return;
		T v = a[lo];									
		int lt = lo, i = lo + 1, gt = hi;

		while (i <= gt) {
			int cmp = compare(a[i], v, comp);
			if (cmp < 0) exchange(a, lt++, i++);
			else if (cmp > 0) exchange(a, i, gt--);
			else i++;
		}
		sort(a, lo, lt - 1, comp);
		sort(a, gt + 1, hi, comp);
	}
};


#endif