// Chipotgang 618311

#include <iostream>
#include <algorithm>
#include <string>

#define maxN 100000
using namespace std;

class Relation{
public:
	int node, parent;

	Relation(){}
};

bool operator < (Relation r1, Relation r2){
	return r1.node < r2.node;
}

Relation r1[maxN];
Relation r2[maxN];
int queue[maxN];
int q_index;

int next_token(string& c, int i){
	for(int j=i+1; j<c.length(); j++){
		if(c[j] == '(' or c[j] == ')'){
			return j;
		}
	}
	return -1;
}

int get_parents(string c, Relation* r){ // return size
	int index = 0; // index of number
	q_index = 0;
	int r_index = 0;
	int last_number = 0;
	while(index < c.length()){
		char curr = c[index];
		if(curr == '('){
			index ++;
		}
		else if(curr == ')'){
			r[r_index].node = queue[q_index-1];
			r[r_index].parent = queue[q_index-2];
			r_index++;
			q_index--;
			index ++;
		}
		else{
			int next = next_token(c, index);
			int num = stoi(c.substr(index, next-index));
			queue[q_index] = num;
			q_index ++;
			index = next;
		}
	}
	return r_index;
}

string remove_spaces(string s){
	string c;
	for(int i=0; i<s.length(); i++){
		if(s[i] != ' '){
			c.push_back(s[i]);
		}
	}
	return c;
}

int main(){
	string c1, c2;
	getline(cin, c1);
	getline(cin, c2);
	c1 = remove_spaces(c1);
	c2 = remove_spaces(c2);
	int next1 = next_token(c1, 0);
	int next2 = next_token(c2, 0);
	int num1 = stoi(c1.substr(0, next1));
	int num2 = stoi(c2.substr(0, next2));
	if(num1 != num2){
		cout<<"No\n";
		return 0;
	}
	int n1 = get_parents(c1, r1);
	int n2 = get_parents(c2, r2);
	if(n1 != n2){
		cout<<"No\n";
		return 0;
	}
	sort(r1, r1+n1);
	sort(r2, r2+n2);
	for(int i=0; i<n1; i++){
		if(r1[i].node != r2[i].node || r1[i].parent != r2[i].parent){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}