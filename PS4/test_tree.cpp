#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct BSTVertex {

  BSTVertex* parent;
  BSTVertex* left;
  BSTVertex* right;
  string key;
  long rank;
  long height;
};

class BST {
protected:
  BSTVertex *root;

  long h(BSTVertex* T) { if (T == NULL) return -1; else return T->height; }

  BSTVertex* rotateLeft(BSTVertex* T) {
    BSTVertex* w = T->right;
    w->parent = T->parent;
    T->parent = w;
    T->right = w->left;
    if (w->left != NULL) w->left->parent = T;
    w->left = T; 

    T->height = max(h(T->left), h(T->right)) + 1;
    w->height = max(h(w->left), h(w->right)) + 1;
    w->rank=w->rank + 1 + T->rank;
    return w;
  }

  BSTVertex* rotateRight(BSTVertex* T) {
    BSTVertex* w = T->left;
    w->parent = T->parent;
    T->parent=w;
    T->left=w->right;
    if (w->right != NULL) 
    w->right->parent = T;
    w->right = T;

    T->height = max(h(T->left), h(T->right)) + 1;
    w->height = max(h(w->left), h(T->right)) + 1;
    T->rank=T->rank- 1 - w->rank;
    return w;
  }

  BSTVertex* insert(BSTVertex* T, string v) {
    if (T == NULL) {                             // insertion point is found
      T = new BSTVertex;
      T->key = v;
      T->parent = T->left = T->right = NULL;
      T->rank = 0;
      T->height = 0;
    }
    else if (T->key < v) {                       // search to the right
      T->right = insert(T->right, v);
      T->right->parent = T;
    }
    else {                                      // search to the left
      T->left = insert(T->left, v);
      T->rank+=1; 
      T->left->parent = T;
    }
    
    T->height = max(h(T->left), h(T->right)) + 1;
    
    long balance = h(T->left) - h(T->right);
    if (balance == 2) { // left heavy
      long balance2 = h(T->left->left) - h(T->left->right);
      if (balance2 > 0) {
        T = rotateRight(T);
      }
      else { // -1
        T->left = rotateLeft(T->left);
        T = rotateRight(T);
      }
    }
    else if (balance == -2) { // right heavy
      long balance2 = h(T->right->left) - h(T->right->right);
      if (balance2 < 0)
        T = rotateLeft(T);
      else { // 1
        T->right = rotateRight(T->right);
        T = rotateLeft(T);
      }
    }
    return T;                                    // return the updated BST
  }

  string findMin(BSTVertex* T) {
         if (T == NULL)       return " ";         // BST is empty, no minimum
    else if (T->left == NULL) return T->key;     // this is the min
    else                      return findMin(T->left); // go to the left
  }
  string findMax(BSTVertex* T) {
         if (T == NULL)        return " ";        // BST is empty, no maximum
    else if (T->right == NULL) return T->key;    // this is the max
    else                       return findMax(T->right); // go to the right
  }

  BSTVertex* search(BSTVertex* T, string v) {
         if (T == NULL)   return T;              // not found
    else if (T->key == v) return T;              // found
    else if (T->key < v)  return search(T->right, v); // search to the right
    else                  return search(T->left, v); // search to the left
  }

  string predecessor(BSTVertex* T) {
    if (T->left != NULL)                         // we have left subtree
      return findMax(T->left);                   // this is the predecessor
    else {
      BSTVertex* par = T->parent;
      BSTVertex* cur = T;
      // if par(ent) is not root and cur(rent) is its left children
      while ((par != NULL) && (cur == par->left)) { 
        cur = par;                               // continue moving up
        par = cur->parent;
      }
      if (par == NULL)
        return " ";
      else
        return par->key;        // this is the successor of T
    }
  }

  string successor(BSTVertex* T) {
    if (T->right != NULL)                        // we have right subtree
      return findMin(T->right);                  // this is the successor
    else {
      BSTVertex* par = T->parent;
      BSTVertex* cur = T;
      // if par(ent) is not root and cur(rent) is its right children
      while ((par != NULL) && (cur == par->right)) {
        cur = par;                               // continue moving up
        par = cur->parent;
      }

      if (par == NULL){
        return " ";
      }
      else{
        return par->key;
      }       // this is the successor of T
    }
  }

  long compute(BSTVertex* T){
    if (T->parent == NULL)
      return 0;
    else if (T->key > T->parent->key)
      return T->parent->rank + 1 + compute(T->parent);
    else
      return compute(T->parent);
  }

  BSTVertex* remove(BSTVertex* T, string v) {

    if (T->key == v) {                           // the node to be deleted
      if (T->left == NULL && T->right == NULL)   // this is a leaf
        T = NULL;                                // simply erase this node
      else if (T->left == NULL && T->right != NULL) { // only one child at right
        T->right->parent = T->parent;            // ma, take care of my child
        T = T->right;                            // bypass T
      }
      else if (T->left != NULL && T->right == NULL) { // only one child at left
        T->left->parent = T->parent;             // ma, take care of my child
        T = T->left;                             // bypass T
      }
      else { // has two children, find successor to avoid quarrel
        string successorV = successor(v);           // predecessor is also OK btw
        T->key = successorV;                     // replace with successorV
        T->right = remove(T->right, successorV); 
        T->height=max(h(T->right),h(T->left))+1;// delete the old successorV
      }
    }
    else if (T->key < v){                         // search to the right
      T->right = remove(T->right, v);
      T->height=max(h(T->right),h(T->left))+1;
    }
    else{     
      T->rank-=1;                                    // search to the left
      T->left = remove(T->left, v);
      T->height=max(h(T->right),h(T->left))+1;
    }

    if (T != NULL){
    long balance = h(T->left) - h(T->right);
    if (balance == 2) { // left heavy
      long balance2 = h(T->left->left) - h(T->left->right);
      if (balance2 > 0) {
        T = rotateRight(T);
      }
      else { // -1
        T->left = rotateLeft(T->left);
        T = rotateRight(T);
      }
    }
    else if (balance == -2) { // right heavy
      long balance2 = h(T->right->left) - h(T->right->right);
      if (balance2 < 0)
        T = rotateLeft(T);
      else { // 1
        T->right = rotateRight(T->right);
        T = rotateLeft(T);
      }

    T->height=max(h(T->right),h(T->left))+1;
    }
  }

    return T;                                    // return the updated BST
  }

public:
  BST() { root = NULL; }

  void insert(string v) { root = insert(root, v); }

  string successor(string v) { 
    BSTVertex* vPos = search(root, v);
    return successor(vPos);

  }
  string predecessor(string v) { 
    BSTVertex* vPos = search(root, v);
    return predecessor(vPos);
  }

  long compute(string v){
    if (root == NULL)
      return 0;
    if (root->key == v){
      return root->rank;
    }
    else{
      BSTVertex *pos=search(root,v);
      if (pos == NULL) {
        root=insert(root,v);
        string vertex=predecessor(v);
        root=remove(root,v);
        if (vertex == " ") {
          return 0;}
        pos=search(root,vertex);
        
      };
      long result=0;
      if (v > pos->key)
        result+=1;
      return result+pos->rank + compute(pos);      
    }
  }

  void remove(string v) { root = remove(root, v); }

};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  BST* female = new BST(); 
  BST* male = new BST();
  map<string, int> match;
  
  freopen("1.in","r",stdin);

  while (1){
    int n; cin>>n;
    if (n == 0){
      break;
    }
    else if (n == 1){
      string name;cin>>name;
      int gender;cin>>gender;
      if (gender == 1){
        male->insert(name);
        match[name]=1;
      }
      else{
        female->insert(name);
        match[name]=2;
      }
    }
    else if (n == 2){
      string name;cin>>name;
      int gender=match[name];
      if (gender == 1){
        male->remove(name);
      }
      else{
        female->remove(name);
      }
      match.erase(name);
    }
    else if (n == 3){
      string lower,upper;cin>>lower;cin>>upper;
      int gender;cin>>gender;
      long result=0;
      if (gender == 1 || gender == 0){

        result+=(male->compute(upper)-male->compute(lower));
      }
      if (gender == 2 || gender == 0){
        result+=(female->compute(upper)-female->compute(lower));
      }
      cout<<result<<"\n";
    }
  }

}