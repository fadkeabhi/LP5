// Implement Min, Max, Sum, and Average operations using Parallel Reduction
// Run using
// g++ -fopenmp 3_min_max_reduction.cpp
// ./a.out

#include <iostream>
#include <vector>
#include <omp.h>
#include <climits>

using namespace std;

void min_reduction(vector<int> &arr)
{
    double start_time = omp_get_wtime();
    int min_value = INT_MAX;
#pragma omp parallel for reduction(min : min_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    double end_time = omp_get_wtime();
    cout << "Minimum value: " << min_value << endl;
    cout << "Time taken by min_reduction: " << end_time - start_time << " seconds" << endl;
}

void max_reduction(vector<int> &arr)
{
    double start_time = omp_get_wtime();
    int max_value = INT_MIN;
#pragma omp parallel for reduction(max : max_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    double end_time = omp_get_wtime();
    cout << "Maximum value: " << max_value << endl;
    cout << "Time taken by max_reduction: " << end_time - start_time << " seconds" << endl;
}

void sum_reduction(vector<int> &arr)
{
    double start_time = omp_get_wtime();
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    double end_time = omp_get_wtime();
    cout << "Sum: " << sum << endl;
    cout << "Time taken by sum_reduction: " << end_time - start_time << " seconds" << endl;
}

void average_reduction(vector<int> &arr)
{
    double start_time = omp_get_wtime();
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    double end_time = omp_get_wtime();
    cout << "Average: " << (double)sum / arr.size() << endl;
    cout << "Time taken by average_reduction: " << end_time - start_time << " seconds" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    average_reduction(arr);

    return 0;
}
