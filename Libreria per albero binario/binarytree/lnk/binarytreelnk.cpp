
#include <stdexcept>

/* ********************************************************************** */

// Specific constructors (NodeLnk)

//Copy of the value
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk:: NodeLnk (const Data& newInfo) {
  info = newInfo;
  sx = dx = nullptr;
}


//Move of the value
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk:: NodeLnk (Data&& newInfo) noexcept {
  info = std::move(newInfo);
  sx = dx = nullptr;
}

/* ********************************************************************** */

// Specific member functions (inherited from Node)

template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk:: Element() {
  return info;
}


template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk:: Element() const {
  return info;
}


template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk:: IsLeaf() const noexcept {
  return (sx == nullptr && dx == nullptr);
}


template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk:: HasLeftChild() const noexcept {
 return (sx != nullptr);
}


template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk:: HasRightChild() const noexcept {
  return (dx != nullptr);
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk&  BinaryTreeLnk<Data>::NodeLnk:: LeftChild() const {
  if (sx != nullptr) {
    return * sx;
  }
  throw std::out_of_range ("Access to null pointer");
}


template <typename Data>
typename  BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>::NodeLnk:: RightChild() const {
  if (dx != nullptr) {
    return * dx;
  }
  throw std::out_of_range ("Access to null pointer");
}


/* ************************************************************************ */

// Specific constructors

//Copy of the value
template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk (const Data& newInfo) {
  root = new NodeLnk (newInfo);
  size ++ ;
}


//Move of the value
template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk (Data&& sposta) noexcept {
  root = new NodeLnk (std::move(sposta));
  size ++ ;
}


//Copy constructor
template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk (const BinaryTreeLnk<Data>& copia) {
  if (copia.root != nullptr) {
    root = CopyTree (copia.root);
  }
  else {
    root = nullptr;
  }
  size = copia.size;
}


//Move constructor
template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk (BinaryTreeLnk<Data>&& sposta) noexcept {
  std::swap (root, sposta.root);
  std::swap (size, sposta.size);
}


/* ************************************************************************ */

// Destructor
template <typename Data>
BinaryTreeLnk<Data>:: ~BinaryTreeLnk() {
  NodeLnk * temp = root;
  root = nullptr;
  Remove (temp);
}

/* ************************************************************************ */

/* ************************************************************************ */

// Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>:: operator  = (const BinaryTreeLnk<Data>& assegna) {
  BinaryTreeLnk<Data> * temp = new BinaryTreeLnk<Data> (assegna);
  std::swap (temp->root, root);
  size = assegna.size;
  temp->~BinaryTreeLnk();
  return * this;
}

// Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>:: operator = (BinaryTreeLnk<Data>&& vecchio) noexcept {
  std::swap (root, vecchio.root);
  std::swap (size, vecchio.size);
  vecchio.Clear();
return * this;
}

/* ************************************************************************ */

// Comparison operators

template <typename Data>
inline bool BinaryTreeLnk<Data>:: operator == (const BinaryTreeLnk<Data>& verifica) const noexcept {
  return IdenticalTreeLnk (root, verifica.root);
}


template <typename Data>
inline bool BinaryTreeLnk<Data>:: operator != (const BinaryTreeLnk<Data>& verifica) const noexcept {
  return !(*this == verifica);
}

/* ************************************************************************ */

// Specific member functions (inherited from BinaryTree)

template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>:: Root() const {
  if (root != nullptr) {
    return * root;
  }
  throw std::length_error ("Access to an empty Tree!");
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>:: NewRoot (const Data& newRoot) {
  if (root == nullptr) {
    root = new NodeLnk (newRoot);
  }
  else {
    RemoveLeftChild (*root);
    RemoveRightChild (*root);
    root->info = newRoot;
  }
  size = 1;
  return * root;
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>:: NewRoot (Data&& newRoot) noexcept {
  if (root == nullptr) {
    root = new NodeLnk (std::move(newRoot));
  }
  else {
    RemoveLeftChild (*root);
    RemoveRightChild (*root);
    root->info = std::move(newRoot);
  }
  size = 1;
  return * root;
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>:: AddLeftChild (NodeLnk& node, const Data& newInfo) {
  if (node.sx != nullptr) {
    RemoveLeftChild (node);
  }
  node.sx = new NodeLnk (newInfo);
  size ++;
  return * (node.sx);
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>:: AddLeftChild (NodeLnk& node, Data&& newInfo) noexcept {
  if (node.sx != nullptr) {
    RemoveLeftChild (node);
  }
  node.sx = new NodeLnk (std::move(newInfo));
  size ++;
  return * (node.sx);
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>:: AddRightChild (NodeLnk& node, const Data& newInfo) {
  if (node.dx != nullptr) {
    RemoveRightChild (node);
  }
  node.dx = new NodeLnk (newInfo);
  size ++;
  return *(node.dx);
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk& BinaryTreeLnk<Data>:: AddRightChild (NodeLnk& node, Data&& newInfo) noexcept {
  if (node.dx != nullptr) {
    RemoveRightChild (node);
  }
  node.dx = new NodeLnk (std::move(newInfo));
  size++;
  return *(node.dx);
}


template <typename Data>
void BinaryTreeLnk<Data>:: RemoveLeftChild (NodeLnk& old) {
  if (old.HasLeftChild()) {
      Remove(old.sx);
  }
  old.sx = nullptr;
}


template <typename Data>
void BinaryTreeLnk<Data>:: RemoveRightChild (NodeLnk& old) {
  if (old.HasLeftChild()) {
    Remove(old.dx);
  }
  old.dx = nullptr;
}

/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
void BinaryTreeLnk<Data>:: Clear() {
  Remove(root);
  root = nullptr;
}


/* ************************************************************************ */
//Accessory function

template <typename Data>
void BinaryTreeLnk<Data>:: Remove (NodeLnk * old) {
  if (old != nullptr) {
    Remove (old->sx);
    Remove (old->dx);
    delete old;
    size--;
  }
}


template <typename Data>
typename BinaryTreeLnk<Data>:: NodeLnk * BinaryTreeLnk<Data>:: CopyTree (NodeLnk * copia) {
  if (copia == nullptr) {
      return nullptr;
  }
  NodeLnk * node = new NodeLnk (copia->info);
  node->sx = CopyTree (copia->sx);
  node->dx = CopyTree (copia->dx);
  return node;
}


template <typename Data>
bool BinaryTreeLnk<Data>:: IdenticalTreeLnk (const NodeLnk * root1, const NodeLnk * root2) const noexcept {
  if ( (root1 == root2) || (root1 == nullptr && root2 == nullptr))  {
    return true;
  }
  if (root1 != nullptr && root2 != nullptr) {
    return (root1->info == root2->info && IdenticalTreeLnk (root1->sx, root2->sx) && IdenticalTreeLnk (root1->dx , root2->dx));
  }
  return false;
}
