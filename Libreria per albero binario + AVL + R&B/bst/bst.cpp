
namespace lasd {

/* ************************************************************************** */

// Specific constructors (BSTNode)

//Copy of the value
template <typename Data>
BST<Data>::BSTNode:: BSTNode (const Data& newInfo) : BinaryTreeLnk<Data>:: NodeLnk (newInfo) {}


//Move of the value
template <typename Data>
BST<Data>::BSTNode:: BSTNode (Data&& newInfo) noexcept : BinaryTreeLnk<Data>:: NodeLnk (std::move(newInfo)) {}


/* ********************************************************************** */

//Specfic member functions (BSTNode)

template <typename Data>
inline typename BST<Data>:: BSTNode * BST<Data>::BSTNode:: Left() {
  return  (BSTNode *) BinaryTreeLnk<Data>::NodeLnk:: sx;
}


template <typename Data>
inline const typename BST<Data>:: BSTNode * BST<Data>::BSTNode:: Left() const {
  return (BSTNode *) BinaryTreeLnk<Data>::NodeLnk:: sx;
}


template <typename Data>
inline typename BST<Data>:: BSTNode * BST<Data>::BSTNode:: Right() {
  return (BSTNode *) BinaryTreeLnk<Data>::NodeLnk:: dx;
}


template <typename Data>
inline const typename BST<Data>:: BSTNode * BST<Data>::BSTNode:: Right() const {
  return (BSTNode *) BinaryTreeLnk<Data>::NodeLnk:: dx;
}


template <typename Data>
typename BST<Data>:: BSTNode *  BST<Data>::BSTNode:: Find (BSTNode * node, const Data& key) const {
  if (node == nullptr || node->Element() == key) {
    return node;
  }
  if (key < node->Element()) {
    return Find (node->Left(), key);
  }
  else {
    return Find (node->Right(), key);
  }
}


//restituisce il padre del nodo, o il padre dell'eventuale nodo da aggiungere
template <typename Data>
typename BST<Data>:: BSTNode * BST<Data>::BSTNode:: FindParent (BSTNode * node, const Data& key) const {
  BSTNode * parent = nullptr;
  BSTNode * temp = node;
  while (temp != nullptr && temp->Element() != key) {
    if (temp->Element() > key) {
      parent = temp;
      temp = temp->Left();
    }
    else {
      parent = temp;
      temp = temp->Right();
    }
  }
  return parent;
}


template <typename Data>
typename BST<Data>:: BSTNode * BST<Data>::BSTNode:: MinParent (BSTNode * node) const {
  BSTNode * parent = nullptr;
  BSTNode * temp = node;
  while (temp->Left() != nullptr) {
    parent = temp;
    temp = temp->Left();
  }
  return parent;
}


template <typename Data>
typename BST<Data>:: BSTNode * BST<Data>::BSTNode:: MaxParent (BSTNode * node) const {
  BSTNode * parent = nullptr;
  BSTNode * temp = node;
  while (temp->Right() != nullptr) {
    parent = temp;
    temp = temp->Right();
  }
  return parent;
}

/* ************************************************************************** */

// Copy constructor
template <typename Data>
BST<Data>:: BST (const BST<Data>& copia) : BinaryTreeLnk<Data> (copia) {}

// Move constructor
template <typename Data>
BST<Data>:: BST (BST<Data>&& sposta) noexcept : BinaryTreeLnk<Data> (std::move(sposta)) {}

/* ************************************************************************ */


// Copy assignment
template <typename Data>
BST<Data>& BST<Data>:: operator = (const BST<Data>& assegna) {
  BinaryTreeLnk<Data>:: operator  = (assegna);
  return * this;
}

// Move assignment
template <typename Data>
BST<Data>& BST<Data>:: operator = (BST<Data>&& vecchio) noexcept {
  BinaryTreeLnk<Data>:: operator  = (std::move(vecchio));
  return * this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
bool BST<Data>:: operator == (const BST<Data>& verifica) const noexcept {
  bool flag = false;
  if (size == verifica.size) {
     ulong indice = 0;
     Vector<Data> vec1(size);
     Vector<Data> vec2(verifica.size);
     EqualsBST ( (BSTNode *)root, vec1, indice);
     indice = 0;
     EqualsBST ( ((BSTNode *)verifica.root), vec2, indice);
     if (vec1 == vec2) {
       flag = true;
     }
     vec1.Clear();
     vec2.Clear();
  }
  return flag;
}


template <typename Data>
inline bool BST<Data>:: operator != (const BST<Data>& verifica) const noexcept {
  return (!(*this == verifica));
}

/* ************************************************************************ */

// Specific member functions (inherited from BinaryTree)

template <typename Data>
inline typename BST<Data>:: BSTNode& BST<Data>:: Root() const {
 return (BSTNode &)BinaryTreeLnk<Data>:: Root();
}


template <typename Data>
typename BST<Data>:: BSTNode& BST<Data>:: NewRoot (const Data& newRoot) {
  if (root == nullptr) {
    root = new BSTNode (newRoot);
  }
  else {
    this->RemoveLeftChild (*root);
    this->RemoveRightChild (*root);
    root->Element() = newRoot;
  }
  size = 1;
  return * (BSTNode *) root;
}


template <typename Data>
typename BST<Data>:: BSTNode& BST<Data>:: NewRoot (Data&& newRoot) noexcept {
  if (root == nullptr) {
    root = new BSTNode (std::move(newRoot));
  }
  else {
    this->RemoveLeftChild (*root);
    this->RemoveRightChild (*root);
    root->Element() = std::move(newRoot);
  }
  size = 1;
  return * (BSTNode *) root;
}

/* ************************************************************************ */

/* ************************************************************************ */

// Specific member functions

template <typename Data>
void BST<Data>:: Insert (const Data& elem) {
  BSTNode * parent = nullptr;
  BSTNode * temp = (BSTNode *) root;
  while (temp != nullptr && temp->info != elem) {
    parent = temp;
    if (temp->info > elem) {
      temp = temp->Left();
    }
    else {
      temp = temp->Right();
    }
  }
  if (temp == nullptr) {
    if (parent == nullptr) {
      root = new BSTNode (elem);
    }
    else if (parent->info > elem) {
      parent->BinaryTreeLnk<Data>::NodeLnk:: sx = new BSTNode (elem);
    }
    else {
      parent->BinaryTreeLnk<Data>::NodeLnk:: dx = new BSTNode (elem);
    }
    size ++;
  }
}


template <typename Data>
void BST<Data>:: Insert (Data&& elem) noexcept {
  BSTNode * parent = nullptr;
  BSTNode * temp = (BSTNode *) root;
  while (temp != nullptr && temp->info != elem) {
    parent = temp;
    if (temp->info > elem) {
      temp = temp->Left();
    }
    else {
      temp = temp->Right();
    }
  }
  if (temp == nullptr) {
    if (parent == nullptr) {
      root = new BSTNode (std::move(elem));
    }
    else if (parent->info > elem) {
      parent->BinaryTreeLnk<Data>::NodeLnk:: sx = new BSTNode (std::move(elem));
    }
    else {
      parent->BinaryTreeLnk<Data>::NodeLnk:: dx = new BSTNode (std::move(elem));
    }
    size ++;
  }
}


template <typename Data>
void BST<Data>:: Remove (const Data& rem) {
  root = Remove ((BSTNode *) root, rem);
}


template <typename Data>
const Data& BST<Data>:: Min() const {
  BSTNode * temp = &Root(); //Se l'albero è vuoto la funzione Root() lancia l'eccezione
  while (temp->Left() != nullptr) {
    temp = temp->Left();
  }
  return temp->Element();
}


template <typename Data>
Data BST<Data>:: MinNRemove() {
  Data minimo = Min();
  RemoveMin();
  return minimo;
}


template <typename Data>
void BST<Data>:: RemoveMin() {
  if ( !(this->Empty()) ) {
    RemoveMin ( ((BSTNode *)root)->MinParent ((BSTNode *)root) );
    size -- ;
  }
  else {
    throw std::length_error ("Access to an empty Tree!");
  }
}



template <typename Data>
const Data& BST<Data>:: Max() const {
  BSTNode * temp = &Root(); //Se l'albero è vuoto la funzione Root() lancia l'eccezione
  while (temp->Right() != nullptr) {
    temp = temp->Right();
  }
  return temp->Element();
}


template <typename Data>
Data BST<Data>:: MaxNRemove() {
  Data massimo = Max();
  RemoveMax();
  return massimo;
}


template <typename Data>
void BST<Data>:: RemoveMax() {
  if ( !(this->Empty()) ) {
    RemoveMax ( ((BSTNode *)root)->MaxParent ((BSTNode *)root) );
    size -- ;
  }
  else {
    throw std::length_error ("Access to an empty Tree!");
  }
}


template <typename Data>
const Data& BST<Data>:: Predecessor (const Data& key) const {
  bool flag = false;
  BSTNode * pred = nullptr;
  BSTNode * temp = &Root(); // se l'albero è vuoto lancia eccezione
  if ( key <= this->Min() )  {
    throw std::length_error("The predecessor does not exist!");
  }
  while ( (temp != nullptr) && (flag == false) ) {
    if (key < temp->info) {
      temp = temp->Left();
    }
    else if (key > temp->info) {
      pred = temp;
      temp = temp->Right();
    }
    else {
      if (temp->Left() != nullptr) {
        BSTNode * max = temp->Left();
        while (max->Right() != nullptr) {
          max = max->Right();
        }
        pred = max;
      }
      flag = true;
    }
  }
  return pred->info;
}


template <typename Data>
Data BST<Data>:: PredecessorNRemove (const Data& pred) {
  Data predec = Predecessor (pred);
  RemovePredecessor (pred);
  return predec;
}


template <typename Data>
inline void BST<Data>:: RemovePredecessor (const Data& pred) {
  Remove ( Predecessor (pred) );
}


template <typename Data>
const Data& BST<Data>:: Successor (const Data& key) const {
  bool flag = false;
  BSTNode * sux = nullptr;
  BSTNode * temp = &Root(); // se l'albero è vuoto lancia eccezione
  if ( key >= this->Max() )  {
    throw std::length_error("The successor does not exist!");
  }
  while ( (temp != nullptr) && (flag == false) ) {
    if (key < temp->info) {
      sux = temp;
      temp = temp->Left();
    }
    else if (key > temp->info) {
      temp = temp->Right();
    }
    else {
      if (temp->Right() != nullptr) {
        BSTNode * max = temp->Right();
        while (max->Left() != nullptr) {
          max = max->Left();
        }
        sux = max;
      }
      flag = true;
    }
  }
  return sux->info;
}


template <typename Data>
Data BST<Data>:: SuccessorNRemove (const Data& succ) {
  Data success = Successor (succ);
  RemoveSuccessor (succ);
  return success;
}


template <typename Data>
inline void BST<Data>:: RemoveSuccessor (const Data& succ) {
  Remove ( Successor (succ) );
}

/* ************************************************************************ */

// Specific member functions (inherited from TestableContainer)

template <typename Data>
bool BST<Data>:: Exists (const Data& dat) const noexcept {
  BSTNode * temp = nullptr;
  temp = temp->Find((BSTNode *)root, dat);
  return (temp != nullptr);
}

/* ************************************************************************ */
//Accessory function

template <typename Data>
void BST<Data>:: EqualsBST (BSTNode * node , Vector<Data>& vec, ulong& indice) const noexcept {
  if (node != nullptr) {
     EqualsBST (node->Left(), vec, indice);
     vec[indice] = node->info;
     indice ++;
     EqualsBST (node->Right(), vec, indice);
  }
}


template<typename Data>
typename BST<Data>::BSTNode * BST<Data>:: Remove (BSTNode * node, const Data& rem) {
  if (node == nullptr){
    return node;
  }
  else if (rem < node->info) {
    node->BinaryTreeLnk<Data>::NodeLnk:: sx = Remove (node->Left(), rem);
  }
  else if (rem > node->info) {
    node->BinaryTreeLnk<Data>::NodeLnk:: dx = Remove (node->Right(), rem);
  }
  else{
    BSTNode * temp = node;
    if ( (node->Right() == nullptr) && (node->Left() == nullptr) ) {
      delete node;
      node = nullptr;
      size--;
    }
    else if (node->Right() == nullptr) {
      node = node->Left();
      delete temp;
      size--;
    }
    else if (node->Left() == nullptr) {
      node = node->Right();
      delete temp;
      size--;
    }
    else {
      node->info = this->Predecessor (node->info);
      node->BinaryTreeLnk<Data>::NodeLnk:: sx = Remove (node->Left(), node->info);
    }
  }
  return node;
}




template <typename Data>
void BST<Data>:: RemoveMin (BSTNode * minPar) {
  BSTNode * min = nullptr;
  if (minPar == nullptr) {
    min = (BSTNode *) root;
    root = min->Right();
  }
  else {
    min = minPar->Left();
    minPar->BinaryTreeLnk<Data>::NodeLnk:: sx = min->Right();
  }
  delete min;
}


template <typename Data>
void BST<Data>:: RemoveMax (BSTNode * maxPar) {
  BSTNode * max = nullptr;
  if (maxPar == nullptr) {
    max = (BSTNode *) root;
    root = max->Left();
  }
  else {
    max = maxPar->Right();
    maxPar->BinaryTreeLnk<Data>::NodeLnk:: dx = max->Left();
  }
  delete max;
}




}
