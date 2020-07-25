#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
    public:
		Node(): cof{0}, pow{0}
		{
			Next=NULL;
		}
		Node(int c,int p): cof{c}, pow{p}
		{
			Next=NULL;
		} 
		void setcof(int c)               
		{
			cof=c;
		}
		void setpow(int p)
		{
			pow=p;
		}
		int getcof()
		{
			return cof;
		}
		int getpow()
		{
			return pow;
		}		
		void setNext(Node *n)
		{
			Next=n;
		}
		Node *getNext()
		{
			return Next;
		}
		void display()
		{
			cout<<cof <<"x^"<< pow;
		}   
  private:
      int cof,pow;
      Node *Next;
 
};
   class Polynomial
   {
         private:
                 Node *head;
                 int Degree;
                 
         public:
         Polynomial()
         {
                     head=NULL;
                     Degree=0;
         }
         Node *gethead()
         {
              return head;
              }
           void sethead(Node *n)
           {
                head=n;
                }  
         void setDegree(int d)
         {
             Degree=d;
         }
          int getDegree()
          {
              return Degree;
          }   
         void insert(int cof,int pow)
         {
              Node *n=new Node(cof,pow);
              if(head==NULL)
              {
                      head=n; 
                      Degree=n->getpow();    
              }
              else
              {
                  Node *curr=head;
                  Node *prev=NULL;
                  while(curr!=NULL && curr->getpow()>pow)
                  {
                  prev=curr;
                  curr=curr->getNext();
                  }
                  if(prev==NULL)
                  {
                      head=n;
                      n->setNext(curr); 
                      Degree=n->getpow();       
                  }
                  else if(curr==NULL)
                  {
                       prev->setNext(n);
                  }
                  else if(curr!=NULL && prev!=NULL)
                  {
                     prev->setNext(n);
                     n->setNext(curr);
                       
                  }
              }
              
         }
         void Delete()
         {
          if(head==NULL)
          {
           cout<<"List is already Empty"<<endl;
          }
           else
           {
            Node *temp=head;
            Node *prev=NULL;
            while(temp->getNext()!=NULL)
            {
            prev=temp;
                 temp=temp->getNext();                 
            }
            prev->setNext(NULL);
              temp->setNext(NULL);
              delete temp;
              temp=NULL;
               
               
           }                 
         }
          Polynomial subtraction(Polynomial p)
         {
				Polynomial result;
				Node *temp1=head;
				Node *temp2=p.gethead();
				while(temp1!=NULL || temp2!=NULL)
				{
                   if(temp1==NULL)
                   {
						int cof=temp2->getcof();
						int pow=temp2->getpow(); 
						result.insert(cof,pow);
						temp2=temp2->getNext();
                   }  
                  else if(temp2==NULL)
                  {
						int cof=temp1->getcof();
						int pow=temp1->getpow();						
						result.insert(cof,pow);
						temp1=temp1->getNext();
               	  } 
                   else if(temp1->getpow()==temp2->getpow())
                   {
						int cof=temp1->getcof()-temp2->getcof();
						int pow=temp1->getpow();
              
						result.insert(cof,pow);
						temp1=temp1->getNext();
						temp2=temp2->getNext();
                   } 
                   else if(temp1->getpow()>temp2->getpow()) 
                   {
                        int cof=temp1->getcof();
						int pow=temp1->getpow();                              
						result.insert(cof,pow);
						temp1=temp1->getNext();
						
                   }
                    else if(temp2->getpow()>temp1->getpow())              
					{ 
						int cof=temp2->getcof();
						int pow=temp2->getpow();
						
						result.insert(cof,pow);
						temp2=temp2->getNext();
					}
					
					}
					return result;
}
            Polynomial add(Polynomial p){
                Polynomial result;
                Node * temp1 = head, * temp2 = p.head;
                while(temp1 != NULL || temp2 != NULL){
                    if(temp1->getpow() == temp2 ->getpow()) {
                        int c = temp1->getcof() + temp2->getcof();
                        result.insert(c, temp1->getpow());
                        temp1 = temp1->getNext();
                        temp2 = temp2->getNext();
                    }
                    else if(temp1->getpow() > temp2->getpow()){
                        int c = temp1->getcof();
                        result.insert(c, temp1->getpow());
                        temp1 = temp1->getNext();
                    }
                    else if(temp2->getpow() > temp1->getpow()){
                        int c = temp2->getcof();
                        result.insert(c, temp2->getpow());
                        temp2 = temp2->getNext();
                    }
                }
                if(temp1 != NULL){
                    while(temp1 != NULL){
                        result.insert(temp1->getcof(),temp1->getpow());
                        temp1 = temp1->getNext();
                    }
                }
                else if(temp2 != NULL){
                    while(temp2 != NULL){
                        result.insert(temp2->getcof(),temp2->getpow());
                        temp2 = temp2->getNext();
                    }
                }

                return result;
            }
			void display()
			{
				Node *temp=head;
				while(temp!=NULL)
				{
					if(temp->getNext()!=NULL)
					{
						temp->display();
						cout<<" + ";               
					}
					else
					{
						temp->display();
					}
			
			
				temp=temp->getNext();
			}
			
		}
					
	};   
int main()
{
		Polynomial p1,p2;
		cout << "Assignment # 2\nPolynomials\n"<<endl;
		cout << "1st Polynomial\n";
		p1.insert(1,2);
		p1.insert(2,2);
		p1.insert(3,2);
		p1.insert(5,2);
		p1.display();
		cout << endl << endl;
		cout << "2nd Polynomial\n";
		p2.insert(3,3);
		p2.insert(2,2);
		p2.insert(1,4);
		p2.insert(4,0);
		p2.display();
		

		Polynomial res = p1.subtraction(p2);
		cout << "\n\nSubtraction: \n";
		res.display();
		
		Polynomial res2 = p1.add(p2);
		cout << "\nAddition\n";
		res2.display();
		         
getch();
return 0;
}

