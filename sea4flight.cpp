/*There are flight paths between cities. If there is a flight between city A and city B then there is
an edge between the cities. The cost of the edge can be the time that flight takes to reach city
B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can
be represented by airport name or name of the city. Use adjacency list representation of the
graph or use adjacency matrix representation of the graph. Justify the storage representation
used.*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Node{
public:
	string NAME;
	int cost;
	Node* next;	
};

class Graph_representation{
	string name[10]; int arr[10][10]; Node* Name[10];
	int n;
public:
	Graph_representation(){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				arr[i][j]=0;
	}
	Node* create_node(string,int);
	void get_citynames(int);
	void getdata(int);
	void display_vertices_no(int);
	void display_data(int);
};

Node* Graph_representation::create_node(string ss,int weight){
	Node* p=new(Node);
	p->NAME=ss;
	p->cost=weight;
	p->next=NULL;

	return p;
}

void Graph_representation::get_citynames(int choice){

	cout<<"\nenter total no. of cities : ";
	cin>>n;

	switch(choice){
		case 1:
			name[0]="***";
			cout<<"\n\nenter names : ";
			for(int i=1;i<=n;i++){
			cout<<"\n\t"<<i<<"-->";
			cin>>name[i];					
			}break;

		case 2:
			cout<<"\n\nenter names : ";
			for(int i=0;i<n;i++){
				string s;
				cout<<"\n\t"<<i+1<<"-->";
				cin>>s;
				Name[i]=create_node(s,0);
			}break;
				
	}
}

void Graph_representation::getdata(int choice){

	int source,destination,cost;

	switch(choice){

	case 1:
			{
			cout<<"\n\nenter data(enter negative number to exit) : ";
			for(int i=0;i<n*(n-1);i++){
				cout<<"\n\n\tsource no.: ";
				cin>>source;
				cout<<"\n\t\t\t destination no.: ";
				cin>>destination;

				if(source<=0 || destination<=0)
					break;
				cout<<"\n\n\tenter cost of time : ";
				cin>>arr[source-1][destination-1];
			}break;
		}
	case 2:	
		{
			cout<<"\n\nenter data (enter negative numbers to exit) : ";
			for(int i=0;i<n*(n-1);i++){
				cout<<"\n\n\tsource no.: ";
				cin>>source;
				cout<<"\n\t\t\t destination no.: ";
				cin>>destination;
				
				if(source<=0 || destination<=0)
					break;
				cout<<"\n\n\t enter cost : ";
				cin>>cost;
				
				Node* temp=Name[source-1];
				while(temp->next!=NULL)
				temp=temp->next;
				
				temp->next=create_node(Name[destination-1]->NAME,cost);			
						
			}
		}

	}
}

void Graph_representation::display_vertices_no(int choice){

switch(choice){
	case 1:
		cout<<"\n\n";
		for(int i=1;i<=n;i++)
		cout<<i<<"-->"<<name[i]<<endl;
		break;
		
	case 2:	
		cout<<"\n\n";
		for(int i=0;i<n;i++)
		cout<<i+1<<"-->"<<Name[i]->NAME<<endl;
		break;
	}
}	

void Graph_representation::display_data(int choice){

switch(choice){
	case 1: {
		cout<<"\n\n";
		for(int i=0;i<=n;i++)
		cout<<name[i]<<"\t";
	
		for(int i=0;i<n;i++){
			cout<<"\n"<<name[i+1]<<"\t";
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<"\t";
			}
		}break;
		
	case 2:{
		cout<<"\n\n";
		for(int i=0;i<n;i++){
			cout<<endl;
			Node *temp=Name[i];
			while(temp!=NULL){
			cout<<temp->NAME<<"--->";
			temp=temp->next;
			}
		}
	}break;		
		
	}
}
int main(){

	Graph_representation g;
	int choice,choice1;
	while(1){
	cout<<"\n\n1.adjacency matrix \n2.adjacency list 3.exit\n\nenter choice : ";
	cin>>choice1;
	
	if(choice1==3)
	exit(0);

	g.get_citynames(choice1);
	while(1){
		cout<<"\n1.enter citynames \n2.enter graph data \n3.display vertices no. \n4.diaplay data \n5.another repersentation \n6.exit \n\t enter choice : ";
		cin>>choice;
		switch(choice){
			case 1:
					g.get_citynames(choice1);
					break;

			case 2:
					g.getdata(choice1);
					break;

			case 3:
					g.display_vertices_no(choice1);
					break;

			case 4:
					g.display_data(choice1);
					break;
			
			case 5:
					break;

			case 6:
					exit(0);

			default :
					cout<<"\n invalid choice";				
		}
		}
			
	}
	return 0;
}
