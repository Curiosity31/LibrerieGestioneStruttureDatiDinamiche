
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public BinaryTree<Data>  {

private:


protected:

  using BinaryTree<Data>:: size;

public:

  //using BinaryTree<Data>::;

  struct NodeLnk : BinaryTree<Data>:: Node {

  private:


  protected:

  Data info;
  NodeLnk * sx = nullptr;
  NodeLnk * dx = nullptr;

  // Specific constructors

  //Copy of the value
  NodeLnk (const Data&);
  //Move of the value
  NodeLnk (Data&&) noexcept;


  public:

    friend class BinaryTreeLnk<Data>;

    /* ********************************************************************** */

    // Specific member functions (inherited from Node)

    Data& Element() override;
    const Data& Element() const override;

    inline bool IsLeaf() const noexcept override;
    inline bool HasLeftChild() const noexcept override;
    inline bool HasRightChild() const noexcept override;

    NodeLnk& LeftChild() const override;
    NodeLnk& RightChild() const override;


  };

  /* ************************************************************************ */

  // Default constructor
  BinaryTreeLnk() = default;

  // Specific constructors
  BinaryTreeLnk (const Data& ); // Construct a tree with a given root data (Copy of the value)
  BinaryTreeLnk (Data&&) noexcept; // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  BinaryTreeLnk (const BinaryTreeLnk<Data>&);

  // Move constructor
  BinaryTreeLnk (BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk<Data>& operator  = (const BinaryTreeLnk<Data>&);

  // Move assignment
  BinaryTreeLnk<Data>& operator = (BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const BinaryTreeLnk<Data>&) const noexcept;
  inline bool operator != (const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeLnk& Root() const override; // Override Node member (might throw std::length_error)
  NodeLnk& NewRoot (const Data&) override; // Override Node member (Copy of the value)
  NodeLnk& NewRoot (Data&&) noexcept override; // Override Node member (Move of the value)

  NodeLnk& AddLeftChild (NodeLnk&, const Data&); // Add a child to a given node (Copy of the value)
  NodeLnk& AddLeftChild (NodeLnk&, Data&&) noexcept; // Add a child to a given node (Move of the value)
  NodeLnk& AddRightChild (NodeLnk&, const Data&); // Add a child to a given node (Copy of the value)
  NodeLnk& AddRightChild (NodeLnk&, Data&&) noexcept; // Add a child to a given node (Move of the value)

  void RemoveLeftChild (NodeLnk&); // Remove an entire subtree rooted in a child of a given node
  void RemoveRightChild (NodeLnk&); // Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

protected:

  NodeLnk * root = nullptr;

  void Remove (NodeLnk *);
  NodeLnk * CopyTree (NodeLnk *);
  bool IdenticalTreeLnk (const NodeLnk *, const NodeLnk *) const noexcept;

};

/* ************************************************************************** */

#include "binarytreelnk.cpp"

}

#endif
