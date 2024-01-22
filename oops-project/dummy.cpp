#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
vector<string> matr = {"Addition", "Subtraction", "Multiplication", "Transpose", "Rank", "Determenant", "Inverse"};
vector<string> sat = {"Mean","Mode","Median","Variance","Standard Deviation"};
void printmat(int line_ct, vector<string> &v,string op)
{
    cout << "\t\t\t\t\t" <<"Avaliable " <<op<< " Operations:" << "\n"<<endl<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == line_ct)
        {
            cout << "\t\t\t\t      >  ";
            cout << "\x1b[1;36m" << v[i] << "\x1b[22;0m\n";
        }
        else
        {
            cout << "\t\t\t\t\t" << v[i] << "\n";
            printf(" ");
        }
    }
}
int sel_mat_op(vector<string> a,string op)
{
    int ch;
    system("cls");

    printmat(0, a,op);
    int ct = 0;
    int n = a.size();
    n--;
    while (true)
    {
        ch = getch();
        if (ch == 72)
        {
            if (ct <= 0)
                ct = n;
            else
                ct--;
        }
        else if (ch == 80)
        {
            if (ct == n)
                ct = 0;
            else
                ct++;
        }
        else if (ch == 13)
        {
            system("cls");
            return ct;
            break;
        }
        system("cls");
        printmat(ct, a,op);
    }
}
const double EPSILON = 1e-10;
class matrix
{
public:
    int row_size, col_size;
    vector<vector<double>> arr;

    // private:
    void input_mat()
    {
        cout<<"Enter elements of "<<row_size<<" x "<<col_size<<" matrix: "<<endl;
        for (int i = 0; i < row_size; i++)
        {
            vector<double> temp;
            for (int j = 0; j < col_size; j++)
            {
                double x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }
    }
    void print_mat()
    {
        for (auto vec : arr)
        {
            for (auto ele : vec)
                cout << ele << " ";
            cout << endl;
        }
        cout << endl;
    }
};
class mat_operations : public matrix
{
public:
    mat_operations operator+(matrix mat2)
    {
        mat_operations mat3;
        for (int i = 0; i < row_size; i++)
        {
            vector<double> temp;
            for (int j = 0; j < col_size; j++)
            {
                double x = arr[i][j] + mat2.arr[i][j];
                temp.push_back(x);
            }
            mat3.arr.push_back(temp);
        }
        return mat3;
    }
    mat_operations operator-(matrix mat2)
    {
        mat_operations mat3;
        for (int i = 0; i < row_size; i++)
        {
            vector<double> temp;
            for (int j = 0; j < col_size; j++)
            {
                double x = arr[i][j] - mat2.arr[i][j];
                temp.push_back(x);
            }
            mat3.arr.push_back(temp);
        }
        return mat3;
    }
    mat_operations operator*(matrix mat2)
    {
        mat_operations mat3;
        for (int i = 0; i < row_size; i++)
        {
            vector<double> temp;
            for (int j = 0; j < col_size; j++)
            {
                double x = 0;
                for (int k = 0; k < col_size; k++)
                {
                    x += arr[i][k] * mat2.arr[k][j];
                }
                temp.push_back(x);
            }
            mat3.arr.push_back(temp);
        }
        return mat3;
    }
    mat_operations mat_transpose()
    {
        mat_operations mat3;
        for (int i = 0; i < col_size; i++)
        {
            vector<double> temp;
            for (int j = 0; j < row_size; j++)
            {
                temp.push_back(arr[j][i]);
            }
            mat3.arr.push_back(temp);
        }
        return mat3;
    }
    int mat_determinant(vector<vector<double>> m)
    {
        int n = m.size();
        if (n == 0)
        {
            return 0; // Matrix is empty
        }
        if (n == 1)
        {
            return m[0][0]; // Base case for a 1x1 matrix
        }

        if (n != m[0].size())
        {
            cerr << "Input matrix is not square. Determinant calculation is not possible." << endl;
            return 0;
        }

        int determinant = 0;
        int sign = 1; // Sign of the cofactor

        for (int i = 0; i < n; i++)
        {
            // Calculate the cofactor matrix
            vector<vector<double>> cofactorMatrix(n - 1, vector<double>(n - 1));
            for (int j = 1; j < n; j++)
            {
                int col = 0;
                for (int k = 0; k < n; k++)
                {
                    if (k == i)
                        continue;
                    cofactorMatrix[j - 1][col++] = m[j][k];
                }
            }

            determinant += sign * m[0][i] * mat_determinant(cofactorMatrix);
            sign = -sign;
        }

        return determinant;
    }
    vector<vector<double>> calculateInverse(vector<vector<double>> &matrix)
    {
        int n = matrix.size();
        if (n != matrix[0].size())
        {
            cerr << "Input matrix is not square. Inverse calculation is not possible." << endl;
            return vector<vector<double>>();
        }
        vector<vector<double>> augmentedMatrix(n, vector<double>(2 * n, 0.0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                augmentedMatrix[i][j] = matrix[i][j];
                augmentedMatrix[i][j + n] = (i == j) ? 1.0 : 0.0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            double pivot = augmentedMatrix[i][i];
            if (pivot == 0.0)
            {
                cerr << "Matrix is singular. Inverse does not exist." << endl;
                return vector<vector<double>>();
            }

            for (int j = 0; j < 2 * n; j++)
            {
                augmentedMatrix[i][j] /= pivot;
            }

            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    double factor = augmentedMatrix[k][i];
                    for (int j = 0; j < 2 * n; j++)
                    {
                        augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                    }
                }
            }
        }

        vector<vector<double>> inverse(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                inverse[i][j] = augmentedMatrix[i][j + n];
            }
        }

        return inverse;
    }
    int rankOfMatrix(vector<vector<double>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rank = 0;

        for (int col = 0; col < cols; col++)
        {
            int pivotRow = rank;

            // Find the first non-zero entry in the current column
            while (pivotRow < rows && abs(matrix[pivotRow][col]) < EPSILON)
            {
                pivotRow++;
            }

            if (pivotRow < rows)
            {
                // Swap the pivot row with the current row
                if (pivotRow != rank)
                {
                    for (int j = col; j < cols; j++)
                    {
                        swap(matrix[rank][j], matrix[pivotRow][j]);
                    }
                }

                // Normalize the pivot row
                double pivot = matrix[rank][col];
                for (int j = col; j < cols; j++)
                {
                    matrix[rank][j] /= pivot;
                }

                // Eliminate non-zero entries below the pivot
                for (int i = rank + 1; i < rows; i++)
                {
                    double factor = matrix[i][col];
                    for (int j = col; j < cols; j++)
                    {
                        matrix[i][j] -= factor * matrix[rank][j];
                    }
                }

                rank++;
            }
        }

        return rank;
    }
};
void input_formact(mat_operations &ob1,mat_operations &ob2){
   
        cout<<"Enter no of Rows and Columns of first matrix: ";
        cin >> ob1.row_size >> ob1.col_size;
        cout<<endl;
        ob1.input_mat();
        cout<<endl;
        cout<<"Enter no of Rows and Columns of second matrix: ";
        cin >> ob2.row_size >> ob2.col_size;
        cout<<endl;
        ob2.input_mat();
}
void input_formact(mat_operations& ob1){
    cout<<"Enter no of Rows and Columns of first matrix: ";
        cin >> ob1.row_size >> ob1.col_size;
        cout<<endl;
        ob1.input_mat();
        cout<<endl;
}
void select_matrix_operations(){
 int op = sel_mat_op(matr,"Matrix");
    cout << op << endl;
    mat_operations ob1, ob2, ob3;
    if (op == 0)
    { cout<<"For Addition:"<<endl<<endl;
        input_formact(ob1,ob2);
        ob3 = ob1 + ob2;
       cout<<"Result: "<<endl;
        ob3.print_mat();
    }
    if (op == 1)
    {
        cout<<"For Subtraction:"<<endl<<endl;
       input_formact(ob1,ob2);
        ob3 = ob1 - ob2;
       cout<<"Result: "<<endl;
        ob3.print_mat();
    }
    if (op == 2)
    {
        cout<<"For Multiplication:"<<endl<<endl;
        input_formact(ob1,ob2);
        ob3 = ob1 * ob2;
       cout<<"Result: "<<endl;
        ob3.print_mat();
    }
    if (op == 3)
    {
        cout<<"For Transpose:"<<endl<<endl;
       input_formact(ob1);
        ob3 = ob1.mat_transpose();
       cout<<"Result: "<<endl;
        ob3.print_mat();
    }
    if (op == 4)
    {
        cout<<"For Rank:"<<endl<<endl;
        input_formact(ob1);
        int rk = ob1.rankOfMatrix(ob1.arr);
        cout<<"Rank: "<<rk<<endl;
    }
    if (op == 5)
    {
         cout<<"For Determinant:"<<endl<<endl;
        input_formact(ob1);
        int det = ob1.mat_determinant(ob1.arr);
        cout<<"Determenant: "<<det<<endl;
    }
     if (op == 6)
    {
         cout<<"For Inverse:"<<endl<<endl;
        input_formact(ob1);
        ob3.arr = ob1.calculateInverse(ob1.arr);
       cout<<"Result: "<<endl;
        ob3.print_mat();
    }
   
    
}
class StatisticsCalculator
{
private:
    vector<double> data;

public:
    // Constructor to initialize the data vector
    StatisticsCalculator(const vector<double> &input_data) : data(input_data) {}

    // Method to calculate the mean
    double calculateMean() const
    {
        double sum = 0.0;
        for (double value : data)
        {
            sum += value;
        }
        return sum / data.size();
    }

    // Method to calculate the median
    double calculateMedian() const
    {
        vector<double> sortedData = data;
        sort(sortedData.begin(), sortedData.end());

        if (sortedData.size() % 2 == 0)
        {
            size_t mid1 = sortedData.size() / 2 - 1;
            size_t mid2 = sortedData.size() / 2;
            return (sortedData[mid1] + sortedData[mid2]) / 2.0;
        }
        else
        {
            size_t mid = sortedData.size() / 2;
            return sortedData[mid];
        }
    }

    // Method to calculate the mode
    double calculateMode() const
    {
        map<double, int> count;
        for (double value : data)
        {
            count[value]++;
        }

        double mode = 0.0;
        int maxCount = 0;

        for (const auto &pair : count)
        {
            if (pair.second > maxCount)
            {
                mode = pair.first;
                maxCount = pair.second;
            }
        }

        return mode;
    }

    // Method to calculate the variance
    double calculateVariance() const
    {
        double mean = calculateMean();
        double sumOfSquaredDifferences = 0.0;
        for (double value : data)
        {
            double difference = value - mean;
            sumOfSquaredDifferences += difference * difference;
        }
        return sumOfSquaredDifferences / data.size();
    }

    // Method to calculate the standard deviation
    double calculateStandardDeviation() const
    {
        double variance = calculateVariance();
        return sqrt(variance);
    }
};

// void printmat(int line_ct,vector<string> &v)
// {
//     cout << "\t\t\t" << "Avaliable Statistics Operations" << "\n"<<endl<<endl;
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (i == line_ct)
//         {
//             cout << "\t\t\t\t\t>";
//             cout << "\x1b[1;36m" << v[i] << "\x1b[22;0m\n";
//         }
//         else
//         {
//             cout << "\t\t\t\t\t" << v[i] << "\n";
//             printf(" ");
//         }
//     }
// }
// int sel_sat_op(vector<string> a){
//      int ch;
//     system("cls");
//     printmat(0,a);
//     int ct = 0;
//     int n = a.size();
//     n--;
//     while (true)
//     {
//         ch = getch();
//         if (ch == 72)
//         {
//             if (ct <= 0)
//                 ct = n;
//             else
//                 ct--;
//         }
//         else if (ch == 80)
//         {
//             if (ct == n)
//                 ct = 0;
//             else
//                 ct++;
//         }
//         else if (ch == 13)
//         {
//             system("cls");
//             // cout << ct;
//             return ct;
//             break;
//         }
//         system("cls");
//         printmat(ct,a);
//     }

// }
void select_satistics_operations(){
    cout << "\t\t\t" << "Avaliable Statistics Operations" << "\n";
    int choice = sel_mat_op(sat,"Statistics");
    cout<<"Size of data: ";
    int n;
    cin >> n;
    cout<<"Enter data: ";
    vector<double> data;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        data.push_back(x);
    }

    StatisticsCalculator calculator(data);
// vector<string> sat = {"Mean","Mode","Median","Variance","Standard Deviation"};
if(choice ==0)
    cout << "Mean: " << calculator.calculateMean() << endl;
else if(choice ==1)
    cout << "Mode: " << calculator.calculateMode() << endl;
else if(choice ==2)
    cout << "Median: " << calculator.calculateMedian() << endl;
else if(choice ==3)
    cout << "Variance: " << calculator.calculateVariance() << endl;
else if(choice ==4)
    cout << "Standard Deviation: " << calculator.calculateStandardDeviation() << endl;

}
int main()
{
    select_matrix_operations();
    select_satistics_operations();


   
    return 0;
}