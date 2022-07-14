#include <iostream>

const int Files = 4;
const int Columns = 4;

bool evaluateMatrix(int matrix[Files][Columns], int posI, int posJ)
{
    bool found = true;
    for (int i = 0; i < Files && found; i++)
    {
        for (int j = 0; j < Columns && found; j++)
        {
            bool conditionA = (matrix[posI][posJ] > matrix[posI][j]);
            bool conditionB = (matrix[posI][posJ] < matrix[i][posJ]);
            if ( conditionA || conditionB )
                found = false;
        }
    }
    return found;
}
void showMatrix(int matrix[Files][Columns])
{
    for (int i = 0; i < Files; i++)
    {
        for (int j = 0; j < Columns; j++)
        {
            std::cout << "[ " << matrix[i][j] << " ]";
        }
        std::cout << std::endl;        
    }
}
void resultOfEvaluation(int matrix[Files][Columns])
{
    int posFil = 0;
    int posCol = 0;
    for ( posFil = 0; posFil < Files; posFil++)
    {
        for (posCol = 0; posCol < Columns; posCol++)
        {
            if (evaluateMatrix(matrix, posFil, posCol))
                std::cout << "[[[punto silla: (" << posFil << ", " << posCol << ").]]]" << std::endl;            
        }
    } 
}
int main()
{
    int A[Files][Columns] = {
        {50, 40, 2, 30},
        {10, 11, 5, 12},
        {5, 2, 4, 8},
        {4, 2, 3, 6}
    };

    showMatrix(A);
    resultOfEvaluation(A);

    return 0;
}