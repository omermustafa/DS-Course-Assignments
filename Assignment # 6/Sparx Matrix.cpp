#include<iostream>
#include<conio.h>
#include <unistd.h>
using namespace std;

class GNode
{
public:
    GNode(int r=0,int c=0,int v=0)
    {
        row = r;
        col = c;
        val = v;
        right = down = NULL;
    }
    void setGNode(int r,int c,int v)
    {
        row = r;
        col = c;
        val = v;
    }
    void setRow(int r){
        row = r;
    }
    void setCol(int c){
        col = c;
    }
    void setValue(int v){
        val = v;
    }
    int getRow(){
        return row;
    }
    int getCol(){
        return col;
    }
    int getValue(){
        return val;
    }
    void display(){
        cout << val << "\t";
    }
    GNode * getRight(){
        return right;
    }
    GNode * getDown(){
        return down;
    }
    void setRight(GNode *r){
        right = r;
    }
    void setDown(GNode *r){
        down = r;
    }
private:
    int row,col,val;
    GNode * right, * down;
};

class GList
{
public:
    GList(){
        head = new GNode();
        row = 0;
        col = 0;
    }
    GList(int r,int c){
        head = new GNode(r,c);
        row = r;
        col = c;
        insertRowHeads();
        insertColHeads();
    }
    void insertRowHeads()
    {
        int i = 1;
        GNode* temp = head;
        while(i <= row){
            GNode * n = new GNode(i);
            temp->setDown(n);
            temp = temp->getDown();            
            i++;
        }
        temp->setDown(head);

    }
    void insertColHeads()
    {
        int i = 1;
        GNode* temp = head;
        while(i <= col){
            GNode * n = new GNode(i);
            temp->setRight(n);
            temp = temp->getRight();
            i++;
        }
        temp->setRight(head);
    }

    void insert(int r,int c, int val){
        GNode *node = new GNode(r,c,val);
        GNode * rowHead  = getRowHead(r);
        GNode * colHead  = getColHead(c);
        insertRowWise(rowHead,node);
//        insertColWise(colHead, node);
    }
    void insertRowWise(GNode* rh, GNode *n) {

         GNode * temp = rh;
            if(temp == NULL){
                temp = n;
            }
            else{
                while( temp->getRight() != NULL && temp->getCol() < n->getCol()){
                        temp = temp->getRight();
                }
              temp->setRight(n);
            }
//        cout<<"Row Wise Insertion Successfull "<<endl;
    }
    void insertColWise(GNode* dh, GNode *n) {

        GNode * temp = dh;
        if(temp == NULL){
            temp = n;
        }
        else{
            while( temp->getDown() != NULL && temp->getRow() < n->getRow()){
                temp = temp->getDown();
            }
            temp->setDown(n);
        }
//        cout<<"Column Wise Insertion Successfull "<<endl;
    }
    GNode* getRowHead(int r){
        GNode * temp = head;
        int i = 1;
        while (i <=  r){
            temp = temp->getDown();
		    i++;
        }
        return temp;
    }
    GNode* getColHead(int c){
        GNode * temp = head;
        int i = 1;
        while (i <=  c){
            temp = temp->getRight();
            i++;
        }
        return temp;
    }
    void display(){
        int i = 1;
        while( i <= row){
            GNode * tempRowHead = getRowHead(i);
            GNode * tempColHead = getColHead(i);
            displayRow(tempRowHead);
            cout<<endl;
            i++;
        }
    }

    void displayRow(GNode * temp){
		int counter=1;
        while(temp != NULL){
            if( temp->getRight() == NULL)
			{
					cout << "0\t"; 
			} 
            temp->display();
	        temp = temp->getRight();
        	counter++;
		}
    }
    void displayCol(GNode * temp){
        while(temp != NULL){
            temp->display();
            temp = temp->getDown();
        }
    }
private:
    GNode * head;
    int row,col;
};
int main()
{
	int sparseMatrix[4][5] = 
	{	{0,0,3,0,4},
		{0,0,5,7,0},
		{0,0,0,0,0},
		{0,2,6,0,0}		};
	
	
	int  size = 0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++){
			if(sparseMatrix[i][j] != 0){
				size++;
			}			
		}
	}
	
	int k=0;
	int compactMatrix[3][size];

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++){
			if(sparseMatrix[i][j] != 0){
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = sparseMatrix[i][j];
				k++;
			}			
		}
	}	
	cout << "Conversion of Sparx Matrix into compact using Array\n";
	cout << "First Row Represents row\n";
	cout << "Second Row Represents Column\n";
	cout << "Third Row Represents Value correspending to row & col\n\n";
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<size; j++){
			cout << compactMatrix[i][j] << " ";
		}
			cout << endl;
	}

//Inserting into Orthogonal List
	GList list(3,size);
	k=0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<size; j++){
			if(sparseMatrix[i][j] != 0){
				
			list.insert(1,k,i);
			list.insert(2,k,j);
			list.insert(3,k,sparseMatrix[i][j]);
			k++;
		}
			}
	}	
	cout << "\n\nConversion of Sparx Matrix into compact using Orthogonal List\n";
	cout << "First Row Represents row\n";
	cout << "Second Row Represents Column\n";
	cout << "Third Row Represents Value correspending to row & col\n\n";
	list.display();


	getch();
    return 0;
}



