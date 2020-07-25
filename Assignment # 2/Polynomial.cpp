#include<iostream>
#include<conio.h>
using namespace std;

class PolyNode
{
    public:
            PolyNode(){
                coef = exp = 0;
                next = NULL;
            }
            PolyNode(int c,int e){
                coef = c;
                exp = e;
                next = NULL;
            }
            void setCoef(int c){
                coef = c;
            }
            void setExp(int e){
                exp = e;
            }
            void setNext(PolyNode *n){
                next = n;
            }
            int getCoef(){
                return coef;
            }
            int getExp(){
                return exp;
            }
            PolyNode* getNext(){
                return next;
            }
            void display(){
                cout<<coef<<" X ^ "<<exp;
                if(exp > 0){
                	cout <<" + ";
				}
            }
            void displaysub(){
                cout<<coef<<" X ^ "<<exp;
                if(exp > 0){
                	cout <<" ";
				}
            }
    private :
        int coef,exp;
        PolyNode *next;

};

class Polynomial
{
    public:
            Polynomial(){
                head = NULL;
                size = 0;
            }
            void insert(int c,int e){
                PolyNode *n = new PolyNode(c,e);

                if(head == NULL){
                    head = n;
                }
                else{
                  PolyNode * prev = NULL, *curr = head;

                  while(curr != NULL && curr->getExp() > e){
                       prev = curr;
                       curr = curr->getNext();
                  }
                  if(prev == NULL){ // Insert at Begining
                    n->setNext(curr);
                    head = n;
                  }
                  else if( prev != NULL && curr == NULL){ // insertion at end

                        prev->setNext(n);
                  }
                  else if( prev != NULL && curr != NULL){ // insertion at Middle
                         n->setNext(curr);
                         prev->setNext(n);
                  }
                }
                size++;
            }

            void display(){
                PolyNode * temp = head;

                while(temp != NULL){
                    temp->display();
                    temp = temp->getNext();
                }
            }
            void displaysub(){
                PolyNode * temp = head;

                while(temp != NULL){
                    temp->displaysub();
                    temp = temp->getNext();
                }
            }
            Polynomial add(Polynomial p){
                Polynomial result;
                PolyNode * temp1 = head, * temp2 = p.head;
                while(temp1 != NULL || temp2 != NULL){
                    if(temp1->getExp() == temp2 ->getExp()) {
                        int c = temp1->getCoef() + temp2->getCoef();
                        result.insert(c, temp1->getExp());
                        temp1 = temp1->getNext();
                        temp2 = temp2->getNext();
                    }
                    else if(temp1->getExp() > temp2->getExp()){
                        int c = temp1->getCoef();
                        result.insert(c, temp1->getExp());
                        temp1 = temp1->getNext();
                    }
                    else if(temp2->getExp() > temp1->getExp()){
                        int c = temp2->getCoef();
                        result.insert(c, temp2->getExp());
                        temp2 = temp2->getNext();
                    }
                }
                if(temp1 != NULL){
                    while(temp1 != NULL){
                        result.insert(temp1->getCoef(),temp1->getExp());
                        temp1 = temp1->getNext();
                    }
                }
                else if(temp2 != NULL){
                    while(temp2 != NULL){
                        result.insert(temp2->getCoef(),temp2->getExp());
                        temp2 = temp2->getNext();
                    }
                }

                return result;
            }
         Polynomial sub(Polynomial p){
                Polynomial result;
                PolyNode * temp1 = head, * temp2 = p.head;
                while(temp1 != NULL || temp2 != NULL){
                    if(temp1->getExp() == temp2 ->getExp()) {
                        int c = temp1->getCoef() - temp2->getCoef();
                        result.insert(c, temp1->getExp());
                        temp1 = temp1->getNext();
                        temp2 = temp2->getNext();
                    }
                    else if(temp1->getExp() > temp2->getExp()){
                        int c = temp1->getCoef();
                        result.insert(c, temp1->getExp());
                        temp1 = temp1->getNext();
                    }
                    else if(temp2->getExp() > temp1->getExp()){
                        int c = temp2->getCoef();
                        result.insert(c, temp2->getExp());
                        temp2 = temp2->getNext();
                    }
                }
                if(temp1 != NULL){
                    while(temp1 != NULL){
                        result.insert(temp1->getCoef(),temp1->getExp());
                        temp1 = temp1->getNext();
                    }
                }
                else if(temp2 != NULL){
                    while(temp2 != NULL){
                        result.insert(temp2->getCoef(),temp2->getExp());
                        temp2 = temp2->getNext();
                    }
                }

                return result;
            }
    private:

        PolyNode * head;
        int size;
};
