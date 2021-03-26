#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct AVLNode{
	AVLNode *left;
	AVLNode *right;
	AVLNode* parent;
	string key;
    long height;
    long rank;
};

class AVL{
protected:
	AVLNode *root;
	long height(AVLNode *T){
		if (T == NULL)
			return -1;
		else
			return T->height;
	}

	AVLNode* balance(AVLNode *T)
    {
        int balanceFactor = diff(T);//__diff用来计算平衡因子（左右子树高度差）
        if (balanceFactor > 1)//左子树高于右子树
        {
        if (diff(T->left) > 0)//左左外侧
            T=ll_Rotation(T);
        else//左右内侧
            T=lr_Rotation(T);
        }
        else if (balanceFactor < -1)//右子树高于左子树
        {
        if (diff(T->right) > 0)//右左内侧
            T=rl_Rotation(T);
        else//右右外侧
            T=rr_Rotation(T);
        }
        return T;
    }

    AVLNode* rr_Rotation(AVLNode *T)//right-right rotation
    {
    AVLNode* w = T->left;
    w->parent = T->parent;
    T->parent=w;
    T->left=w->right;
    if (w->right != NULL) 
    w->right->parent = T;
    w->right = T;

    T->height = max(height(T->left), height(T->right)) + 1;
    w->height = max(height(w->left), height(T->right)) + 1;
    T->rank=T->rank- 1 - w->rank;
    return w;
    }
    
    AVLNode* ll_Rotation(AVLNode *T)//left-left rotation
    {
    AVLNode* w = T->right;
    w->parent = T->parent;
    T->parent = w;
    T->right = w->left;
    if (w->left != NULL) w->left->parent = T;
    w->left = T; 

    T->height = max(height(T->left), height(T->right)) + 1;
    w->height = max(height(w->left), height(w->right)) + 1;
    w->rank=w->rank + 1 + T->rank;
    return w;
    }

    AVLNode* lr_Rotation(AVLNode *T)//left-right rotation
    {
    	AVLNode* tmp;
    	tmp = T->left;
    	T->left = rr_Rotation(tmp);
    	return ll_Rotation(T);
    }

    AVLNode* rl_Rotation(AVLNode *T)//right-left rotation
    {
    	AVLNode* tmp;
    	tmp = T->right;
    	T->right = ll_Rotation(tmp);
    	return rr_Rotation(T);
    }


	AVLNode* insert(AVLNode *T, string v){
		if (T == NULL){
			T=new AVLNode;
			T->key=v;
			T->rank=0;
			T->height=0;
		    T->parent = T->left = T->right = NULL;
		}
		else if (v < T->key){
			T->left=insert(T->left,v);
			T->rank+=1;
			T->left->parent=T;
			T=balance(T);
		}
		else if (v > T->key){
			T->right=insert(T->right,v);
			T->right->parent=T;
			T=balance(T);
		}
	}

    AVLNode* findMin(AVLNode* T) {
        if (T == NULL)       return NULL;         // BST is empty, no minimum
        else if (T->left == NULL) return T;     // this is the min
        else                      return findMin(T->left); // go to the left
    }

    AVLNode* findMax(AVLNode* T) {
        if (T == NULL)        return NULL;        // BST is empty, no maximum
        else if (T->right == NULL) return T;    // this is the max
        else                       return findMax(T->right); // go to the right
    }

	int diff(AVLNode *T){
		return height(T->left)-height(T->right);
	}

	AVLNode* remove(AVLNode* T, string v){
		if (T == NULL)
			return T;

        if (v == T->key)//根节点
     {
     	if (T->right == NULL && T->left == NULL){
     		T=NULL;
     	}
        else if (T->left != NULL && T->right != NULL)//左右子树都非空
        {
            if (diff(T) > 0)//左子树更高，在左边删除
            {
                T->key = findMax(T->left)->key;//以左子树的最大值替换当前值
                T->left = remove(T->left, T->key);//删除左子树中已经替换上去的节点
            }
            else//右子树更高，在右边删除
            {
                T->key = findMin(T->right)->key;
                T->right = remove(T->right, T->key);
            }
        }
      else if (T->left == NULL && T->right != NULL) { // only one child at right
        T->right->parent = T->parent;            // ma, take care of my child
        T = T->right;                            // bypass T
      }
      else if (T->left != NULL && T->right == NULL) { // only one child at left
        T->left->parent = T->parent;             // ma, take care of my child
        T = T->left;                             // bypass T
      }
    }//end-if
    else if (v < T->key)//往左边删除
    {
        T->left = remove(T->left, v);//左子树中递归删除
        T->rank -= 1;
        //判断平衡的条件与在插入时情况类似
        if (diff(T) < -1)//不满足平衡条件，删除左边的后，右子树变高
        {
            if (diff(T->right) > 0)
            {
                T = rl_Rotation(T);
            }
            else
            {
                T = rr_Rotation(T);
            }
        }
    }//end else if
    else
    {
        T->right = remove(T->right, v);
        if (diff(T) > 1)//不满足平衡条件
        {
            if (diff(T->left) < 0)
            {
                T = lr_Rotation(T);
            }
            else
            {
                T = ll_Rotation(T);
            }
        }
    }
    return T;

	}

  AVLNode* search(AVLNode* T, string v) {
    if (T == NULL)   return T;              // not found
    if (T->right == NULL && T->left == NULL) return T;
    else if (T->key == v) return T;
    else if (T->right == NULL ){
      if (T->key < v) return T;
      else return search(T->left,v);
    }
    else if (T->left == NULL){
      if (T->key > v) return T;
      else return search(T->right,v);
    }
    else if (T->key > v) return search(T->left, v);
    else if (T->key < v) return search(T->right, v);
  }

   long compute(AVLNode* T){
    if (T->parent == NULL)
      return 0;
    else if (T->key > T->parent->key)
      return T->parent->rank+1+compute(T->parent);
    else
      return compute(T->parent);
  }

public:
	AVL() {root=NULL; }

	void insert(string v){root=insert(root,v);}

	void remove(string v){root=remove(root,v);}

  long compute(string v){
    if (root == NULL)
      return 0;
    if (root->key == v){
      return root->rank;
    }
    else{
      AVLNode *pos=search(root,v);
      int result = 0;
      if (pos->key < v)
        result+=1;
      return result+pos->rank + compute(pos);      
    }
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  AVL* female = new AVL(); 
  AVL* male = new AVL();
  map<string, int> match;

  // male->insert("A");
  // male->insert("B");
  // male->insert("Z");
  // male->insert("K");
  // male->insert("J");
  // male->insert("C");
  // male->insert("O");
  // male->insert("L");
  // male->insert("Y");
  // male->insert("X");
  // male->remove("J");
  // male->remove("L");


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