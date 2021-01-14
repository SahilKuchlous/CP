#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;
ifstream fin("first.in");
ofstream fout("first.out");
int n;
string str[30100];
bool valid[30100];
set<int> adj[26];
bool vis[26];
bool stack[26];
bool pos = true;
int o = 0;
struct Node {
	struct Node *children[26];
	bool end;
};
struct Node *new_node () {
	struct Node *n = new Node;
	n->end = false;
	for (int i=0; i<26; i++) {
		n->children[i] = NULL;
	}
	return n;
}
void insert (struct Node *root, string s) {
	struct Node *cur = root;
	for (int i=0; i<s.length(); i++) {
		if (!cur->children[s.at(i)-'a']) {
			cur->children[s.at(i)-'a'] = new_node();
		}
		cur = cur->children[s.at(i)-'a'];
	}
	cur->end = true;
}
void make_graph (struct Node *root, string s) {
	struct Node *cur = root;
	for (int i=0; i<s.length(); i++) {
		if (cur->end) pos = false;
		for (int j=0; j<26; j++) {
			if (j != s.at(i)-'a' && cur->children[j]) {
				adj[s.at(i)-'a'].insert(j);
			}
		}
		cur = cur->children[s.at(i)-'a'];
	}
}
bool dfs (int x) {
	vis[x] = stack[x] = true;
	for (auto i: adj[x]) {
		if (!vis[i] && dfs(i)) {
			return true;
		} else if (stack[i]) {
			return true;
		}
	}
	stack[x] = false;
	return false;
}
bool check_cycle () {
	for (int i=0; i<26; i++) {
		for (int j=0; j<26; j++) {
			vis[j] = stack[j] = false;
		}
		if (dfs(i)) {
			return true;
		}
	}
	return false;
}
int main () {
	fin >> n;
	struct Node *root = new_node();
	for (int i=0; i<n; i++) {
		fin >> str[i];
		insert(root, str[i]);
		valid[i] = true;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<26; j++) {
			adj[j].clear();
		}
		pos = true;
		make_graph(root, str[i]);
		if (pos && !check_cycle()) {
			o++;
			valid[i] = true;
		} else {
			valid[i] = false;
		}
	}
	fout << o << endl;
	for (int i=0; i<n; i++) {
		if (valid[i]) fout << str[i] << endl;
	}
}