
namespace lasd {

/* ************************************************************************** */

// Specific constructors (RBNode)

//Copy of the value
template <typename Data>
RB<Data>:: RBNode:: RBNode (const Data& newInfo) : BST<Data>:: BSTNode  (newInfo) {
  color = RED;
}


//Move of the value
template <typename Data>
RB<Data>:: RBNode:: RBNode (Data&& newInfo) noexcept : BST<Data>:: BSTNode  (std::move(newInfo)) {
  color = RED;
}

/* ************************************************************************** */

//Specfic member functions (BSTNode)

template <typename Data>
inline typename RB<Data>:: RBNode * RB<Data>::RBNode:: Left() {
  return (RBNode *) BST<Data>::BSTNode:: sx;
}


template <typename Data>
inline const typename RB<Data>:: RBNode *  RB<Data>::RBNode:: Left() const {
  return (RBNode *) BST<Data>::BSTNode:: sx;
}


template <typename Data>
inline typename RB<Data>:: RBNode *  RB<Data>::RBNode:: Right() {
  return (RBNode *) BST<Data>::BSTNode:: dx;
}


template <typename Data>
inline const typename RB<Data>:: RBNode *  RB<Data>::RBNode:: Right() const {
  return (RBNode *) BST<Data>::BSTNode:: dx;
}


/* ************************************************************************** */

// Specific constructors (RB)

// Copy constructor
template <typename Data>
RB<Data>:: RB (const RB<Data>& copia) {
  if (copia.root != nullptr) {
    root = CopyRB ((RBNode *) copia.root);
  }
  else {
    root = nullptr;
  }
  size = copia.size;
}

// Move constructor
template <typename Data>
RB<Data>:: RB (RB<Data>&& sposta) noexcept : BST<Data> (std::move(sposta)) { }

/* ************************************************************************ */

// Copy assignment
template <typename Data>
RB<Data>& RB<Data>:: operator = (const RB<Data>& assegna) {
  RB<Data> * temp = new RB<Data> (assegna);
  std::swap (temp->root, root);
  size = assegna.size;
  temp->~RB();
  return * this;
}


// Move assignment
template <typename Data>
RB<Data>& RB<Data>:: operator = (RB<Data>&& vecchio) noexcept {
  BST<Data>:: operator = (std::move(vecchio));
  return * this;
}

/* ************************************************************************ */

// Comparison operators
template <typename Data>
inline bool RB<Data>:: operator == (const RB<Data>& verifica) const noexcept {
  return ( BST<Data>:: operator == (verifica) );
}


template <typename Data>
inline bool RB<Data>:: operator != (const RB<Data>& verifica) const noexcept {
  return (!(*this == verifica));
}

/* ************************************************************************ */

// Specific member functions (inherited from BinaryTree)

template <typename Data>
inline typename RB<Data>::RBNode& RB<Data>:: Root() const {
  return (RBNode&) BST<Data>:: Root();
}


template <typename Data>
typename RB<Data>::RBNode& RB<Data>:: NewRoot (const Data& newRoot) {
  if (root == nullptr) {
    RBNode * node = new RBNode (newRoot);
    node->color = BLACK;
    root = node;
  }
  else {
    this->RemoveLeftChild (*root);
    this->RemoveRightChild (*root);
    root->Element() = newRoot;
  }
  size = 1;
  return * (RBNode *) root;
}


template <typename Data>
typename RB<Data>::RBNode& RB<Data>:: NewRoot (Data&& newRoot) noexcept {
  if (root == nullptr) {
    RBNode * node = new RBNode (std::move(newRoot));
    node->color = BLACK;
    root = node;
  }
  else {
    this->RemoveLeftChild (*root);
    this->RemoveRightChild (*root);
    root->Element() = std::move(newRoot);
  }
  size = 1;
  return * (RBNode *) root;
}


/* ************************************************************************ */

// Specific member functions

template <typename Data>
void RB<Data>:: Insert (const Data& key) {
  RBNode * temp = Insert ((RBNode *)root, key);
  temp->color = BLACK;
  root = temp;
}


template <typename Data>
void RB<Data>:: Insert (Data&& key) noexcept {
  RBNode * temp = Insert ((RBNode *)root, std::move(key));
  temp->color = BLACK;
  root = temp;
}


template <typename Data>
void RB<Data>:: Remove (const Data& rem) {
  RBNode * temp = Remove ((RBNode *) root, rem);
  if ( temp != nullptr ) {
    temp->color = BLACK;
  }
  root = temp;
}


template <typename Data>
Data RB<Data>:: MinNRemove() {
  Data minimo = this->Min();
  Remove (minimo);
  return minimo;
}


template <typename Data>
void RB<Data>:: RemoveMin() {
  Remove (this->Min());
}


template <typename Data>
Data RB<Data>:: MaxNRemove() {
  Data massimo = this->Max();
  Remove (massimo);
  return massimo;
}


template <typename Data>
void RB<Data>:: RemoveMax(){
  Remove (this->Max());
}


template <typename Data>
Data RB<Data>:: PredecessorNRemove (const Data& pred) {
  Data predec = this->Predecessor(pred);
  Remove (predec);
  return predec;
}

template <typename Data>
void RB<Data>::RemovePredecessor (const Data& pred) {
  Remove (this->Predecessor(pred));
}


template <typename Data>
Data RB<Data>:: SuccessorNRemove (const Data& succ) {
  Data success = this->Successor (succ);
  Remove (success);
  return success;
}


template <typename Data>
void RB<Data>:: RemoveSuccessor (const Data& succ) {
  Remove (this->Successor(succ));
}


/* ************************************************************************ */


//Accessory function

template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: CopyRB (RBNode * copia) {
  if (copia == nullptr) {
      return nullptr;
  }
  RBNode * node = new RBNode (copia->info);
  node->color = copia->color;
  node->BST<Data>::BSTNode:: sx = CopyRB (copia->Left());
  node->BST<Data>::BSTNode:: dx = CopyRB (copia->Right());
  return node;
}



template <typename Data>
typename RB<Data>:: Color RB<Data>:: Colore (RBNode * node) const noexcept {
  if (node == nullptr) {
    return BLACK;
  }
  return node->color;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: Insert (RBNode * node, const Data& key) {
  if (node == nullptr) {
    node = new RBNode (key);
    size ++;
  }
  else {
    if (node->info > key) {
      node->BST<Data>::BSTNode:: sx = Insert (node->Left(), key);
      node = BilanciaSx (node);
    }
    else if (node->info < key) {
      node->BST<Data>::BSTNode:: dx = Insert (node->Right(), key);
      node = BilanciaDx (node);
    }
  }
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RotazioneDx (RBNode * node) {
  RBNode * newRoot = node->Right();
  node->BST<Data>::BSTNode:: dx = newRoot->Left();
  newRoot->BST<Data>::BSTNode:: sx = node;
  return newRoot;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RotazioneSx (RBNode * node) {
  RBNode * newRoot = node->Left();
  node->BST<Data>::BSTNode:: sx = newRoot->Right();
  newRoot->BST<Data>::BSTNode:: dx = node;
  return newRoot;
}


template <typename Data>
int RB<Data>:: TipoViolazioneSx (RBNode * nodeSx, RBNode * nodeDx) {
  int violazione = 0;
  if ( ( Colore (nodeSx) == RED) && ( Colore (nodeDx) == RED) ) {
    if ( (Colore (nodeSx->Left()) == RED) || (Colore (nodeSx->Right()) == RED) ) {
      violazione = 1;
    }
  }
  else {
    if ( Colore (nodeSx) == RED ) {
      if ( Colore (nodeSx->Right()) == RED ) {
        violazione = 2;
      }
      else {
        if ( Colore (nodeSx->Left()) == RED ) {
          violazione = 3;
        }
      }
    }
  }
  return violazione;
}


template <typename Data>
int RB<Data>:: TipoViolazioneDx (RBNode * nodeSx, RBNode * nodeDx) {
  int violazione = 0;
  if ( ( Colore (nodeSx) == RED) && ( Colore (nodeDx) == RED) ) {
    if ( (Colore (nodeDx->Left()) == RED) || (Colore (nodeDx->Right()) == RED) ) {
      violazione = 1;
    }
  }
  else {
    if ( Colore (nodeDx) == RED ) {
      if ( Colore (nodeDx->Left()) == RED ) {
        violazione = 2;
      }
      else {
        if ( Colore (nodeDx->Right()) == RED ) {
          violazione = 3;
        }
      }
    }
  }
  return violazione;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: BilanciaSx (RBNode * node) {
  if ( node->Left() != nullptr ) {
    int violazione = TipoViolazioneSx (node->Left(), node->Right());
    switch (violazione) {
      case 1:
        node = Bilancia1 (node);
      break;

      case 2:
        node = BilanciaSx2 (node);
        node = BilanciaSx3 (node);
      break;

      case 3:
        node = BilanciaSx3 (node);
      break;
    }
  }
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: BilanciaDx (RBNode * node) {
  if ( node->Right() != nullptr ) {
    int violazione = TipoViolazioneDx (node->Left(), node->Right());
    switch (violazione) {
      case 1:
        node = Bilancia1 (node);
      break;

      case 2:
        node = BilanciaDx2 (node);
        node = BilanciaDx3 (node);
      break;

      case 3:
        node = BilanciaDx3 (node);
      break;
    }
  }
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: Bilancia1 (RBNode * node) {
  node->color = RED;
  node->Right()->color = BLACK;
  node->Left()->color = BLACK;
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: BilanciaSx2 (RBNode * node) {
  node->BST<Data>::BSTNode:: sx = RotazioneDx (node->Left());
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: BilanciaSx3 (RBNode * node) {
  node = RotazioneSx (node);
  node->color = BLACK;
  node->Right()->color = RED;
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: BilanciaDx2 (RBNode * node) {
  node->BST<Data>::BSTNode:: dx = RotazioneSx (node->Right());
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: BilanciaDx3 (RBNode * node) {
  node = RotazioneDx (node);
  node->color = BLACK;
  node->Left()->color = RED;
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: Remove (RBNode * node, const Data& rem) {
  if ( node != nullptr ) {
    if ( node->info < rem ) {
      bool flag = false;
      if ( (Colore (node->Right()) == BLACK) && (node->Right() != nullptr) ) {
        flag = true;
      }
      node->BST<Data>::BSTNode:: dx = Remove (node->Right(), rem);
      if ( node->Right() == nullptr && flag == true) {
        node = BilLeafDx (node);
      }
      else {
        node = RemBilDx (node);
      }
    }
    else if ( node->info > rem ) {
      bool flag = false;
      if ( (Colore (node->Left()) == BLACK) && (node->Left() != nullptr) ) {
        flag = true;
      }
      node->BST<Data>::BSTNode:: sx = Remove (node->Left(), rem);
      if (node->Left() == nullptr && flag == true) {
        node = BilLeafSx (node);
      }
      else {
        node = RemBilSx (node);
      }
    }
    else {
      if ( (node->Left() == nullptr) && (node->Right() == nullptr) && (node->color == BLACK) ) {
        delete node;
        size --;
        return nullptr;
      }
      else {
        node = RemoveRoot (node);
        size --;
      }
    }
  }
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemoveRoot (RBNode * node) {
  RBNode * temp = nullptr;
  if ( (node->Left() == nullptr) || (node->Right() == nullptr) ) {
    temp = node;
    if ( node->Left() == nullptr ) {
      node = node->Right();
    }
    else if ( node->Right() == nullptr ) {
      node = node->Left();
    }
    if ( Colore(temp) == BLACK ) {
      PropagateBlack (node);
    }
  }
  else {
      temp = StaccaMin (node->Right(), node);
      node->info = temp->info;
      if ( node->Right() != nullptr ) {
        node = RemBilDx (node);
      }
      else if (node->Right() == nullptr && temp->color == BLACK) {
        node = BilLeafDx (node);
      }
  }
  delete temp;
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>::BilLeafSx (RBNode * node) {
  if ( Colore (node->Right()) == BLACK ) {
    Color colore = node->color;
    node = RotazioneDx (node);
    node->color = colore;
    if (node->Right() != nullptr) {
      node->Right()->color = BLACK;
      node->Left()->color = BLACK;
    }
    else if (node->Left()->IsLeaf() ) {
      PropagateBlack (node);
      node->Left()->color = RED;
    }
    else {
      node->BST<Data>::BSTNode:: sx = RotazioneDx (node->Left());
      node = RotazioneSx (node);
      node->color = colore;
      node->Right()->color = BLACK;
      node->Left()->color = BLACK;
    }
    if (node->Left()->Right() != nullptr) {
      node->Left()->Right()->color = RED;
    }
  }
  else if ( Colore (node->Right()) == RED )  {
    node = RotazioneDx (node);
    if (node->Left()->Right()->IsLeaf()) {
      node->color = BLACK;
      node->Left()->Right()->color = RED;
    }
    else if ( node->Left()->Right()->Right() != nullptr ) {
      node->BST<Data>::BSTNode:: sx = RotazioneDx (node->Left());
      node->color = BLACK;
      node->Left()->color = RED;
      node->Left()->Right()->color = BLACK;
    }
    else {
      node->color = BLACK;
      node->Left()->BST<Data>::BSTNode:: dx = RotazioneSx ( node->Left()->Right() );
      node->BST<Data>::BSTNode:: sx = RotazioneDx ( node->Left() );
    }
  }
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>::BilLeafDx (RBNode * node) {
  if ( Colore (node->Left()) == BLACK ) {
    Color colore = node->color;
    node = RotazioneSx (node);
    node->color = colore;
    if (node->Left() != nullptr) {
      node->Left()->color = BLACK;
      node->Right()->color = BLACK;
    }
    else if (node->Right()->IsLeaf()) {
      PropagateBlack (node);
      node->Right()->color = RED;
    }
    else {
      node->BST<Data>::BSTNode:: dx = RotazioneSx (node->Right());
      node = RotazioneDx (node);
      node->color = colore;
      node->Right()->color = BLACK;
      node->Left()->color = BLACK;
    }
    if (node->Right()->Left() != nullptr) {
      node->Right()->Left()->color = RED;
    }
  }
  else if ( Colore (node->Left()) == RED )  {
    node = RotazioneSx (node);
    if (node->Right()->Left()->IsLeaf()) {
      node->color = BLACK;
      node->Right()->Left()->color = RED;
    }
    else if ( node->Right()->Left()->Left() != nullptr )  {
      node->BST<Data>::BSTNode:: dx = RotazioneSx (node->Right());
      node->color = BLACK;
      node->Right()->color = RED;
      node->Right()->Left()->color = BLACK;
    }
    else {
      node->color = BLACK;
      node->Right()->BST<Data>::BSTNode:: sx = RotazioneDx ( node->Right()->Left() );
      node->BST<Data>::BSTNode:: dx = RotazioneSx ( node->Right() );
    }
  }
  return node;
}



template <typename Data>
void RB<Data>:: PropagateBlack (RBNode * node) {
  if ( Colore(node) == RED ) {
    node->color = BLACK;
  }
  else {
    node->color = D_BLACK;
  }
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: StaccaMin (RBNode * node, RBNode * parent) {
  RBNode * temp = nullptr;
  if (node != nullptr) {
    if (node->Left() != nullptr) {
      bool flag = false;
      if ( node->Left()->color == BLACK ) {
        flag = true;
      }
      temp = StaccaMin (node->Left(), node);
      if ( node == parent->Left() ) {
        if ( (node->Left() == nullptr) && (flag == true) ) {
              parent->BST<Data>::BSTNode:: sx = BilLeafSx (node);
        }
        else {
          parent->BST<Data>::BSTNode:: sx = RemBilSx (node);
        }
      }
      else {
        if ( (node->Left() == nullptr) && (flag == true) ) {
          parent->BST<Data>::BSTNode:: dx = BilLeafSx (node);
        }
        else {
          parent->BST<Data>::BSTNode:: dx = RemBilDx (node);
        }
      }
      node = temp;
    }
    else {
      temp = node;
      if ( node == parent->Left() ) {
        parent->BST<Data>::BSTNode:: sx = node->Right();
      }
      else {
        parent->BST<Data>::BSTNode:: dx = node->Right();
      }
      if ( Colore(node) == BLACK ) {
        if ( node->Right() != nullptr ) {
          PropagateBlack (node->Right());
        }
      }
    }
  }
  return temp;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilSx (RBNode * node) {
  if ( (node->Left() != nullptr) || (node->Right() != nullptr) ) {
    int violazione = TipoViolazioneSxCanc (node->Left(), node->Right());
    switch (violazione) {
      case 1:
        node = RemBilSx1 (node);
        node->BST<Data>::BSTNode:: sx = RemBilSx (node->Left());
      break;

      case 2:
        node = RemBilSx2 (node);
      break;

      case 3:
        node = RemBilSx3 (node);
      break;

      case 4:
        node = RemBilSx4 (node);
      break;
    }
  }
  return node;
}


template <typename Data>
int RB<Data>::  TipoViolazioneSxCanc (RBNode * nodesx, RBNode * nodedx) {
  int violazione = 0;
  if (Colore(nodesx) == D_BLACK) {
    if ( Colore (nodedx) == RED) {
      violazione = 1;
    }
    else if ( (Colore (nodedx->Right()) == BLACK) && ( Colore (nodedx->Left()) == BLACK)) {
      violazione = 2;
    }
    else if (Colore (nodedx->Right()) == BLACK) {
      violazione = 3;
    }
    else {
      violazione = 4;
    }
  }
  return violazione;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilSx1 (RBNode * node) {
  node = RotazioneDx (node);
  node->color = BLACK;
  node->Left()->color = RED;
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilSx2 (RBNode * node) {
  node->Right()->color = RED;
  if (node->Left() != nullptr) {
    node->Left()->color = BLACK;
    PropagateBlack (node);
  }
  else {
    node->color = BLACK;
  }
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilSx3 (RBNode * node) {
  node->BST<Data>::BSTNode:: dx = RotazioneSx (node->Right());
  node->Right()->color = BLACK;
  node->Right()->Right()->color = RED;
  node = RemBilSx4 (node);
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilSx4 (RBNode * node) {
  node = RotazioneDx (node);
  node->Right()->color = node->color;
  node->color = node->Left()->color;
  node->Left()->color = BLACK;
  node->Left()->Left()->color = BLACK;
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilDx (RBNode * node) {
  if ( (node->Left() != nullptr) || (node->Right() != nullptr) ) {
    int violazione = TipoViolazioneDxCanc (node->Left(), node->Right());
    switch (violazione) {
      case 1:
        node = RemBilDx1 (node);
        node->BST<Data>::BSTNode:: dx = RemBilDx (node->Right());
      break;

      case 2:
        node = RemBilDx2 (node);
      break;

      case 3:
        node = RemBilDx3 (node);
      break;

      case 4:
        node = RemBilDx4 (node);
      break;
    }
  }
  return node;
}


template <typename Data>
int RB<Data>:: TipoViolazioneDxCanc (RBNode * nodesx, RBNode * nodedx) {
  int violazione = 0;
  if (Colore (nodedx) == D_BLACK)  {
    if ( Colore (nodesx) == RED) {
      violazione = 1;
    }
    else if ( (Colore (nodesx->Right()) == BLACK) && ( Colore (nodesx->Left()) == BLACK)) {
      violazione = 2;
    }
    else if (Colore (nodesx->Left()) == BLACK) {
      violazione = 3;
    }
    else {
      violazione = 4;
    }
  }
  return violazione;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilDx1 (RBNode * node) {
  node = RotazioneSx (node);
  node->color = BLACK;
  node->Right()->color = RED;
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilDx2 (RBNode * node) {
  node->Left()->color = RED;
  node->Right()->color = BLACK;
  PropagateBlack (node);
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilDx3 (RBNode * node) {
  node->BST<Data>::BSTNode:: sx = RotazioneDx (node->Left());
  node->Left()->color = BLACK;
  node->Left()->Left()->color = RED;
  node = RemBilDx4 (node);
  return node;
}


template <typename Data>
typename RB<Data>:: RBNode * RB<Data>:: RemBilDx4 (RBNode * node) {
  node = RotazioneSx (node);
  node->Left()->color = node->color;
  node->color = node->Right()->color;
  node->Right()->color = BLACK;
  node->Right()->Right()->color = BLACK;
  return node;
}


/* ************************************************************************ */

}
