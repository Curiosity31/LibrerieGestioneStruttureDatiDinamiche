
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


template <typename Data>
class List : public LinearContainer<Data> , public SearchableContainer<Data> {

private:

  // ...

protected:

  using LinearContainer<Data>:: size;

  struct Node
  {

    Data info;
    Node * next = nullptr;
    // ...

    /* ********************************************************************** */

    // Specific constructors
    Node (const Data&, Node *);

    // Copy constructor
    Node (const Node&);

    // Move constructor
    Node (Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    ~Node () = default;


    /* ********************************************************************** */

    // Comparison operators
    inline bool operator == (const Node&) const noexcept;

    inline bool operator != (const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  Node * head = nullptr;
  Node * tail = nullptr;

public:

  // Default constructor
  List() = default;

  // Copy constructor
  List (const List&);

  // Move constructor
  List (List&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~List();

  /* ************************************************************************ */

  // Copy assignment
  List& operator = (const List&);

  // Move assignment
  List& operator = (List&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const List&) const noexcept;
  inline bool operator != (const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void RemoveFromFront();
  Data FrontNRemove();
  void InsertAtFront (const Data&); // Copy of the value
  void InsertAtFront (Data&&) noexcept; // Move of the value

  void InsertAtBack (const Data&); // Copy of the value
  void InsertAtBack (Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& Front() const override; // Override LinearContainer member
  Data& Back() const override; // Override LinearContainer member

  Data& operator[] (const ulong) override; // Override LinearContainer member
  Data& operator[] (const ulong) const override; // Override LinearContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename SearchableContainer<Data>::MapFunctor;
  inline void MapPreOrder (MapFunctor, void *) override; // Override SearchableContainer member
  inline void MapPostOrder (MapFunctor, void *) override; // Override SearchableContainer member

  using typename SearchableContainer<Data>::FoldFunctor;
  inline void FoldPreOrder (FoldFunctor, const void *, void *) const override; // Override SearchableContainer member
  inline void FoldPostOrder (FoldFunctor, const void *, void *) const override; // Override SearchableContainer member

protected:

  void MapPreOrder (MapFunctor, Node *, void *); // Accessory function executing from one point of the list onwards
  void MapPostOrder(MapFunctor, Node *, void *); // Accessory function executing from one point of the list onwards

  void FoldPreOrder (FoldFunctor, Node *, const void *, void *) const; // Accessory function executing from one point of the list onwards
  void FoldPostOrder(FoldFunctor, Node *, const void *, void *) const; // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

#include "list.cpp"

}

#endif
