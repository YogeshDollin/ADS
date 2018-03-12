/*There are flight paths between cities. If there is a flight between city A and city B then there is
an edge between the cities. The cost of the edge can be the time that flight takes to reach city
B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can
be represented by airport name or name of the city. Use adjacency list representation of the
graph or use adjacency matrix representation of the graph. Justify the storage representation
used.*/
#include <iostream>
#include <string.h>
using namespace std;

class Node{
public:
	string name;
	int time;
	Node(){
		name="";
		time=0;
	}
};

class Graph_representation{
	string name[10]; int arr[10][10];
	int n;
public:
	Graph_representation(){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				arr[i][j]=0;
	}
	void get_citynames();
	void getdata();
	void display_vertices_no();
	void display_data();
};

void Graph_representation::get_citynames(){
	cout<<"\nenter total no. of cities : ";
	cin>>n;
	name[0]="***";
	cout<<"\n\nenter names : ";
	for(int i=1;i<=n;i++){
		cout<<"\n\t"<<i<<"-->";
		cin>>name[i];
	}
}

void Graph_representation::getdata(){
	int source,destination;
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
	}
}

void Graph_representation::display_vertices_no(){
	cout<<"\n\n";
	for(int i=1;i<=n;i++)
		cout<<i<<"-->"<<name[i]<<endl;
}

void Graph_representation::display_data(){
	cout<<"\n\n";
	for(int i=0;i<=n;i++)
		cout<<name[i]<<"\t";

	for(int i=0;i<n;i++){
		cout<<"\n"<<name[i+1]<<"\t";
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<"\t";
	}
}

int main(){

	Graph_representation g;
	int choice;

	g.get_citynames();

	while(1){
		cout<<"\n1.enter citynames \n2.enter graph data \n3.display vertices no. \n4.diaplay data \n5.exit \n\t enter choice : ";
		cin>>choice;
		switch(choice){
			case 1:
					g.get_citynames();
					break;

			case 2:
					g.getdata();
					break;

			case 3:
					g.display_vertices_no();
					break;

			case 4:
					g.display_data();
					break;

			case 5:
					exit(0);

			default :
					cout<<"\n invalid choice";				
		}
	}
	return 0;
}