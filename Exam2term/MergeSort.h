#pragma once
namespace merge_sort
{
	template<typename T>
	void merge(T* a, int an, T*b, int bn, T*buf)
	{
		int i = 0, j = 0, k = 0;
		while (i<an&&j<bn)
		{
			while (i<an&&a[i] <= b[j])
				buf[k++] = a[i++];
			while (j<bn&&b[j] <= a[i])
				buf[k++] = b[j++];
		}
		while (i<an)
			buf[k++] = a[i++];
		while (j<bn)
			buf[k++] = b[j++];
	}

	template<typename T>
	void merge_sort_impl(T* arr, T* buf, int length)
	{
		if (length == 1) return;
		int mid = length / 2;
		merge_sort_impl(arr, buf, mid);
		merge_sort_impl(arr + mid, buf, length - mid);
		merge(arr, mid, arr + mid, length - mid, buf);
		memcpy(arr, buf, sizeof(T)*length);
		/*
		for (int i = 0; i < length; i++)
		arr[i] = buf[i];
		*/
	}

	template<typename T>
	void merge_sort(T* arr, int length)
	{
		T* tmp = new T[length];
		merge_sort_impl(arr, tmp, length);
		delete[] tmp;
	}
}