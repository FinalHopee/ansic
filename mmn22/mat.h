#define MATRIX_SIZE 4
#define MAT_MEMBER_CNT (MATRIX_SIZE*MATRIX_SIZE)
#define CCOL iterator%MATRIX_SIZE
#define CROW iterator/MATRIX_SIZE
#define TCOL tempIndex%MATRIX_SIZE
#define TROW tempIndex/MATRIX_SIZE
#define MAX_INPUT_LEN 100
#define MAT_COUNT 6

typedef float mat[MATRIX_SIZE][MATRIX_SIZE];
void add_mat(mat* A, mat* B, mat* C);
void sub_mat(mat* A, mat* B, mat* C);
void mul_mat(mat* A, mat* B, mat* C);
void mul_scalar(mat* A, float scalar, mat* B);
void trans_mat(mat* A, mat* B);

/* mymat.c */
void read_mat();
void print_mat();
mat* GetMatrixFromInput();
void ProcessCommand(char command[]);
void clearBuffer();