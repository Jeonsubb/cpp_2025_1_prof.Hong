#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
//������ 10 ~ 60 ���̿� ����
void inputData(int data[], int size) {
    srand(time(0));
    for(int i = 0; i<size; i++){
        data[i]= (rand() % 51) + 10;
    }
}

void swap(int arr[], int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}
void showData(const string &msg, int data[], int size){
    cout << msg << " : ";
    for (int i=0; i<size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

void sortData(int data[], int size){
    for (int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(data[i]>data[j]){
                swap(data, i,j);
            }
        }
    }
}

void reverse(int data[], int size){
    for(int i=0; i<size/2; i++){
        swap(data,i,size-i-1);
    }
}

void maxSort(int data[], int size){
    int maxindex = 0;
    int max = data[0];
    for(int i=0; i<size; i++){
        if(data[i]> max){
            maxindex = i;
            max = data[i];
        }
    }
    swap(data,maxindex,size-1);
}
/*
 * ���̵��� �ſ� ���� �˰��� ����
 * ���ĵ� ���� �迭�� ���� ���� �߰��ϴ� �˰��� > �� �迭�� ũ��� ���� �迭���� +1�� ����� ���� �迭�� copy�� ��
 * ���Ե� ���� �߰��� ���� �˰��� �����ϱ�
 * O(n) �˰������� ����
 */
int* insertData(int data[], int size, int value) {
    int* newData = new int[size + 1];// �Լ� �����Ŀ��� ���� �־� delete[] �ʿ�

    //��ġ ã�� 
    int insertIndex=0;
    while(insertIndex < size && data[insertIndex] < value){
        insertIndex++;
    }

    for(int i=0; i<insertIndex; i++){
        newData[i] = data[i];
    }
    newData[insertIndex] = value;

    for(int i= insertIndex; i<size;i++){
        newData[i+1] = data[i];
    }
    return newData;
}

int main() {
    int data[SIZE];
    inputData(data, SIZE);
    showData("���� �Է�", data, SIZE);

    sortData(data, SIZE);
    showData("������", data, SIZE);

    reverse(data, SIZE);
    showData("\n���� ���ġ", data, SIZE);

    maxSort(data, SIZE);

    sortData(data, SIZE);
    showData("\n ������", data, SIZE);

    int realData[] = { 5, 15, 99 };
    for (int newData : realData) {
        int* result = insertData(data, SIZE, newData);
        cout << "\n\n" << newData << " : ";
        showData("�Ǽ� ������", result, SIZE + 1);
        delete[] result;
    }
    system("pause");
    return 0;
}
