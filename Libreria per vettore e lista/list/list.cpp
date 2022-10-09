
#include <stdexcept>

/* ************************************************************************** */

// Specific constructors
template <typename Data>
List<Data>::Node:: Node (const Data& nuovaInfo,  Node * nxt) {
  info = nuovaInfo;
  next = nxt;
}


// Copy constructor
template <typename Data>
List<Data>:: Node::Node (const Node& copia) {
  info = copia.info;
  next = nullptr;
}


// Move constructor
template <typename Data>
List<Data>::Node:: Node (Node&& sposta) noexcept {
  std::swap (info, sposta->info);
  std::swap (next, sposta->next);
}


// Comparison operators
template <typename Data>
inline bool List<Data>::Node:: operator == (const Node& verifica) const noexcept{
  return (info == verifica.info);
}

template <typename Data>
inline bool List<Data>::Node:: operator != (const Node& verifica) const noexcept{
  return !(*this == verifica);
}


/* ************************************************************************** */


// Copy constructor
template <typename Data>
List<Data>:: List (const List<Data>& lista) {
  if (lista.size == 0) {
    List();
  }
  else {
    this->head = new Node (*(lista.head));
    Node * curL  = lista.head;
    Node * curH = head;
    while (curL->next != nullptr) {
      curH->next = new Node (*curL->next);
      curH = curH->next;
      curL = curL->next;
    }
    tail = curL;
    size = lista.size;
  }
}


// Move constructor
template <typename Data>
List<Data>:: List(List&& lista) noexcept {
  std::swap (head, lista.head);
  std::swap (tail, lista.tail);
  std::swap (size, lista.size);
}


// Destructor
template <typename Data>
List<Data>:: ~List() {
  Node * temp = head;
  while (temp != nullptr) {
    temp = head->next;
    delete head;
    head = temp;
  }
  tail = temp;
}


//copy assignment
template <typename Data>
List<Data>& List<Data>:: operator = (const List& assegna) {
  List<Data>  * temp = new List<Data> (assegna);
  std::swap (temp->head, this->head);
  std::swap (temp->tail, this->tail);
  (* temp).~List ();
  size = assegna.size;
  return * this;
}


// Move assignment
template <typename Data>
List<Data>&  List<Data>:: operator = (List&& vecchio) noexcept {
  std::swap (head, vecchio.head);
  std::swap (tail, vecchio.tail);
  std::swap (size, vecchio.size);
  vecchio.Clear();
  return * this;
}


// Comparison operators
template <typename Data>
bool List<Data>:: operator == (const List& verifica) const noexcept {
  if (size != verifica.size) {
    return false;
  }
  else {
    Node * curV = verifica.head;
    Node * curT = head;
    while (curV != nullptr) {
      if (* curV == * curT) {
        curV = curV->next;
        curT = curT->next;
      }
      else {
        return false;
      }
    }
    return true;
  }
}


template<typename Data>
inline bool List<Data>:: operator != (const List& verifica) const noexcept{
  return !(*this == verifica);
}


/* ************************************************************************ */


// RemoveFromFront
template <typename Data>
void List<Data>:: RemoveFromFront() {
  if (size != 0) {
    Node * temp;
    temp = head->next;
    delete head;
    head = temp;
    size -- ;
  }
  else {
    throw std::length_error ("Access to an empty List!");
  }
}


//FrontNRemove
template <typename Data>
Data List<Data>:: FrontNRemove() {
  if (size != 0) {
    Data elem = head->info;
    RemoveFromFront ();
    return elem;
  }
  else {
    throw std::length_error ("Access to an empty List!");
  }
}


//InsertAtFront (copy of the value)
template <typename Data>
void List<Data>:: InsertAtFront (const Data& nuovaInfo) {
  List<Data>:: Node * nuovoNodo = new List<Data>::Node (nuovaInfo, head);
  if (size == 0){
    tail = nuovoNodo;
  }
  head = nuovoNodo;
  size ++;
}


//InsertAtFront  (move of the value)
template <typename Data>
void List<Data>:: InsertAtFront (Data&& nuovaInfo) noexcept {
  List<Data>:: Node * nuovoNodo = new List<Data>::Node (std::move(nuovaInfo), head);
  if (size == 0){
    tail = nuovoNodo;
  }
  head = nuovoNodo;
  size ++;
}


// InsertAtBack (copy of the value)
template <typename Data>
void List<Data>:: InsertAtBack (const Data& nuovaInfo) {
  Node * nuovoNodo = new Node (nuovaInfo, nullptr);
  if (size == 0) {
      head = nuovoNodo;
  }
  else {
    Node * temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = nuovoNodo;
  }
  tail = nuovoNodo;
  size ++ ;
}



//InsertAtBack  (move of the value)
template <typename Data>
void List<Data>:: InsertAtBack (Data&& nuovaInfo) noexcept {
  Node * nuovoNodo = new Node (std::move(nuovaInfo), nullptr);
  if (size == 0) {
      head = nuovoNodo;
  }
  else {
    Node * temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = nuovoNodo;
  }
  tail = nuovoNodo;
  size ++ ;
}


/* ************************************************************************ */


//Clear
template <typename Data>
void List<Data>:: Clear() {
  this->~List();
  size = 0;
}


/* ************************************************************************ */


//Front
template <typename Data>
Data& List<Data>:: Front() const {
  if (size != 0)
    return head->info;
  else {
    throw std::length_error ("Access to an empty List!");
  }
}



//Back
template <typename Data>
Data& List<Data>:: Back() const {
  if (size != 0) {
    return tail->info;
  }
  else {
    throw std::length_error ("Access to an empty List!");
  }
}


// Operator []
template <typename Data>
Data& List<Data>:: operator[] (const ulong indice)  {
  if (indice < size){
    Node * temp = head;
    for (ulong i=0; i<indice; i++) {
      temp = temp->next;
    }
    return temp->info;
  }
  else {
    throw std::out_of_range ("Access at index " + std::to_string(indice) + "; List size " + std::to_string(size)+".");
  }
}


/* ************************************************************************ */


// Specific member functions (inherited from SearchableContainer)


template <typename Data>
inline void List<Data>:: MapPreOrder (MapFunctor fun, void * par) {
  MapPreOrder (fun, head, par);
}


template <typename Data>
inline void List<Data>:: MapPostOrder(MapFunctor fun, void * par) {
  MapPostOrder (fun, head, par);
}


template <typename Data>
inline void List<Data>:: FoldPreOrder (FoldFunctor fun, const void * par, void * acc) const {
  FoldPreOrder (fun, head, par, acc);
}


template <typename Data>
inline void List<Data>:: FoldPostOrder (FoldFunctor fun, const void * par, void * acc) const {
  FoldPostOrder (fun, head, par, acc);
}


//Accessory function executing from one point of the list onwards (protected member functions)

template <typename Data>
void List<Data>:: MapPreOrder (MapFunctor fun, Node * indice, void * par) {
  while (indice != nullptr) {
    fun (indice->info, par);
    indice = indice->next;
  }
}


template <typename Data>
void List<Data>:: MapPostOrder (MapFunctor fun, Node * indice, void * par) {
  if (indice != nullptr) {
    MapPostOrder (fun, indice->next, par);
    fun (indice->info, par);
  }
}



template <typename Data>
void List<Data>:: FoldPreOrder (FoldFunctor fun , Node * indice , const void * par , void * acc) const {
  while (indice != nullptr) {
    fun (indice->info, par, acc);
    indice = indice->next;
  }
}


template <typename Data>
void List<Data>:: FoldPostOrder(FoldFunctor fun,  Node * indice, const void * par, void * acc) const {
  if (indice != nullptr) {
    FoldPostOrder (fun, indice->next, par, acc);
    fun (indice->info, par, acc);
  }
}
