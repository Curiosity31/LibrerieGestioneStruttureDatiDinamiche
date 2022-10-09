
#ifndef AVL_HPP
#define AVL_HPP

/* ************************************************************************** */

#include "../bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class AVL : virtual public BST<Data> {

private:

  // ...

protected:

  using BST<Data>:: size;
  using BST<Data>:: root;


public:

  struct AVLNode : protected BST<Data>:: BSTNode {

protected:

   using BST<Data>::BSTNode:: info;
   int height = 0;

   // Specific constructors

   //Copy of the value
   AVLNode (const Data&);
   //Move of the value
   AVLNode (Data&&) noexcept;

   inline AVLNode * Left(); // Mutable access to the element
   inline const AVLNode *  Left() const; // Immutable access to the element
   inline AVLNode *  Right(); // Mutable access to the element
   inline const AVLNode *  Right() const; // Immutable access to the element


public:

  friend class AVL<Data>;

  };

  /* ************************************************************************ */

  // Default constructor
  AVL() = default;

  // Copy constructor
  AVL (const AVL<Data>&);

  // Move constructor
  AVL (AVL<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~AVL() = default;

  /* ************************************************************************ */

  // Copy assignment
  AVL<Data>& operator = (const AVL<Data>&);

  // Move assignment
  AVL<Data>& operator = (AVL<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const AVL<Data>&) const noexcept;
  inline bool operator != (const AVL<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline AVLNode& Root() const override; // Override BinaryTree member (might throw std::length_error)
  inline AVLNode& NewRoot (const Data&) override; // Override BinaryTree member (Copy of the value)
  inline AVLNode& NewRoot (Data&&) noexcept override; // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  void Insert (const Data&) override; // Copy of the value
  void Insert (Data&&) noexcept override; // Move of the value
  void Remove (const Data&) override;

  Data MinNRemove() override; // (might throw std::length_error)
  void RemoveMin() override; // (might throw std::length_error)

  Data MaxNRemove() override; // (might throw std::length_error)
  void RemoveMax() override; // (might throw std::length_error)

  Data PredecessorNRemove (const Data&) override; // (might throw std::length_error)
  void RemovePredecessor (const Data&) override; // (might throw std::length_error)

  Data SuccessorNRemove (const Data&) override; // (might throw std::length_error)
  void RemoveSuccessor (const Data&) override; // (might throw std::length_error)

  /* ************************************************************************ */

protected:

  AVLNode * CopyAvl (AVLNode *);
  int Height (AVLNode *) const noexcept;
  AVLNode * Insert (AVLNode *, const Data&);
  AVLNode * BilanciaSx (AVLNode *);
  AVLNode * BilanciaDx (AVLNode *);
  AVLNode * RotazioneDx (AVLNode *);
  AVLNode * RotazioneSx (AVLNode *);
  AVLNode * RotazioneSdx (AVLNode *);
  AVLNode * RotazioneDsx (AVLNode *);
  AVLNode * Remove (AVLNode *, const Data&);

};

}

/* ************************************************************************** */

#include "avl.cpp"

/* ************************************************************************** */

#endif
