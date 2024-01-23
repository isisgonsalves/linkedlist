#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;


struct Node {

   int data;

   Node * next;

};


Node * createNode (int n) {

   Node * newNode; 

   

   newNode = (Node *) malloc (sizeof (Node));

   newNode->data = n;

   newNode->next = NULL;

   return newNode;

}


Node * insertAtHead (Node * top, int n) {

   Node * newNode;

   newNode = createNode (n);

   newNode->next = top; 

   top = newNode;

   return top;      

}   


int size (Node * top) {

   Node * curr;

   int numNodes = 0;

   

   curr = top;

   while (curr != NULL) {

      numNodes = numNodes + 1;

      curr = curr->next;

   }

   return numNodes;

}


void printList (Node * top) {

   Node * curr;

   int count = 0;

   if (top == NULL) {

      cout << "List empty." <<endl;

      return;

   }   

   curr = top;

   while (curr != NULL) {

      cout << curr -> data << " ";

      curr = curr->next;

   }

   cout << "\n";

}


void printOut (Node * top, ofstream &out ) {

//to print to output file

   Node * curr;

   int count = 0;

   if (top == NULL) {

      out << "List empty." <<endl;
   }   

   curr = top;

   while (curr != NULL) {

      out << curr -> data << " ";

      curr = curr->next;

   }

   out << "\n";

}


Node *reverse (Node *top) {

     Node *curr = top;

     Node *advCurr = NULL;

     while (curr != NULL) {

        advCurr = curr->next;

        if (top == curr) 

           top->next = NULL;      

        else { curr->next = top;

               top = curr;

             }

        curr = advCurr;

     } //while      

     return top;

}


Node *listAddition(Node *listA, Node * listB) {
	 
	 //To add the large integers
	 
    int carry = 0;
    
    Node *curr, *sumlist, *tempNode;   

    sumlist=NULL;

    while(listA != NULL || listB != NULL) {
      
		  int sum = 0;
		  
	      if(listA != NULL) {
	        sum += listA->data;
	        listA = listA->next;
	      }
	      if(listB != NULL) {
	        sum += listB->data;
	        listB = listB->next;
	      }
	      
	        sum += carry;
	
			carry = sum / 10;
			sum = (sum % 10);
				      
			tempNode= createNode(sum);
	      
	      if(sumlist == NULL)
	        	sumlist=tempNode;
	        else
	        	curr->next =tempNode;
	        
	        curr= tempNode;
	
	    if(carry > 0) {
	      curr->next = createNode(carry);
	    }
    
	}
	
    return sumlist;
  
}


int main() {

  	ifstream in; //declare input file
	ofstream out; //declare output file 


   Node *listA, *listB, *listOrderA, *listOrderB, *sumlistOrder, *res;
   
   char num;
   int diff;
   
	listA = NULL;
	listB = NULL;
	listOrderA= NULL;
	listOrderB= NULL;
	sumlistOrder= NULL;

	in.open("input.txt");
	out.open("output.txt");
	
	
	if (!in.is_open()) {
		cout << "\nERROR: File cannot be found...Try again\n";
		return 0;
	}
	
		in>>noskipws;
		
		in>>num;
		
		
		while(num != '-'){
					
					listA = NULL;
					listB = NULL;
					
				while(num != ' '){
				
					listA= insertAtHead(listA, num-'0');
			
					in>>num;
				}
				
				while(num == ' '){
				
					in>>num;
					
					
					while (num != '\n'){
					
						listB=insertAtHead(listB, num-'0');
						
						in>>num;
					}
				
				
				//find size of lists
				int sizeA=size(listA);
				int sizeB=size(listB);
				
			
				//find difference in sizes
				if(sizeA > sizeB)
					 diff=sizeA-sizeB;
				else
					 diff=sizeB-sizeA;
					 
				//catch the sumList from add function
			  	res=listAddition(listA,listB);
			  	
			  	//Reverse integer and sum lists for printing
				listOrderA= reverse(listA);
			  	listOrderB= reverse(listB);
			  	sumlistOrder= reverse(res);
			  	
			  	//size of sum list
			  	int sizeSum= size(sumlistOrder);
			  	
			  	   //if else statements for formatting purposes
				  if(sizeSum > sizeB){		  		
				  		cout<<setw(diff*2+3);
				  		out<<setw(diff*2+3);
			  		}
			  		else
					  if(sizeSum == sizeB){
							cout<<setw(diff*2+1);
						  	out<<setw(diff*2+1);
						} 
					
				  	printList (listOrderA);
				  	printOut (listOrderA, out);
				  	
				  	cout<<setw(sizeB*2+3)<<"+\n";
				  	out<<setw(sizeB*2+3)<<"+\n";
				  	
				  	if(sizeSum > sizeB){
					  	cout<<setw(3);
					  	out<<setw(3);
					}
					else 
						if(sizeSum == sizeB){
							cout<<setw(0);
					  		out<<setw(0);
						}
					
				  	printList(listOrderB);
				  	printOut (listOrderB,out);
				  
					for (int i=0; i<sizeSum*2;i++){
						cout<<"=";
						out<<"=";
					}
					
				  	cout<<endl;
				  	out<<endl;
				  	
				  	printList(sumlistOrder);
				  	printOut(sumlistOrder,out);
				  	
				  	cout<<endl;
				  	out<<endl;
				
				  	for (int c=0; c<sizeSum*2;c++){
						cout<<"=";
						out<<"=";
					}
					
				  	cout<<endl<<endl<<endl;
				  	out<<endl<<endl<<endl;

				}
			
				in>>num;
					
			}


   return 0;

}

