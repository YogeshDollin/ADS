#include <iostream>
#include <stack>
using namespace std;

class Node{
public:
	char data;
	Node* left;
	Node* right;
};

class Exptree{
	Node* temp;
	stack <Node*> Stack;
public:
	Node* create_node(char c){
		Node *temp=new(Node);
		temp->data=c;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}

	Node* create_expression_tree(string);
	void display(Node*);
};

Node* Exptree::create_expression_tree(string s){
	for(int i=0;i<s.size();i++){
		if(isalpha(s[i])){
			Node *temp=create_node(s[i]);
			Stack.push(temp);
		}
		else{
			Node *temp=create_node(s[i]);
			temp->right=Stack.top();
			Stack.pop();
			temp->left=Stack.top();
			Stack.pop();
			Stack.push(temp);
		}
	}
	return Stack.top();
}

void Exptree::display(Node* link){
	if(link==NULL)
		return;
	else{
		display(link->left);
		cout<<link->data;
		display(link->right);
	}
}

int main(){
	Node *root=NULL;
	Exptree e;
	string s;
	cout<<"\n enter postfix expression : ";
	cin>>s;

	root=e.create_expression_tree(s);
	e.display(root);
	cout<<endl;

	return 0;

}