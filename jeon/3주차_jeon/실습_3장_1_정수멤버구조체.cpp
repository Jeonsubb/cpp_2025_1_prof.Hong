#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct Rectangle {
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
};

/*
typedef struct Rectangle {
    int leftBottomX;
    int leftBottomY;
    int width;
    int height;
} Rectangle;
*/


//기본적인 C 언어 문법에서는 struct Rectangle를 반드시 써야
int compareRectangles(const struct Rectangle* a, const struct Rectangle* b) {

    int as = a->width * a->height;
    int bs = b->width * b->height;
    return (as - bs); //포인터 구조체로 받으면 멤버 변수에 접근 하기 위해서 -> 연산자..
}
void showRectangle(struct Rectangle r) {
    printf("[%d, %d, %d, %d]\n", r.leftBottomX, r.leftBottomY, r.width, r.height);
}

//매개변수 자료형에 * 붙으면 멤버변수에 접근 하기 위해서 -> 를 쓴다는 거
void showRectangles(const char* message, struct Rectangle* rectangles[], int numRectangles) {
    cout << message << "\n";
    for (int i = 0; i < numRectangles; i++) {
        cout << rectangles[i]->leftBottomX << " " << rectangles[i]->leftBottomY << " " << rectangles[i]->width << " " << rectangles[i]->height << "\n";
    }

}

//이렇게 swap 가능.. 지금 이 swap은 포인터 값 자체가 바뀌는게 아니라 포인터 배열의 인덱스 위치만 조정하는 거니깐.
void swap(struct Rectangle* rect[], int i, int j) {
    struct Rectangle* temp = rect[i];
    rect[i] = rect[j];
    rect[j] = temp;
}

//x좌표 기준 정렬을 하라는 거 .... 이걸로 하면 정렬이 의미가 없어서 넓이 기준으로 함

//선택정렬  -> 최소/최대의 인덱스를 찾고 걔를 맨앞 혹은 맨뒤에 하나씩 쌓아가는거
//버블정렬 -> 크거나 작다면 옆으로 밀어내는 방식 

void selectionSortRectangles(struct Rectangle* rectangles[], int numRectangles) {
    // int compareRectangles(const Student* b);를 사용한 정렬
    // void swap(Rectangle * rect[], int i, int j) 사용
    for (int i = 0; i < numRectangles; i++) {
        for (int j = 0; j < numRectangles-1 ; j++) {
            //오른쪽으로 가야 됨.. 
            if (compareRectangles(rectangles[j], rectangles[j+1]) > 0)  swap(rectangles, j, j+1);
        }
    }


}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);//한글깨지는 문제 해결하기 위해 사용 
    const int numRectangles = 5;
    struct Rectangle r1 = { 3, 5, 10, 15 };
    struct Rectangle r2 = { 3, 5, 10, 12 };
    struct Rectangle r3 = { 3, 5, 6, 10 };
    struct Rectangle r4 = { 3, 5, 7, 8 };
    struct Rectangle r5 = { 3, 3, 9, 14 };

    //각 구조체 변수의 주소를 담는 포인터 배열 변수, ... 그래서 포인터 배열 초기화 할 때 &으로 주소를 넣음
    struct Rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 };

    showRectangles("정렬전:", rectangles, numRectangles);

    selectionSortRectangles(rectangles, numRectangles);

    showRectangles("정렬후:", rectangles, numRectangles);

    system("pause");
    return 0;
}