#include<iostream>
#include<conio.h>
using namespace std;

class Polynomial
{
	public:
			Polynomial()
			{
				size = highestDegree = 0;				
			}	
			Polynomial(string n, int h)
			{
				name = n;
				highestDegree = h;
				size = h+1;
			//	cout<<"Size  = "<<size<<", Highest Degree = "<<highestDegree<<endl;
				create();								
			}
			void create(){
				ptr[size];
				cout<<"Polynomial Created "<<endl;
				init();
			}
			void init(){
				
				for(int i=0;i<size; i++){
					ptr[i] = 0;
				}
				cout<<"Plynomial Initialized "<<endl;
			}
			void display(){
				cout<<name<<" =  ";				
				for(int i=size-1;i >= 0; i--){
					if(ptr[i] != 0)
						cout<<ptr[i]<<" X ^ "<<i<<" + ";					
				}
				cout<<endl;
			}
			int addPower(int p1,int p2)
			{
				int p=p1+p2;
				return p;
			}
			void setPolynomial(int x[],int s)
			{
				if(s == size){
					for(int i=0; i<size; i++){
						ptr[i] = x[i];
					}
				}
				else{
					cout<<"Degree of both polynomials are not same";
				}
			}
			Polynomial add(Polynomial p){
				int m = (highestDegree > p.highestDegree) ? highestDegree : p.highestDegree;
				
				Polynomial result("Add Result",m);
				for(int i=0; i<=m; i++){
					if(i >= size){
						result.ptr[i] = p.ptr[i];
					}
					else if(i >= p.size){
						result.ptr[i] = ptr[i];
					}
					else
						result.ptr[i] = ptr[i] + p.ptr[i];
				}
				return result;
			}
			Polynomial sub(Polynomial p){
				int m = (highestDegree > p.highestDegree) ? highestDegree : p.highestDegree;
				
				Polynomial result("Sub Result",m);
				for(int i=0; i<=m; i++){
					if(i >= size){
						result.ptr[i] = p.ptr[i];
					}
					else if(i >= p.size){
						result.ptr[i] = ptr[i];
					}
					else
						result.ptr[i] = ptr[i] - p.ptr[i];
				}
				return result;
			}
		
		int *multiply(int A[], int B[], int m, int n)
{
   int *prod = new int[m+n-1];
 
   // Initialize the porduct polynomial
   for (int i = 0; i<m+n-1; i++)
     prod[i] = 0;
 
   // Multiply two polynomials term by term
 
   // Take ever term of first polynomial
   for (int i=0; i<m; i++)
   {
     // Multiply the current term of first polynomial
     // with every term of second polynomial.
     for (int j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }
 
   return prod;
}
		
		
			Polynomial multiply(Polynomial p){
				
				int m = size +p.size-2;
				cout<<"highest degree of result is "<<m<<endl;
			//	int mLow = (highestDegree < p.highestDegree) ? highestDegree : p.highestDegree;
				Polynomial result("Mul Result",m);
				cout<<"outer loop degeree "<<highestDegree<<endl;
				cout<<"inner loop degeree "<<p.highestDegree<<endl;

				//int k=0;
				for(int i=0; i<m; i++)
				{
					for(int j=0;j<=p.highestDegree;j++)
					{
							cout<<"inner size is "<<j<<" outer size is "<<i<<endl;
					         result.ptr[i+j] = result.ptr[i+j]+ this->ptr[i]*p.ptr[j];
	
			//	result[k].ptr[i+j]= p.ptr[i] * this->ptr[j];
				cout<<result.ptr[i+j]<<endl;
			
				
				getch();
					}
					
					//result=new Polynomial()
				//	k++;
				}
				
			//	Polynomial final=result[0].add(result[1]);

				return result;
			}	
			
	private:
		int highestDegree;
		int ptr[100];
		int size;	
		string name;
};
int main()
{
	Polynomial p1("P1",2),p2("P2",1);
	int a[3]={6,4,2};
	int b[2]={7,5};
	p1.setPolynomial(a,3);
	p2.setPolynomial(b,2);
	p1.display();		
	cout<<endl;
	p2.display();
	Polynomial p3 = p1.add(p2);
	p3.display();

	Polynomial p4 = p1.sub(p2);
	p4.display();
	cout<<endl<<endl;
	Polynomial p5 = p1.multiply(p2);
	p5.display();
	getch();
	return 0;
}

