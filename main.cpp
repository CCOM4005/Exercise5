#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int info;
    node *next;
}; 

int buscar(node * , int);
void otherprocessList(node *&, node *&);
void processList( int&, node *&, node *&, node *&, node *&,node *& ); 
void print( node *&, node *&, node *&,node *&, node *&, node *&);

int main ()

{ 
    node *start,  *nuevo, *fin, *p;
    node *start2,  *nuevo2, *fin2, *p2;
    node *start3,  *nuevo3, *fin3, *p3;
    int cant, cant2, valor, valor2,cantTotal;

    
    start = NULL;
    start2 = NULL; 
    start3 = NULL; 
    nuevo = NULL;
    nuevo2 = NULL; 
    nuevo3 = NULL;
    fin = NULL;
    fin2 = NULL;
    fin3 = NULL; 
    	
	cout<<"Entre la cantidad de elementos de la lista uno: ";
	cin>>cant;
	

    for (int i = 0; i < cant; i++)
    {
        cout << "Indique el valor de la lista: ";
        cin >> valor;
        nuevo = new node;
        nuevo -> info = valor;
        nuevo -> next = NULL;

        if (start == NULL)
        {
                start = nuevo;
                fin = nuevo;
        }
        else 
        {
            fin -> next = nuevo;
            fin = nuevo;
        }
    }
    cout<<"Entre la cantidad de elementos de la lista dos: ";
	cin>>cant2;
    for (int i = 0; i < cant2; i++)
    {
        cout << "Indique el valor de la lista: ";
        cin >> valor2;
        nuevo2 = new node;
        nuevo2 -> info = valor2;
        nuevo2 -> next = NULL;

        if (start2 == NULL)
        {
                start2 = nuevo2;
                fin2 = nuevo2;
        }
        else 
        {
            fin2 -> next = nuevo2;
            fin2 = nuevo2;
        }
    }
    cantTotal=cant+cant2;
    
  otherprocessList(fin, start2 );
  processList(cantTotal, start,p, nuevo3,start3,fin3);
 	print( start,start2, start3,p,p2,p3);
  
    system ("pause");
return 0;
}

void otherprocessList(node *&fin, node *&start2)
{
     fin->next=start2;
}
void processList(int &cantTotal, node *&start,node *&p, node *&list3, node *&start3, node *&fin3)
{
     int randNum=0;
     for(int i=0;i<cantTotal; i++)
     {
        p = start;
        list3=NULL;
    	randNum= rand()% cantTotal + 1;
        for(int j=0;j<randNum-1; j++)
        {
        	p = p -> next;
        } 
        
        list3 = new node;
        list3 -> info = p->info;
		list3 -> next = NULL;
		
		
		if (start3 == NULL)
        {
            start3 = list3;
            fin3 = list3;
       	}
       	
       	else 
      	{
         	fin3 -> next = list3;
        	fin3 = list3;
      	}  
						
      
      }
}
void print(node *&start, node *&start2, node *&start3, node *&p, node *&p2, node *&p3)
{

    cout<<"\nElementos de la nueva lista random: " ;
    p3= start3;
    while(p3 !=NULL)
    {
             cout<< p3->info<< " ";
             p3= p3->next;
     }
    cout<<endl<<endl;
     
}
