#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);//��� �޸� �Ҵ��ϴ� �Լ�
void print_matrix(int** matrix, int row, int col);//��� ����ϴ� �Լ�
int free_matrix(int** matrix, int row, int col);//��� �޸� �Ҵ� ����
int fill_data(int** matrix, int row, int col);//��� �޸𸮿� �� �Է��ϴ� �Լ�
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);//a,b��� ���ϴ� �Լ�
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);//a,b��� ���� �Լ�
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);//��ġ ��� ���ϴ� �Լ�
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);//a,��ġ ��� �� ���ϴ� �Լ� 

int main()
{
    char command;
    printf("[----- [���°�]  [2019038059] -----]\n");

	int row, col;//��,�� ���� ����
	srand(time(NULL));

	printf("Input row and col : ");
	scanf("%d %d", &row, &col);//��� �� �Է�
    int** matrix_a = create_matrix(row, col);//���a �޸� �Ҵ�
	int** matrix_b = create_matrix(row, col);//���b �޸� �Ҵ�
    int** matrix_a_t = create_matrix(col, row);//a�� ��ġ��� �޸� �Ҵ�

	printf("Matrix Created.\n");

	if (matrix_a == NULL || matrix_b == NULL) {return -1;}

	do{//��� a,���b �� NULL�� �ƴϸ� ����
		printf("----------------------------------------------------------------\n");
		printf("                     Matrix Manipulation                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Matrix   = z           Print Matrix        = p \n");
		printf(" Add Matrix          = a           Subtract Matrix     = s \n");
		printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
		printf(" Quit                = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);//command �Է�

		switch(command) {
		case 'z': case 'Z'://z�� �Է�������
		    printf("Matrix Initialized\n");
			fill_data(matrix_a, row, col);//a��� �޸𸮿� �������� 20���� ���� �Է�
			fill_data(matrix_b, row, col);//b��� �޸𸮿� �������� 20���� ���� �Է�
			break;
        case 'p': case 'P'://p�� �Է�������
            printf("Print matrix\n");
            printf("matrix_a\n");
			print_matrix(matrix_a, row, col);//a��� ���
			printf("matrix_b\n");
			print_matrix(matrix_b, row, col);//b��� ���
			break;
        case 'a': case 'A'://a�� �Է�������
			printf("Add two matrices\n");
			addition_matrix(matrix_a, matrix_b, row, col);//a���b��Ĵ���
			break;
        case 's': case 'S'://s�� �Է�������
			printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);//a��� b��� �M
			break;
        case 't': case 'T'://t�� �Է�������
			printf("Transpose matrix_a \n");
			printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);//a�� ��ġ ��� ����
            print_matrix(matrix_a_t, col, row);//a�� ��ġ ��� ���
			break;
        case 'm': case 'M'://m�� �Է� ������
			printf("Multiply matrix_a with transposed matrix_a \n");
			transpose_matrix(matrix_a, matrix_a_t, col, row);//a�� ��ġ ��� ����
            multiply_matrix(matrix_a, matrix_a_t, row, col);//a�� a����ġ��� ����
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);//a�� ��ġ��� �޸� �Ҵ� ����
            free_matrix(matrix_a, row, col);//a��� �޸� �Ҵ� ����
            free_matrix(matrix_b, row, col);//b��� �޸� �Ҵ� ����
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)//��� �޸� �Ҵ��ϴ� �Լ�
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return NULL;//null ����
	}

	int** matrix = (int**)malloc(sizeof(int*) * row);//matrix �� �� �޸� �Ҵ�
	for (int r = 0; r < row; r++) {
		matrix[r] = (int*)malloc(sizeof(int) * col);//matrix�࿡ ���켭 ���� �޸� �Ҵ�
	}

	/* Check post conditions */
	if (matrix == NULL) {//matrix�� �޸� �Ҵ� �ȵ�������
		printf("Memory Allocation Failed.\n");
		return NULL;
	}

	return matrix;//matrix ����
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)//matrix ����ϴ� �Լ�
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return;
	}
    for (int matrix_row = 0; matrix_row < row; matrix_row++) {// ����� �ุŭ �ݺ�
		for (int matrix_col = 0; matrix_col < col; matrix_col++)//����� ����ŭ �ݺ�
			printf("%3d ", matrix[matrix_row][matrix_col]);//matrix������ ����� ���
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
int free_matrix(int** matrix, int row, int col)//�޸� �Ҵ�����
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return -1;
	}

	for (int matrix_row = 0; matrix_row < row; matrix_row++) {//matrix �� ��ŭ�ݺ�
		free(matrix[matrix_row]);//matrix ���� �޸��Ҵ� ����
	}

	free(matrix);
	return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)//��� �޸𸮿� �� �Է��ϴ� �Լ�
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return -1;
	}
    for (int matrix_row = 0; matrix_row < row; matrix_row++)
		for (int matrix_col = 0; matrix_col < col; matrix_col++)
			matrix[matrix_row][matrix_col] = rand() % 20;//matrix��Ŀ� 20������ ������ �Է�
	/* Check post conditions */
    if (matrix == NULL) {//matrix null�϶�
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	return 1;
}

/* mmatrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)//a��� b��� ���ϴ� �Լ�
{
    int** matrix_sum = create_matrix(row, col);//sum�̶�� matrix �޸� �Ҵ�
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {// ����� �ุŭ �ݺ�
		for (int matrix_col = 0; matrix_col < col; matrix_col++)// ����� ����ŭ �ݺ�
			matrix_sum[matrix_row][matrix_col] = matrix_a[matrix_row][matrix_col] + matrix_b[matrix_row][matrix_col];
	}//sum������ ��� ����  a��b�� ������ ��� ���� ���ؼ� ���� �־���
	/* Check post conditions */
	if (matrix_a == NULL || matrix_b == NULL || matrix_sum == NULL) {//a��İ� b��İ� sum����� null�϶�
		printf("Memory Allocation Failed.\n");
		return -1;
	}

	print_matrix(matrix_sum, row, col);//sum��� ���
	free_matrix(matrix_sum, row, col);//sum��� �޸� �Ҵ� ����
	return 1;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)//a��� b��� ���� �Լ�
{
    int** matrix_sub = create_matrix(row, col);//sub�̶�� matrix �޸� �Ҵ�
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {// ����� �ุŭ �ݺ�
		for (int matrix_col = 0; matrix_col < col; matrix_col++)// ����� ����ŭ �ݺ�
			matrix_sub[matrix_row][matrix_col] = matrix_a[matrix_row][matrix_col] - matrix_b[matrix_row][matrix_col];
	}//sub������ ��� ����  a��b�� ������ ��� ���� ���� ���� �־���
	/* Check post conditions */
    if (matrix_a == NULL || matrix_b == NULL || matrix_sub == NULL) {
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	print_matrix(matrix_sub, row, col);//sub��� ���
	free_matrix(matrix_sub, row, col);//sub��� �޸� �Ҵ� ����

	return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)//��ġ ��� ���ϴ� �Լ�
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {// ����� �ุŭ �ݺ�
		for (int matrix_col = 0; matrix_col < col; matrix_col++)// ����� ����ŭ �ݺ�
			matrix_t[matrix_row][matrix_col] = matrix[matrix_col][matrix_row];
	}//matrix_t�� matrix�� ��� ���� �Ųٷ� �Է�
	/* Check post conditions */
    if (matrix == NULL || matrix_t ==NULL) {//matrix�� matrix_t �� null�ϋ�
		printf("Memory Allocation Failed.\n");
		return -1;
	}

	return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)//a,��ġ ��� �� ���ϴ� �Լ� 
{
    int** matrix_axt = create_matrix(row, row);//axt��� ��� �޸� �Ҵ�
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {//�� �Ǵ� ���� 0�����ϋ�
		printf("Check the size of row and col!\n");
		return -1;
	}
	for (int matrix_a_row = 0; matrix_a_row < row; matrix_a_row++) {// a����� �ุŭ �ݺ�
		for (int matrix_t_row = 0; matrix_t_row < row; matrix_t_row++) {// t����� �ุŭ �ݺ�
			int temp = 0;
			for (int matrix_col = 0; matrix_col < col; matrix_col++)// ����� ����ŭ �ݺ�
				temp += matrix_a[matrix_a_row][matrix_col] * matrix_t[matrix_col][matrix_t_row];//temp�� a����������,���� �ݺ��� ���̶� t����ݺ� ������ ���� ���ؼ� temp�� �ְ�
                //�״����� t�� ���� �ݺ��ϸ鼭 ���ؼ� temp�� ���ؼ� �ְ� ���������� a�� �൵ �ݺ��ϸ鼭 ���ؼ� temp�� ���ؼ� �ִ´�
			matrix_axt[matrix_a_row][matrix_t_row] = temp;//axt��� ��Ŀ� temp�� �Է�
		}
	}
	/* Check post conditions */
    if (matrix_t == NULL || matrix_axt ==NULL) {//matrix_t �� matrix_axt null �ϴ�
		printf("Memory Allocation Failed.\n");
		return -1;
	}
	print_matrix(matrix_axt, row, row);//axt��� ���
	free_matrix(matrix_axt, row, col);//axt�� ��� �޸� �Ҵ� ����
	return 1;
}

