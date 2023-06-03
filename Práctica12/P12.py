import random
import time
import matplotlib.pyplot as plt

def generate_random_list(size):
    return [random.randint(1, 1000) for _ in range(size)]

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]
    left = merge_sort(left)
    right = merge_sort(right)
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def plot_performance(performance):
    plt.plot(performance['sizes'], performance['insertion_sort'], label='Insertion Sort')
    plt.plot(performance['sizes'], performance['quick_sort'], label='QuickSort')
    plt.plot(performance['sizes'], performance['merge_sort'], label='MergeSort')
    plt.xlabel('Input Size')
    plt.ylabel('Execution Time (seconds)')
    plt.title('Sorting Algorithm Performance')
    plt.legend()
    plt.show()

def main():
    sizes = [10, 100, 1000, 10000]
    performance = {'sizes': sizes, 'insertion_sort': [], 'quick_sort': [], 'merge_sort': []}

    for size in sizes:
        arr = generate_random_list(size)

        # Insertion Sort
        start_time = time.time()
        insertion_sort(arr.copy())
        insertion_time = time.time() - start_time
        performance['insertion_sort'].append(insertion_time)

        # QuickSort
        start_time = time.time()
        quick_sort(arr.copy())
        quicksort_time = time.time() - start_time
        performance['quick_sort'].append(quicksort_time)

        # MergeSort
        start_time = time.time()
        merge_sort(arr.copy())
        merge_time = time.time() - start_time
        performance['merge_sort'].append(merge_time)

        print(f'Size: {size}')
        print(f'Unsorted Array: {arr}')
        print(f'Insertion Sort: {insertion_sort(arr.copy())}')
        print(f'QuickSort: {quick_sort(arr.copy())}')
        print(f'MergeSort: {merge_sort(arr.copy())}')
        print('--------------------------')

    plot_performance(performance)

if __name__ == '__main__':
    main()