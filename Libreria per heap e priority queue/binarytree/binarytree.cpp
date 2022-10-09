
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>:: operator == (const BinaryTree<Data>& verifica) const noexcept {
  if (size != verifica.size) {
    return false;
  }
  if (size == 0 && verifica.size == 0) {
    return true;
  }
  return IdenticalTree (Root(), verifica.Root());
}

template <typename Data>
inline bool BinaryTree<Data>:: operator != (const BinaryTree<Data>& verifica) const noexcept {
  return !(*this == verifica);
}

/* ************************************************************************ */

template <typename Data>
inline void BinaryTree<Data>:: MapInOrder (MapFunctor fun, void * par) {
   MapInOrder (fun, par, &Root());
}

template <typename Data>
inline void BinaryTree<Data>:: FoldInOrder (FoldFunctor fun, const void * par, void * acc) const {
  FoldInOrder (fun, par, acc, &Root());
}


/* ************************************************************************ */

// Specific member functions (inherited from SearchableContainer)

template <typename Data>
inline void BinaryTree<Data>:: MapPreOrder (MapFunctor fun, void * par) {
  MapPreOrder (fun, par, &Root());
}

template <typename Data>
inline void BinaryTree<Data>:: MapPostOrder (MapFunctor fun, void * par) {
  MapPostOrder (fun, par, &Root());
}

template <typename Data>
inline void BinaryTree<Data>:: FoldPreOrder (FoldFunctor fun, const void * par, void * acc) const {
  FoldPreOrder (fun, par, acc, &Root());
}

template <typename Data>
inline void BinaryTree<Data>:: FoldPostOrder (FoldFunctor fun, const void * par, void * acc) const {
  FoldPostOrder (fun, par, acc, &Root());
}

/* ************************************************************************ */

// Specific member functions (inherited from BreadthSearchableContainer)

template <typename Data>
inline void BinaryTree<Data>:: MapBreadth (MapFunctor fun, void * par) {
  MapBreadth (fun, par, &Root());
}

template <typename Data>
inline void BinaryTree<Data>:: FoldBreadth (FoldFunctor fun, const void * par, void * acc) const {
  FoldBreadth (fun, par, acc, &Root());
}

/* ************************************************************************ */

// Accessory function

template <typename Data>
bool BinaryTree<Data>:: IdenticalTree (const Node& root1, const Node& root2) const noexcept {
  if ((root1.IsLeaf() && root2.IsLeaf()) && (root1.Element() == root2.Element()) )  {
    return true;
  }
  if ( (!(root1.IsLeaf())) && (!(root2.IsLeaf())) ) {
    try {
      return (root1.Element() == root2.Element() && IdenticalTree (root1.LeftChild(), root2.LeftChild()) && IdenticalTree (root1.RightChild() , root2.RightChild()));
    }
    catch (std::exception& exc) {
      if ( ((!(root1.HasLeftChild() ))&& root2.HasLeftChild()) || (root1.HasLeftChild() && (!(root2.HasLeftChild()))) ) {
        return false;
      }
      if ( ((!(root1.HasRightChild() ))&& root2.HasRightChild()) || (root1.HasRightChild() && (!(root2.HasRightChild()))) ) {
        return false;
      }
       return true;
    }
  }
  return false;
}

// Accessory function executing from one node of the tree

template <typename Data>
void BinaryTree<Data>:: MapBreadth (MapFunctor fun, void * par, Node * node) {
  QueueVec<Node *> que;
  if (node != nullptr) {
    que.Enqueue (node);
    Node * temp;
    while (! que.Empty()) {
      temp = que.Head();
      if (temp != nullptr) {
        fun (temp->Element(), par);
        if (temp->HasLeftChild()) {
          que.Enqueue (&temp->LeftChild());
        }
        if (temp->HasRightChild()) {
          que.Enqueue (&temp->RightChild());
        }
      }
      que.Dequeue();
    }
  }
}


template <typename Data>
void BinaryTree<Data>:: MapPreOrder (MapFunctor fun, void * par, Node * node){
  if (node != nullptr) {
    fun (node->Element(), par);
    if (node->HasLeftChild()) {
      MapPreOrder (fun, par, &node->LeftChild());
    }
    if (node->HasRightChild()) {
      MapPreOrder (fun, par, &node->RightChild());
    }
  }
}


template <typename Data>
void BinaryTree<Data>:: MapInOrder (MapFunctor fun, void * par, Node * node) {
  if (node != nullptr) {
    if (node->HasLeftChild()) {
      MapInOrder (fun, par, &node->LeftChild());
    }
    fun (node->Element(), par);
    if (node->HasRightChild()) {
      MapInOrder (fun, par, &node->RightChild());
    }
  }
}


template <typename Data>
void BinaryTree<Data>:: MapPostOrder (MapFunctor fun, void * par, Node * node) {
  if (node != nullptr) {
    if (node->HasLeftChild()) {
      MapPostOrder (fun, par, &node->LeftChild());
    }
    if (node->HasRightChild()) {
      MapPostOrder (fun, par, &node->RightChild());
    }
    fun (node->Element(), par);
  }
}


template <typename Data>
void BinaryTree<Data>:: FoldBreadth (FoldFunctor fun, const void * par, void * acc, Node * node) const {
  QueueVec<Node *> que;
  if (node != nullptr) {
    que.Enqueue (node);
    Node * temp;
    while (! que.Empty()) {
      temp = que.Head();
      if (temp != nullptr) {
        fun (temp->Element(), par, acc);
        if (temp->HasLeftChild()) {
          que.Enqueue (&temp->LeftChild());
        }
        if (temp->HasRightChild()) {
          que.Enqueue (&temp->RightChild());
        }
      }
      que.Dequeue();
    }
  }
}


template <typename Data>
void BinaryTree<Data>:: FoldPreOrder (FoldFunctor fun, const void * par, void * acc, Node * node) const {
  if (node != nullptr) {
    fun (node->Element(), par, acc);
    if (node->HasLeftChild()) {
      FoldPreOrder (fun, par, acc, &node->LeftChild());
    }
    if (node->HasRightChild()) {
      FoldPreOrder (fun, par, acc, &node->RightChild());
    }
  }
}


template <typename Data>
void BinaryTree<Data>:: FoldInOrder (FoldFunctor fun, const void * par, void * acc, Node * node) const {
  if (node != nullptr) {
    if (node->HasLeftChild()) {
      FoldInOrder (fun, par, acc, &node->LeftChild());
    }
    fun (node->Element(), par, acc);
    if (node->HasRightChild()) {
      FoldInOrder (fun, par, acc, &node->RightChild());
    }
  }
}


template <typename Data>
void BinaryTree<Data>:: FoldPostOrder (FoldFunctor fun, const void * par, void * acc, Node * node) const {
  if (node != nullptr) {
    if (node->HasLeftChild()) {
      FoldPostOrder (fun, par, acc, &node->LeftChild());
    }
    if (node->HasRightChild()) {
      FoldPostOrder (fun, par, acc, &node->RightChild());
    }
    fun (node->Element(), par, acc);
  }
}
