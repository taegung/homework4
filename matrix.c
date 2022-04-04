#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);//행렬 메모리 할당하는 함수
void print_matrix(int** matrix, int row, int col);//행렬 출력하는 함수
int free_matrix(int** matrix, int row, int col);//행렬 메모리 할당 해제
int fill_data(int** matrix, int row, int col);//행렬 메모리에 값 입력하는 함수
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);//a,b행렬 더하는 함수
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);//a,b행렬 뺴는 함수
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);//전치 행렬 구하는 함수
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);//a,전치 행렬 곱 구하는 함수 

int main()
{
    char command;
    printf("[----- [윤태경]  [2019038059] -----]\n");

	int row, col;//행,열 변수 지정
	srand(time(NULL));

	printf("Input row and col : ");
	scanf("%d %d", &row, &col);//행과 열 입력
    int** matrix_a = create_matrix(row, col);//행렬a 메모리 할당
	int** matrix_b = create_matrix(row, col);//행렬b 메모리 할당
    int** matrix_a_t = create_matrix(col, row);//a의 전치행렬 메모리 할당

	printf("Matrix Created.\n");

	if (matrix_a == NULL || matrix_b == NULL) {return -1;}

	do{//행렬 a,행렬b 가 NULL이 아니면 실행
		printf("----------------------------------------------------------------\n");
		printf("                     Matrix Manipulation                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Matrix   = z           Print Matrix        = p \n");
		printf(" Add Matrix          = a           Subtract Matrix     = s \n");
		printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
		printf(" Quit                = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);//command 입력

		switch(command) {
		case 'z': case 'Z'://z를 입력했을떄
		    printf("Matrix Initialized\n");
			fill_data(matrix_a, row, col);//a행렬 메모리에 랜덩으로 20이하 정수 입력
			fill_data(matrix_b, row, col);//b행렬 메모리에 랜덩으로 20이하 정수 입력
			break;
        case 'p': case 'P'://p를 입력했을때
            printf("Print matrix\n");
            printf("matrix_a\n");
			print_matrix(matrix_a, row, col);//a행렬 출력
			printf("matrix_b\n");
			print_matrix(matrix_b, row, col);//b행렬 출력
			break;
        case 'a': case 'A'://a를 입력했을떄
			printf("Add two matrices\n");
			addition_matrix(matrix_a, matrix_b, row, col);//a행렬b행렬더함
			break;
        case 's': case 'S'://s를 입력했을떄
			printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);//a행렬 b행렬 뻄
			break;
        case 't': case 'T'://t를 입력했을때
			printf("Transpose matrix_a \n");
			printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);//a의 전치 행렬 구함
            print_matrix(matrix_a_t, col, row);//a의 전치 행렬 출력
			break;
        case 'm': case 'M'://m을 입력 했을때
			printf("Multiply matrix_a with transposed matrix_a \n");
			transpose_matrix(matrix_a, matrix_a_t, col, row);//a의 전치 행렬 구함
            multiply_matrix(matrix_a, matrix_a_t, row, col);//a와 a의전치행렬 곱함
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);//a의 전치행렬 메모리 할당 해제
            free_matrix(matrix_a, row, col);//a행렬 메모리 할당 해제
            free_matrix(matrix_b, row, col);//b행렬 메모리 할당 해제
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)//행렬 메모리 할당하는 함수
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return NULL;//null 리턴
	}

	int** matrix = (int**)malloc(sizeof(int*) * row);//matrix 에 행 메모리 할당
	for (int r = 0; r < row; r++) {
		matrix[r] = (int*)malloc(sizeof(int) * col);//matrix행에 대헤서 열의 메모리 할당
	}

	/* Check post conditions */
	if (matrix == NULL) {//matrix가 메모리 할당 안되있을때
		printf("Memory Allocation Failed.\n");
		return NULL;
	}

	return matrix;//matrix 리턴
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)//matrix 출력하는 함수
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return;
	}
    for (int matrix_row = 0; matrix_row < row; matrix_row++) {// 행렬의 행만큼 반복
		for (int matrix_col = 0; matrix_col < col; matrix_col++)//행렬의 열만큼 반복
			printf("%3d ", matrix[matrix_row][matrix_col]);//matrix각각의 행과렬 출력
		printf("\n");
	}
	printf("\n");
	/* Check post conditions */
	 if (matrix == NULL) {
		printf("Memory Allocation Failed.\n");
		return;
	}


	return;
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)//메모리 할당해제
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return -1;
	}

	for (int matrix_row = 0; matrix_row < row; matrix_row++) {//matrix 행 만큼반복
		free(matrix[matrix_row]);//matrix 각행 메모리할당 해제
	}

	free(matrix);
	return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)//행렬 메모리에 값 입력하는 함수
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return -1;
	}
    for (int matrix_row = 0; matrix_row < row; matrix_row++)
		for (int matrix_col = 0; matrix_col < col; matrix_col++)
			matrix[matrix_row][matrix_col] = rand() % 20;//matrix행렬에 20이하의 정수값 입력
	/* Check post conditions */
    if (matrix == NULL) {//matrix null일때
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	return 1;
}

/* mmatrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)//a행렬 b행렬 더하는 함수
{
    int** matrix_sum = create_matrix(row, col);//sum이라는 matrix 메모리 할당
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {// 행렬의 행만큼 반복
		for (int matrix_col = 0; matrix_col < col; matrix_col++)// 행렬의 열만큼 반복
			matrix_sum[matrix_row][matrix_col] = matrix_a[matrix_row][matrix_col] + matrix_b[matrix_row][matrix_col];
	}//sum각각의 행과 열에  a와b의 각각의 행과 열를 더해서 값을 넣어줌
	/* Check post conditions */
	if (matrix_a == NULL || matrix_b == NULL || matrix_sum == NULL) {//a행렬과 b행렬과 sum행렬이 null일때
		printf("Memory Allocation Failed.\n");
		return -1;
	}

	print_matrix(matrix_sum, row, col);//sum행렬 출력
	free_matrix(matrix_sum, row, col);//sum행렬 메모리 할당 해제
	return 1;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)//a행렬 b행렬 뺴는 함수
{
    int** matrix_sub = create_matrix(row, col);//sub이라는 matrix 메모리 할당
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {// 행렬의 행만큼 반복
		for (int matrix_col = 0; matrix_col < col; matrix_col++)// 행렬의 열만큼 반복
			matrix_sub[matrix_row][matrix_col] = matrix_a[matrix_row][matrix_col] - matrix_b[matrix_row][matrix_col];
	}//sub각각의 행과 열에  a와b의 각각의 행과 열를 뺴서 값을 넣어줌
	/* Check post conditions */
    if (matrix_a == NULL || matrix_b == NULL || matrix_sub == NULL) {
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	print_matrix(matrix_sub, row, col);//sub행렬 출력
	free_matrix(matrix_sub, row, col);//sub행렬 메모리 할당 해제

	return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)//전치 행렬 구하는 함수
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {// 행렬의 행만큼 반복
		for (int matrix_col = 0; matrix_col < col; matrix_col++)// 행렬의 열만큼 반복
			matrix_t[matrix_row][matrix_col] = matrix[matrix_col][matrix_row];
	}//matrix_t에 matrix의 행과 열을 거꾸로 입력
	/* Check post conditions */
    if (matrix == NULL || matrix_t ==NULL) {//matrix와 matrix_t 가 null일떄
		printf("Memory Allocation Failed.\n");
		return -1;
	}

	return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)//a,전치 행렬 곱 구하는 함수 
{
    int** matrix_axt = create_matrix(row, row);//axt라는 행렬 메모리 할당
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//행 또는 열이 0이하일떄
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_a_row = 0; matrix_a_row < row; matrix_a_row++) {// a행렬의 행만큼 반복
		for (int matrix_t_row = 0; matrix_t_row < row; matrix_t_row++) {// t행렬의 행만큼 반복
			int temp = 0;
			for (int matrix_col = 0; matrix_col < col; matrix_col++)// 행렬의 열만큼 반복
				temp += matrix_a[matrix_a_row][matrix_col] * matrix_t[matrix_col][matrix_t_row];//temp에 a의행은고정,열은 반복한 값이랑 t의행반복 열고정 값을 곱해서 temp에 넣고
                //그다음은 t의 열도 반복하면서 곱해서 temp에 더해서 넣고 마지막으로 a의 행도 반복하면서 곱해서 temp에 더해서 넣는다
			matrix_axt[matrix_a_row][matrix_t_row] = temp;//axt라는 행렬에 temp값 입력
		}
	}
	/* Check post conditions */
    if (matrix_t == NULL || matrix_axt ==NULL) {//matrix_t 와 matrix_axt null 일대
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	print_matrix(matrix_axt, row, row);//axt행렬 출력
	free_matrix(matrix_axt, row, col);//axt의 행렬 메모리 할당 해제
	return 1;
}

