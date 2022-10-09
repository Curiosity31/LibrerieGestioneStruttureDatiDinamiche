
#ifndef RB_HPP
#define RB_HPP

/* ************************************************************************** */

#include "../bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class RB : virtual public  BST<Data> {

private:

  // ...

protected:

  using BST<Data>:: size;
  using BST<Data>:: root;

  enum Color {RED, BLACK, D_BLACK};

public:

  struct RBNode : protected BST<Data>:: BSTNode {

  protected:

    using BST<Data>::BSTNode:: info;

    Color color = RED;

    // Specific constructors

   //Copy of the value
   RBNode (const Data&);
   //Move of the value
   RBNode (Data&&) noexcept;

   inline RBNode * Left(); // Mutable access to the element
   inline const RBNode *  Left() const; // Immutable access to the element
   inline RBNode *  Right(); // Mutable access to the element
   inline const RBNode *  Right() const; // Immutable access to the element

  public:

    friend class RB<Data>;

  };

  /* ************************************************************************ */

  // Default constructor
  RB() = default;

  // Copy constructor
  RB (const RB<Data>&);

  // Move constructor
  RB (RB<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~RB() = default;

  /* ************************************************************************ */

  // Copy assignment
  RB<Data>& operator = (const RB<Data>&);

  // Move assignment
  RB<Data>& operator = (RB<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const RB<Data>&) const noexcept;
  inline bool operator != (const RB<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline RBNode& Root() const override; // Override BinaryTree member (might throw std::length_error)
  RBNode& NewRoot (const Data&) override; // Override BinaryTree member (Copy of the value)
  RBNode& NewRoot (Data&&) noexcept override; // Override BinaryTree member (Move of the value)

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

  RBNode * CopyRB (RBNode *);
  Color Colore (RBNode *) const noexcept;
  RBNode * Insert (RBNode *, const Data&);
  RBNode * RotazioneDx (RBNode *);
  RBNode * RotazioneSx (RBNode *);
  int TipoViolazioneSx (RBNode *, RBNode *);
  int TipoViolazioneDx (RBNode *, RBNode *);
  RBNode * BilanciaSx (RBNode *);
  RBNode * BilanciaDx (RBNode *);
  RBNode * Bilancia1 (RBNode *);
  RBNode * BilanciaSx2 (RBNode *);
  RBNode * BilanciaSx3 (RBNode *);
  RBNode * BilanciaDx2 (RBNode *);
  RBNode * BilanciaDx3 (RBNode *);
  RBNode * Remove (RBNode *, const Data&);
  RBNode * RemoveRoot (RBNode *);
  RBNode * BilLeafSx (RBNode *);
  RBNode * BilLeafDx (RBNode *);
  void PropagateBlack (RBNode *);
  RBNode * StaccaMin (RBNode *, RBNode *);
  RBNode * RemBilSx (RBNode *);
  int TipoViolazioneSxCanc (RBNode *, RBNode *);
  RBNode * RemBilSx1 (RBNode *);
  RBNode * RemBilSx2 (RBNode *);
  RBNode * RemBilSx3 (RBNode *);
  RBNode * RemBilSx4 (RBNode *);
  RBNode * RemBilDx (RBNode *);
  int TipoViolazioneDxCanc (RBNode *, RBNode *);
  RBNode * RemBilDx1 (RBNode *);
  RBNode * RemBilDx2 (RBNode *);
  RBNode * RemBilDx3 (RBNode *);
  RBNode * RemBilDx4 (RBNode *);

};

}

/* ************************************************************************** */

#include "rb.cpp"

/* ************************************************************************** */

#endif
