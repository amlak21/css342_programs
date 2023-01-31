//This program declares and implements functions for deifferent sorting algorithms

#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//function declarations
void BubbleSort(vector<int>& vec, int first, int last);
void InsertionSort(vector<int>& vec, int first, int last);
void MergeSort(vector<int>& vec, int first, int last);
void Merge(vector<int>& vec, int first, int mid, int last);
void IterativeMergeSort(vector<int>& vec, int first, int last);
void IterativeMerge(vector<int>& vec, vector<int>& temp_arr, int first, int mid, int last);
void QuickSort(vector<int>& vec, int first, int last);
void ShellSort(vector<int>& vec, int first, int last);

//implementation of the functions
void BubbleSort(vector<int>& vec, int first, int last)
{
    if (first < 0 || last < 0)
    {
        cerr << "INVALID INPUT!" << endl;
    }
    else
    {
        for (int i = first; i < last; i++)
        {
            for (int j = first; j < last; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    std::swap(vec[j], vec[j + 1]);
                }
            }
        }
    }
}

void InsertionSort(vector<int>& vec, int first, int last)
{
    if (first < 0 || last < 0)
    {
        cerr << "INVALID INPUT!" << endl;
    }
    else
    {
        for (int place = first; place <= last; place++)
        {
            int temp = vec[place];
            int i = place;

            while ((i > first) && (vec[i - 1] > temp))
            {
                vec[i] = vec[i - 1];
                i--;
            }

            vec[i] = temp;
        }

    }
}

void MergeSort(vector<int>& vec, int first, int last)
{
    if (first < 0 || last < 0)
    {
        cerr << "INVALID INPUT!" << endl;
    }
    else
    {
        if (first < last)
        {
            int mid = (first + last) / 2;
            MergeSort(vec, first, mid);
            MergeSort(vec, mid + 1, last);
            Merge(vec, first, mid, last);
        }
    }
}

void Merge(vector<int>& vec, int first, int mid, int last)
{
    int size = (last - first) + 1;
   vector<int> temp_vec(size);
    int first1 = first;
    int first2 = mid + 1;
    int last1 = mid;
    int last2 = last;
    int index = 0; 

    while ((first1 <= last1) && (first2 <= last2))
    {
        if (vec[first1] < vec[first2])
        {
            temp_vec[index] = vec[first1];
            first1++;
        }
        else
        {
            temp_vec[index] = vec[first2];
            first2++;
        }
        index++;
    }

    while (first1 <= last1)
    {
        temp_vec[index] = vec[first1];
        first1++;
        index++;
    }

    while (first2 <= last2)
    {
        temp_vec[index] = vec[first2];
        first2++;
        index++;
    }

    for (index = 0; index < size; index++)
    {
        vec[first] = temp_vec[index];
        first++;
    }
}

void IterativeMergeSort(vector<int>& vec, int first, int last)
{
    if (first < 0 || last < 0)
    {
        cerr << "INVALID INPUT!" << endl;
    }
    else 
    {
        int size = vec.size();
        vector<int>temp_vec(size);
        for (int i = 1; i <= last + 1; i *= 2)
        {
            for (int low = first; low < last + 1 - i; low += i + i)
            {
                int mid = low + i - 1;
                int high = std::min(low + i + i - 1, last);
                IterativeMerge(vec, temp_vec, low, mid, high);
            }
        }
    }
}

void IterativeMerge(vector<int>& vec, vector<int>& temp_vec, int first, int mid, int last)
{
    for (int i = first; i <= last; i++)
    {
        temp_vec[i] = vec[i];
    }

    int i = first;
    int j = mid + 1;

    for (int k = first; k <= last; k++)
    {
        if (i > mid)
        {
            vec[k] = temp_vec[j++];
        }
        else if (j > last)
        {
            vec[k] = temp_vec[i++];
        }
        else if (temp_vec[j] < temp_vec[i])
        {
            vec[k] = temp_vec[j++];
        }
        else
        {
            vec[k] = temp_vec[i++];
        }
    }
}

void QuickSort(vector<int>& vec, int first, int last)
{
    if (first < 0 || last < 0)
    {
        cerr << "INVALID INPUT!" << endl;
    }
    else
    {
        if ((last - first) < 6)
        {
            InsertionSort(vec, first, last); 
            return;
        }

        int mid = (last + first) / 2;
        if (vec[first] > vec[last])
        {
            std::swap(vec[first], vec[last]);
        }
        if (vec[first] > vec[mid])
        {
            std::swap(vec[first], vec[mid]);
        }
        if (vec[mid] > vec[last])
        {
            std::swap(vec[mid], vec[last]);
        }

        int pivot = vec[mid];
        std::swap(vec[mid], vec[last - 1]);
        int left = first + 1;
        int right = last - 2;
        bool done = false;
        while (!done)
        {
            while (vec[left] < pivot)
            {
                left++;
            }
            while (vec[right] > pivot)
            {
                right--;
            }
            if (right > left)
            {
                std::swap(vec[left], vec[right]);
                left++;
                right--;
            }
            else
            {
                done = true;
            }
        }
        std::swap(vec[left], vec[last - 1]);
        QuickSort(vec, first, left - 1);
        QuickSort(vec, left + 1, last);
    }
}

void ShellSort(vector<int>& vec, int first, int last)
{
    int size = (last - first) + 1;
    for (int gap = size / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2))
    {
        for (int i = gap + first; i <= last; i++)
        {
            int temp = vec[i];
            int j = i;
            for (; (j >= gap + first) && (temp < vec[j - gap]); j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}

#endif