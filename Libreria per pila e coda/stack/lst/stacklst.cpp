
#include <stdexcept>

/* ************************************************************************** */

// Default constructor
template <typename Data>
StackLst<Data>:: StackLst() : List<Data> () {}


// Copy constructor
template <typename Data>
StackLst<Data>:: StackLst (const StackLst& stacklist) : List<Data> (stacklist) {}


// Move constructor
template <typename Data>
StackLst<Data>:: StackLst (StackLst&& stacklist) noexcept : List<Data> (std::move(stacklist)) {}


/* ************************************************************************ */

// Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (const StackLst& vecchio) {
  List<Data>:: operator = (vecchio);
  return * this;
}

// Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (StackLst&& assegna) noexcept {
  List<Data>:: operator = (std::move(assegna));
  return * this;
}


/* ************************************************************************ */


// Comparison operators

template <typename Data>
inline bool StackLst<Data>:: operator == (const StackLst& verifica) const noexcept {
  return List<Data>:: operator == (verifica);
}


template <typename Data>
inline bool StackLst<Data>:: operator != (const StackLst& verifica) const noexcept {
  return !(*this == verifica);
}


/* ************************************************************************ */


// Specific member functions (inherited from Stack)

template <typename Data>
inline Data& StackLst<Data>:: Top() const {
  return List<Data>:: Front();
}


template <typename Data>
inline void StackLst<Data>:: Pop() {
  List<Data>:: RemoveFromFront();
}


template <typename Data>
inline Data StackLst<Data>:: TopNPop() {
  return List<Data>:: FrontNRemove();
}


template <typename Data>
inline void StackLst<Data>:: Push (const Data& nuovaInfo) {
  List<Data>:: InsertAtFront (nuovaInfo);
}


template <typename Data>
inline void StackLst<Data>:: Push (Data&& nuovaInfo) noexcept {
  List<Data>:: InsertAtFront (std::move(nuovaInfo));
}

/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
inline void StackLst<Data>:: Clear() {
  List<Data>:: Clear();
}
