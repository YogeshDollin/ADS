/*You have a business with several offices; you want to lease phone lines to connect them up
with each other; and the phone company charges different amounts of money to connect
different pairs of cities. You want a set of lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate data structures.*/

#include <iostream>
#define Inf 10000
using namespace std;

class vertex{
public:
	char name;
	int key;
	bool visit;
	vertex(){
		name='-';
		key=Inf;
		visit=0;
	}
};

class Minimum_spanning_tree{
	int mat[5][5],n,parent[5];
	char Name[5]; 
	vertex graph[5]; 
public:
	Minimum_spanning_tree(){
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				mat[i][j]=0;
	}
	void get_vertices_no();
	void getdata();
	void prims_algo();
	void kruskal_algo();
	void display_vertices_no();
	void display();
};

void Minimum_spanning_tree::prims_algo(){

	graph[0].key=0;
	parent[0]=-1;

	for(int count=0;count<n-1;count++){
	int min=Inf ,min_index;

	for(int i=0;i<n;i++)
		if(graph[i].visit==0 && graph[i].key < min)
			min=graph[i].key, min_index=i;

		graph[min_index].visit=1;

		for(int i=0;i < n;i++)
			if(mat[min_index][i] && graph[i].visit==0 && mat[min_index][i] < graph[i].key)
				parent[i]=min_index , graph[i].key=mat[min_index][i] ;
		}

		int sum=0;

		cout<<"\n\nthe minimum cost is : ";
		for(int i=0;i<n;i++)
			sum=sum+graph[i].key;
		cout<<sum;

		cout<<"\n\n path : ";
		for(int i=0;i<n;i++){
			cout<<endl<<Name[parent[i]]<<"-->"<<graph[i].name<<" = "<<graph[i].key;
		}
		cout<<endl;

}

void Minimum_spanning_tree::get_vertices_no(){
	cout<<"\n\nenter total no. of vertices : ";
	cin>>n;

	cout<<"\n\nenter vertex name : ";
	for(int i=0;i<n;i++){
		cout<<i+1<<"-->";
		cin>>Name[i];
		graph[i].name=Name[i];
	}
}

void Minimum_spanning_tree::display_vertices_no(){
	cout<<"\n\nvertices no:"<<endl;
	for(int i=0;i<n;i++){
		cout<<endl<<i+1<<"-->"<<Name[i];
	}
}

void Minimum_spanning_tree::getdata(){
	int source,destination;

	cout<<"\n enter data(enter negative no. to exit)";
	for(int i=0;i<n*(n-1);i++){
		cout<<"\n\n enter source no.: ";
		cin>>source;
		cout<<"\n\n enter destination no.: ";
		cin>>destination;

		if(source <= 0 || destination <= 0)
			break;

		cout<<"\n\nenter weight of edge : ";
		cin>>mat[source-1][destination-1];
		mat[destination-1][source-1]=mat[source-1][destination-1];
	}

}

void Minimum_spanning_tree::display(){
	cout<<"* \t";
	for(int i=0;i<n;i++)
		cout<<Name[i]<<"\t";

	for(int i=0;i<n;i++){
		cout<<endl<<Name[i]<<"\t";
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	Minimum_spanning_tree m;

	
	
	
	
	

	while(1){
		cout<<"\n1.Insert veritces name.\n2.display veritices no.\n3.getdata of graph.\n4.display stored data.";
		cout<<"\n5.prims algorithm.\n6.kruskal's algorithm.\n7.exit";
		int choice;

		cout<<"\n\n enter choice : ";
		cin>>choice;

		switch(choice){
			case 1:
					m.get_vertices_no();
					break;

			case 2:
					m.display_vertices_no();
					break;

			case 3:
					m.getdata();
					break;

			case 4:
					m.display();
					break;

			case 5:
					m.prims_algo();
					break;

			case 6:
			
			case 7:
					exit(0);

			default :
					cout<<"\n\nInvalid choice";		
		}

	}

	return 0;
}
