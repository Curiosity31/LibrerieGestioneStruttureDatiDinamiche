
#include <stdexcept>


/* ********************************************************************** */

// Specific constructor
template <typename Data>
PriorityQueue<Data>:: PriorityQueue (const LinearContainer<Data>& commute) : Heap<Data> (commute) { }

// Copy constructor
template <typename Data>
PriorityQueue<Data>:: PriorityQueue (const PriorityQueue<Data>& copia) : Heap<Data> (copia) { }

// Move constructor
template <typename Data>
PriorityQueue<Data>:: PriorityQueue (PriorityQueue<Data>&& sposta) noexcept : Heap<Data> (std::move(sposta)) { }

/* ************************************************************************ */


// Copy assignment
template <typename Data>
PriorityQueue<Data>& PriorityQueue<Data>:: operator = (const PriorityQueue<Data>& assegna) {
  Heap<Data>:: operator = (assegna);
  return * this;
}

// Move assignment
template <typename Data>
PriorityQueue<Data>& PriorityQueue<Data>::operator = (PriorityQueue<Data>&& vecchio) noexcept {
  Heap<Data>:: operator = (std::move(vecchio));
  return * this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
inline bool PriorityQueue<Data>::operator == (const PriorityQueue<Data>& verifica) const noexcept {
  return Heap<Data>:: operator == (verifica);
}


template <typename Data>
inline bool PriorityQueue<Data>:: operator != (const PriorityQueue<Data>& verifica) const noexcept {
  return (!(*this == verifica));
}

/* ************************************************************************ */


// Specific member functions

template <typename Data>
const Data&  PriorityQueue<Data>:: Tip() const  {
  if (size != 0) {
    return treeVec[0]->Element();
  }
  throw std::length_error ("Access to an empty Priority Queue!");
}


template <typename Data>
void PriorityQueue<Data>:: RemoveTip() {
  if (size != 0) {
    if (size != 1) {
      std::swap (treeVec[0]->Element(), treeVec[size-1]->Element());
      if ((size-1)%2 == 1) {
        this->RemoveLeftChild (treeVec[size-1]->Parent());
      }
      else {
        this->RemoveRightChild (treeVec[size-1]->Parent());
      }
      this->Heapify (treeVec, 0);
    }
    else {
      this->Clear();
    }
  }
  else {
    throw std::length_error ("Access to an empty Priority Queue!");
  }
}


template <typename Data>
Data PriorityQueue<Data>:: TipNRemove() {
  if (size != 0) {
    Data elem = treeVec[0]->Element();
    if (size != 1) {
      std::swap (treeVec[0]->Element(), treeVec[size-1]->Element());
      if ((size-1)%2 == 1) {
        this->RemoveLeftChild (treeVec[size-1]->Parent());
      }
      else {
        this->RemoveRightChild (treeVec[size-1]->Parent());
      }
      this->Heapify (treeVec, 0);
    }
    else {
      this->Clear();
    }
    return elem;
  }
  throw std::length_error ("Access to an empty Priority Queue!");
}


// Copy of the value
template <typename Data>
void PriorityQueue<Data>:: Insert (const Data& newInfo) {
  if (size != 0) {
    if (size%2 == 0) {
      this->AddRightChild (*(treeVec[(size/2)-1]), newInfo);
      ExactLocation (treeVec, size-1);
    }
    else  {
      this->AddLeftChild (*(treeVec[(size/2)]), newInfo);
      ExactLocation (treeVec, size-1);
    }
  }
  else {
    this->NewRoot (newInfo);
  }
}


// Move of the value
template <typename Data>
void PriorityQueue<Data>:: Insert (Data&& newInfo) noexcept {
  if (size != 0) {
    if (size%2 == 0) {
      this->AddRightChild (*(treeVec[(size/2)-1]), std::move(newInfo));
      ExactLocation (treeVec, size-1);
    }
    else  {
      this->AddLeftChild (*(treeVec[(size/2)]), std::move(newInfo));
      ExactLocation (treeVec, size-1);
    }
  }
  else {
    this->NewRoot (std::move(newInfo));
  }
}


//Copy of the value
template <typename Data>
void PriorityQueue<Data>:: ChangePriority (typename BinaryTreeVec<Data>:: NodeVec& node, const Data& elem) {
  if (treeVec[node.GetIndex()] != nullptr) {
    if (node.Element() < elem) {
      node.Element() = elem;
      if ( !(node.IsLeaf()) ) {
        this->Heapify (treeVec, node.GetIndex());
      }
    }
    else if (node.Element() > elem) {
      node.Element() = elem;
      if (node.HasParent()) {
        ExactLocation (treeVec, node.GetIndex());
      }
    }
  }
}


//Move of the value
template <typename Data>
void PriorityQueue<Data>:: ChangePriority (typename BinaryTreeVec<Data>:: NodeVec& node, Data&& elem) noexcept {
  if (treeVec[node.GetIndex()] != nullptr) {
    if (node.Element() < elem) {
      node.Element() = std::move(elem);
      if ( !(node.IsLeaf()) ) {
        this->Heapify (treeVec, node.GetIndex());
      }
    }
    else if (node.Element() > elem) {
      node.Element() = std::move(elem);
      if (node.HasParent()) {
        ExactLocation (treeVec, node.GetIndex());
      }
    }
  }
}


/* ************************************************************************ */

// Accessory function

template <typename Data>
void PriorityQueue<Data>:: ExactLocation (Vector<typename BinaryTreeVec<Data>:: NodeVec*>& vec, uint position) {
  while ((position > 0) && (vec[position]->Element() < vec[position]->Parent().Element()) ) {
    std::swap ( vec[position]->Element(), vec[position]->Parent().Element() );
    if (position % 2 == 0) {
      position = (position / 2) -1;
    }
    else {
      position = (position / 2);
    }
  }
}
