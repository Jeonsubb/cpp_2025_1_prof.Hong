//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <string.h>
//#include <stdlib.h>
//
//using namespace std;
//
////구조체 별명 지어주기
////typedef struct 구조체이름 {} 구조체 별명; ... 이때 별명과 이름이 같으면 안됨
//typedef struct rectangle {
//    int leftBottomX;
//    int leftBottomY;
//    int width;
//    int height;
//    const char* name; //문자열을 넣을 때 "가나다" 같은, 얘네는 상수로 취급하기 때문에 변수 자료형에 const 붙여줘야 됨
//} Rectangle;
//
//
//int compareRectangles(const Rectangle* a, const Rectangle* b) {
//    return (a->leftBottomX - b->leftBottomX);
//}
//void showRectangle(struct rectangle r) {
//    printf("[%d, %d, %d, %d, %s]\n", r.leftBottomX, r.leftBottomY, r.width, r.height, r.name);
//}
//
//void changeRectangle(Rectangle* r, const char* newName) {
//    cout << "r1 name is changed" << endl;
//    // r.name = newName;
//    // strcpy(r.name, newName);
//    r->name = _strdup(newName);
//}
//
//void showRectangles(string message, Rectangle* rectangles[], int numRectangles) {
//    //void showRectangle(struct Rectangle r) 사용
//    cout << message;
//    for (int i = 0; i < numRectangles; i++) {
//
//        //포인터니까 *로 값 반환///////////////////이런게 제일 중요함 함수 넘겨줄때 앞에 뭘줘야 하는지
//        
//        showRectangle(*rectangles[i]);
//    }
//
//
//}
//
//void swap(struct rectangle* rect[], int i, int j) {
//    struct rectangle* temp = rect[i];
//    rect[i] = rect[j];
//    rect[j] = temp;
//}
//
////x좌표 기준 정렬을 하라는 거 .... 이걸로 하면 정렬이 의미가 없어서 넓이 기준으로 함
//
////선택정렬  -> 최소/최대의 인덱스를 찾고 걔를 맨앞 혹은 맨뒤에 하나씩 쌓아가는거
////버블정렬 -> 크거나 작다면 옆으로 밀어내는 방식 
//
//void selectionSortRectangles(struct rectangle* rectangles[], int numRectangles) {
//    // int compareRectangles(const Student* b);를 사용한 정렬
//    // void swap(Rectangle * rect[], int i, int j) 사용
//    for (int i = 0; i < numRectangles; i++) {
//        for (int j = 0; j < numRectangles - 1; j++) {
//            //오른쪽으로 가야 됨.. 
//            if (compareRectangles(rectangles[j], rectangles[j + 1]) > 0)  swap(rectangles, j, j + 1);
//        }
//    }
//
//
//}
//
//int main(void) {
//    //SetConsoleOutputCP(CP_UTF8);//한글깨지는 문제 해결하기 위해 사용  ---> windows.h 에 있는거
//    const int numRectangles = 5;
//    struct rectangle r1 = { 3, 5, 10, 15,"r1" };
//    struct rectangle r2 = { 1, 2, 8, 12 ,"r2" };
//    struct rectangle r3 = { 1, 2, 8, 10,"r3" };
//    struct rectangle r4 = { 3, 5, 10, 15 ,"r4" };
//    struct rectangle r5 = { 3, 5, 10, 14,"r5" };
//    struct rectangle* rectangles[numRectangles] = { &r1,&r2,&r3,&r4,&r5 };
//
//    showRectangles("정렬전:", rectangles, numRectangles);
//    changeRectangle(&r1, "square");
//
//
//    showRectangle(r1);
//    showRectangles("변경후:", rectangles, numRectangles);
//    selectionSortRectangles(rectangles, numRectangles);
//
//    showRectangles("정렬후:", rectangles, numRectangles);
//
//    system("pause");
//    return 0;
//}