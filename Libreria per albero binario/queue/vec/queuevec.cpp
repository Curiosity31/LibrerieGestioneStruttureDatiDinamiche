
#include <stdexcept>

/* ************************************************************************** */

// Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data> (8) {
  head = 0;
  tail = 0;
}


// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec (const QueueVec& queuestk) : Vector<Data>(queuestk) {
  head = queuestk.head;
  tail = queuestk.tail;
}


// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec (QueueVec&&  queuestk) noexcept : Vector<Data>(std::move(queuestk)) {
  std::swap(head, queuestk.head);
  std::swap(tail, queuestk.tail);
}


/* ************************************************************************ */


// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator = (const QueueVec& vecchio) {
  Vector<Data>:: operator = (vecchio);
  head = vecchio.head;
  tail = vecchio.tail;
  return * this;
}

// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator = (QueueVec&& assegna) noexcept {
  std::swap(head, assegna.head);
  std::swap(tail, assegna.tail);
  Vector<Data>:: operator = (std::move(assegna));
  return * this;
}

/* ************************************************************************ */


// Comparison operators
template <typename Data>
bool QueueVec<Data>:: operator == (const QueueVec& verifica) const noexcept {
   if (Size() != verifica.Size()) {
     return false;
   }
   else {
      ulong temp1 = head;
      ulong temp2 = verifica.head;
      while (temp1 != tail) {
          if (elements[temp1] != verifica.elements[temp2]) {
              return false;
          }
          temp1 = (temp1 + 1) % size;
          temp2 = (temp2 + 1) % verifica.size;
        }
        return true;
    }
}


template <typename Data>
inline bool QueueVec<Data>::operator != (const QueueVec& verifica) const noexcept {
   return !(* this == verifica);
}

/* ************************************************************************ */

// Specific member functions (inherited from Queue)

template <typename Data>
Data& QueueVec<Data>:: Head() const {
  if (! Empty()) {
    return elements[head];
  }
  else {
    throw std::length_error ("Access to an empty queue");
  }
}


template <typename Data>
void QueueVec<Data>:: Dequeue() {
  if (! Empty()) {
    head = (head+1) % size;
    if (size > (Size() * 4)){
      Reduce ();
    }
  }
  else{
    throw std::length_error ("Access to an empty queue");
  }
}


template <typename Data>
Data QueueVec<Data>:: HeadNDequeue() {
  Data temp = elements[head];
  Dequeue();
  return temp;
}


template <typename Data>
void QueueVec<Data>:: Enqueue (const Data& inser) {
  if (head == ((tail+1)%size)) {
    Expand ();
  }
  elements[tail] = inser;
  tail = (tail + 1) % size;
}


template <typename Data>
void QueueVec<Data>:: Enqueue (Data&& inser) noexcept {
  if (head == ((tail+1)%size)) {
    Expand ();
  }
  elements[tail] = std::move(inser);
  tail = (tail + 1) % size;
}


/* ************************************************************************ */

// Specific member functions (inherited from Container)

template <typename Data>
inline bool QueueVec<Data>:: Empty() const noexcept {
  return (head == tail);
}


template <typename Data>
inline ulong QueueVec<Data>:: Size() const noexcept {
  return (head <= tail) ? (tail-head) : (size - (head - tail));
}


template <typename Data>
void QueueVec<Data>:: Clear() {
  Vector<Data>:: Clear();
  head = 0;
  tail = 0;
  Vector<Data> :: Resize (8);
}


template <typename Data>
void QueueVec<Data>:: Expand() {
  Data * tmpElem = new Data [size * 2];
  ulong ind = 0;
  while (head != tail) {
    std::swap (elements[head], tmpElem[ind]);
    head = ((head + 1) % size);
    ind ++ ;
  }
  head = 0;
  tail = ind;
  size = size * 2;
  std::swap (elements, tmpElem);
  delete [] tmpElem;
}


template <typename Data>
void QueueVec<Data>:: Reduce() {
  Data * tmpElem = new Data [size/2];
  ulong ind = 0;
  while (head != tail) {
    std::swap (elements[head], tmpElem[ind]);
    head = ((head + 1) % size);
    ind ++ ;
  }
  head = 0;
  tail = ind;
  size = size/2;
  std::swap (elements, tmpElem);
  delete [] tmpElem;
}
