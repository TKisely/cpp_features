using namespace std;
#include <iostream>

void separator(){
    cout<<"\n-----||\t\t||-----\n";
}

//Abstract example
//Abstract base class
class Shape{
public:
    //pure virtual function => cant have an object
    virtual void draw()=0;
};

class Circle:public Shape{
private:
    int r;
public:
    explicit Circle(int r_in=0):r(r_in){}
    void draw() override{
        cout<<"Drew a circle : "<<r<<endl;
    }
};

class RandomShape:public Shape{
    //if we dont override all the virtual funcs
    //it will be abstract as well
protected:
    int area;
public:
    RandomShape(int a){this->area=a; cout<<"Abstract base class's constructor"<<endl;}


};

class DefinedRandomShape:public RandomShape{
private:
    int circumference;
public:
    DefinedRandomShape(int a, int cf): RandomShape(a){
        circumference=cf;
        cout<<"Derived class's constructor"<<endl;
    }
    void draw(){
        cout<<area<<" area and circumference "<<circumference<<endl;
    }
};

//Polymorphism
//Compile-time Polymorphism
class LotOfFunctions{
public:
    LotOfFunctions(){cout<<"Constructed"<<endl;};

public:
    void printNums(int a, int b){cout<<a<<b<<endl;}
    void printNums(double a, double b){cout<<a<<b<<endl;}
    void printNums(int a, int b, int c){cout<<a<<b<<c<<endl;}
    //same name different parameter lists
    //operator overloading is the same
    //function OVERLOADING
};

//Polymorphism
//Run-time Polymorphism

class BaseForPoly{
public:
    virtual void printSomethingVirt(){cout<<"Something BASE VIRT"<<endl;}
    void printSomething(){cout<<"Something BASE"<<endl;}
};

class DerivedForPoly:public BaseForPoly{
public:
    void printSomethingVirt(){cout<<"Something DERI from VIRT"<<endl;}
    void printSomething(){cout<<"Something DERI"<<endl;}
};


int main() {
    //pre and post increment
    int num=42;
    cout<<num++<<" -> "<<num<<endl;
    //result: 42 - > 43
    num = 42;
    cout<<++num<<" -> "<<num<<endl;
    //result: 43 -> 42
    separator();


    //Abstract class example
    Circle c(5);
    c.draw();
    //Shape shape(); does not compile,
    //because it is an abstract class

    Shape *shape = new Circle(7); //has to be public inh.
    shape->draw();
    //result : Drew a circle : 7

    DefinedRandomShape drs(8,9);
    drs.draw();
    //result : Abs.base const., then derived const.
    //8 area and circumference 9
    separator();


    //Polymorphism
    //Compile-time Polymorphism
    LotOfFunctions lof;
    lof.printNums(1,2);
    lof.printNums(1.2,3.4);
    lof.printNums(6,7,8);

    separator();

    //Polymorphism
    //Run-time Polymorphism
    BaseForPoly baseForPoly;
    DerivedForPoly derivedForPoly;
    baseForPoly.printSomethingVirt();
    derivedForPoly.printSomethingVirt();
    //result: BASE then DERI

    BaseForPoly* baseForPolyPTR;
    baseForPolyPTR=&derivedForPoly;
    derivedForPoly.printSomethingVirt();
    baseForPolyPTR->printSomethingVirt();
    //result: DERI then DERI
    //THIS IS THE RUNTIME POLY
    //basePTR calls DERI because the func was virtual

    derivedForPoly.printSomething();
    baseForPolyPTR->printSomething();
    //result: DERI then BASE
    //basePTR calls BASE, NOT virtual case













    std::cout << "\n\nFinished" << std::endl;
    return 0;
}
