/*
5,6장 학습후 아래 실습 코드를 완성할 수 있는 스킬을 확보해야 한다.
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <string.h>



using namespace std;

class Student {
public:
    
    char* name;
    int age;
    char* city;
    //디폴트 생성자
    Student() {}
    Student(const char* name, int age, const char* city);
    void swap(Student* b);
    void showStudent();
    ~Student(); // Destructor 추가
    int compareStudents(const Student* b);
    void updateStudentCity(const char* city);
};
void Student::updateStudentCity(const char* city) {
    this->city = _strdup(city);
}
int Student::compareStudents(const Student* b) {
    return (this->age - b->age);

}
void Student::showStudent() {
    cout << this->name << " " << this->age << " " << this->city << "\n";
}
// Constructor 구현 - 오류 수정

/*
name은 const char* — 즉, 문자열 리터럴의 주소고
this->name은 char* — 즉, Student 객체 안에서 실제로 소유할 메모리 주소
strdup 함수를 쓰자 (malloc이랑 strcpy를 합친거,,, 복사본을 만들고 heap 메모리 공간에 새로 저장해서 name이 걔를 가리키도록!)
사실은 string을 쓰면 다 해결된다.
*/
Student::Student(const char* name, int age, const char* city) {
    this->name = _strdup(name);
    this->age = age;
    this->city = _strdup(city);

}

// Destructor 구현
//소멸자
Student::~Student() {
    //널 체크
    if (name) free(name);
    if (city) free(city);
}
void Student::swap(Student* b) {


   
        char* temp1 = this->name;
        this->name = b->name;
        b->name = temp1;

        char* temp2 = this->city;
        this->city = b->city;
        b->city = temp2;


        int temp = this->age;
        this->age = b->age;
        b->age = temp;
    
}

void showStudents(string message, Student* students[], int numStudents) {
    //void showStudent();를 사용한 객체 출력

    cout << message << "\n";
    for (int i = 0; i < numStudents; i++) {
        students[i]->showStudent();
    }

}

void selectionSortStudents(Student* students[], int numStudents) {
    // int compareStudents(const Student* b);를 사용한 정렬
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - 1; j++) {
            if (students[j]->compareStudents(students[j + 1]) > 0) students[j]->swap(students[j + 1]);
        }
    }


}
int main() {
    SetConsoleOutputCP(CP_UTF8);//한글깨지는 문제 해결하기 위해 사용 
// 학생 객체 초기화
    int numStudents = 5;
    Student student1("hong", 23, "Busan");
    Student student2("Gang", 22, "Ju");
    Student student3("Ul", 13, "Sal");
    Student student4("Li", 19, "Han");
    Student student5("Gp", 33, "Gong");
    Student* students[5] = { &student1,&student2,&student3,&student4 ,&student5 };
    // 각 학생 정보 출력
    showStudents("before:", students, numStudents);
    student1.updateStudentCity("NAAAAAAAAAAAa");
    student1.showStudent();
    selectionSortStudents(students, numStudents);
    showStudents("after", students, numStudents);

    system("pause");
    return 0;
}