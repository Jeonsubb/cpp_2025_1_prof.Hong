/*
* ������ �迭 ó�� �Լ� ����
*/
#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()

#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 4

using namespace std;




// ��� ���� - ���� �����Ϳ� ���� ���ذ� �ʿ� => chap 2
int** addMatrix2(int X[][COLS_A], int Y[][COLS_A], int rows, int cols) {
    int** Z = new int* [rows];
    for (int i = 0; i < rows; i++) {
        Z[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            Z[i][j] = X[i][j] + Y[i][j];
        }
    }
    return Z;
}



int main() {
    srand(time(0)); // ���� �ʱ�ȭ

    int A[ROWS_A][COLS_A]; // 2x3 ���
    int B[ROWS_B][COLS_B]; // 3x4 ���
    int C[ROWS_A][COLS_B]; // 2x4 ���
    int D[ROWS_A][COLS_A]; // 2x3 ���� ���
    int E[ROWS_A][COLS_A]; // ���� ��� ���
    int F[COLS_B][ROWS_B]; // ��ġ ���
    int G[ROWS_A][COLS_B]; // ��ġ ��� Ȱ�� ���� ���


    inputData(A, ROWS_A, COLS_A);
    inputData(B, ROWS_B, COLS_B);

    // �迭 ���� (���� ����)
    for (int i = 0; i < ROWS_A; i++)
        for (int j = 0; j < COLS_A; j++)
            D[i][j] = A[i][j];

    cout << "A[2][3] = \n";
    showData("��� A", A, ROWS_A, COLS_A);

    cout << "D[2][3] = \n";
    showData("��� D", D, ROWS_A, COLS_A);

    cout << "B[3][4] = \n";
    showData("��� B", B, ROWS_B, COLS_B);

    addMatrix(A, D, E, ROWS_A, COLS_A);
    cout << "E[2][3] = \n";
    showData("��� E", E, ROWS_A, COLS_A);

    int** H = addMatrix2(A, D, ROWS_A, COLS_A);
    cout << "H[2][3] = \n";
    showData2("��� H", H, ROWS_A, COLS_A);

    multiplyMatrix(A, B, C, ROWS_A, COLS_A, COLS_B);
    cout << "C[2][4] = \n";
    showData("��� C", C, ROWS_A, COLS_B);

    transposeMatrix(B, F, ROWS_B, COLS_B);
    cout << "F[4][3] = \n";
    showData("��� F (B�� ��ġ)", F, COLS_B, ROWS_B);

    multiplyMatrixTransposed(A, F, G, ROWS_A, COLS_A, COLS_B);
    cout << "G[2][4] (��ġ ����� Ȱ���� ���� ���) = \n";
    showData("��� G", G, ROWS_A, COLS_B);

    if (equals(A, D, ROWS_A, COLS_A))
        cout << "��� A�� D�� �����մϴ�.\n";
    else
        cout << "��� A�� D�� �������� �ʽ��ϴ�.\n";
    system("pause");
    return 0;
}
