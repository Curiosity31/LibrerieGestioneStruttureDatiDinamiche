
#include <stdexcept>
#include <cmath>


/* ********************************************************************** */
// Specific constructors (NodeVec)

//Copy of the value
template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec (const Data& newInfo, const ulong newInd) {
  info = newInfo;
  index = newInd;
}


//Move of the value
template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec (Data&& newInfo, const ulong newInd) noexcept {
  info = std::move(newInfo);
  index = newInd;
}



/* ********************************************************************** */


// Specific member functions

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec:: HasParent() const noexcept{
  return (index != 0);
}


template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::  HasLeftSibling() const noexcept {
  if (index % 2 == 1 || index == 0) {
    return false;
  }
  else {
     if (cur->treeVec [index - 1] != nullptr) {
       return true;
     }
     return false;
  }
}


template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::  HasRightSibling() const noexcept {
  if ((index % 2 == 0) || (index == 0) ) {
    return false;
  }
  else {
     if (cur->treeVec [index + 1] != nullptr) {
       return true;
     }
     return false;
  }
}


template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec:: Parent() const {
  if (HasParent()) {
    if (index % 2 == 0) {
      return * (cur->treeVec [(index/2) - 1]);
    }
    else {
      return * (cur->treeVec [index/2]);
    }
  }
  throw std::out_of_range ("Access at null pointer");
}


template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::  LeftSibling() const {
  if (HasLeftSibling()) {
    return * (cur->treeVec [index - 1]);
  }
  throw std::out_of_range ("Access at null pointer");
}


template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::  RightSibling() const {
  if (HasRightSibling()) {
    return * (cur->treeVec [index + 1]);
  }
  throw std::out_of_range ("Access at null pointer");
}

/* ********************************************************************** */

// Specific member functions (inherited from Node)

template <typename Data>
inline Data& BinaryTreeVec<Data>::NodeVec:: Element() {
  return info;
}


template <typename Data>
inline const Data& BinaryTreeVec<Data>::NodeVec:: Element() const {
  return info;
}


template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec:: IsLeaf() const noexcept {
  return ( (! HasLeftChild()) && (! HasRightChild()) );
}


template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec:: HasLeftChild() const noexcept {
  return ((((2*index) +1) < cur->treeVec.Size()) && cur->treeVec[(2*index) +1] != nullptr);
}


template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec:: HasRightChild() const noexcept {
  return ((((2*index) +2) < cur->treeVec.Size()) && cur->treeVec[(2*index) +2] != nullptr);
}


template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec&  BinaryTreeVec<Data>::NodeVec:: LeftChild() const {
  if (HasLeftChild()) {
    return  * (cur->treeVec[(2 * index) + 1]);
  }
  throw std::out_of_range ("Access to null pointer");
}


template <typename Data>
typename  BinaryTreeVec<Data>:: NodeVec& BinaryTreeVec<Data>::NodeVec:: RightChild() const {
  if (HasRightChild()) {
    return * (cur->treeVec[(2 * index) + 2]);
  }
  throw std::out_of_range ("Access to null pointer");
}


template <typename Data>
inline const ulong BinaryTreeVec<Data>::NodeVec:: GetIndex () const {
  return index;
}

/* ************************************************************************ */

//default constructors
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec() {
  for (uint i=0; i<7; ++i) {
    treeVec[i] = nullptr;
  }
}

// Specific constructors

//Copy of the value
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec (const Data& newInfo) {
  for (uint i=0; i<7; ++i) {
    treeVec[i] = nullptr;
  }
  NodeVec * root = new NodeVec (newInfo, 0);
  treeVec[0] = root;
  height[0] = 1;
  root->cur = this;
  size++;
}


//Move of the value
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec (Data&& newInfo) noexcept {
  for (uint i=0; i<7; ++i) {
    treeVec[i] = nullptr;
  }
  NodeVec * root = new NodeVec (std::move(newInfo), 0);
  treeVec[0] = root;
  height[0] = 1;
  root->cur = this;
  size++;
}


// Copy constructor
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec (const BinaryTreeVec<Data>& copia) {
  treeVec.Resize(copia.treeVec.Size());
  for (uint i=0; i<treeVec.Size(); ++i) {
    treeVec[i] = nullptr;
  }
  for (uint i=0; i<copia.treeVec.Size(); ++i) {
    if (copia.treeVec[i] != nullptr) {
      treeVec[i] = new NodeVec (copia.treeVec[i]->info, i);
      treeVec[i]->cur = this;
    }
  }
  height.Resize (copia.height.Size());
  for (uint i=0; i<copia.height.Size(); ++i) {
    height[i] = copia.height[i];
  }
  size = copia.size;
}

// Move constructor
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec (BinaryTreeVec<Data>&& sposta) noexcept {
  treeVec.Resize (sposta.treeVec.Size());
  for (uint i=0; i<treeVec.Size(); ++i) {
    treeVec[i] = nullptr;
  }
  for(int i=0; i<treeVec.Size(); ++i){
    if(sposta.treeVec[i] != nullptr){
      std::swap (treeVec[i], sposta.treeVec[i]);
      sposta.treeVec[i] = nullptr;
      treeVec[i]->cur = this;
    }
  }
  height.Resize (sposta.height.Size());
  for(uint i=0; i<height.Size(); ++i){
    std:: swap (height[i], sposta.height[i]);
    sposta.height[i] = 0;
  }
  std:: swap (size, sposta.size);
}


/* ************************************************************************ */


// Destructor
template <typename Data>
BinaryTreeVec<Data>:: ~BinaryTreeVec() {
  Remove(treeVec[0]);
}

/* ************************************************************************ */

// Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>:: operator = (const BinaryTreeVec<Data>& assegna) {
  Clear();
  treeVec.Resize(assegna.treeVec.Size());
  for (uint i=0; i<treeVec.Size(); ++i) {
    treeVec[i] = nullptr;
  }
  for (uint i=0; i<assegna.treeVec.Size(); ++i) {
    if (assegna.treeVec[i] != nullptr) {
      treeVec[i] = new NodeVec (assegna.treeVec[i]->info, i);
      treeVec[i]->cur = this;
    }
  }
  height.Resize (assegna.height.Size());
  for (uint i=0; i<assegna.height.Size(); ++i) {
    height[i] = assegna.height[i];
  }
  size = assegna.size;
  return * this;
}


// Move assignment
template <typename Data>
BinaryTreeVec<Data>&  BinaryTreeVec<Data>::operator = (BinaryTreeVec<Data>&& vecchio) noexcept {
  Clear();
  treeVec.Resize (vecchio.treeVec.Size());
  for (uint i=0; i<treeVec.Size(); ++i) {
    treeVec[i] = nullptr;
  }
  for(int i=0; i<treeVec.Size(); ++i){
    if(vecchio.treeVec[i] != nullptr){
      std::swap (treeVec[i], vecchio.treeVec[i]);
      treeVec[i]->cur = this;
    }
  }
  height.Resize (vecchio.height.Size());
  for(uint i=0; i<height.Size(); ++i){
    std:: swap (height[i], vecchio.height[i]);
    vecchio.height[i] = 0;
  }
  std:: swap (size, vecchio.size);
  vecchio.Clear();
  return * this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
bool BinaryTreeVec<Data>:: operator == (const BinaryTreeVec<Data>& verifica) const noexcept {
  if (size != verifica.size) {
    return false;
  }
  else {
    uint curs = 0;
    while (curs < verifica.treeVec.Size() && curs < treeVec.Size()) {
      if ((treeVec[curs] != nullptr && verifica.treeVec[curs] != nullptr) ) {
        if (treeVec[curs]->info != verifica.treeVec[curs]->info) {
          return false;
        }
        curs ++;
      }
      else if (treeVec[curs] == nullptr && verifica.treeVec[curs] == nullptr) {
        curs ++;
      }
      else {
        return false;
      }
    }
    if (curs < verifica.treeVec.Size() || curs < treeVec.Size()) {
      return false;
    }
  }
  return true;
}


template <typename Data>
inline bool BinaryTreeVec<Data>:: operator != (const BinaryTreeVec<Data>& verifica) const noexcept {
  return !(*this == verifica);
}


/* ************************************************************************ */

// Specific member functions (inherited from BinaryTree)

template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec& BinaryTreeVec<Data>:: Root() const {
  if (treeVec[0] != nullptr) {
    return * (treeVec[0]);
  }
  throw std::length_error ("Access to an empty Tree!");
}


template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec& BinaryTreeVec<Data>:: NewRoot (const Data& newRoot) {
  if (treeVec[0] == nullptr) {
    NodeVec * root = new NodeVec (newRoot, 0);
    treeVec[0] = root;
    root->cur = this;
    height[0] = 1;
  }
  else {
    RemoveLeftChild (*(treeVec[0]));
    RemoveRightChild (*(treeVec[0]));
    treeVec[0]->info = newRoot;
  }
  size = 1;
  return *(treeVec[0]);
}


template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec& BinaryTreeVec<Data>:: NewRoot (Data&& newRoot) noexcept {
  if (treeVec[0] == nullptr) {
    NodeVec * root = new NodeVec (std::move(newRoot), 0);
    treeVec[0] = root;
    root->cur = this;
    height[0] = 1;
  }
  else {
    RemoveLeftChild (*(treeVec[0]));
    RemoveRightChild (*(treeVec[0]));
    treeVec[0]->info = std::move(newRoot);
  }
  size = 1;
  return *(treeVec[0]);
}


template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec&  BinaryTreeVec<Data>:: AddLeftChild (NodeVec& node, const Data& newInfo) {
  if (node.HasLeftChild()) {
    RemoveLeftChild (node);
  }
  if (((2 * node.index) + 1) >= (treeVec.Size())) {
      Expand();
  }
  NodeVec * newNode = new NodeVec (newInfo, (2 * node.index) + 1);
  treeVec[(2 * node.index) + 1] = newNode;
  newNode->cur = this;
  height[log2((2 * node.index) +2)] ++;
  size ++;
  return * (treeVec [(2 * node.index) + 1]);
}


template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec& BinaryTreeVec<Data>:: AddLeftChild (NodeVec& node, Data&& newInfo) noexcept {
  if (node.HasLeftChild()) {
    RemoveLeftChild (node);
  }
  if (((2 * node.index) + 1) >= (treeVec.Size())) {
      Expand();
  }
  NodeVec * newNode = new NodeVec (std::move(newInfo), (2 * node.index) + 1);
  treeVec[(2 * node.index) + 1] = newNode;
  newNode->cur = this;
  height[log2((2 * node.index) +2)] ++;
  size ++;
  return * (treeVec [(2 * node.index) + 1]);
}


template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec& BinaryTreeVec<Data>:: AddRightChild (NodeVec& node, const Data& newInfo) {
  if (node.HasRightChild()) {
    RemoveRightChild (node);
  }
  if (((2 * node.index) + 2) >= (treeVec.Size())) {
    Expand();
  }
  NodeVec * newNode = new NodeVec (newInfo, (2 * node.index) + 2);
  treeVec[(2 * node.index) + 2] = newNode;
  newNode->cur = this;
  height[log2((2 * node.index) +3)] ++;
  size ++;
  return * (treeVec [(2 * node.index) + 2]);
}


template <typename Data>
typename BinaryTreeVec<Data>:: NodeVec& BinaryTreeVec<Data>:: AddRightChild (NodeVec& node, Data&& newInfo) noexcept {
  if (node.HasRightChild()) {
    RemoveRightChild (node);
  }
  if (((2 * node.index) + 2) >= (treeVec.Size())) {
      Expand();
  }
  NodeVec * newNode = new NodeVec (std::move(newInfo), (2 * node.index) + 2);
  treeVec[(2 * node.index) + 2] = newNode;
  newNode->cur = this;
  height[log2((2 * node.index) +3)] ++;
  size ++;
  return * (treeVec [(2 * node.index) + 2]);
}


template <typename Data>
void BinaryTreeVec<Data>:: RemoveLeftChild (NodeVec& old) {
  if (old.HasLeftChild()) {
      Remove (treeVec[(2 * old.index) +1]);
  }
  if (height[height.Size()-1] == 0) {
    Reduce();
  }
}


template <typename Data>
void BinaryTreeVec<Data>:: RemoveRightChild (NodeVec& old) {
  if (old.HasRightChild()) {
      Remove (treeVec[(2 * old.index) +2]);
  }
  if (height[height.Size()-1] == 0) {
    Reduce();
  }
}

/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
void BinaryTreeVec<Data>:: Clear() {
  Remove(treeVec[0]);
  height.Resize(3);
  for (uint i=0; i<height.Size(); ++i) {
    height[i] = 0;
  }
  treeVec.Resize(7);
  for (uint i=0; i<7; ++i) {
    treeVec[i] = nullptr;
  }
}

/* ************************************************************************ */

// Specific member functions (inherited from BreadthSearchableContainer)

template <typename Data>
void BinaryTreeVec<Data>:: MapBreadth (MapFunctor fun, void * par) {
  for (uint i=0; i<treeVec.Size(); ++i) {
    if (treeVec[i] != nullptr) {
      fun (treeVec[i]->info, par);
    }
  }
}


template <typename Data>
void BinaryTreeVec<Data>:: FoldBreadth (FoldFunctor fun, const void * par , void * acc) const {
  for (uint i=0; i<treeVec.Size(); ++i) {
    if (treeVec[i] != nullptr) {
      fun (treeVec[i]->info, par, acc);
    }
  }
}


/* ************************************************************************ */

// Accessory function

template <typename Data>
void BinaryTreeVec<Data>:: Expand()  {
  ulong j = treeVec.Size();
  treeVec.Resize (pow(2,(height.Size() + 1))-1);
  for (uint i=j; i<treeVec.Size(); ++i) {
    treeVec[i] = nullptr;
  }
  height.Resize(height.Size() + 1);
}


template <typename Data>
void BinaryTreeVec<Data>:: Reduce() {
  uint i = 0;
  while (height[i] != 0) {
    i++ ;
  }
  height.Resize (i);
  treeVec.Resize (pow(2,(height.Size()))-1);
}


template <typename Data>
void BinaryTreeVec<Data>:: Remove (NodeVec * old) {
  if (old != nullptr) {
    if (old->HasLeftChild()) {
      Remove (treeVec[(2 * old->index) +1]);
    }
    if (old->HasRightChild()) {
      Remove (treeVec[(2 * old->index) +2]);
    }
    height[log2(old->index +1)] -- ;
    treeVec[old->index] = nullptr;
    delete old;
    size--;
  }
}
