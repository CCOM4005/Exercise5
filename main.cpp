#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int info;
    node *next;
}; 

void mergeLists(node *&, node *&);
void createRandList( int&, node *&, node *&, node *&, node *&,node *& ); 
void print( node *&, node *&, node *&,node *&, node *&, node *&);

int main ()

{ 
    node *head,  *newNode, *tail, *current;
    node *head2,  *newNode2, *tail2, *current2;
    node *head3,  *newNode3, *tail3, *current3;
    int cant, cant2, value, value2,cantTotal;

    
    head = head2 = head3 = NULL; 
    newNode = newNode2 = newNode3 = NULL;
    tail = tail2 = tail3 = NULL; 
    	
	cout<<"Entre la cantidad de elementos de la lista uno: ";
	cin>>cant;
	

    for (int i = 0; i < cant; i++)
    {
        cout << "Indique el valor del numero entero: ";
        cin >> value;
        newNode = new node;
        newNode->info = value;
        newNode->next = NULL;

        if (head == NULL)
        {
                head = newNode;
                tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout<<"Entre la cantidad de elementos de la lista dos: ";
	cin>>cant2;
    for (int i = 0; i < cant2; i++)
    {
        cout << "Indique el valor del numero entero: ";
        cin >> value2;
        newNode2 = new node;
        newNode2->info = value2;
        newNode2->next = NULL;

        if (head2 == NULL)
        {
                head2 = newNode2;
                tail2 = newNode2;
        }
        else 
        {
            tail2->next = newNode2;
            tail2 = newNode2;
        }
    }
    cantTotal=cant+cant2;
    
  mergeLists(tail, head2 );
  createRandList(cantTotal, head,current, newNode3,head3,tail3);
  print( head,head2, head3,current,current2,current3);
  
    system ("pause");
return 0;
}

void mergeLists(node *&tail, node *&head2)
{
     tail->next=head2;
}
void createRandList(int &cantTotal, node *&head,node *&current, node *&list3, node *&head3, node *&tail3)
{
     int randNum=0;
     for(int i=0;i<cantTotal; i++)
     {
        current = head;
        list3=NULL;
        srand(time_t(NULL));
    	randNum= rand()% cantTotal + 1;
        for(int j=0;j<randNum-1; j++)
        {
        	current = current -> next;
        } 
        
        list3 = new node;
        list3 -> info = current->info;
		list3 -> next = NULL;
		
		
		if (head3 == NULL)
        {
            head3 = list3;
            tail3 = list3;
       	}
       	
       	else 
      	{
         	tail3 -> next = list3;
        	tail3 = list3;
      	}  
						
      
      }
}
void print(node *&head, node *&head2, node *&head3, node *&current, node *&current2, node *&current3)
{

    cout<<"\nElementos de la nueva lista random: " ;
    current3 = head3;
    while(current3 !=NULL)
    {
             cout<< current3->info<< " ";
             current3= current3->next;
     }
    cout<<endl<<endl;
     
}
