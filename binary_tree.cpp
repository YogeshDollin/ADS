/*Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i.Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv.Change a tree so that the roles of the left and right pointers are swapped at
every node
v.Search a value*/


#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

class Node{
public:
	int data;
	Node *right,*left;
};

class BST{
	stack <Node*> Stack;
public:
	Node* create_node();
	Node* insert(Node*,int);
	void display(Node*);
	void minimum_value(Node*);
	void search_value(Node*,int);
	int height(Node*);
	void swap(Node*);
};

int BST::height(Node* node){
	if(node==NULL)
		return 0;
	else{
		int depth_left=height(node->left)+1;
		int depth_right=height(node->right)+1;
		int max_depth=(depth_right>depth_left?depth_right:depth_right==depth_left?depth_left:depth_left);
		return max_depth;
	}
}

void BST::swap(Node* root){
	if(root==NULL){
		return;
	}

	swap(root->left);
	swap(root->right);
	Node* temp=root->left;
		root->left=root->right;
		root->right=temp;
}

void BST::minimum_value(Node* root){
	Node* temp=root;
	if(root==NULL){
		cout<<"\n empty tree";
		return;
	}
	while(temp->left!=NULL)
		temp=temp->left;
	cout<<"\n Minimum value : "<<temp->data;

}

void BST::search_value(Node* root,int key){
	if(root==NULL){
		cout<<"\n empty tree";
		return;
	}
	Node *trav=root,*trav_follower=root;
	bool flag=0;
	int count=0;
	while(trav!=NULL){
		if(trav->data==key){
			flag=1;
			cout<<"\n data found at "<<count<<" level";
			break;
		}
		else if(trav->data > key){
			trav=trav->left;
			count++;
		}
		else{
			trav=trav->right;
			count++;
		}
	}
	if(flag==0)
		cout<<"\n data not found";
}

Node* BST::create_node(){
	Node* p=new(Node);
	cin>>p->data;
	p->right=NULL;
	p->left=NULL;
	return p;
}

Node* BST::insert(Node* root,int n){
	for(int i=0;i<n;i++){
		Node *trav=root,*trav_follower=root;
		Node* temp=create_node();
		if(root==NULL)
			root=temp;
		else{
			while(trav!=NULL){
				if(temp->data>trav->data){
					trav_follower=trav;
					trav=trav->right;
				}
				else if(temp->data<trav->data){
					trav_follower=trav;
					trav=trav->left;
				}	
			}
			if(temp->data > trav_follower->data)
				trav_follower->right=temp;
			else if(temp->data < trav_follower->data)
				trav_follower->left=temp;
		}
	}
	return root;
}

void BST::display(Node* root){
	/*if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL){
		cout<<root->data<<"-->";
		return;
	}
	display(root->left);
	cout<<root->data<<"-->";
	display(root->right);*/

	Node *temp=root;
	if(root==NULL)
		return;
	else{
		while(1){

			while(temp!=NULL){
				Stack.push(temp);
				temp=temp->left;
			}
			if(temp==NULL && Stack.empty())
				break;
			else if(temp==NULL && !Stack.empty()){

				temp=Stack.top();
				cout<<temp->data<<"-->";
				Stack.pop();
				temp=temp->right;
			}
		}
	}
}

int main(){

	BST b;
	Node *root=NULL;
	while(1){
		cout<<"\n1.insert"<<"\n2.display"<<"\n3.minimum value"<<"\n4.no.of nodes in longest path"<<"5.swap"<<"\n6.search"<<"\n7.exit";
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
					int n;
					cout<<"\n enter the total number of data : ";
					cin>>n;
					cout<<"\n enter data : ";
					root=b.insert(root,n);
					break;

			case 2:
					b.display(root);
					break;
			case 3:
					b.minimum_value(root);
					break;

			case 4:
					cout<<"\nno. of nodes in longest path: "<<b.height(root)<<endl;
					break;		
			case 5:
					if(root==NULL)
						cout<<"\n tree empty()";
					b.swap(root);
					break;		
			case 6:int key;
					cout<<"\n enter number to be search : ";
					cin>>key;
					b.search_value(root,key);
					break;
							
			case 7:
					exit(0);
			default :
					cout<<"\n invalid choice";						
		}
	}
	return 0;
}

