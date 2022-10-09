
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : public BreadthSearchableContainer<Data> {

private:


protected:

using BreadthSearchableContainer<Data>:: size;

public:

  struct Node {

  private:


  protected:


  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() = 0; // Mutable access to the element
    virtual const Data& Element() const = 0; // Immutable access to the element

    virtual bool IsLeaf() const noexcept = 0;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0;

    virtual Node& LeftChild() const = 0; // (might throw std::out_of_range)
    virtual Node& RightChild() const = 0; // (might throw std::out_of_range)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree<Data>& operator = (const BinaryTree<Data>&) = delete;

  // Move assignment
  BinaryTree<Data>& operator = (BinaryTree<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator == (const BinaryTree<Data>&) const noexcept;
  virtual inline bool operator != (const BinaryTree<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual Node& Root() const = 0; // (might throw std::length_error)
  virtual Node& NewRoot (const Data&) = 0; // Copy of the value
  virtual Node& NewRoot (Data&&) noexcept = 0; // Move of the value

  using typename SearchableContainer<Data>::MapFunctor;
  void inline MapInOrder (MapFunctor, void *);

  using typename SearchableContainer<Data>::FoldFunctor;
  void inline FoldInOrder (FoldFunctor, const void *, void *) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  void inline MapPreOrder (MapFunctor, void *) override; // Override SearchableContainer member
  void inline MapPostOrder (MapFunctor, void *) override; // Override SearchableContainer member

  void inline FoldPreOrder (FoldFunctor, const void *, void *) const override; // Override SearchableContainer member
  void inline FoldPostOrder (FoldFunctor, const void *, void *) const override; // Override SearchableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  void inline MapBreadth (MapFunctor, void *) override; // Override BreadthSearchableContainer member
  void inline FoldBreadth (FoldFunctor, const void *, void *) const override; // Override BreadthSearchableContainer member

protected:

  virtual bool IdenticalTree (const Node&, const Node&) const noexcept;

  void MapBreadth (MapFunctor, void *, Node *); // Accessory function executing from one node of the tree
  void MapPreOrder (MapFunctor, void *, Node *); // Accessory function executing from one node of the tree
  void MapInOrder (MapFunctor, void *, Node *); // Accessory function executing from one node of the tree
  void MapPostOrder (MapFunctor, void *, Node *); // Accessory function executing from one node of the tree

  void FoldBreadth (FoldFunctor, const void *, void *, Node *) const; // Accessory function executing from one node of the tree
  void FoldPreOrder (FoldFunctor, const void *, void *, Node *) const; // Accessory function executing from one node of the tree
  void FoldInOrder (FoldFunctor, const void *, void *, Node *) const; // Accessory function executing from one node of the tree
  void FoldPostOrder (FoldFunctor, const void *, void *, Node *) const; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

#include "binarytree.cpp"

}

#endif
