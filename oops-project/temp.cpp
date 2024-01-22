#include <bits/stdc++.h>
#include "mensuration.h"
#include <conio.h>
using namespace std;

// Base class
class Shape {
public:
    virtual double getArea() = 0; // Pure virtual function
    virtual double getvolume()=0;//pure virtual function
    virtual double getperimeter()=0;//pure virtual function
    virtual double getcurvedsurfacearea()=0;//pure virtual function
    

};
struct Node
{
    int coefficient;
    int exponent;
    Node *next;
};
class Polynomial
{
protected:
    Node *head;

public:
    Polynomial() : head(nullptr) {}

    // Function to insert a term into the polynomial in descending order of exponent
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
            while (current->next && exponent < current->next->exponent)
            {
                // Traverse the list until the correct position is found
                current = current->next;
            }

            // Insert the new term
            newNode->next = current->next;
            current->next = newNode;
        }
    }
     void display()
    {
        Node *current = head;
        while (current)
        {
            if (current->coefficient != 0)
            {
                if (current->coefficient > 0)
                {
                    if (current != head)
                    {
                        cout << " + ";
                    }
                }
                else
                {
                    cout << " - ";
                }

                cout << abs(current->coefficient);
                if (current->exponent > 0)
                {
                    cout << "x";
                    if (current->exponent > 1)
                    {
                        cout << "^" << current->exponent;
                    }
                }
            }

            current = current->next;
        }

        if (!head)
        {
            cout << "0"; // Display "0" for an empty polynomial
        }

        cout << endl;
    }
      Node *getHead() const
    {
        return head;
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
                result.insertTerm(term1->coefficient + term2->coefficient, term1->exponent);
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
                result.insertTerm(term1->coefficient - term2->coefficient, term1->exponent);
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
        Polynomial result;

        Node *term1 = p1.getHead();
        while (term1)
        {
            Node *term2 = p2.getHead();
            while (term2)
            {
                result.insertTerm(term1->coefficient * term2->coefficient, term1->exponent + term2->exponent);
                term2 = term2->next;
            }
            term1 = term1->next;
        }

        return result;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea() {
        return length * width;
    }
    double getvolume(){
        return 0;
    }
    double getperimeter(){
        return 2*(length+width);
    }
    double getcurvedsurfacearea(){
        return 0;
    }
};
class parallelogram : public Shape {
public:
    double length;
    double width;
public:
    parallelogram(double l, double w) : length(l), width(w) {}
    double getArea() {
        return length * width;
    }
    
    double getvolume(){
        return 0;
    }
    double getperimeter(){
        return 2*(length+width);
    }
    double getcurvedsurfacearea(){
        return 0;
    }
};

class Sphere: public Shape{
    private:
    double radius;
    public:
    Sphere(double radius):radius(radius){}
    double getArea(){
        return 4*M_PI*pow(radius,2);
    }
     double getvolume(){
        return (4/3)*M_PI*pow(radius,3);}
    double getperimeter(){
        return 0;

    }
    double getcurvedsurfacearea(){
          return 4*M_PI*pow(radius,2);

    }  
};
class Triangle: public Shape{
    private:
    double side1,side2,side3,s;
    public:
     Triangle(double side1,double side2,double side3):side1(side1),side2(side2),side3(side3){
        this->s=(side1+side2+side3)/2;
     }
      double getArea(){
        return sqrt((s-side1)*(s-side2)*(s-side3));

    }
     double getvolume(){
        return 0;
    }
    double getperimeter(){
        return side1+side2+side3;
    }
    double getcurvedsurfacearea(){
        return 0;
    }
};
class Rhombus : public Shape{
    
    private:
    double side1,d1,d2;
    public:
    Rhombus(double side1, double d1,double d2){
        this->side1=side1;
        this->d1=d1;
        this->d2=d2;
    }
    double getArea(){
         return 0.5*d1*d2;
        
    }
    double getcurvedsurfacearea(){
        return 0;
    }
  
    double getvolume(){
        return 0;
    }
    double getperimeter(){
        return 4*side1;
    }

};
class Cone : public Shape {
    private:
    double height,radius;
    public:
    Cone(double height=0,double radius=0){
        this->height=height;
        this->radius=radius;
    }
    double  getvolume(){
        return (1/3)*pow(radius,2)*height;
        
    }
    double getArea(){
        double slant_height=sqrt(pow(height,2)+pow(radius,2));
           return M_PI*radius*(slant_height+radius);

    }
    double getcurvedsurfacearea(){
         double slant_height=sqrt(pow(height,2)+pow(radius,2));
         return M_PI*radius*slant_height;
    }
    double getperimeter(){
        return 0;
    }
};
class Cuboid :public Shape{
    double length,bredth,height;
    public:
    Cuboid(double length=0,double bredth=0,double height=0){
        this->length=length;
        this->bredth=bredth;
        this->height=height;
    }
    double getvolume(){
         return length*bredth*height;
       
    }
    double getcurvedsurfacearea(){
        return 2*height*(length+bredth);

    }
    double getArea(){ 
         return 2*(length*bredth+bredth*height+height*length);
     
    }
    double getperimeter(){
        return 0;
    }
};

// Derived class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() {
        return M_PI * pow(radius, 2);
    }
    double getvolume(){
        return 0;
    }
    double getperimeter(){
        return 2*M_PI*radius;
    }
    double getcurvedsurfacearea(){
        return 0;
    }
};
class Square: public Shape{
    private:
    double side;
    public:
    Square(double side): side(side){}
    double getArea(){
        return pow(side,2);
    }
    double getvolume(){
        return 0;
    }
    double getperimeter(){
        return 4*side;
    }
    double getcurvedsurfacearea(){
        return 0;
    }

};
class Cylinder: public Shape{
    private:
    double height,radius;
    public:
    Cylinder(double height,double radius): height(height),radius(radius){
        
    }
    double getcurvedsurfacearea(){
        return 2*M_PI*radius*height;

    }
    double getArea()  {
             return 2*M_PI*radius*(height+radius);
    }
    double  getvolume(){
             return M_PI*(pow(radius,2))*height;}
    double getperimeter(){
        return 0;
    }
  
};
class Trapezium: public Shape{
    double height,a,b,c,d;
    public:
    Trapezium(double height,double a,double b,double c,double d):height(height),a(a),b(b),c(c),d(d){}
    double getArea(){
        return 1/2*height*(a+b);
    }
    double getvolume(){
        return 0;
    }
    double getperimeter(){
        return a+b+c+d;
    }
    double getcurvedsurfacearea(){
        return 0;
    }

};
class Hemisphere:public Shape{
private:
double radius;
public:

Hemisphere(double radius=0){
  
    this->radius=radius;
}
double getvolume(){
    double volume=(0.67)*M_PI*(pow(radius,3));
    return volume;
}
double getArea(){

    return 3*M_PI*(pow(radius,2));

}
double getcurvedsurfacearea(){
     double csa=2*M_PI*(pow(radius,2));
     return csa;
}
double getperimeter(){
    return 0;
}

};
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
                double root1 = (-coefficients[1] + std::sqrt(discriminant)) / (2 * coefficients[0]);
                double root2 = (-coefficients[1] - std::sqrt(discriminant)) / (2 * coefficients[0]);
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

// Operator overloading
ostream& operator<<(ostream& os, Shape& s) {
    os << "Area or Total surface area: " << s.getArea()<<" m2"<<endl;
    os << "Curved surface area: " << s.getcurvedsurfacearea()<<" m2"<<endl;
    os << "Volume: " << s.getvolume()<<" m3"<<endl;
    os << "Perimeter: " << s.getperimeter()<<" m"<<endl;
    return os;
}
vector<string> arr1 = {"Rectangle", "parallelogram", "sphere", "Triangle", "Rhombus", "Cone", "Cuboid", "Circle", "Square", "Cylinder","Trapezium","Hemisphere"};
vector<string> arr2 = {"LinearPolynomialSolver","QuadraticPolynomialSolver"};
vector<string>arr3={"MENSURATION","EQUATIONS"};
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
int  types(){
      int ch;
    system("cls");
    printmat(0,arr3);
    int ct = 0;
    int n=arr3.size();
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
        printmat(ct,arr3);
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


void select_Equations_operation(){
      cout<<"\t\t\t"<<" Available options"<<endl;
    int x =equations(arr2);
    
      if(x==0 || x==1 ){
    vector<double> coefficients;
    cout << "Enter the coefficients (from highest to lowest degree): ";
    for (int i = x; i >= 0; i--) {
        double coeff;
        cin >> coeff;
        coefficients.push_back(coeff);
    }

    PolynomialEquationSolver* solver;

    if (x == 0) {
        solver = new LinearPolynomialSolver(coefficients);
    }  if (x == 1) {
        solver = new QuadraticPolynomialSolver(coefficients);
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
    // select_Equations_operation();
    select_linearequation_operation();
    // onevariablelinearequation();
// twovariablelinearequation();
// threevariablelinearequation();
    

  

    return 0;
}


