#include <stdio.h>
void print_array(int row, int coloumn, const int array[row][coloumn])
{
    for (int i = 0; i < row; i++)
    {
        for(int j = 0 ; j < coloumn; j++){
            printf("%d ", array[i][j]);
        }
    printf("\n");
    }    
}
void get_array(int row, int coloumn, const int array[row][coloumn]){
    // her öğrencinin satırları
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coloumn; j++)
        {
            printf("\n array[%d][%d] =  ", i, j);
            scanf("%d", &array[i][j]);
        }
    }   
}
int findMaxMark(int row, int coloumn, const int array[row][coloumn], int exam){
    int max_mark = array[0][exam-1];
    for (int i = 0; i < row; i++){
       if (max_mark < array[i][exam-1]){
            max_mark = array[i][exam-1];
       }       
    }
    return max_mark;
}
int main(){
    int row_students, col_marks, exam,max_mark;
    printf("Please enter the students number: ");
    scanf("%d", &row_students);
    printf("Please enter the students marks number: ");
    scanf("%d", &col_marks);
    int  array[col_marks][row_students];
    get_array(row_students,col_marks,array);
    puts("Array is: ");
    print_array(row_students, col_marks, array);
    printf("Please enter the exam number to access the max mark: ");
    scanf("%d", &exam);
    max_mark = findMaxMark(row_students,col_marks,array,exam);
    printf("%dth exams max mark is: %d\n",exam,max_mark);
    return 0;

}

