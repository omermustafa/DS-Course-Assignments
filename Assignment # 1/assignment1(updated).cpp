/*
 * @Assignment # 1 - Determinant, Adjoint, Cofactor
 * @Omer Mustafa
 * F2016-472
*/
#include<iostream>
#include<iomanip>
using namespace std;

float Determinant (float **matrix, int n);
void cofactor (float **matrix, float **holder, int r, int c, int n);
void Adjoint(float **matrix, float **adju, int n);

//determinant Function
float Determinant(float **matrix, int n){
	int sign=1;
    float det=0;
	//holder is for storing cofactors
    float **holder = new float*[n];
    //allocate memory for each row of 2d pointer array
    for (int i = 0; i <n; ++i){
    	holder[i] = new float[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           holder[i][j] = matrix[i][j];
        }
    }
	//	cout << "Inside Determinant: " << n;
	//matrix contains single element
	
	if (n==1){
		return matrix[0][0];
	}
	for (int x =0; x < n; x++){
		cofactor(matrix, holder, 0, x, n);
		det += (sign* matrix[0][x] * Determinant(holder,n-1));
		sign =(-sign);//alternate sign for next term
	}

	//Deleting Memory
	for (int i = 0; i <n; i++){
	    	delete[] holder[i];
	   }
	delete [] holder;
	holder = NULL;

	return det;
}
//function gets the cofactor matrix
void cofactor (float **matrix, float **holder,int r, int c, int n){

	int i=0,j=0;
	//Traversing through each index of matrix
	for(int row = 0; row < n; row++){
		for (int col = 0; col < n; col++){
			//copy into holder, elements that are not in given row/col
			if(row !=r && col != c){
				holder[i][j++] = matrix[row][col];
				//row is filled so move to next row index and reset col index
				if (j== n -1){
					j=0;
					i++;
				}
			}
		}
	}
}//end cofactor

//function gets the adjoint matrix
void Adjoint(float **matrix,float **adju,int n){
	//declare and initalize variables
	int x=0, i=0, sign = 1;

	if (n==1){
		adju[0][0] = 1;
	}
	//array used to store cofactors of matrix
	float **holder = new float*[n];
	//allocate memory for each row of 2d array
	for (i = 0; i <n; ++i){
		holder[i] = new float[n];
	}

	    for (i=0; i<n; i++){
	        for (x=0; x<n; x++){
	            //get cofactor
	            cofactor(matrix, holder, i, x, n);
	            // sign is positive if sum of row and column index equals even.
                if ((i+x)%2==0)
	            	sign=1;
	            else
	            	sign=-1;
	            //transpose of cofactor matrix
	            adju[x][i] = sign*Determinant(holder, n-1);
	        }
	    }
	 //free memory of array, then clear array to prevent memory errors
	for (int i = 0; i <n; i++){
			delete[] holder[i];
	   }
	delete [] holder;
	holder = NULL;
}

int main(){
	int n=3; //Dimension of the matrix
	cin >> n;
    float determinant=0;

    // allocate memory for array of pointers
    float **matrix = new float*[n];
    float **adjoint = new float*[n];
    //allocate memory for each row of 2d pointer arrays
    for (int i = 0; i <n; ++i){
    	matrix[i] = new float[n];
	}
    for (int i = 0; i <n; ++i){
    	adjoint[i] = new float[n];    
	}

    //Input Matrix elements
    cout<<"Enter matrix elements row by row:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           cin>>matrix[i][j];
        }
    }
    
    //printing Matrix
    cout<<"\nInput matrix: ";
    for(int i = 0; i < n; i++){
        cout<<"\n";
        for(int j = 0; j < n; j++)
            cout<<matrix[i][j]<<"\t";
    }

    //finding determinant
    determinant = Determinant(matrix,n);
    cout<<"\n\nDeterminant: "<<determinant << endl;

    //get adjoint of matrix
    Adjoint(matrix,adjoint,n);

    //printing Resultant final matrix
    cout<<"Adjoint matrix of the given Matrix: ";
    for(int i = 0; i < n; i++){
        cout<<"\n";
        for(int j = 0; j < n; j++)
            cout<<adjoint[i][j]<<"\t";
    }
   return 0;
}

