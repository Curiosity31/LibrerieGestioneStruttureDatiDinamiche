
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : public  BinaryTreeLnk<Data> {

private:

  // ...

protected:

  using BinaryTreeLnk<Data>:: size;
  using BinaryTreeLnk<Data>:: root;


  // ...

public:

  struct BSTNode : protected BinaryTreeLnk<Data>:: NodeLnk {

  private:

    // ...

  protected:

    using BinaryTreeLnk<Data>::NodeLnk:: info;

    // Specific constructors

    //Copy of the value
    BSTNode (const Data&);
    //Move of the value
    BSTNode (Data&&) noexcept;




    inline BSTNode * Left(); // Mutable access to the element
    inline const BSTNode *  Left() const; // Immutable access to the element
    inline BSTNode *  Right(); // Mutable access to the element
    inline const BSTNode *  Right() const; // Immutable access to the element

    BSTNode * Find (BSTNode *, const Data&) const;
    BSTNode * FindParent (BSTNode *, const Data&) const;

    BSTNode * MinParent (BSTNode *) const;
    BSTNode * MaxParent (BSTNode *) const;

  public:

    friend class BST<Data>;

    // ...

  };

  /* ************************************************************************ */

  // Default constructor
  BST() = default;

  // Copy constructor
  BST (const BST<Data>&);

  // Move constructor
  BST (BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST<Data>& operator = (const BST<Data>&);

  // Move assignment
  BST<Data>& operator = (BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BST<Data>&) const noexcept;
  inline bool operator != (const BST<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline BSTNode& Root() const override; // Override BinaryTree member (might throw std::length_error)
  BSTNode& NewRoot (const Data&) override; // Override BinaryTree member (Copy of the value)
  BSTNode& NewRoot (Data&&) noexcept override; // Override BinaryTree member (Move of the value)

  /* ************************************************************************ */

  // Specific member functions

  virtual void Insert (const Data&); // Copy of the value
  virtual void Insert (Data&&) noexcept; // Move of the value
  virtual void Remove (const Data&);

  const Data& Min() const; // (might throw std::length_error)
  virtual Data MinNRemove(); // (might throw std::length_error)
  virtual void RemoveMin(); // (might throw std::length_error)

  const Data& Max() const; // (might throw std::length_error)
  virtual Data MaxNRemove(); // (might throw std::length_error)
  virtual void RemoveMax(); // (might throw std::length_error)

  const Data& Predecessor (const Data&) const; // (might throw std::length_error)
  virtual Data PredecessorNRemove (const Data&); // (might throw std::length_error)
  virtual inline void RemovePredecessor (const Data&); // (might throw std::length_error)

  const Data& Successor (const Data&) const; // (might throw std::length_error)
  virtual Data SuccessorNRemove (const Data&); // (might throw std::length_error)
  virtual inline void RemoveSuccessor (const Data&); // (might throw std::length_error)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists (const Data&) const noexcept override; // Override TestableContainer member

protected:

  void EqualsBST (BSTNode *, Vector<Data>&, ulong&) const noexcept;
  BSTNode * Remove (BSTNode *, const Data&);
  void RemoveMin (BSTNode *);
  void RemoveMax (BSTNode *);

};

}

/* ************************************************************************** */

#include "bst.cpp"


/* ************************************************************************** */

#endif
