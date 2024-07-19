/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_quicksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:58:18 by cde-migu          #+#    #+#             */
/*   Updated: 2024/07/17 14:59:05 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to swap two integers
static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using the Lomuto partition scheme
static int partition(int* arr, int low, int high)
{
    int pivot = arr[high]; // Pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform QuickSort on the array
int *quicksort(int* arr, int low, int high)
{
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
		return (arr);
    }
	else
		return (NULL);
}

// int main() {
//     int array[] = {10, 5, 2, 3};
//     int n = sizeof(array) / sizeof(array[0]);

//     quicksort(array, 0, n - 1);

//     printf("Sorted array: \n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");

//     return 0;
// }