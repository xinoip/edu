

comparisons = 0
displacements = 0


def partition(arr, low, high):
    i = (low-1)
    pivot = arr[high]
    print(f'Sorting part: {arr}')
    print(f'Pivot: {arr[high]}')
    print(f'Small index: {i}')
    global comparisons
    global displacements

    for j in range(low, high):

        comparisons += 1
        if arr[j] < pivot:

            i = i+1
            if arr[i] != arr[j]:
                displacements += 1
            arr[i], arr[j] = arr[j], arr[i]

    if arr[i+1] != arr[high]:
        displacements += 1
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)


def quickSort(arr, low, high):
    print(f'quick-sort: {arr}')
    print(f'start index: {low}')
    print(f'end index: {high}')
    global comparisons
    comparisons += 1
    if low < high:

        pi = partition(arr, low, high)
        print(f'Sorted part.')
        print(f'Part index: {pi}')

        print(f'Seperately quick sort parts')
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)
    print('------------')


def start(arr):
    print(f'Quick sorting: {arr}')
    n = len(arr)
    quickSort(arr, 0, n-1)

    global comparisons
    global displacements
    print(f'Quick Sort done: {arr}')
    print(f'Comparisons count: {comparisons}')
    print(f'Displacement count: {displacements}')


A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
C = [5, 2, 13, 9, 1, 7, 6, 8, 1, 15, 4, 11]
D = ['S', 'B', 'I', 'M', 'H', 'Q', 'C', 'L', 'R', 'E', 'P', 'K']

start(D)
