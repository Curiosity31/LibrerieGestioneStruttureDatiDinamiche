
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : public BinaryTree<Data> {

private:

  // ...

protected:

  using BinaryTree<Data>:: size;
  Vector <uint> height = Vector <uint> (3);

public:


  struct NodeVec : BinaryTree<Data>:: Node {

  private:

    // ...

  protected:

    ulong index = 0;
    Data info;

    BinaryTreeVec<Data> * cur ;

    // Specific constructors

    //Copy of the value
    NodeVec (const Data&, const ulong);
    //Move of the value
    NodeVec (Data&&, const ulong) noexcept;


  public:

    friend class BinaryTreeVec<Data>;

    /* ********************************************************************** */

    // Specific member functions

    inline bool HasParent() const noexcept;
    bool HasLeftSibling() const noexcept;
    bool HasRightSibling() const noexcept;

    NodeVec& Parent() const; // (might throw std::out_of_range)
    NodeVec& LeftSibling() const; // (might throw std::out_of_range)
    NodeVec& RightSibling() const; // (might throw std::out_of_range)

    inline const ulong GetIndex () const;
    /* ********************************************************************** */

    // Specific member functions (inherited from Node)

    inline Data& Element() override; // Override Node member Mutable access to the element
    inline const Data& Element() const override; // Override Node member Immutable access to the element

    inline bool IsLeaf() const noexcept override; // Override Node member
    inline bool HasLeftChild() const noexcept override; // Override Node member
    inline bool HasRightChild() const noexcept override; // Override Node member

    NodeVec& LeftChild() const override; // Override Node member (might throw std::out_of_range)
    NodeVec& RightChild() const override; // Override Node member (might throw std::out_of_range)

  };

  /* ************************************************************************ */

  // Default constructor
  BinaryTreeVec();

  // Specific constructors
  BinaryTreeVec (const Data&); // Construct a tree with a given root data (Copy of the value)
  BinaryTreeVec (Data&&) noexcept; // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  BinaryTreeVec (const BinaryTreeVec<Data>&);

  // Move constructor
  BinaryTreeVec (BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec<Data>& operator = (const BinaryTreeVec<Data>&);

  // Move assignment
  BinaryTreeVec<Data>& operator = (BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BinaryTreeVec<Data>&) const noexcept;
  inline bool operator != (const BinaryTreeVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() const override; // Override Node member (might throw std::length_error)
  NodeVec& NewRoot (const Data&) override; // Override Node member (Copy of the value)
  NodeVec& NewRoot (Data&&) noexcept override; // Override Node member (Move of the value)

  NodeVec& AddLeftChild (NodeVec&, const Data&); // Add a child to a given node (Copy of the value)
  NodeVec& AddLeftChild (NodeVec&, Data&&) noexcept; // Add a child to a given node (Move of the value)
  NodeVec& AddRightChild (NodeVec&, const Data&); // Add a child to a given node (Copy of the value)
  NodeVec& AddRightChild (NodeVec&, Data&&) noexcept; // Add a child to a given node (Move of the value)

  void RemoveLeftChild (NodeVec&); // Remove an entire subtree rooted in a child of a given node
  void RemoveRightChild (NodeVec&); // Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  using typename BinaryTree<Data>::MapFunctor;
  void  MapBreadth (MapFunctor, void *) override; // Override BreadthSearchableContainer member

  using typename BinaryTree<Data>::FoldFunctor;
  void FoldBreadth (FoldFunctor, const void *, void *) const override; // Override BreadthSearchableContainer member

protected:

  Vector <NodeVec*> treeVec = Vector <NodeVec*> (7);

  void Expand(); // Accessory function
  void Reduce(); // Accessory function
  void Remove (NodeVec *);

};

/* ************************************************************************** */

#include "binarytreevec.cpp"

}

#endif
