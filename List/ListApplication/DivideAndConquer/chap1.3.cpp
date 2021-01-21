#include <iostream>

using namespace std;

//复杂度为O(n^3)
int MaxSubseqSum1(int A[], int N) {
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            ThisSum = 0;
            for (int k = i; k <= j; k++) {
                ThisSum += A[k];
            }
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

//复杂度为O(n^2)
//
int MaxSubseqSum2(int A[], int N) {
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; i++) {
        ThisSum = 0;
        for (int j = i; j < N; j++) {
            ThisSum += j;
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

int Max3(int A, int B, int C) {
    return A > B ? A > C ? A : C : B > C ? B : C;
}

// 分治
int divideAndConquer(int List[], int left, int right) {
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;

    int LeftBorderSum, RightBorderSum;

    int center;

    if (left == right) {
        if (List[left] > 0) return List[left];
        else return 0;
    }

    center = (left + right) / 2;
    MaxLeftSum = divideAndConquer(List, left, center);
    MaxRightSum = divideAndConquer(List, center + 1, right);

    /*处理中间过程*/

    //[center,right]
    MaxLeftBorderSum = 0, LeftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    //[left,center]
    MaxRightBorderSum = 0, RightBorderSum = 0;
    for (int i = center + 1; i <= right; i++) {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum) {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);

}

//复杂度为O(nlogn)
int MaxSubseqSum3(int A[], int N) {

    return divideAndConquer(A, 0, N - 1);
}

//联机算法
int MaxSubseqSum4(int A[], int N) {

    int ThisSum, MaxSum, j;
    ThisSum = MaxSum = 0;

    for (j = 0; j < N; j++) {
        ThisSum += A[j];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        } else if (ThisSum < 0) {
            ThisSum = 0;
        }
    }

    return MaxSum;

}

int main() {

    const int N = 8;
    int List[N] = {4, -3, 5, -2, -1, 6, 2, -2};
    int res = MaxSubseqSum4(List, N);
    printf("%d", res);

    return 0;
}