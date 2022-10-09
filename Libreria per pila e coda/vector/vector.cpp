
#include <stdexcept>

/* ************************************************************************** */

//Specific constructor
template <typename Data>
Vector<Data>::Vector (const ulong taglia) {
  size = taglia;
  elements = new Data[taglia];
}


// Copy constructor
template <typename Data>
Vector<Data>::Vector (const Vector<Data>& vect){
  size = vect.size;
  elements = new Data[size];
  for (uint i = 0; i < size; ++i){
    elements[i] = vect.elements[i];
  }
}


// Move constructor
template <typename Data>
Vector<Data>::Vector (Vector<Data>&& vect) noexcept{
  std::swap (elements, vect.elements);
  std::swap (size, vect.size);
}


/* ************************************************************************** */


// Destructor
template <typename Data>
Vector<Data>:: ~Vector(){
  delete [] elements;
}


/* ************************************************************************** */


// Copy assignment
template <typename Data>
Vector<Data>& Vector<Data>:: operator = (const Vector<Data>& assegna){
  Vector<Data> * tmpvect = new Vector<Data>(assegna);
  std::swap (*tmpvect, *this);
  delete tmpvect;
  return * this;
}


// Move assignment
template <typename Data>
Vector<Data>&  Vector<Data>:: operator = (Vector<Data>&& vecchio) noexcept {
  std::swap (elements, vecchio.elements);
  std::swap (size, vecchio.size);
  vecchio.Clear();
  return * this;
}


/* ************************************************************************** */


// Comparison operators

// Equals
template <typename Data>
bool Vector<Data>:: operator == (const Vector<Data>& verifica) const noexcept{
  uint i = 0;
  if (size != verifica.size) {
    return false;
  }
  else {
    while (i < verifica.size) {
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


// Not Equals
template<typename Data>
inline bool Vector<Data>:: operator != (const Vector<Data>& verifica) const noexcept{
  return !(*this == verifica);
}


/* ************************************************************************** */


// Specific member functions

template <typename Data>
void Vector<Data>:: Resize (const ulong nuovaTaglia){
  if (nuovaTaglia == 0){
    Clear ();
  }
  else if (nuovaTaglia != size){
    ulong limit = (size < nuovaTaglia) ? size : nuovaTaglia;
    Data * tmpElem = new Data [nuovaTaglia];
    for(ulong i = 0; i < limit; i++){
      std::swap (elements[i], tmpElem[i]);
    }
    std::swap (elements, tmpElem);
    size = nuovaTaglia;
    delete[] tmpElem;
  }
}


/* ************************************************************************** */


template <typename Data>
void Vector<Data>:: Clear() {
  delete[] elements;
  elements = nullptr;
  size = 0;
}


/* ************************************************************************** */


// Specific member functions (inherited from LinearContainer)

template<typename Data>
Data& Vector<Data>:: Front() const {
 if (size !=0){
   return elements[0];
 }
 else{
   throw std::length_error ("Access to an empty vector");
 }
}


template<typename Data>
Data& Vector<Data>:: Back() const {
 if (size !=0){
   return elements[size-1];
 }
 else{
   throw std::length_error ("Access to an empty vector");
 }
}


template<typename Data>
Data& Vector<Data>:: operator[] (const ulong indice) {
   if (indice < size){
     return elements[indice];
   }
   else {
     throw std::out_of_range ("Access at index " + std::to_string(indice) + "; vector size"+ std::to_string(size)+".");
   }
}


/* ************************************************************************ */


// Specific member functions (inherited from SearchableContainer)

template<typename Data>
void Vector<Data>:: MapPreOrder (MapFunctor fun, void * par){
  for (ulong i = 0; i < size; i++){
    fun (elements[i], par);
  }
}


template<typename Data>
void Vector<Data>:: MapPostOrder(MapFunctor fun, void * par) {
  ulong i = size;
  while (i > 0) {
    fun(elements[--i], par);
  }
}


template<typename Data>
void Vector<Data>:: FoldPreOrder (FoldFunctor fun, const void * par, void * acc) const {
  for (ulong i = 0; i < size; i++){
    fun(elements[i], par, acc);
  }
}


template<typename Data>
void Vector<Data>:: FoldPostOrder (FoldFunctor fun, const void * par, void * acc) const {
  ulong i = size;
  while (i > 0) {
    fun(elements[--i], par, acc);
  }
}
