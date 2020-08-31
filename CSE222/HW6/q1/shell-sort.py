def shell_sort(arr):

    comparisons = 0
    displacements = 0
    arr_len = len(arr)
    gap = arr_len // 2

    while gap > 0:
        print(f'Arr: {arr}')
        print(f'Gap: {gap}')

        for i in range(gap, arr_len):

            print(f'Pick arr[{i}]: {arr[i]}')
            temp = arr[i]

            print('Shifting gap-sorted elements.')
            j = i
            while j >= gap and arr[j-gap] > temp:
                comparisons += 1
                print(f'Swap {arr[j]} with {arr[j-gap]}')
                if(arr[j] != arr[j-gap]):
                    displacements += 1
                arr[j] = arr[j-gap]
                j -= gap
            comparisons += 1

            print(f'Put last picked arr[{i}]: {arr[i]} to arr[{j}]')
            if(arr[j] != temp):
                displacements += 1
            arr[j] = temp
            print(f'arr[{i}]: {arr[j]} is correct')
            print('------------------------')

        print('Reduce gap.')
        gap //= 2

    print(f'Arr: {arr}')
    print(f'Gap: {gap}')
    print('Shell Sort done')
    print(f'Comparisons count: {comparisons}')
    print(f'Displacement count: {displacements}')


A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
C = [5, 2, 13, 9, 1, 7, 6, 8, 1, 15, 4, 11]
D = ['S', 'B', 'I', 'M', 'H', 'Q', 'C', 'L', 'R', 'E', 'P', 'K']

shell_sort(D)
