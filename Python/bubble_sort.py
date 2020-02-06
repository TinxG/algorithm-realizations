def bubbleSort(sorted_list):
    for i in range(0, len(sorted_list)+1):
        for i in range(1, len(sorted_list)):
            if sorted_list[i-1] > sorted_list[i]:
                sorted_list[i-1], sorted_list[i] = sorted_list[i], sorted_list[i-1]
    return sorted_list


if __name__ == "__main__":
    for i in bubbleSort([3, 1, 4, 2, 7, 6, 5]):
        print(i, end='')
