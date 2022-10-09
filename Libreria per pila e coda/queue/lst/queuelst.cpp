
#include <stdexcept>

/* ************************************************************************** */

// Default constructor
template <typename Data>
QueueLst<Data>:: QueueLst() : List<Data> () {}

// Copy constructor
template <typename Data>
QueueLst<Data>:: QueueLst (const QueueLst& queuelist) : List<Data> (queuelist) {}

// Move constructor
template <typename Data>
QueueLst<Data>:: QueueLst (QueueLst&& queuelist) noexcept : List<Data> (std::move(queuelist)) {}

/* ************************************************************************ */


// Copy assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (const QueueLst& vecchio) {
  List<Data>:: operator = (vecchio);
  return * this;
}

// Move assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (QueueLst&& assegna) noexcept {
  List<Data>:: operator = (std::move(assegna));
  return * this;
}


/* ************************************************************************ */


// Comparison operators

template <typename Data>
inline bool QueueLst<Data>:: operator == (const QueueLst& verifica) const noexcept {
  return List<Data>:: operator == (verifica);
}


template <typename Data>
inline bool QueueLst<Data>:: operator != (const QueueLst& verifica) const noexcept {
  return !(*this == verifica);
}


/* ************************************************************************ */


// Specific member functions (inherited from Queue)

template <typename Data>
inline Data& QueueLst<Data>:: Head() const {
  return List<Data>:: Front();
}


template <typename Data>
inline void QueueLst<Data>:: Dequeue() {
  List<Data>:: RemoveFromFront();
}


template <typename Data>
inline Data QueueLst<Data>:: HeadNDequeue() {
  return List<Data>:: FrontNRemove();
}


template <typename Data>
inline void QueueLst<Data>:: Enqueue (const Data& nuovaInfo) {
  List<Data>:: InsertAtBack (nuovaInfo);
}


template <typename Data>
inline void QueueLst<Data>:: Enqueue (Data&& nuovaInfo) noexcept {
  List<Data>:: InsertAtBack (std::move (nuovaInfo));
}

/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
inline void QueueLst<Data>:: Clear() {
  List<Data>:: Clear();
}


/* ************************************************************************** */
