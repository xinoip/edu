
comparisons = 0
displacements = 0


def mergeSort(arr):
    global comparisons
    global displacements
    if len(arr) > 1:
        print(f'Merge-Sorting: {arr}')
        mid = len(arr)//2
        print(f'Pick middle index: {mid}')
        L = arr[:mid]
        print(f'Divide left half: {L}')
        R = arr[mid:]
        print(f'Divide right half: {L}')

        print(f'Merge-Sort Left Half')
        mergeSort(L)
        print(f'Merge-Sort Right Half')
        mergeSort(R)

        i = j = k = 0

        print('Combine left and right half')

        while i < len(L) and j < len(R):
            comparisons += 1
            if L[i] < R[j]:
                if arr[k] != L[i]:
                    displacements += 1
                arr[k] = L[i]

                i += 1
            else:
                if arr[k] != R[j]:
                    displacements += 1
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            if arr[k] != L[i]:
                displacements += 1
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            if arr[k] != R[j]:
                displacements += 1
            j += 1
            k += 1
        print(f'Combined halves: {arr}')
    else:
        print('It is sorted')
        print('------------')


A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
C = [5, 2, 13, 9, 1, 7, 6, 8, 1, 15, 4, 11]
D = ['S', 'B', 'I', 'M', 'H', 'Q', 'C', 'L', 'R', 'E', 'P', 'K']

mergeSort(D)
print(f'Merge sort done.')
print(f'Comparisons count: {comparisons}')
print(f'Displacement count: {displacements}')
