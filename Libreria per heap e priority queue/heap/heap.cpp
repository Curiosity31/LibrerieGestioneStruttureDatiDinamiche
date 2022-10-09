

/* ********************************************************************** */

//Protected member functions

template <typename Data>
void Heap<Data>:: BuildTree (const LinearContainer<Data>& commute, uint siz) {
  if (siz != 0) {
    this->NewRoot (commute[0]);
    uint j = 1;
    for (uint i = 0; i < siz/2; ++i) {
      if (2*i+1 < siz) {
        this->AddLeftChild (*(treeVec[i]), commute[j]);
        j++;
      }
      if (2*i+2 < siz) {
        this->AddRightChild (*(treeVec[i]), commute[j]);
        j++;
      }
    }
  }
}


template <typename Data>
void Heap<Data>:: BuildHeap() {
  uint start = (size / 2) - 1;
  for (int i = start; i >= 0; i--) {
      Heapify (treeVec, i);
  }
}


template <typename Data>
void Heap<Data>:: Heapify (Vector <typename BinaryTreeVec<Data>:: NodeVec*>& vec, uint i) {
  uint min = i;
  uint left = 2 * i + 1;
  uint right = 2 * i + 2;

  if ( (left < size) && (vec[left]->Element() <  vec[min]->Element()) ) {
    min = left;
  }
  if ( (right < size) && (vec[right]->Element() < vec[min]->Element()) ) {
    min = right;
  }
  if (min != i) {
    std::swap (vec[i]->Element(), vec[min]->Element());
    Heapify (vec, min);
  }
}


/* ********************************************************************** */
// Specific constructors

template <typename Data>
Heap<Data>:: Heap (const LinearContainer<Data>& commute) {
  BuildTree (commute, commute.Size());
  BuildHeap();
}


// Copy constructor
template <typename Data>
Heap<Data>:: Heap (const Heap<Data>& copia) : BinaryTreeVec<Data> (copia) { }


// Move constructor
template <typename Data>
Heap<Data>:: Heap (Heap<Data>&& sposta) noexcept : BinaryTreeVec<Data> (std::move(sposta)) { }


/* ************************************************************************ */

// Copy assignment
template <typename Data>
Heap<Data>& Heap<Data>:: operator = (const Heap<Data>& assegna) {
  BinaryTreeVec<Data>:: operator = (assegna);
  return * this;
}

// Move assignment
template <typename Data>
Heap<Data>& Heap<Data>:: operator = (Heap<Data>&& vecchio) noexcept {
  BinaryTreeVec<Data>:: operator = (std::move(vecchio));
  return * this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
inline bool Heap<Data>:: operator == (const Heap<Data>& verifica) const noexcept {
 return BinaryTreeVec<Data>:: operator == (verifica);
}


template <typename Data>
inline bool Heap<Data>::  operator != (const Heap<Data>& verifica) const noexcept {
  return (!(*this == verifica));
}

/* ************************************************************************ */

// Specific member functions

template <typename Data>
void Heap<Data>:: Sort() {
  int heapSize = size;
  for (int i = size-1; i>0; i--) {
    std::swap (treeVec[0]->Element(), treeVec[i]->Element());
    size --;
    Heapify (treeVec, 0);
  }
  size = heapSize;
  for (uint i=0; i<(size/2); ++i) {
    std::swap (treeVec[i]->Element(), treeVec[heapSize-1]->Element());
    heapSize -- ;
  }
}


/* ************************************************************************ */

// Specific member functions (inherited from SearchableContainer)


template <typename Data>
void Heap<Data>:: MapPreOrder (MapFunctor fun, void * par) {
  for (uint i=0; i<size; ++i) {
    fun (treeVec[i]->Element(), par);
  }
  BuildHeap();
}


template <typename Data>
void Heap<Data>::  MapPostOrder (MapFunctor fun, void * par) {
  for (int i=size-1; i>=0; i--) {
    fun (treeVec[i]->Element(), par);
    if ( (i < size/2) ) {
      Heapify (treeVec, i);
    }
  }
}


template <typename Data>
void Heap<Data>:: FoldPreOrder (FoldFunctor fun, const void * par, void * acc) const {
  for (uint i=0; i<size; ++i) {
     fun (treeVec[i]->Element(), par, acc);
  }
}


template <typename Data>
void Heap<Data>:: FoldPostOrder (FoldFunctor fun, const void * par, void * acc) const {
  for (int i=size-1; i>=0; i--) {
     fun (treeVec[i]->Element(), par, acc);
  }
}
