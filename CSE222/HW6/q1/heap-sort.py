

comparisons = 0


def heapify(arr, n, i):
    global comparisons
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    comparisons += 1
    if l < n and arr[i] < arr[l]:
        largest = l

    comparisons += 1
    if r < n and arr[largest] < arr[r]:
        largest = r

    comparisons += 1
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        heapify(arr, n, largest)


def heapSort(arr):
    displacements = 0
    print(f'Heap sorting: {arr}')
    n = len(arr)

    print('Building the maxheap')

    for i in range(n//2 - 1, -1, -1):
        print(f"Heapify: {arr}")
        heapify(arr, n, i)
        print(f"Heapified: {arr}")
        print("------------")

    print(f'Built max heap: {arr}')

    print('Extract elements one by one')
    for i in range(n-1, 0, -1):
        print(f'Swap {arr[i]} with {arr[0]}')
        if arr[i] != arr[0]:
            displacements += 1
        arr[i], arr[0] = arr[0], arr[i]
        print(f"Heapify: {arr}")
        heapify(arr, i, 0)
        print(f"Heapified: {arr}")

    global comparisons
    print(f'Heap sort done: {arr}')
    print(f'Comparisons count: {comparisons}')
    print(f'Displacement count: {displacements}')


A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
C = [5, 2, 13, 9, 1, 7, 6, 8, 1, 15, 4, 11]
D = ['S', 'B', 'I', 'M', 'H', 'Q', 'C', 'L', 'R', 'E', 'P', 'K']

heapSort(D)
