// Copyright 2021 NNTU-CS
void sort(int arr[], int len) {
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = (len - 1); j >= (i + 1); j--) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}
int cbinsearch(int* arr, int size, int value) {
    int left = 0;
    int right = size - 1;
    int count = 0;
    int a;
    while (left < right) {
        a = left + (right - left) / 2;
        if (arr[a] == value) {
            left = a;
            while (arr[left] == value) {
                left--;
            }
            left++;
            while (arr[left] == value) {
                count++;
                left++;
            }
        } else if (arr[a] > value) {
            right = a;
        } else {
            left = a + 1;
        }
    }
    return count;
}
int countPairs1(int *arr, int len, int value) {
  sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] <= value) {
            for (int j = i + 1; j < len - 1; j++) {
                if (arr[i] + arr[j] == value) {
                    count++;
                }
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    sort(arr, len);
    int el = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] < value) {
            el = value - arr[i];
            for (int b = 0; b <= i; b++) {
                arr[b] = 0;
            }
            count = count + cbinsearch(arr, len, el);
        }
    }
    return count;
}
