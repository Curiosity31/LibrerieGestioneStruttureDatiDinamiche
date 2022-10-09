#include <cmath>

namespace lasd {


/* ************************************************************************** */

// Specific constructors (AVLNode)

//Copy of the value
template <typename Data>
AVL<Data>:: AVLNode:: AVLNode (const Data& newInfo) : BST<Data>:: BSTNode (newInfo) {
  height = 0;
}


//Move of the value
template <typename Data>
AVL<Data>:: AVLNode:: AVLNode (Data&& newInfo) noexcept : BST<Data>:: BSTNode (std::move(newInfo)) {
  height = 0;
}

/* ************************************************************************** */

//Specfic member functions (BSTNode)

template <typename Data>
inline typename AVL<Data>:: AVLNode * AVL<Data>::AVLNode:: Left() {
  return (AVLNode *) BST<Data>::BSTNode:: sx;
}


template <typename Data>
inline const typename AVL<Data>:: AVLNode *  AVL<Data>::AVLNode:: Left() const {
  return (AVLNode *) BST<Data>::BSTNode:: sx;
}


template <typename Data>
inline typename AVL<Data>:: AVLNode *  AVL<Data>::AVLNode:: Right() {
  return (AVLNode *) BST<Data>::BSTNode:: dx;
}


template <typename Data>
inline const typename AVL<Data>:: AVLNode *  AVL<Data>::AVLNode:: Right() const {
  return (AVLNode *) BST<Data>::BSTNode:: dx;
}

/* ************************************************************************** */

// Copy constructor
template <typename Data>
AVL<Data>:: AVL (const AVL<Data>& copia) {
  if (copia.root != nullptr) {
    root = CopyAvl ((AVLNode *) copia.root);
  }
  else {
    root = nullptr;
  }
  size = copia.size;
}


// Move constructor
template <typename Data>
AVL<Data>:: AVL (AVL<Data>&& sposta) noexcept : BST<Data> (std::move(sposta)) { }

/* ************************************************************************ */

// Copy assignment
template <typename Data>
AVL<Data>& AVL<Data>:: operator = (const AVL<Data>& assegna) {
  AVL<Data> * temp = new AVL<Data> (assegna);
  std::swap (temp->root, root);
  size = assegna.size;
  temp->~AVL();
  return * this;
}


// Move assignment
template <typename Data>
AVL<Data>& AVL<Data>:: operator = (AVL<Data>&& vecchio) noexcept {
  BST<Data>:: operator = (std::move(vecchio));
  return * this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
inline bool AVL<Data>:: operator == (const AVL<Data>& verifica) const noexcept {
  return ( BST<Data>:: operator == (verifica) );
}


template <typename Data>
inline bool AVL<Data>:: operator != (const AVL<Data>& verifica) const noexcept {
  return (!(*this == verifica));
}

/* ************************************************************************ */

// Specific member functions (inherited from BinaryTree)

template <typename Data>
inline typename AVL<Data>:: AVLNode&  AVL<Data>:: Root() const {
  return (AVLNode&) BST<Data>:: Root();
}


template <typename Data>
inline typename AVL<Data>:: AVLNode& AVL<Data>:: NewRoot (const Data& newRoot) {
  return (AVLNode&) BST<Data>:: NewRoot(newRoot);
}


template <typename Data>
inline typename AVL<Data>:: AVLNode& AVL<Data>:: NewRoot (Data&& newRoot) noexcept {
  return (AVLNode&) BST<Data>:: NewRoot(newRoot);
}


/* ************************************************************************ */

// Specific member functions

template <typename Data>
void AVL<Data>:: Insert (const Data& key) {
  root = Insert ((AVLNode *)root, key);
}


template <typename Data>
void AVL<Data>:: Insert (Data&& key) noexcept {
  root = Insert ((AVLNode *)root, std::move(key));
}


template <typename Data>
void AVL<Data>:: Remove (const Data& rem) {
  root = Remove ((AVLNode *) root, rem);
}


template <typename Data>
Data AVL<Data>:: MinNRemove() {
  Data minimo = this->Min();
  root = Remove ((AVLNode *) root, minimo);
  return minimo;
}


template <typename Data>
void AVL<Data>:: RemoveMin() {
  root = Remove ((AVLNode *) root, this->Min());
}


template <typename Data>
Data AVL<Data>:: MaxNRemove() {
  Data massimo = this->Max();
  root = Remove ((AVLNode *) root, massimo);
  return massimo;
}


template <typename Data>
void AVL<Data>:: RemoveMax(){
  root = Remove ((AVLNode *) root, this->Max());
}


template <typename Data>
Data AVL<Data>:: PredecessorNRemove (const Data& pred) {
  Data predec = this->Predecessor(pred);
  root = Remove ((AVLNode *) root, predec);
  return predec;
}

template <typename Data>
void AVL<Data>::RemovePredecessor (const Data& pred) {
  root = Remove ((AVLNode *) root, this->Predecessor(pred));
}


template <typename Data>
Data AVL<Data>:: SuccessorNRemove (const Data& succ) {
  Data success = this->Successor (succ);
  root = Remove ((AVLNode *) root, success);
  return success;
}


template <typename Data>
void AVL<Data>:: RemoveSuccessor (const Data& succ) {
  root = Remove ((AVLNode *) root, this->Successor(succ));
}

/* ************************************************************************ */

//Accessory function

template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: CopyAvl (AVLNode * copia) {
  if (copia == nullptr) {
      return nullptr;
  }
  AVLNode * node = new AVLNode (copia->info);
  node->height = copia->height;
  node->BST<Data>::BSTNode:: sx = CopyAvl (copia->Left());
  node->BST<Data>::BSTNode:: dx = CopyAvl (copia->Right());
  return node;
}

template <typename Data>
int AVL<Data>:: Height (AVLNode * node) const noexcept {
  if (node == nullptr) {
    return -1;
  }
  return node->height;
}


template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: Insert (AVLNode * node, const Data& key) {
  if (node == nullptr) {
    node = new AVLNode (key);
    size ++;
  }
  else {
    if (node->info > key) {
      node->BST<Data>::BSTNode:: sx = Insert (node->Left(), key);
      node = BilanciaSx (node);
    }
    else if (node->info < key) {
      node->BST<Data>::BSTNode:: dx = Insert (node->Right(), key);
      node = BilanciaDx (node);
    }
  }
  return node;
}


template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: BilanciaSx (AVLNode * node) {
  if ( ( Height (node->Left()) - Height (node->Right()) ) == 2 ) {
    if (Height (node->Left()->Left()) > Height (node->Left()->Right())) {
      node = RotazioneSx (node);
    }
    else {
      node = RotazioneDsx (node);
    }
  }
  else {
    node->height = 1 + std::max (Height (node->Left()), Height (node->Right()));
  }
  return node;
}


template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: BilanciaDx (AVLNode * node) {
  if ( ( Height (node->Right()) - Height (node->Left()) ) == 2 ) {
    if (Height (node->Right()->Right()) > Height (node->Right()->Left())) {
      node = RotazioneDx (node);
    }
    else {
      node = RotazioneSdx (node);
    }
  }
  else {
    node->height = 1 + std::max (Height (node->Left()), Height (node->Right()));
  }
  return node;
}


template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: RotazioneDx (AVLNode * node) {
  AVLNode * newRoot = node->Right();
  node->BST<Data>::BSTNode:: dx = newRoot->Left();
  newRoot->BST<Data>::BSTNode:: sx = node;
  node->height = 1 + std::max (Height (node->Left()), Height (node->Right()));
  newRoot->height = 1 + std::max (Height (newRoot->Left()), Height (newRoot->Right()));
  return newRoot;
}


template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: RotazioneSx (AVLNode * node) {
  AVLNode * newRoot = node->Left();
  node->BST<Data>::BSTNode:: sx = newRoot->Right();
  newRoot->BST<Data>::BSTNode:: dx = node;
  node->height = 1 + std::max (Height (node->Left()), Height (node->Right()));
  newRoot->height = 1 + std::max (Height (newRoot->Left()), Height (newRoot->Right()));
  return newRoot;
}

template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: RotazioneSdx (AVLNode * node) {
  node->BST<Data>::BSTNode:: dx = RotazioneSx (node->Right());
  return RotazioneDx (node);
}


template <typename Data>
typename AVL<Data>:: AVLNode * AVL<Data>:: RotazioneDsx (AVLNode * node) {
  node->BST<Data>::BSTNode:: sx = RotazioneDx (node->Left());
  return RotazioneSx (node);
}


template<typename Data>
typename AVL<Data>::AVLNode * AVL<Data>:: Remove (AVLNode * node, const Data& rem) {
  if (node == nullptr){
    return node;
  }
  else if (rem < node->info) {
    node->BST<Data>::BSTNode:: sx = Remove (node->Left(), rem);
    node = BilanciaDx (node);
  }
  else if (rem > node->info) {
    node->BST<Data>::BSTNode:: dx = Remove (node->Right(), rem);
    node = BilanciaSx (node);
  }
  else{
    AVLNode * temp = node;
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
      node->BST<Data>::BSTNode:: sx = Remove (node->Left(), node->info);
      node = BilanciaDx (node);
    }
  }
  return node;
}



/* ************************************************************************ */


}
