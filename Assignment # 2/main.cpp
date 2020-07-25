#include <iostream>
#include <conio.h>
#include "Polynomial.cpp"

using namespace std;
int main() {
    Polynomial p1,p2;
	cout << "Assignment # 2\nPolynomials\n"<<endl;
	cout << "1st Polynomial\n";    
	p1.insert(2,2);
    p1.insert(5,1);
    p1.insert(6,0);
    p1.display();
    
	cout << "\n\n2nd Polynomial\n";
	p2.insert(6,3);
    p2.insert(4,2);
    p2.insert(8,1);
    p2.insert(9,0);
    p2.display();

	cout << "\n\nAddition of the matrices: \n";
    Polynomial res = p1.add(p2);
    res.display();

	cout << "\n\nSubtraction of the matrices: \n";
    Polynomial res2 = p1.sub(p2);
    res2.displaysub();


    getch();
    return 0;
}
