#include<iostream>
#include<conio.h>
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
    //        cout<<i<<" Row Head Created: "<< temp <<endl;
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
        insertColWise(colHead, node);
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
    GList list(4,7);
    list.insert(1,1,10);
    list.insert(1,2,11);
    list.insert(1,3,12);
    list.insert(1,4,15);
  	list.insert(1,6,2);
    list.insert(2,1,13);
    list.insert(2,4,16);
	list.insert(4,2,22);	
	list.insert(1,7,111);
	list.insert(4,7,28);	
	cout << "Displaying Matrix\n\n";
	list.display();
	getch();
    return 0;
}



