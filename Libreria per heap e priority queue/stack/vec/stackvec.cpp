
#include <stdexcept>

/* ************************************************************************** */

// Default constructor
template <typename Data>
StackVec<Data>::StackVec() : Vector<Data> (8) {
  index = 0;
}


// Copy constructor
template <typename Data>
StackVec<Data>::StackVec (const StackVec& stk) : Vector<Data>(stk) {
  index = stk.index;
}


// Move constructor
template <typename Data>
StackVec<Data>::StackVec (StackVec&& stk) noexcept : Vector<Data>(std::move(stk)) {
  std::swap(index, stk.index);
}


/* ************************************************************************ */


// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (const StackVec& vecchio) {
  Vector<Data>:: operator = (vecchio);
  index = vecchio.index;
  return * this;
}


// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (StackVec&& assegna) noexcept {
  std::swap(index, assegna.index);
  Vector<Data>:: operator = (std::move (assegna));
  return * this;
}


/* ************************************************************************ */


// Comparison operators

template <typename Data>
bool StackVec<Data>:: operator == (const StackVec& verifica) const noexcept{
  uint i = 0;
  if (index != verifica.index) {
    return false;
  }
  else {
    while (i < verifica.index) {
      if (elements[i] == verifica.elements[i]) {
        i++;
      }
      else {
        return false;
      }
    }
    return true;
  }
}


template <typename Data>
inline bool StackVec<Data>:: operator != (const StackVec& verifica) const noexcept {
  return !(* this == verifica);
}


/* ************************************************************************ */

// Specific member functions (inherited from Stack)

template <typename Data>
Data& StackVec<Data>:: Top() const {
  if (index != 0) {
    return elements[index-1];
  }
  else{
    throw std::length_error ("Access to an empty stack");
  }
}


template <typename Data>
void StackVec<Data>:: Pop() {
  if (index != 0) {
    index -- ;
    if (size > (index * 4)){
      Reduce ();
    }
  }
  else{
    throw std::length_error ("Access to an empty stack");
  }
}


template <typename Data>
Data StackVec<Data>:: TopNPop() {
  Pop();
  return elements[index];
}


template <typename Data>
void StackVec<Data>:: Push (const Data& inser) {
  if (size == index) {
    Expand ();
  }
  elements[index] = inser;
  index ++ ;
}


template <typename Data>
void StackVec<Data>:: Push (Data&& inser) noexcept {
  if (size == index) {
    Expand ();
  }
  elements[index] = std::move(inser);
  index ++ ;
}


/* ************************************************************************ */

// Specific member functions (inherited from Container)


template <typename Data>
inline bool StackVec<Data>:: Empty() const noexcept {
  return (index == 0);
}


template <typename Data>
inline ulong StackVec<Data>:: Size() const noexcept {
  return index;
}


template <typename Data>
void StackVec<Data>:: Clear() {
  Vector<Data>:: Clear();
  index = 0;
  Vector<Data> :: Resize (8);
}


// Accessory function
template <typename Data>
inline void StackVec<Data>:: Expand() {
  Vector<Data> :: Resize (index * 2);
}


// Accessory function
template <typename Data>
inline void StackVec<Data>:: Reduce() {
  Vector<Data>:: Resize (size * 0.5);
}
