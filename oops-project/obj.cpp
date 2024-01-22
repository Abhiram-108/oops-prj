#include <bits/stdc++.h>
#include "mensuration.h"
#include <conio.h>
using namespace std;
class PolynomialEquationSolver {
protected:
    vector<double> coefficients;
public:
    PolynomialEquationSolver() {}

    PolynomialEquationSolver(vector<double>& coefficients) : coefficients(coefficients) {}

    virtual void solve() {
        cout << "Default polynomial equation solver. (Placeholder implementation)" << endl;
    }

};
class LinearPolynomialSolver : public PolynomialEquationSolver {
public:
    using PolynomialEquationSolver::PolynomialEquationSolver;

    void solve() override {
        if (coefficients.size() == 2) {
            double x = -coefficients[0] / coefficients[1];
            cout << "Solution: x = " << x << std::endl;
        } else {
            cout << "Invalid coefficients for a linear equation." << endl;
        }
    }
};
class QuadraticPolynomialSolver : public PolynomialEquationSolver {
public:
    using PolynomialEquationSolver::PolynomialEquationSolver;

    void solve() override {
        if (coefficients.size() == 3) {
            double discriminant = coefficients[1] * coefficients[1] - 4 * coefficients[0] * coefficients[2];

            if (discriminant > 0) {
                double root1 = (-coefficients[1] + sqrt(discriminant)) / (2 * coefficients[0]);
                double root2 = (-coefficients[1] - sqrt(discriminant)) / (2 * coefficients[0]);
                std::cout << "Solutions: x1 = " << root1 << ", x2 = " << root2 << endl;
            } else if (discriminant == 0) {
                double root = -coefficients[1] / (2 * coefficients[0]);
                cout << "Solution: x = " << root << endl;
            } else {
                cout << "No real solutions. Discriminant is negative." << endl;
            }
        } else {
            cout << "Invalid coefficients for a quadratic equation." << endl;
        }
    }
};
class TwoLinearEquationSolver {
private:
    double a1, b1, c1, a2, b2, c2;
    string var1, var2;
public:
    TwoLinearEquationSolver() {}

    TwoLinearEquationSolver(double a1, double b1, double c1, double a2, double b2, double c2, const std::string& var1, const std::string& var2)
        : a1(a1), b1(b1), c1(c1), a2(a2), b2(b2), c2(c2), var1(var1), var2(var2) {}

    void solve() {
        double determinant = a1 * b2 - a2 * b1;

        if (determinant != 0) {
            double x = (b1 * c2 - b2 * c1) / determinant;
            double y = (a2 * c1 - a1 * c2) / determinant;

            std::cout << "Solution: " << var1 << " = " << x << ", " << var2 << " = " << y << std::endl;
        } else {
            if ((a1 / a2 == b1 / b2) && (a1 / a2 == c1 / c2)) {
                cout << "Infinite solutions. Both equations represent the same line." << std::endl;
            } else {
            cout << "No unique solution. Determinant is zero." << std::endl;
            }
        }
    }

};
class ThreeLinearEquationSolver {
private:
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
public:
    ThreeLinearEquationSolver() {}

    ThreeLinearEquationSolver(double a1, double b1, double c1, double d1,
                              double a2, double b2, double c2, double d2,
                              double a3, double b3, double c3, double d3,
                              const std::string& var1, const std::string& var2, const std::string& var3)
        : a1(a1), b1(b1), c1(c1), d1(d1),
          a2(a2), b2(b2), c2(c2), d2(d2),
          a3(a3), b3(b3), c3(c3), d3(d3),
          var1(var1), var2(var2), var3(var3) {}

    void solve() {
        double detA = det(a1, b1, c1, a2, b2, c2, a3, b3, c3);
        double detX = det(d1, b1, c1, d2, b2, c2, d3, b3, c3);
        double detY = det(a1, d1, c1, a2, d2, c2, a3, d3, c3);
        double detZ = det(a1, b1, d1, a2, b2, d2, a3, b3, d3);

        if (detA != 0) {
            double x = detX / detA;
            double y = detY / detA;
            double z = detZ / detA;

            cout << "Solution: " << var1 << " = " << x << ", " << var2 << " = " << y << ", " << var3 << " = " << z << endl;
        } else {
            if (detA == 0 && detX == 0 && detY == 0 && detZ == 0) {
                cout << "Infinite solutions. All coefficients are zero." << std::endl;
            } else {
                cout << "No unique solution. Determinant is zero." << std::endl;
            }
        }
    }

    string var1, var2, var3;

    double det(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        return a * (e * i - h * f) - b * (d * i - g * f) + c * (d * h - g * e);
    }
};
class LinearEquationSolver {
private:
    double a, b;
    std::string var;
public:
    LinearEquationSolver() {}

    LinearEquationSolver(double a, double b, const std::string& var)
        : a(a), b(b), var(var) {}

    void solve() {
        if (a != 0) {
            double x = -b / a;
            std::cout << "Solution: " << var << " = " << x << std::endl;
        } else {
            std::cout << "No solution. Coefficient of " << var << " is zero." << std::endl;
        }
    }

};
void onevariablelinearequation(){
     double a, b;
    string var;

    cout << "Enter the coefficient of the variable: ";
    cin >> a;

    cout << "Enter the constant term: ";
    cin >> b;

    cout << "Enter the name of the variable: ";
    cin >> var;

    LinearEquationSolver linearEquationSolver(a, b, var);
    linearEquationSolver.solve();
}
void twovariablelinearequation(){
     double a1, b1, c1, a2, b2, c2;
    string var1, var2;

    cout << "Enter the coefficient of the first variable for the first equation: ";
    cin >> a1;

    cout << "Enter the coefficient of the second variable for the first equation: ";
    cin >> b1;

    cout << "Enter the constant term for the first equation: ";
    cin >> c1;

    cout << "Enter the coefficient of the first variable for the second equation: ";
    cin >> a2;

    cout << "Enter the coefficient of the second variable for the second equation: ";
    cin >> b2;

    cout << "Enter the constant term for the second equation: ";
    cin >> c2;

    cout << "Enter the name of the first variable: ";
    cin >> var1;

    cout << "Enter the name of the second variable: ";
    cin >> var2;

    TwoLinearEquationSolver twoLinearEquationSolver(a1, b1, c1, a2, b2, c2, var1, var2);
    twoLinearEquationSolver.solve();

}
void threevariablelinearequation(){
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    string var1, var2, var3;

    cout << "Enter the coefficient of the first variable for the first equation: ";
    cin >> a1;

    cout << "Enter the coefficient of the second variable for the first equation: ";
    cin >> b1;

    cout << "Enter the coefficient of the third variable for the first equation: ";
    cin >> c1;

    cout << "Enter the constant term for the first equation: ";
    cin >> d1;

    cout << "Enter the coefficient of the first variable for the second equation: ";
    cin >> a2;

    cout << "Enter the coefficient of the second variable for the second equation: ";
    cin >> b2;

    cout << "Enter the coefficient of the third variable for the second equation: ";
    cin >> c2;

    cout << "Enter the constant term for the second equation: ";
    cin >> d2;

    cout << "Enter the coefficient of the first variable for the third equation: ";
    cin >> a3;

    cout << "Enter the coefficient of the second variable for the third equation: ";
    cin >> b3;

    cout << "Enter the coefficient of the third variable for the third equation: ";
    cin >> c3;

    cout << "Enter the constant term for the third equation: ";
    cin >> d3;

    cout << "Enter the name of the first variable: ";
    cin >> var1;

    cout << "Enter the name of the second variable: ";
    cin >> var2;

    cout << "Enter the name of the third variable: ";
    cin >> var3;

    ThreeLinearEquationSolver threeLinearEquationSolver(a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3, var1, var2, var3);
    threeLinearEquationSolver.solve();

}
vector<string> arr2 = {"LinearPolynomialSolver","QuadraticPolynomialSolver"};
vector<string>arr4={"onevariable","twovariable","threevariable"};
void printmat(int line_ct,vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i == line_ct)
        {
            cout << "\t\t\t\t\t>";
            cout << "\x1b[1;36m" << v[i] << "\x1b[22;0m\n";
        }
        else
        {
            cout << "\t\t\t\t\t" << v[i] << "\n";
            printf(" ");
        }
    }
}

int  equations(vector<string>&arr2){
      int ch;
    system("cls");
    printmat(0,arr2);
    int ct = 0;
    int n=arr2.size();
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
        printmat(ct,arr2);
    }
}
int variable(vector<string>&arr4){
      int ch;
    system("cls");
    printmat(0,arr4);
    int ct = 0;
    int n=arr4.size();
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
        printmat(ct,arr4);
    }

}
void select_linearequation_operation(){
   
        cout<<"\t\t\t"<<" Available options"<<endl;
    int x=variable(arr4);
    if(x==0){
        onevariablelinearequation();

    }
    if(x==1){
        twovariablelinearequation();

    }
    if(x==2){
        threevariablelinearequation();
    }
}
void  QuadraticPolynomialSolver(vector<double>&arr){
    if(arr.size()==3){
        double a=arr[0];
        double b=arr[1];
        double c=arr[2];
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
            // double x1 = (-b + (sqrt(-delta))) / (2 * a);
            // double x2 = (-b - (sqrt(-delta))) / (2 * a);
            cout << "The equation has two complex roots." << endl;
            cout << "Equation:  " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-delta) / (2 * a);
            cout << "x1 =  " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "x2 =  " << realPart << " - " << imaginaryPart << "i" << endl;
}

}
else{
    cout<<"invalid input"<<endl;
}
}
void select_Equations_operation(){
      cout<<"\t\t\t"<<" Available options"<<endl;
    int x =equations(arr2);
    
      if(x==0 || x==1 ){
    vector<double> coefficients;
    cout << "Enter the coefficients (from highest to lowest degree): ";
    for (int i = x+1; i >= 0; i--) {
        double coeff;
        cin >> coeff;
        coefficients.push_back(coeff);
    }

    PolynomialEquationSolver* solver;

    if (x == 0) {
        solver = new LinearPolynomialSolver(coefficients);
    }  if (x == 1) {
             QuadraticPolynomialSolver(coefficients);
    } 


    solver->solve();

    delete solver;
    

    }

   
}
int main() {

    // int x1,x;
    // // x=calculator_display();
    // x1=types();
    // if(x1==1){
    // x=equations(arr2);
    // Equations(x);}
    // if(x1==0){
    // x=mensuration(arr1);
    // Mensuration(x);
    
    // }
    // select_Mensuration_operation();
    select_Equations_operation();
    
    select_linearequation_operation();
    // onevariablelinearequation();
// twovariablelinearequation();
// threevariablelinearequation();
    

  

    return 0;
}