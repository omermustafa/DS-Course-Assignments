/*
 * @Assignment # 4 - Data Structures
 * @Omer Mustafa
 * F2016-472
*/

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class Node
{
    public:
        Node(){
            data1 = "";
            data2 = 0;
            next1 = next2 = NULL;
        }
        Node(string d1, int d2){
            data1 = d1;
            data2 = d2;
            next1 = next2 = NULL;
        }
        void display(){
            cout << "Student name: " << data1 << "\t\t"
                    "Student data: " << data2 << endl;
        }
        char getdata1(){
            return data1[0];
        }
        int getdata2(){
            return data2;
        }
        Node* getNext1(){
            return next1;
        }
        Node* getNext2(){
            return next2;
        }
        void setNext1(Node* n){
            next1 = n;
        }
        void setNext2(Node* n){
            next2 = n;
        }
        void setData1(int d){
            data1 = d;
        }
        void setData2(int d){
            data2 = d;
        }
    private:
        //data1 is used to store names
        //data2 is used to store arbitrary numbers
        string data1;
        int data2;
        //next1 pointer is used to link student names in ascending order
        //next2 pointer is used to link student data in ascending order
        Node * next1, * next2;

};

class List{

    public:
          List(){
                first1 = first2 = NULL;
                size = 0;
          }
         void displayData2(){
            Node * temp = first2;

            while(temp != NULL){
                    temp->display();
                    temp = temp->getNext2();
            }
            cout<<endl<<"Size of List = "<<size<<endl;
          }
         void displayData1(){
            Node * temp = first1;

            while(temp != NULL){
                    temp->display();
                    temp = temp->getNext1();
            }
            cout<<endl<<"Size of List = "<<size<<endl;
          }
         bool search(int d){
            Node * temp = first2;
            bool flag = false;
            while(temp != NULL){
                if(d == temp->getdata2() ){
                    flag = true;
                }
                temp = temp->getNext2();
            }
            return flag;
          }
         int getSize(){
            return size;
          }
         void insertForFirstTime(Node *n){
            first2 = n;
        }
         void insertBeg(Node * n){
            n->setNext2(first2);
            first2 = n;
        }
         void insertMid(Node *n,Node * prev, Node *curr){
                n->setNext2(curr);
                prev->setNext2(n);
        }
         void insertEnd(Node*n,Node *prev){
            prev->setNext2(n);
        }
         void insert(string d1, int d2){
            Node *n = new Node(d1, d2);
            size++;

        //Traversing & linking with respect to numbers (Ascending order)
            if(first2 == NULL)
                insertForFirstTime(n);
            else{
                Node * prev = NULL;
                Node * curr = first2;
                while(curr->getdata2() < d2 && curr->getNext2() != NULL){
                    prev = curr;
                    curr = curr->getNext2();
                }
                if(prev == NULL){
                    insertBeg(n);
                }
                else if(curr->getNext2() == NULL){
                    insertEnd(n,curr);
                }
                else if(prev != NULL && curr != NULL){
                    insertMid(n,prev,curr);
                }

        //Traversing & linking with respect to string (Ascending order)
                if(first1 == NULL)
                    first1 = n;
                else{
                    Node * prev = NULL;
                    Node * curr = first1;
                    while(curr->getdata1() < d1[0] && curr->getNext1() != NULL){
                        prev = curr;
                        curr = curr->getNext1();
                    }
                    if(prev == NULL){
                        //Insert at beginning
                        n->setNext1(first1);
                        first1 = n;
                    }
                    else if(curr->getNext1() == NULL){
                        //Insert at the End
                        prev->setNext1(n);
                    }
                    else if(prev != NULL && curr != NULL){
                        //Insert at the mid
                        n->setNext1(curr);
                        prev->setNext1(n);
                    }
            }
          }
        }
    private:
        Node * first1, * first2;
        int size;
};

int main(){

    List list;
    list.insert("Omer",10);
    list.insert("Asad",5);
    list.insert("Zubair", 14);
    list.insert("Muzzamil",20);
    list.insert("Abdullah",1);
    list.insert("Hassan",5);
    list.insert("Shazib",26);
    list.insert("Mubashar",2);
    list.insert("Husnain",11);
    cout << "Displaying using the first2 pointer i-e Numeric Ascending Order\n\n";
    list.displayData2();

    cout << "\n\nDisplaying using the first1 pointer i-e Name in Ascending Order\n\n";
    list.displayData1();



//Searching from the linked list
//    bool a = list.search(10);
//    if(a == true) cout<<"Element Found\n";
//    else cout<<"Element Not Found\n";

    getch();
    return 0;
}
