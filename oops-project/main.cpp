#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "ascii_bomma.hpp"
using namespace std;

class mat_operations;
class Line;
void print_sbar(string s);
void logo();
void print_multi_sbar(int page, string op2);
void printmatches(int line_ct, vector<string> &v, string op, int page, string op2);
int sel_mat_op(vector<string> a, string op, int page);
void input_formact(mat_operations &ob1, mat_operations &ob2);
void input_formact(mat_operations &ob1);
void select_matrix_operations();
void select_satistics_operations();
void select_Mensuration_operation();
void select_polynomial_operations();
void select_complex_operations();
void select_vector_operations();
void onevariablelinearequation();
void twovariablelinearequation();
void threevariablelinearequation();
void select_linearequation_operation();
void QuadraticPolynomialSolver(vector<double> &arr);
void select_Equations_operation();
void simple_cal();
void select_main_operation();

string operation1;
const double EPSILON = 1e-10;

vector<string> oper = {"Simple Calculator", "Matrices", "Statistics", "Vectors", "Mensuration", "Polynomials", "Finding solutions", "Complex", "Roots", "Exit"};
vector<string> matr = {"Addition", "Subtraction", "Multiplication", "Transpose", "Rank", "Determinant", "Inverse"};
vector<string> sat = {"Mean", "Mode", "Median", "Variance", "Standard Deviation"};
vector<string> arr1 = {"Rectangle", "Parallelogram", "Sphere", "Triangle", "Rhombus", "Cone", "Cuboid", "Circle", "Square", "Cylinder", "Trapezium", "Hemisphere"};
vector<string> arr3 = {"MENSURATION", "EQUATIONS"};
vector<string> vectoralgebra = {"Addition", "Subtraction", "Scalar-Multiplication", "Magnitude", "Unit-Vector", "Dot-Product", "Cross-Product", "Line-Equation"};
vector<string> complexnumber = {"Addition", "Subtraction", "Multiplication", "Division", "Conjugate", "Magnitude", "Angle", "Polor-form", "Euler-form"};
vector<string> polynomials = {"Addition", "Subtraction", "Multiplication"};
vector<string> arr2 = {"LinearPolynomialSolver", "QuadraticPolynomialSolver"};
vector<string> arr4 = {"onevariable", "twovariable", "threevariable"};

// Matrix
class matrix
{
public:
    int row_size, col_size;
    vector<vector<double>> arr;

    // private:
    void input_mat()
    {
        cout << "Enter elements of " << row_size << " x " << col_size << " matrix: " << endl;
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
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            // if(i==0)cout<<""<<endl;
            cout << "|[ ";
            // if(i==n-1) cout<<"-";
            int k = arr[i].size();
            for (int j = 0; j < k; j++)
                cout << arr[i][j] << " ";
            // if(i==0)cout<<"_";
            // if(i==n-1) cout<<"-";
            cout << "]|";
            cout << endl;
        }
        // cout<<"-";
        // for (auto vec : arr)
        // {
        //     for (auto ele : vec)
        //         cout << ele << " ";
        //   cout<<"|";
        //     cout << endl;
        // }
        // cout << endl;
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
        if (mat2.row_size != col_size)
        {
            cout << "Invalid Order" << endl;
            cout << "\n\n Press any key to continue....";
            char con = getch();
            fflush(stdin);
            select_matrix_operations();
        }
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
void input_formact(mat_operations &ob1, mat_operations &ob2)
{
    //    path();
    cout << endl;
    cout << "Enter no of Rows and Columns of first matrix: ";
    cin >> ob1.row_size >> ob1.col_size;
    cout << endl;
    ob1.input_mat();
    cout << endl;
    cout << "Enter no of Rows and Columns of second matrix: ";
    cin >> ob2.row_size >> ob2.col_size;
    cout << endl;
    ob2.input_mat();
}
void input_formact(mat_operations &ob1)
{
    cout << "Enter no of Rows and Columns of first matrix: ";
    cin >> ob1.row_size >> ob1.col_size;
    cout << endl;
    ob1.input_mat();
    cout << endl;
}
void select_matrix_operations()
{
//  print_sbar("SELECT ONE");
start:
    int op = sel_mat_op(matr, "Matrix", 2);
    // cout << op << endl;
    mat_operations ob1, ob2, ob3;

    print_multi_sbar(2, matr[op]);
    if (op == 0)
    {
        cout << "For Addition:" << endl
             << endl;
        input_formact(ob1, ob2);
        ob3 = ob1 + ob2;
        cout << "Result: " << endl;
        ob3.print_mat();
    }
    if (op == 1)
    {
        cout << "For Subtraction:" << endl
             << endl;
        input_formact(ob1, ob2);
        ob3 = ob1 - ob2;
        cout << "Result: " << endl;
        ob3.print_mat();
    }
    if (op == 2)
    {
        cout << "For Multiplication:" << endl
             << endl;
        input_formact(ob1, ob2);
        ob3 = ob1 * ob2;
        cout << "Result: " << endl;
        ob3.print_mat();
    }
    if (op == 3)
    {
        cout << "For Transpose:" << endl
             << endl;
        input_formact(ob1);
        ob3 = ob1.mat_transpose();
        cout << "Result: " << endl;
        ob3.print_mat();
    }
    if (op == 4)
    {
        cout << "For Rank:" << endl
             << endl;
        input_formact(ob1);
        int rk = ob1.rankOfMatrix(ob1.arr);
        cout << "Rank: " << rk << endl;
    }
    if (op == 5)
    {
        cout << "For Determinant:" << endl
             << endl;
        input_formact(ob1);
        int det = ob1.mat_determinant(ob1.arr);
        cout << "Determenant: " << det << endl;
    }
    if (op == 6)
    {
        cout << "For Inverse:" << endl
             << endl;
        input_formact(ob1);
        ob3.arr = ob1.calculateInverse(ob1.arr);
        cout << "Result: " << endl;
        ob3.print_mat();
    }
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    goto start;
}

// Statistics
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
void select_satistics_operations()
{
start:
    // cout << "\t\t\t" << "Avaliable Statistics Operations" << "\n";
    int choice = sel_mat_op(sat, "Statistics", 2);
    print_multi_sbar(2, sat[choice]);
    cout << "Size of data: ";
    int n;
    cin >> n;
    cout << "Enter data: ";
    vector<double> data;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        data.push_back(x);
    }

    StatisticsCalculator calculator(data);
    // vector<string> sat = {"Mean","Mode","Median","Variance","Standard Deviation"};
    if (choice == 0)
        cout << "Mean: " << calculator.calculateMean() << endl;
    else if (choice == 1)
        cout << "Mode: " << calculator.calculateMode() << endl;
    else if (choice == 2)
        cout << "Median: " << calculator.calculateMedian() << endl;
    else if (choice == 3)
        cout << "Variance: " << calculator.calculateVariance() << endl;
    else if (choice == 4)
        cout << "Standard Deviation: " << calculator.calculateStandardDeviation() << endl;
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    goto start;

    return;
}

// Mensuration
class Shape
{
public:
    virtual double getArea() = 0;              // Pure virtual function
    virtual double getvolume() = 0;            // pure virtual function
    virtual double getperimeter() = 0;         // pure virtual function
    virtual double getcurvedsurfacearea() = 0; // pure virtual function
};
class Rectanglee : public Shape
{
public:
    double length;
    double width;

public:
    Rectanglee(double l, double w) : length(l), width(w) {}
    double getArea()
    {
        return length * width;
    }
    double getvolume()
    {
        return 0;
    }
    double getperimeter()
    {
        return 2 * (length + width);
    }
    double getcurvedsurfacearea()
    {
        return 0;
    }
};
class parallelogram : public Shape
{
public:
    double length;
    double width;

public:
    parallelogram(double l, double w) : length(l), width(w) {}
    double getArea()
    {
        return length * width;
    }

    double getvolume()
    {
        return 0;
    }
    double getperimeter()
    {
        return 2 * (length + width);
    }
    double getcurvedsurfacearea()
    {
        return 0;
    }
};
class Sphere : public Shape
{
private:
    double radius;

public:
    Sphere(double radius) : radius(radius) {}
    double getArea()
    {
        return 4 * M_PI * pow(radius, 2);
    }
    double getvolume()
    {
        return (4 / 3) * M_PI * pow(radius, 3);
    }
    double getperimeter()
    {
        return 0;
    }
    double getcurvedsurfacearea()
    {
        return 4 * M_PI * pow(radius, 2);
    }
};
class Triangle : public Shape
{
private:
    double side1, side2, side3, s;

public:
    Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3)
    {
        this->s = (side1 + side2 + side3) / 2;
    }
    double getArea()
    {
        return sqrt((s - side1) * (s - side2) * (s - side3));
    }
    double getvolume()
    {
        return 0;
    }
    double getperimeter()
    {
        return side1 + side2 + side3;
    }
    double getcurvedsurfacearea()
    {
        return 0;
    }
};
class Rhombus : public Shape
{

private:
    double side1, d1, d2;

public:
    Rhombus(double side1, double d1, double d2)
    {
        this->side1 = side1;
        this->d1 = d1;
        this->d2 = d2;
    }
    double getArea()
    {
        return 0.5 * d1 * d2;
    }
    double getcurvedsurfacearea()
    {
        return 0;
    }

    double getvolume()
    {
        return 0;
    }
    double getperimeter()
    {
        return 4 * side1;
    }
};
class Cone : public Shape
{
private:
    double height, radius;

public:
    Cone(double height = 0, double radius = 0)
    {
        this->height = height;
        this->radius = radius;
    }
    double getvolume()
    {
        return (1 / 3) * pow(radius, 2) * height;
    }
    double getArea()
    {
        double slant_height = sqrt(pow(height, 2) + pow(radius, 2));
        return M_PI * radius * (slant_height + radius);
    }
    double getcurvedsurfacearea()
    {
        double slant_height = sqrt(pow(height, 2) + pow(radius, 2));
        return M_PI * radius * slant_height;
    }
    double getperimeter()
    {
        return 0;
    }
};
class Cuboid : public Shape
{
    double length, bredth, height;

public:
    Cuboid(double length = 0, double bredth = 0, double height = 0)
    {
        this->length = length;
        this->bredth = bredth;
        this->height = height;
    }
    double getvolume()
    {
        return length * bredth * height;
    }
    double getcurvedsurfacearea()
    {
        return 2 * height * (length + bredth);
    }
    double getArea()
    {
        return 2 * (length * bredth + bredth * height + height * length);
    }
    double getperimeter()
    {
        return 0;
    }
};
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea()
    {
        return M_PI * pow(radius, 2);
    }
    double getvolume()
    {
        return 0;
    }
    double getperimeter()
    {
        return 2 * M_PI * radius;
    }
    double getcurvedsurfacearea()
    {
        return 0;
    }
};
class Square : public Shape
{
private:
    double side;

public:
    Square(double side) : side(side) {}
    double getArea()
    {
        return pow(side, 2);
    }
    double getvolume()
    {
        return 0;
    }
    double getperimeter()
    {
        return 4 * side;
    }
    double getcurvedsurfacearea()
    {
        return 0;
    }
};
class Cylinder : public Shape
{
private:
    double height, radius;

public:
    Cylinder(double height, double radius) : height(height), radius(radius)
    {
    }
    double getcurvedsurfacearea()
    {
        return 2 * M_PI * radius * height;
    }
    double getArea()
    {
        return 2 * M_PI * radius * (height + radius);
    }
    double getvolume()
    {
        return M_PI * (pow(radius, 2)) * height;
    }
    double getperimeter()
    {
        return 0;
    }
};
class Trapezium : public Shape
{
    double height, a, b, c, d;

public:
    Trapezium(double height, double a, double b, double c, double d) : height(height), a(a), b(b), c(c), d(d) {}
    double getArea()
    {
        return 1 / 2 * height * (a + b);
    }
    double getvolume()
    {
        return 0;
    }
    double getperimeter()
    {
        return a + b + c + d;
    }
    double getcurvedsurfacearea()
    {
        return 0;
    }
};
class Hemisphere : public Shape
{
private:
    double radius;

public:
    Hemisphere(double radius = 0)
    {

        this->radius = radius;
    }
    double getvolume()
    {
        double volume = (0.67) * M_PI * (pow(radius, 3));
        return volume;
    }
    double getArea()
    {

        return 3 * M_PI * (pow(radius, 2));
    }
    double getcurvedsurfacearea()
    {
        double csa = 2 * M_PI * (pow(radius, 2));
        return csa;
    }
    double getperimeter()
    {
        return 0;
    }
};
ostream &operator<<(ostream &os, Shape &s) // Operator Overloading
{
    os << "Area or Total surface area: " << s.getArea() << " m2" << endl;
    os << "Curved surface area: " << s.getcurvedsurfacearea() << " m2" << endl;
    os << "Volume: " << s.getvolume() << " m3" << endl;
    os << "Perimeter: " << s.getperimeter() << " m" << endl;
    return os;
}
void select_Mensuration_operation()
{
start:
    // cout<<"\t\t\t"<<" Available options"<<endl;
    int x = sel_mat_op(arr1, "Mensuration", 2);
    // flow.push_back(arr1[x]);
    print_multi_sbar(2, arr1[x]);

    if (x == 0)
    {
        ascii_rectangle();
        double length, bredth;
        cout << " ENTER (l,b):" << endl;
        cin >> length >> bredth;
        Rectanglee rect(length, bredth);
        cout << "Rectangle:\n"
             << rect << endl;
    }
    else if (x == 1)
    {
        ascii_parallelogram();
        double length, bredth;
        cout << " ENTER (l,b):" << endl;
        cin >> length >> bredth;
        parallelogram rect(length, bredth);
        cout << "parallelogram:\n"
             << rect << endl;
    }
    else if (x == 2)
    {
        ascii_circle();
        double radius;
        cout << "ENTER (R)" << endl;
        cin >> radius;
        Sphere sph(radius);
        cout << "Sphere:\n"
             << sph << endl;
    }
    else if (x == 3)
    {
        ascii_triangle();
        double a, b, c;
        cout << "ENTER(a,b,c)" << endl;
        cin >> a >> b >> c;
        Triangle tri(a, b, c);
        cout << "Triangle:\n"
             << tri << endl;
    }
    else if (x == 4)
    {
        ascii_rhombus();
        double a, b, c;
        cout << "Enter (a,d1,d2): " << endl;
        cin >> a >> b >> c;
        Rhombus rho(a, b, c);
        cout << "Rhombus:\n"
             << rho << endl;
    }
    else if (x == 5)
    {
        ascii_cone();
        double a, b;
        cout << "ENTER(h,r): " << endl;
        cin >> a >> b;
        Cone co(a, b);
        cout << "Cone:\n"
             << co << endl;
    }
    else if (x == 6)
    {
        ascii_cuboid();
        double a, b, c;
        cout << "ENTER (L,B,H): " << endl;
        cin >> a >> b >> c;
        Cuboid cub(a, b, c);
        cout << "Cuboid:\n"
             << cub << endl;
    }
    else if (x == 7)
    {
        ascii_circle();
        double a;
        cout << "ENTER (R): " << endl;
        cin >> a;
        Circle cir(a);
        cout << "Circle:\n:" << cir << endl;
    }
    else if (x == 8)
    {
        ascii_square();
        double a;
        cout << "ENTER(a): " << endl;
        cin >> a;
        Square sq(a);
        cout << "Square:\n"
             << sq << endl;
    }
    else if (x == 9)
    {
        ascii_cylinder();
        double a, b;
        cout << "ENTER (H,R)" << endl;
        cin >> a >> b;
        Cylinder cy(a, b);
        cout << " Cylinder:\n"
             << cy << endl;
    }
    else if (x == 10)
    {
        ascii_trapezium();
        double a, b, c, d, e;
        cout << "ENTER (a,b,c,d,e): " << endl;
        cin >> a >> b >> c >> d >> e;
        Trapezium trap(a, b, c, d, e);
        cout << "Trapezium:\n"
             << trap << endl;
    }
    else if (x == 11)
    {
        ascii_hemisphere();
        double a;
        cout << "ENTER (R)" << endl;

        cin >> a;
        Hemisphere hemi(a);
        cout << "Hemisphere:\n"
             << hemi << endl;
    }
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    goto start;

    return;
}

// Simpler Calculator
class Calculator
{
private:
    string expression;

public:
    Calculator()
    {
        cout << "Enter expression : ";
        getline(cin, expression);
    }

    double evaluatePostfix(const queue<string> &postfix) const
    {
        queue<string> postfixCopy = postfix; // Make a non-const copy
        stack<double> stack;

        while (!postfixCopy.empty())
        {
            string token = postfixCopy.front();
            postfixCopy.pop();

            if (isOperand(token))
            {
                stack.push(stod(token));
            }
            else if (isTrigonometricFunction(token))
            {
                double angle = stack.top();
                stack.pop();
                double result = applyTrigonometricFunction(token, angle);
                stack.push(result);
            }
            else
            {
                double num2 = stack.top();
                stack.pop();

                double num1 = stack.top();
                stack.pop();

                if (token == "+")
                {
                    stack.push(num1 + num2);
                }
                else if (token == "-")
                {
                    stack.push(num1 - num2);
                }
                else if (token == "*")
                {
                    stack.push(num1 * num2);
                }
                else if (token == "/")
                {
                    if (num2 != 0)
                    {
                        stack.push(num1 / num2);
                    }
                    else
                    {
                        cout << "Cannot divide by zero." << endl;
                        return 0;
                    }
                }
                else
                {
                    cout << "Invalid operator." << endl;
                    return 0;
                }
            }
        }

        return stack.top();
    }

    double applyTrigonometricFunction(const string &function, double angle) const
    {
        if (function == "sin")
        {
            return sin(toRadians(angle));
        }
        else if (function == "cos")
        {
            return cos(toRadians(angle));
        }
        else if (function == "tan")
        {
            return tan(toRadians(angle));
        }
        else
        {
            cout << "Invalid trigonometric function." << endl;
            return 0;
        }
    }

    bool isOperand(const string &token) const
    {
        return (token != "+" && token != "-" && token != "*" && token != "/" &&
                token != "sin" && token != "cos" && token != "tan");
    }

    bool isTrigonometricFunction(const string &token) const
    {
        return (token == "sin" || token == "cos" || token == "tan");
    }

    queue<string> infixToPostfix() const
    {
        istringstream iss(expression);
        string token;
        stack<string> operators;
        queue<string> postfix;

        while (iss >> token)
        {
            if (isOperand(token))
            {
                postfix.push(token);
            }
            else if (isTrigonometricFunction(token))
            {
                operators.push(token);
            }
            else if (token == "(")
            {
                operators.push(token);
            }
            else if (token == ")")
            {
                while (!operators.empty() && operators.top() != "(")
                {
                    postfix.push(operators.top());
                    operators.pop();
                }

                if (!operators.empty())
                {
                    operators.pop(); // Pop the opening parenthesis
                }
            }
            else
            {
                while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token))
                {
                    postfix.push(operators.top());
                    operators.pop();
                }

                operators.push(token);
            }
        }

        while (!operators.empty())
        {
            postfix.push(operators.top());
            operators.pop();
        }

        return postfix;
    }

    int getPrecedence(const string &op) const
    {
        if (op == "+" || op == "-")
        {
            return 1;
        }
        else if (op == "*" || op == "/")
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    double toRadians(double degrees) const
    {
        return degrees * M_PI / 180.0;
    }
};
void simple_cal()
{
    // start:
    operation1 = "Simple Calculator";
    print_multi_sbar(1, operation1);

    displayCalculatorInterface();
    cout << endl
         << endl;
    Calculator calculator;
    queue<string> postfix = calculator.infixToPostfix();
    double result = calculator.evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    system("cls");
   select_main_operation();
    // goto start;
}

// Polynomials
struct Node
{
    int coefficient;
    int exponent;
    Node *next;
};
class Polynomial // Base class representing a polynomial
{
protected:
    Node *head;

public:
    Polynomial() : head(nullptr) {}

    void insertTerm(int coefficient, int exponent)
    {
        Node *newNode = new Node{coefficient, exponent, nullptr};

        if (!head || exponent > head->exponent)
        {
            // If the list is empty or the new term has a higher exponent than the head, insert at the beginning
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;
            Node *prev = nullptr;

            // Traverse the list until the correct position is found
            while (current && exponent < current->exponent)
            {
                prev = current;
                current = current->next;
            }

            if (current && current->exponent == exponent)
            {
                // Combine coefficients for terms with the same exponent
                current->coefficient += coefficient;
                delete newNode; // Discard the new node, as its content is already merged
            }
            else
            {
                // Insert the new term
                newNode->next = current;
                if (prev)
                {
                    prev->next = newNode;
                }
                else
                {
                    head = newNode;
                }
            }
        }
    }
    void display()
    {
        Node *current = head;
        bool hasTerms = false;

        while (current)
        {
            if (current->coefficient != 0)
            {
                hasTerms = true;

                if (current != head)
                {
                    cout << (current->coefficient > 0 ? " + " : " - ");
                }
                else if (current->coefficient < 0)
                {
                    cout << "-";
                }

                int absCoefficient = abs(current->coefficient);
                if (current->exponent > 0)
                {
                    cout << absCoefficient << "x";
                    if (current->exponent > 1)
                    {
                        cout << "^" << current->exponent;
                    }
                }
                else
                {
                    cout << absCoefficient;
                }
            }

            current = current->next;
        }

        if (!hasTerms)
        {
            cout << "0";
        }

        cout << endl;
        cout << endl;
    }

    Node *getHead() const
    {
        return head;
    }

    // Destructor to free allocated memory
    ~Polynomial()
    {
        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};
class Addition : public Polynomial
{
public:
    Polynomial add(Polynomial &p1, Polynomial &p2)
    {
        Polynomial result;

        Node *term1 = p1.getHead();
        Node *term2 = p2.getHead();

        while (term1 && term2)
        {
            if (term1->exponent == term2->exponent)
            {
                int sumCoefficients = term1->coefficient + term2->coefficient;
                if (sumCoefficients != 0)
                {
                    result.insertTerm(sumCoefficients, term1->exponent);
                }
                term1 = term1->next;
                term2 = term2->next;
            }
            else if (term1->exponent > term2->exponent)
            {
                result.insertTerm(term1->coefficient, term1->exponent);
                term1 = term1->next;
            }
            else
            {
                result.insertTerm(term2->coefficient, term2->exponent);
                term2 = term2->next;
            }
        }

        while (term1)
        {
            result.insertTerm(term1->coefficient, term1->exponent);
            term1 = term1->next;
        }

        while (term2)
        {
            result.insertTerm(term2->coefficient, term2->exponent);
            term2 = term2->next;
        }

        return result;
    }
};
class Subtraction : public Polynomial
{
public:
    Polynomial subtract(Polynomial &p1, Polynomial &p2)
    {
        Polynomial result;

        Node *term1 = p1.getHead();
        Node *term2 = p2.getHead();

        while (term1 && term2)
        {
            if (term1->exponent == term2->exponent)
            {
                int diffCoefficients = term1->coefficient - term2->coefficient;
                if (diffCoefficients != 0)
                {
                    result.insertTerm(diffCoefficients, term1->exponent);
                }
                term1 = term1->next;
                term2 = term2->next;
            }
            else if (term1->exponent > term2->exponent)
            {
                result.insertTerm(term1->coefficient, term1->exponent);
                term1 = term1->next;
            }
            else
            {
                result.insertTerm(-term2->coefficient, term2->exponent);
                term2 = term2->next;
            }
        }

        while (term1)
        {
            result.insertTerm(term1->coefficient, term1->exponent);
            term1 = term1->next;
        }

        while (term2)
        {
            result.insertTerm(-term2->coefficient, term2->exponent);
            term2 = term2->next;
        }

        return result;
    }
};
class Multiplication : public Polynomial
{
public:
    Polynomial multiply(Polynomial &p1, Polynomial &p2)
    {
        // Clear the existing content of 'result' polynomial
        head = nullptr;

        Node *term1 = p1.getHead();

        // Handle the case where one or both polynomials are empty
        if (!term1)
        {
            return *this; // Result is an empty polynomial
        }

        while (term1)
        {
            Node *term2 = p2.getHead();
            while (term2)
            {
                int productCoefficient = term1->coefficient * term2->coefficient;
                int sumExponents = term1->exponent + term2->exponent;

                // Insert the product term directly, let the insertTerm method handle combining like terms
                insertTerm(productCoefficient, sumExponents);

                term2 = term2->next;
            }
            term1 = term1->next;
        }

        return *this;
    }

    // Destructor to free allocated memory
    ~Multiplication()
    {
        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};
void select_polynomial_operations()
{
start:
    int scalar;
    cout << "\t\t\t"
         << "Avaliable Polynomial Operations"
         << "\n";
    int choice = sel_mat_op(polynomials, "Polynomials", 2);
    print_multi_sbar(2, polynomials[choice]);
    Addition add;
    Subtraction sub;
    Multiplication mul;

    // Create polynomials
    Polynomial p1, p2;

    // Get user input for polynomial 1
    int numTerms1;
    cout << "Enter the number of terms for Polynomial 1: ";
    cin >> numTerms1;

    int coefficient, exponent;
    for (int i = 0; i < numTerms1; ++i)
    {
        cout << "Term " << i + 1 << " (Co,Ex) : ";
        cin >> coefficient >> exponent;
        p1.insertTerm(coefficient, exponent);
    }

    cout << endl
         << "Polynomial 1: ";
    p1.display();

    // Get user input for polynomial 2
    int numTerms2;
    cout << "Enter the number of terms for Polynomial 2: ";
    cin >> numTerms2;

    for (int i = 0; i < numTerms2; ++i)
    {
        cout << "Term " << i + 1 << " (Co,Ex) : ";
        cin >> coefficient >> exponent;
        p2.insertTerm(coefficient, exponent);
    }

    // Display polynomials
    cout << endl
         << "Polynomial 2: ";
    p2.display();

    if (choice == 0)
    {
        Polynomial resultAdd = add.add(p1, p2);
        cout << "Addition Result: ";
        resultAdd.display();
    }
    else if (choice == 1)
    {
        Polynomial resultSub = sub.subtract(p1, p2);
        cout << "Subtraction Result: ";
        resultSub.display();
    }
    else if (choice == 2)
    {
        Polynomial resultMul = mul.multiply(p1, p2);
        cout << "Multiplication Result: ";
        resultMul.display();
    }
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    goto start;

    return;
}

// Vectors

class Vector
{
protected:
    float x, y, z;

public:
    Vector(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    void display(const char *symbol)
    {
        cout << symbol << " = ";

        if (x < 0)
        {
            cout << abs(x) << "i";
        }
        else
        {
            cout << x << "i";
        }

        if (y < 0)
        {
            cout << " - " << abs(y) << "j";
        }
        else
        {
            cout << " + " << y << "j";
        }

        if (z < 0)
        {
            cout << " - " << abs(z) << "k";
        }
        else
        {
            cout << " + " << z << "k";
        }

        cout << endl;
    }

    Vector operator+(const Vector &other)
    {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector operator-(const Vector &other)
    {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    Vector operator*(float scalar)
    {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    float operator*(const Vector &other)
    {
        return x * other.x + y * other.y + z * other.z;
    }

    float magnitude()
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vector unitVector()
    {
        float mag = magnitude();
        if (mag != 0)
        {
            return *this * (1 / mag);
        }
        return *this;
    }

    Vector cross(const Vector &other)
    {
        return Vector(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
};
class Line
{
private:
    Vector point;     // A point on the line
    Vector direction; // Direction vector of the line

public:
    Line(Vector &point, Vector &direction) : point(point), direction(direction) {}

    void display(const char *symbol)
    {
        cout << symbol << " = ";
        point.display("r");
        cout << " + t";
        direction.display("");
    }
};

void select_vector_operations()
{
start:
    int scalar;
    // cout << "\t\t\t"
    //      << "Avaliable Vector Operations"
    //      << "\n";
    int choice = sel_mat_op(vectoralgebra, "Vector-Algebra", 2);
    print_multi_sbar(2, vectoralgebra[choice]);
    Vector v1, v2;
    for (int c = 0; c < 2; c++)
    {
        cout << endl;
        cout << endl
             << "Vector(" << c + 1 << ") -> (xi+yj+zk) ";
        cout << endl
             << "Enter (x,y,z) : ";
        int i, j, k;

        cin >> i >> j >> k;

        if (c == 0)
        {
            v1 = Vector(i, j, k);
            cout << endl;
            v1.display("v1");

            if (choice == 2)
            {
                cout << endl
                     << "Enter the scalar to multiply : ";
                cin >> scalar;
                break;
            }
            else if (choice == 3 || choice == 4)
            {
                break;
            }
        }
        else
        {
            v2 = Vector(i, j, k);
            cout << endl;
            v2.display("v2");
        }
    }

    if (choice == 0)
    {
        Vector sum = v1 + v2;
        cout << endl;
        sum.display("v1 + v2");
    }
    else if (choice == 1)
    {
        Vector diff = v1 - v2;
        cout << endl;
        diff.display("v1 - v2");
    }
    else if (choice == 2)
    {
        cout << endl;
        Vector scaled = v1 * scalar;
        scaled.display("scalar * v1");
    }
    else if (choice == 3)
    {
        cout << endl;
        float magnitudeV1 = v1.magnitude();
        cout << "Magnitude of v1: " << magnitudeV1 << endl;
    }
    else if (choice == 4)
    {
        cout << endl;
        Vector unitV1 = v1.unitVector();
        unitV1.display("Unit vector of v1");
    }
    else if (choice == 5)
    {
        cout << endl;
        float dotProduct = v1 * v2;
        cout << "Dot Product: " << dotProduct << endl;
    }
    else if (choice == 6)
    {
        cout << endl;
        Vector crossProduct = v1.cross(v2);
        crossProduct.display("Cross Product");
    }
    else if (choice == 7)
    {
        cout << endl;
        cout << "Line-Equation: " << endl;
        Line line(v1, v2);

        cout << "Line in Vector Form:" << endl;
        line.display("L");
    }
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    goto start;
}

// Complex Numbers
class ComplexNumber
{
private:
    double real;
    double imag;

public:
    // Constructor
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    // Getter functions
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Setter functions
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    // Conjugate
    ComplexNumber conjugate() const
    {
        return ComplexNumber(real, -imag); // Reverse the sign of the imaginary part
    }

    // Modulus (Magnitude)
    double modulus() const
    {
        return sqrt(real * real + imag * imag);
    }

    // Argument (Angle) in degrees
    double argument() const
    {
        return atan2(imag, real) * (180.0 / M_PI);
    }

    // Polar Form
    void polarForm(double &r, double &theta) const
    {
        r = modulus();
        theta = argument();
    }

    // Exponential Form
    void exponentialForm() const
    {
        double r, theta;
        polarForm(r, theta);
        cout << r << " * e^(i" << theta << " degrees)";
    }

    // Addition
    ComplexNumber operator+(const ComplexNumber &other) const
    {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Subtraction
    ComplexNumber operator-(const ComplexNumber &other) const
    {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Multiplication
    ComplexNumber operator*(const ComplexNumber &other) const
    {
        return ComplexNumber((real * other.real - imag * other.imag), (real * other.imag + imag * other.real));
    }

    // Division
    ComplexNumber operator/(const ComplexNumber &other) const
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        return ComplexNumber((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
    }

    // Display the complex number
    void display(const char *symbol) const
    {
        cout << symbol << " = ";
        cout << real;
        if (imag >= 0)
        {
            cout << " + " << imag << "i";
        }
        else
        {
            cout << " - " << -imag << "i";
        }

        // cout << endl;
    }
};
void select_complex_operations()
{
start:
    int scalar;

    int choice = sel_mat_op(complexnumber, "Complex Numbers", 2);
    print_multi_sbar(2, complexnumber[choice]);

    ComplexNumber c1, c2;
    for (int i = 0; i < 2; i++)
    {
        cout << endl;
        cout << endl
             << "Complex Number " << i + 1 << " -> (a+ib)\n";
        int a, b;
        cout << "(a,b) : ";
        cin >> a >> b;

        if (i == 0)
        {
            c1 = ComplexNumber(a, b);
            // cout << endl;
            c1.display("c1");
            if (choice == 5 || choice == 4 || choice == 6 || choice == 7 || choice == 8)
            {
                break;
            }
        }
        else
        {
            c2 = ComplexNumber(a, b);
            // cout << endl;
            c2.display("c2");
        }
    }

    if (choice == 0)
    {
        ComplexNumber sum = c1 + c2;
        cout << endl
             << endl;
        sum.display("c1 + c2");
    }
    else if (choice == 1)
    {
        cout << endl
             << endl;
        ComplexNumber diff = c1 - c2;
        diff.display("c1 - c2");
    }
    else if (choice == 2)
    {
        cout << endl
             << endl;
        ComplexNumber scaled = c1 * c2;
        scaled.display("c1 * c2");
    }
    else if (choice == 5)
    {
        float magnitudec1 = c1.modulus();
        cout << endl
             << endl;
        cout << "Magnitude of c1: " << magnitudec1 << endl;
    }
    else if (choice == 3)
    {
        ComplexNumber div = c1 / c2;
        cout << endl
             << endl;
        div.display("c1/c2");
    }
    else if (choice == 4)
    {
        ComplexNumber conj = c1.conjugate();
        cout << endl
             << endl;
        conj.display("Conjugate of c1");
    }
    else if (choice == 6)
    {
        cout << endl
             << endl;
        cout << "Argument: " << c1.argument() << " degrees" << endl;
    }
    else if (choice == 7)
    {
        double polarR, polarTheta;
        c1.polarForm(polarR, polarTheta);

        cout << "\nPolar Form: \n\t" << polarR << "(cos(" << polarTheta << ") + i sin(" << polarTheta << "))" << endl;
    }
    else if (choice == 8)
    {
        cout << "\nExponential Form: ";
        c1.exponentialForm();
        cout << endl;
    }
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    goto start;
}

// Equations
class TwoLinearEquationSolver
{
private:
    double a1, b1, c1, a2, b2, c2;
    string var1, var2;

public:
    TwoLinearEquationSolver() {}

    TwoLinearEquationSolver(double a1, double b1, double c1, double a2, double b2, double c2, const string &var1, const string &var2)
        : a1(a1), b1(b1), c1(c1), a2(a2), b2(b2), c2(c2), var1(var1), var2(var2) {}

    void solve()
    {
        double determinant = a1 * b2 - a2 * b1;

        if (determinant != 0)
        {
            double x = (b1 * c2 - b2 * c1) / determinant;
            double y = (a2 * c1 - a1 * c2) / determinant;

            cout << "Solution: " << endl;
            cout << var1 << " = " << x << endl;
            cout << var2 << " = " << y << endl;
        }
        else
        {
            if ((a1 / a2 == b1 / b2) && (a1 / a2 == c1 / c2))
            {
                cout << "Infinite solutions. Both equations represent the same line." << endl;
            }
            else
            {
                cout << "No unique solution. Determinant is zero." << endl;
            }
        }
    }
};

class ThreeLinearEquationSolver
{
private:
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;

public:
    ThreeLinearEquationSolver() {}

    ThreeLinearEquationSolver(double a1, double b1, double c1, double d1,
                              double a2, double b2, double c2, double d2,
                              double a3, double b3, double c3, double d3,
                              const string &var1, const string &var2, const string &var3)
        : a1(a1), b1(b1), c1(c1), d1(d1),
          a2(a2), b2(b2), c2(c2), d2(d2),
          a3(a3), b3(b3), c3(c3), d3(d3),
          var1(var1), var2(var2), var3(var3) {}

    void solve()
    {
        double detA = det(a1, b1, c1, a2, b2, c2, a3, b3, c3);
        double detX = det(d1, b1, c1, d2, b2, c2, d3, b3, c3);
        double detY = det(a1, d1, c1, a2, d2, c2, a3, d3, c3);
        double detZ = det(a1, b1, d1, a2, b2, d2, a3, b3, d3);

        if (detA != 0)
        {
            double x = detX / detA;
            double y = detY / detA;
            double z = detZ / detA;

            cout << "Solution: " << endl;
            cout << var1 << " = " << x << endl;
            cout << var2 << " = " << y << endl;
            cout << var3 << " = " << z << endl;
        }
        else
        {
            if (detA == 0 && detX == 0 && detY == 0 && detZ == 0)
            {
                cout << "Infinite solutions. All coefficients are zero." << endl;
            }
            else
            {
                cout << "No unique solution. Determinant is zero." << endl;
            }
        }
    }

    string var1, var2, var3;

    double det(double a, double b, double c, double d, double e, double f, double g, double h, double i)
    {
        return a * (e * i - h * f) - b * (d * i - g * f) + c * (d * h - g * e);
    }
};

class LinearEquationSolver
{
private:
    double a, b;
    std::string var;

public:
    LinearEquationSolver() {}

    LinearEquationSolver(double a, double b, const std::string &var)
        : a(a), b(b), var(var) {}

    void solve()
    {
        if (a != 0)
        {
            double x = -b / a;
            cout << "Solution: " << endl;
            cout << var << " = " << x << endl;
        }
        else
        {
            cout << "No solution. Coefficient of " << var << " is zero." << endl;
        }
    }
};

void onevariablelinearequation()
{
    double a, b;
    string var = "x";
    cout << "ax+b=0" << endl;
    cin >> a >> b;
    LinearEquationSolver linearEquationSolver(a, b, var);
    linearEquationSolver.solve();
}

void twovariablelinearequation()
{
    double a, b, c, d, e, f;
    string var1 = "x", var2 = "y";
    cout << "a1x+b1y+c1=0" << endl;
    cin >> a >> b >> c;
    cout << "a2x+b2y+c2=0" << endl;
    cin >> d >> e >> f;
    TwoLinearEquationSolver twoLinearEquationSolver(a, b, c, d, e, f, var1, var2);
    twoLinearEquationSolver.solve();
}

void threevariablelinearequation()
{
    double a, b, c, d, e, f, g, h, i, j, k, l;
    string var1 = "x", var2 = "y", var3 = "z";
    cout << "a1x + b1y + c1z + d1 = 0" << endl;
    cin >> a >> b >> c >> d;
    cout << "a2x + b2y + c2z + d2 = 0" << endl;
    cin >> e >> f >> g >> h;
    cout << "a3x + b3y + c3z + d3 = 0" << endl;
    cin >> i >> j >> k >> l;
    ThreeLinearEquationSolver threeLinearEquationSolver(a, b, c, d, e, f, g, h, i, j, k, l, var1, var2, var3);
    threeLinearEquationSolver.solve();
}

void print_sbar(string s) // prints Search Bar
{
    cout << "\t\t\t\t\t\t\t\t---------------------------------\n";
    int n = s.size();
    int s_l = 34 - n;
    s_l = s_l / 2 - 1;
    cout << "\t\t\t\t\t\t\t\t|";
    for (int i = 0; i < s_l; i++)
        cout << " ";
    cout << "\x1b[1;33m" << s;
    for (int i = 0; i < s_l; i++)
        cout << " ";
    cout << "\x1b[0;39m";
    cout << "|\n";
    cout << "\t\t\t\t\t\t\t\t---------------------------------\n";
}

void logo()
{
    string load_page;
    system("cls");

    for (int i = 1; i <= 100; i++)
    {
        cout << "\e[?25l";
        system("cls");

        // cout<<"\t\t\t   ";
        ascii_intro_logo();
        cout << "\n\n\n\n\n\n\n";
        cout << logo_symbols[i % 10];
        cout << "\n\n\n";

        load_page += "\xdb";
        cout << "\t\t\t     " << load_page << " " << (i) << '\%';
        // Sleep(10);
        if (i < 30)
            Sleep(6);
        else
            Sleep(1);
        // // Sleep(1);
    }
    cout << "\n\n\n\t\t\t\t\t\t\t\t    \x1b[38;5;172mPress any key to Continue!\x1b[0m";
    char ch = getch();
    fflush(stdin);
    select_main_operation();
}

void print_multi_sbar(int page, string op2)
{
    ascii_page_logo();
    if (page == 1)
        print_sbar(operation1);
    else if (page == 2)
    {
        print_sbar(operation1);
        print_sbar(op2);
    }
}

void printmatches(int line_ct, vector<string> &v, string op, int page, string op2 = "SELECT ONE")
{
    ascii_page_logo();
    if (page == 1)
        print_sbar(op);
    else if (page == 2)
    {
        print_sbar(op);
        print_sbar(op2);
        operation1 = op;
    }
    // cout << "\t\t\t\t\t" <<"Avaliable " <<op<< " Operations:" << "\n"<<endl<<endl;
    cout << endl
         << endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == line_ct)
        {
            cout << "\t\t\t\t\t\t\t\t      >  ";
            cout << "\x1b[1;36m" << v[i] << "\x1b[22;0m\n";
        }
        else
        {
            cout << "\t\t\t\t\t\t\t\t\t" << v[i] << "\n";
            printf(" ");
        }
    }
}

int sel_mat_op(vector<string> a, string op, int page)
{
    int ch;
    system("cls");
    // path();
    printmatches(0, a, op, page);
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
        else if (ch == 27)
        {
            system("cls");
            select_main_operation();
        }
        system("cls");
        // path();
        printmatches(ct, a, op, page);
    }
}

// equation solver

class PolynomialEquationSolver
{
protected:
    vector<double> coefficients;

public:
    PolynomialEquationSolver() {}

    PolynomialEquationSolver(vector<double> &coefficients) : coefficients(coefficients) {}

    virtual void solve() {}
};

class LinearPolynomialSolver : public PolynomialEquationSolver
{
public:
    using PolynomialEquationSolver::PolynomialEquationSolver;

    void solve() override
    {
        if (coefficients.size() == 2)
        {
            double x = -coefficients[0] / coefficients[1];
            cout << "Solution: x = " << x << std::endl;
        }
        else
        {
            cout << "Invalid coefficients for a linear equation." << endl;
        }
    }
};

void select_linearequation_operation()
{
start:
    // cout<<"\t\t\t"<<" Available options"<<endl;
    int x = sel_mat_op(arr4, "Equations", 2);
    print_multi_sbar(2, arr4[x]);
    if (x == 0)
    {
        onevariablelinearequation();
    }
    if (x == 1)
    {
        twovariablelinearequation();
    }
    if (x == 2)
    {
        threevariablelinearequation();
    }
    cout << "\n\n Press any key to continue....";
    char ch = getch();
    fflush(stdin);
    goto start;
}

//Finding Roots

void QuadraticPolynomialSolver(vector<double> &arr)
{
    if (arr.size() == 3)
    {
        double a = arr[0];
        double b = arr[1];
        double c = arr[2];
        double delta = ((b * b) - (4 * a * c));
        if (delta > 0)
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "The equation has 2 real roots:" << endl;
            cout << "x1: " << x1 << endl;
            cout << "x2: " << x2 << endl;
            cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
        }
        else if (delta == 0)
        {
            double x = -b / ((2) * a);
            cout << "The equation has one real root:" << endl;
            cout << "x1 = " << x << endl;
            cout << "x2 = " << x << endl;
            cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
        }
        else
        {
            cout << "The equation has two complex roots." << endl;
            cout << "Equation:  " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-delta) / (2 * a);
            cout << "x1 =  " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "x2 =  " << realPart << " - " << imaginaryPart << "i" << endl;
        }
        return;
    }
    else
    {
        cout << "invalid input" << endl;
        return;
    }
}

void select_Equations_operation()
{
// cout<<"\t\t\t"<<" Available options"<<endl;
start:
    int x = sel_mat_op(arr2, "Types", 2);
    print_multi_sbar(2, arr2[x]);
    vector<double> coefficients;
    cout << "Enter the coefficients (from highest to lowest degree): ";
    for (int i = x + 1; i >= 0; i--)
    {
        double coeff;
        cin >> coeff;
        coefficients.push_back(coeff);
    }

    PolynomialEquationSolver *solver;

    if (x == 0)
    {
        solver = new LinearPolynomialSolver(coefficients);
        solver->solve();
        delete solver;
    }
    if (x == 1)
    {
        QuadraticPolynomialSolver(coefficients);
    }
    cout << "\n\n Press any key to continue....";
    char con = getch();
    fflush(stdin);
    goto start;
}

// Home Page
void select_main_operation()
{
    // print_sbar("SELECT ONE");
    int k = sel_mat_op(oper, "SELECT ONE", 1);
    // string in_bar;

    if (k == 0)
    {
        simple_cal();
    }
    else if (k == 1)
    {
        select_matrix_operations();
    }
    else if (k == 2)
    {
        select_satistics_operations();
    }
    else if (k == 3)
    {
        select_vector_operations();
    }
    else if (k == 4)
    {
        select_Mensuration_operation();
    }
    else if (k == 5)
    {
        select_polynomial_operations();
    }
    else if (k == 6)
    {
        select_linearequation_operation();
    }
    else if (k == 7)
    {
        select_complex_operations();
    }
    else if (k == 8)
    {
        select_Equations_operation();
    }
    else if (k == 9)
    {
        exit(0);
    }
}

int main()
{
    logo();

    // select_main_operation();
    return 0;
}
