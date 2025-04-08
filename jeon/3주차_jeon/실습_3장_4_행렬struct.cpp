//// matrixMultiplication.cpp - 2차원 행렬을 struct으로 구현  - 자료구조 문제
//#include <stdio.h>
//#include <iostream>
//#include <stdlib.h>
//#include "time.h"
//#include <windows.h>
//using namespace std;
//
//// 보통 행렬에 대하여add, sub, mult, transpose 구현하는 코딩 
////그니까 얘는 행과 열의 수, 그리고 Term이라는 포인터에 행렬을 1차원으로 담고 있는 구조체
//struct Matrix {
//	int rows;
//	int cols;
//	int* Term;
//};
//
//int getData(struct Matrix* a);
//int showData(struct Matrix* a);// 행렬 모양: A[rows][cols] 출력
//void add(struct Matrix*, struct Matrix*, struct Matrix*);
//void transpose(struct Matrix*, struct Matrix*);
//bool multiply(struct Matrix*, struct Matrix*, struct Matrix*);
//void free(struct Matrix*);
//
//
////*/
//int main()
//{
//	SetConsoleOutputCP(CP_UTF8);//한글깨지는 문제 해결하기 위해 사용 
//	struct Matrix a = { 2,3,0 }, b = { 2,3,0 }, c = { 2,3,0 }, d = { 3,4,0 }, e = { 2,4,0 };
//	srand(42);
//	printf("matrix a[2][3]의 입력: \n");
//	getData(&a);
//	showData(&a);
//	printf("matrix b[2][3]의 입력: \n");
//	getData(&b);
//	showData(&b);
//	getData(&c);
//	add(&a, &b, &c);
//	printf("matrix c의 출력: \n");
//	showData(&c);
//
//	printf("matrix d[3][4]의 입력: \n");
//	getData(&d);
//	showData(&d);
//	//*
//	getData(&e);
//	multiply(&a, &d, &e);
//
//	printf("matrix e[2][4]의 출력: \n");
//	showData(&e);
//	free(&a); free(&b); free(&c); free(&d); free(&e);
//	//*/
//	system("pause");
//	return 0;
//}
//
//
//int getData(struct Matrix* a) {
//
//	//메모리 할당
//	int rows = a->rows; int cols = a->cols;
//	a->Term = (int*)malloc(rows * cols* sizeof(int));
//
//	//0~9까지의 랜덤 값 할당
//	for (int i = 0; i < a->rows; i++) {
//		for (int j = 0; j < a->cols; j++) {
//			a->Term[j + i * a->cols] = rand() % 10;
//		}
//	}
//
//	return 0;
//}
//int showData(struct Matrix* a) {
//	int rows = a->rows; int cols = a->cols;
//	for (int i = 0; i < a->rows; i++) {
//		for (int j = 0; j < a->cols; j++) {
//			cout << a->Term[j + i * a->cols] << " ";
//		}
//		cout << "\n";
//	}
//	
//
//
//	return 1;
//}
//void add(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
//
//	//행렬 덧셈을 할려면 각 행과 열이 동일해야 함
//	if (a->rows != b->rows || a->cols != b->cols) {
//		printf("a, b는 incompatiable matrix\n");
//		return;
//	}
//
//	c->Term = (int*)malloc(c->rows * c->cols * sizeof(int));
//
//	for (int i = 0; i < c->rows; i++) {
//		for (int j = 0; j < c->cols; j++) {
//			c->Term[j + i * c->cols] = a->Term[j + i * a->cols]+ b->Term[j + i * b->cols];
//		}
//	}
//
//	return;
//
//}
////*
//void transpose(struct Matrix* a, struct Matrix* a1) {
//	//행과 열 바꾸기
//	a1->rows = a->cols;
//	a1->cols = a->rows;
//	a1->Term = (int*)malloc(a1->rows * a1->rows * sizeof(int));
//	for (int i = 0; i < a->rows; i++) {
//		for (int j = 0; j < a->cols; j++) {
//			a1->Term[i + j * a->rows] = a->Term[j + i * a->cols];
//
//			//오른쪽건 그대로 왼쪽건 i와 j를 바꿔, col 이 row로
//		}
//	}
//	
//
//	
//
//}
//
////a,d,e
//bool multiply(struct Matrix* a, struct Matrix* b, struct Matrix* c) {
//
//	
//	if (a->cols != b->rows) {
//		printf("incompatible matrices");
//		return false;
//	}
//
//	c->Term = (int*)malloc(a->rows * b->cols * sizeof(int));
//
//	struct Matrix bXpose = { b->cols, b->rows };
//	getData(&bXpose);
//	transpose(b, &bXpose);
//	printf("transpose matrix \n");
//	showData(&bXpose);
//
//	//matrix 연산
//	//2,4
//
//	
//	//결과의 행
//	for (int i = 0; i < a->rows; i++) {
//		//결과의 열
//		for (int k = 0; k < b->cols; k++) {
//			int sum = 0;
//			//얘가 공통
//			for (int j = 0; j < a->cols; j++) {
//				//각 행의 열들을 다 돌아				//각 열의 행들을 다 돌아
//				sum += a->Term[j + i * a->cols] * b->Term[k + j * b->cols];
//			}
//			c->Term[k + i * c->cols] = sum;
//		}
//	}
//
//	struct Matrix x = { 2,4,0 };
//	x.Term = (int*)malloc(x.cols * x.rows * sizeof(int));
//
//	for (int i = 0; i < a->rows; i++) {
//		for (int k = 0; k < b->cols; k++) {
//			int sum = 0;
//			for (int j = 0; j < a->cols; j++) {
//				sum += a->Term[j + i * a->cols] * bXpose.Term[j + k * bXpose.cols];
//			}
//			x.Term[k + i * x.cols] = sum;
//		}
//	}
//
//	cout << "전치행렬활용" << "\n";
//	showData(&x);
//
//
//
//	free(&bXpose);
//	return true;
//}
//void free(struct Matrix* m) {
//	free(m->Term);
//}
//
//
//
//
//
//
//
//
///*
////기본적인 2차원 행렬 곱셈
//for (int i = 0; i < m; i++) {
//	for (int j = 0; j < p; j++) {
//		for (int k = 0; k < n; k++) {
//			C[i][j] += A[i][k] * B[k][j];
//		}
//	}
//}
//-> B는 세로 방향으로 접근해야 됨 -> 캐시 효율이 떨어진다.
//
//
////전치행렬을 활용한 2차원 행렬 곱셈
//for (int i = 0; i < a.rows; i++) {
//	for (int k = 0; k < b.cols; k++) {
//		for (int j = 0; j < a.cols; j++) {
//			sum += a[i][j] * bᵗ[k][j];
//		}
//	}
//}
//-> B의 전치를 하고 곱하게 되면 행과 열의 곱이 행과 행의 곱으로 바뀐다!
//
//
//
//
//
//
//
//*/