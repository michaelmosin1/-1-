#include "my_class.hpp"


int main(){
    //Defining massive and variables
    int rows, columns;
    int matrix[N_Max][M_Max];
    //Reading matrix
    mm::read_matrix(matrix, rows, columns);
    //If matrix has two same lines, edit it
    if (mm::has_same_rows(matrix, rows, columns)){
        mm::replace_minimal(matrix, rows, columns, mm::biggest_simple(matrix, rows, columns));
    }
    //Printing out matrix
    mm::print_matrix(matrix, rows, columns);
}