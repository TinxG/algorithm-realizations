def selectionSort(sorted_list):
    result = []
    for i in range(0, len(sorted_list)):
        result.append(max(sorted_list))
        sorted_list.pop(sorted_list.index(max(sorted_list)))
    return result


if __name__ == "__main__":
    for i in selectionSort([7, 4, 2, 3, 5, 1, 6]):
        print(i, end='')
