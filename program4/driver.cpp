
#include <sys/time.h>
#include "sorts.h"


void InitVector(vector<int>& item_vector, int size);
void PrintVector(const vector<int>& item_vector, string name);
int elapsed( timeval &startTime, timeval &endTime );

int main(int argc, char* argv[])
{
    int size = 0;
    string sort_name = "";
    bool print_out = true;
    if ((argc != 3) && (argc != 4))
    {
        cerr << "Usage: Sorter SORT_TYPE VECTOR_SIZE [YES|NO]" << endl;
        return -1;
    }
    sort_name = string(argv[1]);
    size = atoi(argv[2]);
    if (size <= 0)
    {
        cerr << "Vector size must be positive" << endl;
        return -1;
    } if (
        argc == 4)
    {
        string print_arr = string(argv[3]);
        if (print_arr == "NO")
        {
            print_out = false;
        }
        else if (print_arr == "YES")
        {
            print_out = true;
        }
        else
        {
            cerr << "Usage: Sorter SORT_TYPE VECTOR_SIZE [YES|NO]" << endl;
            return -1;
        }
    }
    srand(1);
    vector<int> items(size);
    InitVector(items, size);
    if (print_out)
    {
        cout << "Initial:" << endl;
        PrintVector(items, string("items"));
    }

    struct timeval startTime, endTime;
     gettimeofday(&startTime, 0);
   
    if (sort_name == "BubbleSort")
    {
        BubbleSort(items, 0, size - 1);
    }
    else if (sort_name == "InsertionSort")
    {
        InsertionSort(items, 0, size - 1);
    }
    else if (sort_name == "MergeSort")
    {
        MergeSort(items, 0, size - 1);
    }
    else if (sort_name == "IterativeMergeSort")
    {
        IterativeMergeSort(items, 0, size - 1);
    }
    else if (sort_name == "QuickSort")
    {
        QuickSort(items, 0, size - 1);
    }
    else if (sort_name == "ShellSort")
    {
        ShellSort(items, 0, size - 1);
    }

    gettimeofday(&endTime, 0);

    if (print_out)
    {
        cout << "Sorted:" << endl;
        PrintVector(items, string("item"));
    }
    int elapsed_secs = elapsed(startTime, endTime); 
    cout << "Time (ms): " << elapsed_secs << endl;
    return 0;
}

void InitVector(vector<int>& item_vector, int rand_max)
{
    if (rand_max < 0)
    {
        return;
    }
    vector<int> pool(rand_max);
    for (int i = 0; i < rand_max; i++)
    {
        pool[i] = i;
    }
    int spot;
    for (int i = 0; i < rand_max; i++)
    {
        spot = rand() % (pool.size());
        item_vector[i] = pool[spot];
        pool.erase(pool.begin() + spot);
    }
}
void PrintVector(const vector<int>& item_vector, string name)
{
    int size = item_vector.size();
    for (int i = 0; i < size; i++)
        cout << name << "[" << i << "] = " << item_vector[i] << endl;
}

int elapsed( timeval &startTime, timeval &endTime )  
{ 
return ( endTime.tv_sec - startTime.tv_sec )*1000000  
 + ( endTime.tv_usec - startTime.tv_usec ); 
}