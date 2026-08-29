#include <iostream>
using namespace std;

// Function to input a matrix
void inputMatrix(int **matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function for matrix addition
void addition(int **A, int **B, int **result,
              int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix subtraction
void subtraction(int **A, int **B, int **result,
                 int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplication(int **A, int **B, int **result,
                    int r1, int c1, int c2) {

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {

            result[i][j] = 0;

            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for transpose
void transpose(int **A, int **result,
               int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}

// Function to create a dynamic matrix
int** createMatrix(int rows, int cols) {

    int **matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    return matrix;
}

// Function to delete a dynamic matrix
void deleteMatrix(int **matrix, int rows) {

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {

    int choice;
    int r1, c1, r2, c2;

    // Step 1: Ask the user to choose the operation first
    cout << "===== MATRIX OPERATIONS =====\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose\n";
    cout << "5. Exit\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {

        // =========================
        // MATRIX ADDITION
        // =========================
        case 1:

            cout << "\n--- Matrix Addition ---\n";

            cout << "Enter rows and columns of Matrix A: ";
            cin >> r1 >> c1;

            cout << "Enter rows and columns of Matrix B: ";
            cin >> r2 >> c2;

            if (r1 != r2 || c1 != c2) {

                cout << "Addition is not possible.\n";
                cout << "Both matrices must have the same dimensions.\n";

                break;
            }

            {
                int **A = createMatrix(r1, c1);
                int **B = createMatrix(r2, c2);
                int **result = createMatrix(r1, c1);

                cout << "\nEnter Matrix A:\n";
                inputMatrix(A, r1, c1);

                cout << "\nEnter Matrix B:\n";
                inputMatrix(B, r2, c2);

                addition(A, B, result, r1, c1);

                cout << "\nResult of Addition:\n";
                displayMatrix(result, r1, c1);

                deleteMatrix(A, r1);
                deleteMatrix(B, r2);
                deleteMatrix(result, r1);
            }

            break;


        // =========================
        // MATRIX SUBTRACTION
        // =========================
        case 2:

            cout << "\n--- Matrix Subtraction ---\n";

            cout << "Enter rows and columns of Matrix A: ";
            cin >> r1 >> c1;

            cout << "Enter rows and columns of Matrix B: ";
            cin >> r2 >> c2;

            if (r1 != r2 || c1 != c2) {

                cout << "Subtraction is not possible.\n";
                cout << "Both matrices must have the same dimensions.\n";

                break;
            }

            {
                int **A = createMatrix(r1, c1);
                int **B = createMatrix(r2, c2);
                int **result = createMatrix(r1, c1);

                cout << "\nEnter Matrix A:\n";
                inputMatrix(A, r1, c1);

                cout << "\nEnter Matrix B:\n";
                inputMatrix(B, r2, c2);

                subtraction(A, B, result, r1, c1);

                cout << "\nResult of Subtraction:\n";
                displayMatrix(result, r1, c1);

                deleteMatrix(A, r1);
                deleteMatrix(B, r2);
                deleteMatrix(result, r1);
            }

            break;


        // =========================
        // MATRIX MULTIPLICATION
        // =========================
        case 3:

            cout << "\n--- Matrix Multiplication ---\n";

            cout << "Enter rows and columns of Matrix A: ";
            cin >> r1 >> c1;

            cout << "Enter rows and columns of Matrix B: ";
            cin >> r2 >> c2;

            if (c1 != r2) {

                cout << "Multiplication is not possible.\n";
                cout << "Columns of Matrix A must equal rows of Matrix B.\n";

                break;
            }

            {
                int **A = createMatrix(r1, c1);
                int **B = createMatrix(r2, c2);
                int **result = createMatrix(r1, c2);

                cout << "\nEnter Matrix A:\n";
                inputMatrix(A, r1, c1);

                cout << "\nEnter Matrix B:\n";
                inputMatrix(B, r2, c2);

                multiplication(A, B, result, r1, c1, c2);

                cout << "\nResult of Multiplication:\n";
                displayMatrix(result, r1, c2);

                deleteMatrix(A, r1);
                deleteMatrix(B, r2);
                deleteMatrix(result, r1);
            }

            break;


        // =========================
        // MATRIX TRANSPOSE
        // =========================
        case 4:

            cout << "\n--- Matrix Transpose ---\n";

            // Step 1: Ask which matrix to transpose 
            cout << "\nChoose the matrix for transpose:\n";
            cout << "1. Transpose Matrix A\n"; 
            cout << "2. Transpose Matrix B\n"; 
            cout << "3. Transpose Both Matrices\n"; 
            cout << "\nEnter your choice: "; 
            cin >> choice; 
            

            // =====================================================
            // TRANSPOSE MATRIX A 
            // ===================================================== 
            
            if (choice == 1) { 
                cout << "\n--- Transpose Matrix A ---\n";
                cout << "Enter rows and columns of Matrix A: "; 
                cin >> r1 >> c1; 

                int **A = createMatrix(r1, c1); 
                int **resultA = createMatrix(c1, r1); 
                
                cout << "\nEnter Matrix A:\n"; 
                inputMatrix(A, r1, c1); 
                
                // Perform transpose 
                transpose(A, resultA, r1, c1); 

                // Display original matrix 
                cout << "\nMatrix A:\n"; 
                displayMatrix(A, r1, c1); 
                
                // Display transposed matrix 
                cout << "\nTranspose of Matrix A:\n"; 
                displayMatrix(resultA, c1, r1); 
                
                // Free dynamically allocated memory 
                deleteMatrix(A, r1); deleteMatrix(resultA, c1); 
                } 
                
                
                // ===================================================== 
                // TRANSPOSE MATRIX B 
                // ===================================================== 
                
                else if (choice == 2) { 
                    cout << "\n--- Transpose Matrix B ---\n"; 
                    cout << "Enter rows and columns of Matrix B: "; 
                    cin >> r2 >> c2; 
                    
                    int **B = createMatrix(r2, c2); 
                    int **resultB = createMatrix(c2, r2); 
                    
                    cout << "\nEnter Matrix B:\n"; 
                    inputMatrix(B, r2, c2); 
                    
                    // Perform transpose 
                    transpose(B, resultB, r2, c2); 
                    
                    // Display original matrix 
                    cout << "\nMatrix B:\n"; 
                    displayMatrix(B, r2, c2); 
                    // Display transposed matrix 
                    cout << "\nTranspose of Matrix B:\n"; 
                    displayMatrix(resultB, c2, r2); 
                    
                    // Free dynamically allocated memory 
                    deleteMatrix(B, r2); 
                    deleteMatrix(resultB, c2);
                     } 
                     

                    //===================================================== 
                    // TRANSPOSE BOTH MATRICES 
                    // ===================================================== 
                    else if (choice == 3) { 
                        cout << "\n--- Transpose Both Matrices ---\n"; 
                        
                        // Input dimensions 
                        cout << "Enter rows and columns of Matrix A: "; 
                        cin >> r1 >> c1; 
                        cout << "Enter rows and columns of Matrix B: "; 
                        cin >> r2 >> c2; 
                        
                        // Create matrices 
                        int **A = createMatrix(r1, c1); 
                        int **B = createMatrix(r2, c2); 
                        
                        // Create result matrices with reversed dimensions 
                        int **resultA = createMatrix(c1, r1); 
                        int **resultB = createMatrix(c2, r2); 
                        
                        // Input Matrix A 
                        cout << "\nEnter Matrix A:\n"; 
                        inputMatrix(A, r1, c1); 
                        
                        // Input Matrix B 
                        cout << "\nEnter Matrix B:\n"; 
                        inputMatrix(B, r2, c2); 
                        
                        // Perform transpose 
                        transpose(A, resultA, r1, c1); 
                        transpose(B, resultB, r2, c2); 
                        
                        // Display Matrix A 
                        cout << "\nMatrix A:\n"; 
                        displayMatrix(A, r1, c1); 
                        cout << "\nTranspose of Matrix A:\n"; 
                        displayMatrix(resultA, c1, r1);

                        // Display Matrix B 
                        cout << "\nMatrix B:\n"; 
                        displayMatrix(B, r2, c2); 
                        cout << "\nTranspose of Matrix B:\n"; 
                        displayMatrix(resultB, c2, r2); 
                        
                        // Free dynamically allocated memory 
                        deleteMatrix(A, r1); 
                        deleteMatrix(B, r2); 
                        deleteMatrix(resultA, c1); 
                        deleteMatrix(resultB, c2);
                     }
            break;

            // ========================= 
            // EXIT 
            // =========================
            case 5: 
             cout << "\nExiting the program...\n";
             cout << "Thank you!\n"; 


            break; 
            // ========================= 
            // INVALID CHOICE /
            // =========================


        default:

            cout << "\nInvalid choice!\n";
    }

    return 0;
}