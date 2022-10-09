#include "test.hpp"
#include <iostream>
#include <random>
#include <string>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"


/* ************************************************************************** */

//Funzione per visualizzare la lista tramite MAP
template <typename Data>
void MapView (Data& stampa, void * par) {
  std::cout << stampa << " ";
}

//Funzione che triplica il valore degli elementi tramite map
void MapTriplica (int& elem, void * par) {
  elem = elem * 3 ;
}

//Funzione prodotto interi minori di n tramite Fold
void FoldProdMinN (const int& dat, const void * n, void * prod){
  if (dat < *((int*) n))
  {
    *((int*) prod) *= dat;
  }
}

//Funzione somma per reali maggiore di n tramite Fold
void FoldSommaMaggN (const float& dat, const void * n, void * somma){
  if (dat > *((float*) n))
  {
    *((float*) somma) = (*((float*) somma) + dat);
  }
}


//Funzione che effettua il cubo del valore degli elementi tramite map
void MapCube (float& elem, void * par) {
  elem = elem * elem * elem ;
}


//Ricerca del nodo
typename lasd:: BinaryTreeVec <int> :: NodeVec* SearchVecInt(lasd::BinaryTreeVec<int>:: NodeVec* node, const int& elemento){
if (node != nullptr) {
  if (node->Element() == elemento){
    return node;
  }
  else{
    if (node->HasLeftChild()) {
    lasd::BinaryTreeVec<int>::NodeVec * temp = SearchVecInt(&node->LeftChild(), elemento);
      if (temp != nullptr){
        return temp;
      }
    }
    if (node->HasRightChild()) {
      return SearchVecInt (&node->RightChild(), elemento);
    }
  }
}
return nullptr;
}


//Ricerca del nodo
typename lasd:: BinaryTreeVec <float> :: NodeVec* SearchVecFloat(lasd::BinaryTreeVec<float>:: NodeVec* node, const float& elemento){
if (node != nullptr) {
  if (node->Element() == elemento){
    return node;
  }
  else{
    if (node->HasLeftChild()) {
    lasd::BinaryTreeVec<float>::NodeVec * temp = SearchVecFloat(&node->LeftChild(), elemento);
      if (temp != nullptr){
        return temp;
      }
    }
    if (node->HasRightChild()) {
      return SearchVecFloat (&node->RightChild(), elemento);
    }
  }
}
return nullptr;
}


//Ricerca del nodo
typename lasd:: BinaryTreeLnk <float> :: NodeLnk* SearchLinkFloat(lasd::BinaryTreeLnk<float>:: NodeLnk* node, const float& elemento){
if (node != nullptr) {
  if (node->Element() == elemento){
    return node;
  }
  else{
    if (node->HasLeftChild()) {
    lasd::BinaryTreeLnk<float>::NodeLnk * temp = SearchLinkFloat(&node->LeftChild(), elemento);
      if (temp != nullptr){
        return temp;
      }
    }
    if (node->HasRightChild()) {
      return SearchLinkFloat (&node->RightChild(), elemento);
    }
  }
}
return nullptr;
}


//Ricerca del nodo
typename lasd:: BinaryTreeLnk <int> :: NodeLnk* SearchLinkInt(lasd::BinaryTreeLnk<int>:: NodeLnk* node, const int& elemento){
if (node != nullptr) {
  if (node->Element() == elemento){
    return node;
  }
  else{
    if (node->HasLeftChild()) {
    lasd::BinaryTreeLnk<int>::NodeLnk * temp = SearchLinkInt(&node->LeftChild(), elemento);
      if (temp != nullptr){
        return temp;
      }
    }
    if (node->HasRightChild()) {
      return SearchLinkInt (&node->RightChild(), elemento);
    }
  }
}
return nullptr;
}



//Funzione per creare e popolare l'albero (in rappresentazione vettoriale) randomicamente
void RandomTreeVecInt (uint m, lasd::BinaryTreeVec<int>& tree, lasd::BinaryTreeVec<int>::NodeVec& node ) {
  if (m == 0) {
    return;
  }
  std::default_random_engine gen (std::random_device{}());
  std::uniform_int_distribution<int> distribution(1,3);
  std::uniform_int_distribution<int> val(1,100);
  int value = distribution(gen);

  if (value == 1) {
    RandomTreeVecInt (m-1, tree, tree.AddLeftChild (node, val(gen)));
  }
  else if (value == 2) {
    RandomTreeVecInt (m-1, tree, tree.AddRightChild (node, val(gen)));
  }
  else {
    if (m >= 2) {
      lasd::BinaryTreeVec<int>::NodeVec& temp1 = tree.AddLeftChild (node, val(gen));
      lasd::BinaryTreeVec<int>::NodeVec& temp2 = tree.AddRightChild (node, val(gen));
      m = m-2;
      if (distribution(gen) == 3) {
        RandomTreeVecInt (m, tree, temp1);
      }
      else {
        RandomTreeVecInt (m, tree, temp2);
      }
    }
    else {
      lasd::BinaryTreeVec<int>::NodeVec& temp3 = tree.AddLeftChild (node, val(gen));
      m-- ;
      RandomTreeVecInt (m, tree, temp3);
    }
  }
}


//Funzione per creare e popolare l'albero (in rappresentazione vettoriale) randomicamente
void RandomTreeVecFloat (uint m, lasd::BinaryTreeVec<float>& tree, lasd::BinaryTreeVec<float>::NodeVec& node ) {
  if (m == 0) {
    return;
  }
  std::default_random_engine gen (std::random_device{}());
  std::uniform_int_distribution<int> distribution(1,3);
  std::uniform_real_distribution<float> val(1,100);
  int value = distribution(gen);
  float ins = ((float )((int)(val (gen) * 1000.0f)))/1000.0f;


  if (value == 1) {
    RandomTreeVecFloat (m-1, tree, tree.AddLeftChild (node, ins));
  }
  else if (value == 2) {
    RandomTreeVecFloat (m-1, tree, tree.AddRightChild (node, ins));
  }
  else {
    if (m >= 2) {
      lasd::BinaryTreeVec<float>::NodeVec& temp1 = tree.AddLeftChild (node, ins);
      ins = ((float )((int)(val (gen) * 1000.0f)))/1000.0f;
      lasd::BinaryTreeVec<float>::NodeVec& temp2 = tree.AddRightChild (node, ins);
      m = m-2;
      if (distribution(gen) == 3) {
        RandomTreeVecFloat (m, tree, temp1);
      }
      else {
        RandomTreeVecFloat (m, tree, temp2);
      }
    }
    else {
      lasd::BinaryTreeVec<float>::NodeVec& temp3 = tree.AddLeftChild (node, ins);
      m-- ;
      RandomTreeVecFloat (m, tree, temp3);
    }
  }
}


//Funzione per creare e popolare l'albero (in rappresentazione link) randomicamente
void RandomTreeLnkInt (uint m, lasd::BinaryTreeLnk<int>& tree, lasd::BinaryTreeLnk<int>::NodeLnk& node ) {
  if (m == 0) {
    return;
  }
  std::default_random_engine gen (std::random_device{}());
  std::uniform_int_distribution<int> distribution(1,3);
  std::uniform_int_distribution<int> val(1,100);
  int value = distribution(gen);

  if (value == 1) {
    RandomTreeLnkInt (m-1, tree, tree.AddLeftChild (node, val(gen)));
  }
  else if (value == 2) {
    RandomTreeLnkInt (m-1, tree, tree.AddRightChild (node, val(gen)));
  }
  else {
    if (m >= 2) {
      lasd::BinaryTreeLnk<int>::NodeLnk& temp1 = tree.AddLeftChild (node, val(gen));
      lasd::BinaryTreeLnk<int>::NodeLnk& temp2 = tree.AddRightChild (node, val(gen));
      m = m-2;
      if (distribution(gen) == 3) {
        RandomTreeLnkInt (m, tree, temp1);
      }
      else {
        RandomTreeLnkInt (m, tree, temp2);
      }
    }
    else {
      lasd::BinaryTreeLnk<int>::NodeLnk& temp3 = tree.AddLeftChild (node, val(gen));
      m-- ;
      RandomTreeLnkInt (m, tree, temp3);
    }
  }
}


//Funzione per creare e popolare l'albero (in rappresentazione vettoriale) randomicamente
void RandomTreeLinkFloat (uint m, lasd::BinaryTreeLnk<float>& tree, lasd::BinaryTreeLnk<float>::NodeLnk& node ) {
  if (m == 0) {
    return;
  }
  std::default_random_engine gen (std::random_device{}());
  std::uniform_int_distribution<int> distribution(1,3);
  std::uniform_real_distribution<float> val(1,100);
  int value = distribution(gen);
  float ins = ((float )((int)(val (gen) * 1000.0f)))/1000.0f;


  if (value == 1) {
    RandomTreeLinkFloat (m-1, tree, tree.AddLeftChild (node, ins));
  }
  else if (value == 2) {
    RandomTreeLinkFloat (m-1, tree, tree.AddRightChild (node, ins));
  }
  else {
    if (m >= 2) {
      lasd::BinaryTreeLnk<float>::NodeLnk& temp1 = tree.AddLeftChild (node, ins);
      ins = ((float )((int)(val (gen) * 1000.0f)))/1000.0f;
      lasd::BinaryTreeLnk<float>::NodeLnk& temp2 = tree.AddRightChild (node, ins);
      m = m-2;
      if (distribution(gen) == 3) {
        RandomTreeLinkFloat (m, tree, temp1);
      }
      else {
        RandomTreeLinkFloat (m, tree, temp2);
      }
    }
    else {
      lasd::BinaryTreeLnk<float>::NodeLnk& temp3 = tree.AddLeftChild (node, ins);
      m-- ;
      RandomTreeLinkFloat (m, tree, temp3);
    }
  }
}


/* ************************************************************************** */


void libraryTest () {
  ushort choiceStruct, choiceData;
  do {
    std::cout << std::endl << "Scelta struttura dati." << std::endl;
    std::cout << "Inserire 1 per utilizzare la struttura dati albero di tipo vettore" << std::endl;
    std::cout << "Inserire 2 per utilizzare la struttura dati albero di tipo puntatore" << std::endl;
    std::cout << "Inserire 3 per terminare il programma:   ";
    std::cin >> choiceStruct;

    switch (choiceStruct) {

      case 1:
        std::cout << std::endl << "La struttura dati scelta è: albero di tipo vettore." << std::endl;
        do {
            std::cout << std::endl << "Scelta del tipo di dato." << std::endl;
            std::cout << "Inserire 10 per utilizzare dati di tipo int" << std::endl;
            std::cout << "Inserire 20 per utilizzare dati di tipo float" << std::endl;
            std::cout << "Inserire 30 per terminare il programma:   ";
            std::cin >> choiceData;
            switch (choiceData) {

              case 10: {
                std::cout << std::endl << "Il tipo di dato scelto int." << std::endl;
                uint n, op;
                int exis, m, prodotto = 1, elemento;

                //Creazione albero Random
                std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
                std::cin >> n;
                lasd::BinaryTreeVec<int> vect;

                std::default_random_engine generator (std::random_device{}());
                std::uniform_int_distribution<int> elem (1,100);

                if (n != 0) {
                  vect.NewRoot (elem(generator));
                  n-- ;
                }
                if (n != 0) {
                  RandomTreeVecInt (n, vect, vect.Root());
                }

                //Visualizzazione dell'albero
                std::cout << std::endl << "Visualizzazione in Pre-Ordine:   ";
                vect.MapPreOrder (MapView<int>, nullptr);
                std::cout << std::endl << "Visualizzazione In Ordine:   ";
                vect.MapInOrder (MapView<int>, nullptr);
                std::cout << std::endl << "Visualizzazione in Post-Ordine:   ";
                vect.MapPostOrder (MapView<int>, nullptr);
                std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
                vect.MapBreadth (MapView<int>, nullptr);

                //Ricerca di un dato elemento all'interno dell'albero
                std::cout << std::endl ;
                std::cout << std::endl << "Inserisci un valore da cercare all'interno dell'albero: ";
                std::cin >> exis;

                if (vect.Exists(exis)) {
                  std::cout << std::endl << "L'elemento è presente nell'albero: "<< std::endl;
                }
                else {
                  std::cout << std::endl << "L'elemento non è presente nell'albero: "<< std::endl;
                }

                //Prodotto per gli interi minori di N
                std::cout << std::endl << "Inserisci un intero per effettuare il prodotto degli elementi minori di esso: ";
                std::cin >> m;
                vect.FoldBreadth (&FoldProdMinN, &m, &prodotto);
                if (prodotto != 1) {
                  std::cout << "Il prodotto dei numeri interi minori di "<< m <<" è: " << prodotto << std::endl;
                }
                else {
                  std::cout << "Non esistono numeri interi minori di "<< m << std::endl;
                }

                //Funzione che triplica il valore degli elementi
                std::cout << std::endl << "Moltiplico gli elementi dell'albero x3" << std::endl;
                vect.MapBreadth (MapTriplica, nullptr);

                //Visualizzazione dell'albero
                std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
                vect.MapBreadth (MapView<int>, nullptr);
                std::cout << std::endl;

                //Operazioni specifiche
                std::cout << std::endl << "Inserisci un elemento per effettuare varie operazioni specifiche sul nodo:   ";
                std::cin >> elemento;
                if (vect.Exists(elemento)) {
                  lasd::BinaryTreeVec<int>:: NodeVec * node = SearchVecInt (&vect.Root(), elemento);
                  std::cout << std::endl << "L'elemento inserito è presente "  << std::endl;

                  do {
                      std::cout << std::endl << "Menù per interrogare il nodo." << std::endl;
                      std::cout << "Digitare 1 per visualizzare l'elemento" << std::endl;
                      std::cout << "Digitare 2 per controllare l'esistenza ed accedere al figlio sinistro " << std::endl;
                      std::cout << "Digitare 3 per controllare l'esistenza ed accedere al figlio destro " << std::endl;
                      std::cout << "Digitare 4 per inserire un nuovo figlio sinistro (causa eventuale perdita del sottoalbero)" << std::endl;
                      std::cout << "Digitare 5 per inserire un nuovo figlio destro (causa eventuale perdita del sottoalbero)" << std::endl;
                      std::cout << "Digitare 6 per rimuovere il figlio sinistro (ed eventuale sottoalbero) " << std::endl;
                      std::cout << "Digitare 7 per rimuovere il figlio destro (ed eventuale sottoalbero)" << std::endl;
                      std::cout << "Digitare 8 per controllare l'esistenza ed accedere al padre" << std::endl;
                      std::cout << "Digitare 9 per controllare l'esistenza ed accedere al figlio sinistro"  << std::endl;
                      std::cout << "Digitare 10 per controllare l'esistenza ed accedere al figlio destro"  << std::endl;
                      std::cout << "Digitare 11 per Terminare il programma:   " ;

                      std::cin >> op;

                      switch (op) {
                        case 1:
                          std::cout << std::endl << "L'elemento è: " << node->Element() << std::endl;
                          break;

                        case 2:
                          if (node->HasLeftChild()) {
                            std::cout << std::endl << "Il figlio sinistro è: " << node->LeftChild().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl <<"Non esiste figlio sinistro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 3:
                          if (node->HasRightChild()) {
                            std::cout << std::endl << "Il figlio destro è: " << node->RightChild().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 4:
                          int x;
                          std::cout << std::endl << "Quale elemento vuoi inserire come figlio sinistro?   ";
                          std::cin >> x;
                          vect.AddLeftChild (*node, x);
                          break;

                        case 5:
                          int y;
                          std::cout << std::endl << "Quale elemento vuoi inserire come figlio destro?   " ;
                          std::cin >> y;
                          vect.AddRightChild (*node, y);
                          break;

                        case 6:
                          if (node->HasLeftChild()) {
                            vect.RemoveLeftChild (*node);
                            std::cout << std::endl << "Il filgio sinistro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste figlio sinistro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 7:
                          if (node->HasRightChild()) {
                            vect.RemoveRightChild (*node);
                            std::cout << std::endl <<"Il filgio destro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 8:
                          if (node->HasParent()) {
                            std::cout << std::endl << "Il padre è: " << node->Parent().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste il padre di: " << node->Element() << std::endl;
                          }
                          break;

                        case 9:
                          if (node->HasLeftSibling()) {
                            std::cout << std::endl << "Il fratello sinistro è: " << node->LeftSibling().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste il fratello sinistro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 10:
                          if (node->HasRightSibling()) {
                            std::cout << std::endl << "Il fratello destro è: " << node->RightSibling().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste il fratello destro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 11:
                          std::cout << std::endl << "Terminazione del programma." << std::endl;
                          break;

                        default:
                          std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                        }
                    } while (op != 11);

                }
                else {
                  std::cout << "L'elemento inserito non è presente all'interno dell'albero" << std::endl;
                }



                break;
              }

              case 20: {
                std::cout << std::endl << "Il tipo di dato scelto è: float." << std::endl;
                uint n, op;
                float exis,m, elemento, somma = 0;

                std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
                std::cin >> n;
                lasd::BinaryTreeVec<float> vect;

                std::default_random_engine generator (std::random_device{}());
                std::uniform_real_distribution<float> distribution (1,100);

                if (n != 0) {
                  vect.NewRoot (((float )((int)(distribution (generator) * 1000.0f)))/1000.0f);
                  n-- ;
                }
                if (n != 0) {
                  RandomTreeVecFloat (n, vect, vect.Root());
                }

                //Visualizzazione dell'albero
                std::cout << std::endl << "Visualizzazione in Pre-Ordine:   ";
                vect.MapPreOrder (MapView<float>, nullptr);
                std::cout << std::endl << "Visualizzazione In Ordine:   ";
                vect.MapInOrder (MapView<float>, nullptr);
                std::cout << std::endl << "Visualizzazione in Post-Ordine:   ";
                vect.MapPostOrder (MapView<float>, nullptr);
                std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
                vect.MapBreadth (MapView<float>, nullptr);

                //Ricerca di un dato elemento all'interno dell'albero
                std::cout << std::endl ;
                std::cout << std::endl << "Inserisci un valore da cercare all'interno dell'albero: ";
                std::cin >> exis;

                if (vect.Exists(exis)) {
                  std::cout << std::endl << "L'elemento è presente nell'albero: "<< std::endl;
                }
                else {
                  std::cout << std::endl << "L'elemento non è presente nell'albero: "<< std::endl;
                }

                //Somma dei reali maggiori di N
                std::cout << std::endl << "Inserisci un reale per effettuare la somma degli elementi maggiori di esso: ";
                std::cin >> m;
                vect.FoldBreadth (&FoldSommaMaggN, &m, &somma);
                std::cout << "La somma degli elementi maggiori di "<< m <<" è: " << somma << std::endl;

                //Visualizzazione dell'albero
                std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
                vect.MapBreadth (MapView<float>, nullptr);
                std::cout << std::endl;

                //Operazioni specifiche
                std::cout << std::endl << "Inserisci un elemento per effettuare varie operazioni specifiche sul nodo:   ";
                std::cin >> elemento;
                if (vect.Exists(elemento)) {
                  lasd::BinaryTreeVec<float>:: NodeVec * node = SearchVecFloat (&vect.Root(), elemento);
                  std::cout << std::endl << "L'elemento inserito è presente "  << std::endl;

                  do {
                      std::cout << std::endl << "Menù per interrogare il nodo." << std::endl;
                      std::cout << "Digitare 1 per visualizzare l'elemento" << std::endl;
                      std::cout << "Digitare 2 per controllare l'esistenza ed accedere al figlio sinistro " << std::endl;
                      std::cout << "Digitare 3 per controllare l'esistenza ed accedere al figlio destro " << std::endl;
                      std::cout << "Digitare 4 per inserire un nuovo figlio sinistro (causa eventuale perdita del sottoalbero)" << std::endl;
                      std::cout << "Digitare 5 per inserire un nuovo figlio destro (causa eventuale perdita del sottoalbero)" << std::endl;
                      std::cout << "Digitare 6 per rimuovere il figlio sinistro (ed eventuale sottoalbero) " << std::endl;
                      std::cout << "Digitare 7 per rimuovere il figlio destro (ed eventuale sottoalbero)" << std::endl;
                      std::cout << "Digitare 8 per controllare l'esistenza ed accedere al padre" << std::endl;
                      std::cout << "Digitare 9 per controllare l'esistenza ed accedere al figlio sinistro"  << std::endl;
                      std::cout << "Digitare 10 per controllare l'esistenza ed accedere al figlio destro"  << std::endl;
                      std::cout << "Digitare 11 per Terminare il programma:   " ;

                      std::cin >> op;

                      switch (op) {
                        case 1:
                          std::cout << std::endl << "L'elemento è: " << node->Element() << std::endl;
                          break;

                        case 2:
                          if (node->HasLeftChild()) {
                            std::cout << std::endl << "Il figlio sinistro è: " << node->LeftChild().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl <<"Non esiste figlio sinistro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 3:
                          if (node->HasRightChild()) {
                            std::cout << std::endl << "Il figlio destro è: " << node->RightChild().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 4:
                          float x;
                          std::cout << std::endl << "Quale elemento vuoi inserire come figlio sinistro?   ";
                          std::cin >> x;
                          vect.AddLeftChild (*node, x);
                          break;

                        case 5:
                          float y;
                          std::cout << std::endl << "Quale elemento vuoi inserire come figlio destro?   " ;
                          std::cin >> y;
                          vect.AddRightChild (*node, y);
                          break;

                        case 6:
                          if (node->HasLeftChild()) {
                            vect.RemoveLeftChild (*node);
                            std::cout << std::endl << "Il filgio sinistro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste figlio sinistro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 7:
                          if (node->HasRightChild()) {
                            vect.RemoveRightChild (*node);
                            std::cout << std::endl <<"Il filgio destro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 8:
                          if (node->HasParent()) {
                            std::cout << std::endl << "Il padre è: " << node->Parent().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste il padre di: " << node->Element() << std::endl;
                          }
                          break;

                        case 9:
                          if (node->HasLeftSibling()) {
                            std::cout << std::endl << "Il fratello sinistro è: " << node->LeftSibling().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste il fratello sinistro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 10:
                          if (node->HasRightSibling()) {
                            std::cout << std::endl << "Il fratello destro è: " << node->RightSibling().Element() << std::endl;
                          }
                          else {
                            std::cout << std::endl << "Non esiste il fratello destro di: " << node->Element() << std::endl;
                          }
                          break;

                        case 11:
                          std::cout << std::endl << "Terminazione del programma." << std::endl;
                          break;

                        default:
                          std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                        }
                    } while (op != 11);

                }
                else {
                  std::cout << "L'elemento inserito non è presente all'interno dell'albero" << std::endl;
                }

                //Funzione effettua il cubo del valore degli elementi
                std::cout << std::endl << "Gli elementi dell'albero elevati al cubo sono: " << std::endl;
                vect.MapBreadth (&MapCube, nullptr);
                vect.MapBreadth (MapView<float>, nullptr);
                std::cout << std::endl;

                break;
              }

              case 30: {

                std::cout << "Terminazione del programma." << std::endl;
                return;

              }
              default:
                std::cout << "La scelta del tipo di dato non è corretta, riprova" << std::endl;
                break;
              }
          } while ((choiceData != 10) && (choiceData != 20));

        break;

      case 2:
      std::cout << std::endl <<"La struttura dati scelta è: albero di tipo lista." << std::endl;
      do {
        std::cout << std::endl << "Scelta del tipo di dato." << std::endl;
        std::cout << "Inserire 100 per utilizzare dati di tipo int" << std::endl;
        std::cout << "Inserire 200 per utilizzare dati di tipo float" << std::endl;
        std::cout << "Inserire 300 per per terminare il programma:   ";

        std::cin >> choiceData;
        switch (choiceData) {

          case 100: {
            std::cout << std::endl << "Il tipo di dato scelto è: int." << std::endl;
            uint n, op;
            int exis, m, elemento, prodotto = 1;
            lasd::BinaryTreeLnk <int> link;

            //Creazione albero Random
            std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
            std::cin >> n;

            std::default_random_engine generator (std::random_device{}());
            std::uniform_int_distribution<int> elem (1,100);

            if (n != 0) {
              link.NewRoot (elem(generator));
              n-- ;
            }
            if (n != 0) {
              RandomTreeLnkInt (n, link, link.Root());
            }

            //Visualizzazione dell'albero
            std::cout << std::endl << "Visualizzazione in Pre-Ordine:   ";
            link.MapPreOrder (MapView<int>, nullptr);
            std::cout << std::endl << "Visualizzazione In Ordine:   ";
            link.MapInOrder (MapView<int>, nullptr);
            std::cout << std::endl << "Visualizzazione in Post-Ordine:   ";
            link.MapPostOrder (MapView<int>, nullptr);
            std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
            link.MapBreadth (MapView<int>, nullptr);

            //Ricerca di un dato elemento all'interno dell'albero
            std::cout << std::endl ;
            std::cout << std::endl << "Inserisci un valore da cercare all'interno dell'albero: ";
            std::cin >> exis;

            if (link.Exists(exis)) {
              std::cout << std::endl << "L'elemento è presente nell'albero: "<< std::endl;
            }
            else {
              std::cout << std::endl << "L'elemento non è presente nell'albero: "<< std::endl;
            }

            //Prodotto per gli interi minori di N
            std::cout << std::endl << "Inserisci un intero per effettuare il prodotto degli elementi minori di esso: ";
            std::cin >> m;
            link.FoldBreadth (&FoldProdMinN, &m, &prodotto);
            if (prodotto != 1) {
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" è: " << prodotto << std::endl;
            }
            else {
              std::cout << "Non esistono numeri interi minori di "<< m << std::endl;
            }

            //Funzione che triplica il valore degli elementi
            std::cout << std::endl << "Moltiplico gli elementi dell'albero x3" << std::endl;
            link.MapBreadth (MapTriplica, nullptr);

            //Visualizzazione dell'albero
            std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
            link.MapBreadth (MapView<int>, nullptr);
            std::cout << std::endl;

            //Operazioni specifiche
            std::cout << std::endl << "Inserisci un elemento per effettuare varie operazioni specifiche sul nodo:   ";
            std::cin >> elemento;
            if (link.Exists(elemento)) {
              lasd::BinaryTreeLnk<int>:: NodeLnk * node = SearchLinkInt (&link.Root(), elemento);
              std::cout << std::endl << "L'elemento inserito è presente "  << std::endl;

              do {
                  std::cout << std::endl << "Menù per interrogare il nodo." << std::endl;
                  std::cout << "Digitare 1 per visualizzare l'elemento" << std::endl;
                  std::cout << "Digitare 2 per controllare l'esistenza ed accedere al figlio sinistro " << std::endl;
                  std::cout << "Digitare 3 per controllare l'esistenza ed accedere al figlio destro " << std::endl;
                  std::cout << "Digitare 4 per inserire un nuovo figlio sinistro (causa eventuale perdita del sottoalbero)" << std::endl;
                  std::cout << "Digitare 5 per inserire un nuovo figlio destro (causa eventuale perdita del sottoalbero)" << std::endl;
                  std::cout << "Digitare 6 per rimuovere il figlio sinistro (ed eventuale sottoalbero) " << std::endl;
                  std::cout << "Digitare 7 per rimuovere il figlio destro (ed eventuale sottoalbero)" << std::endl;
                  std::cout << "Digitare 8 per Terminare il programma:   " ;

                  std::cin >> op;

                  switch (op) {
                    case 1:
                      std::cout << std::endl << "L'elemento è: " << node->Element() << std::endl;
                      break;

                    case 2:
                      if (node->HasLeftChild()) {
                        std::cout << std::endl << "Il figlio sinistro è: " << node->LeftChild().Element() << std::endl;
                      }
                      else {
                        std::cout << std::endl <<"Non esiste figlio sinistro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 3:
                      if (node->HasRightChild()) {
                        std::cout << std::endl << "Il figlio destro è: " << node->RightChild().Element() << std::endl;
                      }
                      else {
                        std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 4:
                      int x;
                      std::cout << std::endl << "Quale elemento vuoi inserire come figlio sinistro?   ";
                      std::cin >> x;
                      link.AddLeftChild (*node, x);
                      break;

                    case 5:
                      int y;
                      std::cout << std::endl << "Quale elemento vuoi inserire come figlio destro?   " ;
                      std::cin >> y;
                      link.AddRightChild (*node, y);
                      break;

                    case 6:
                      if (node->HasLeftChild()) {
                        link.RemoveLeftChild (*node);
                        std::cout << std::endl << "Il filgio sinistro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                      }
                      else {
                        std::cout << std::endl << "Non esiste figlio sinistro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 7:
                      if (node->HasRightChild()) {
                        link.RemoveRightChild (*node);
                        std::cout << std::endl <<"Il filgio destro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                      }
                      else {
                        std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 8:
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                      break;

                    default:
                      std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                    }
                } while (op != 8);

            }
            else {
              std::cout << "L'elemento inserito non è presente all'interno dell'albero" << std::endl;
            }

            break;
          }
          case 200: {
            std::cout << std::endl << "Il tipo di dato scelto è: float." << std::endl;
            uint n, op;
            float exis, m, elemento, somma = 0;
            lasd::BinaryTreeLnk <float> link;

            //Creazione albero Random
            std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
            std::cin >> n;

            std::default_random_engine generator (std::random_device{}());
            std::uniform_real_distribution<float> distribution (1,100);

            if (n != 0) {
              link.NewRoot (((float )((int)(distribution (generator) * 1000.0f)))/1000.0f);
              n-- ;
            }
            if (n != 0) {
              RandomTreeLinkFloat (n, link, link.Root());
            }

            //Visualizzazione dell'albero
            std::cout << std::endl << "Visualizzazione in Pre-Ordine:   ";
            link.MapPreOrder (MapView<float>, nullptr);
            std::cout << std::endl << "Visualizzazione In Ordine:   ";
            link.MapInOrder (MapView<float>, nullptr);
            std::cout << std::endl << "Visualizzazione in Post-Ordine:   ";
            link.MapPostOrder (MapView<float>, nullptr);
            std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
            link.MapBreadth (MapView<float>, nullptr);

            //Ricerca di un dato elemento all'interno dell'albero
            std::cout << std::endl ;
            std::cout << std::endl << "Inserisci un valore da cercare all'interno dell'albero: ";
            std::cin >> exis;

            if (link.Exists(exis)) {
              std::cout << std::endl << "L'elemento è presente nell'albero: "<< std::endl;
            }
            else {
              std::cout << std::endl << "L'elemento non è presente nell'albero: "<< std::endl;
            }

            //Somma dei reali maggiori di N
            std::cout << std::endl << "Inserisci un reale per effettuare la somma degli elementi maggiori di esso: ";
            std::cin >> m;
            link.FoldBreadth (&FoldSommaMaggN, &m, &somma);
            std::cout << "La somma degli elementi maggiori di "<< m <<" è: " << somma << std::endl;


            //Visualizzazione dell'albero
            std::cout << std::endl << "Visualizzazione in Ampiezza:   ";
            link.MapBreadth (MapView<float>, nullptr);
            std::cout << std::endl;

            //Operazioni specifiche
            std::cout << std::endl << "Inserisci un elemento per effettuare varie operazioni specifiche sul nodo:   ";
            std::cin >> elemento;
            if (link.Exists(elemento)) {
              lasd::BinaryTreeLnk<float>:: NodeLnk * node = SearchLinkFloat (&link.Root(), elemento);
              std::cout << std::endl << "L'elemento inserito è presente "  << std::endl;

              do {
                  std::cout << std::endl << "Menù per interrogare il nodo." << std::endl;
                  std::cout << "Digitare 1 per visualizzare l'elemento" << std::endl;
                  std::cout << "Digitare 2 per controllare l'esistenza ed accedere al figlio sinistro " << std::endl;
                  std::cout << "Digitare 3 per controllare l'esistenza ed accedere al figlio destro " << std::endl;
                  std::cout << "Digitare 4 per inserire un nuovo figlio sinistro (causa eventuale perdita del sottoalbero)" << std::endl;
                  std::cout << "Digitare 5 per inserire un nuovo figlio destro (causa eventuale perdita del sottoalbero)" << std::endl;
                  std::cout << "Digitare 6 per rimuovere il figlio sinistro (ed eventuale sottoalbero) " << std::endl;
                  std::cout << "Digitare 7 per rimuovere il figlio destro (ed eventuale sottoalbero)" << std::endl;
                  std::cout << "Digitare 8 per Terminare il programma:   " ;

                  std::cin >> op;

                  switch (op) {
                    case 1:
                      std::cout << std::endl << "L'elemento è: " << node->Element() << std::endl;
                      break;

                    case 2:
                      if (node->HasLeftChild()) {
                        std::cout << std::endl << "Il figlio sinistro è: " << node->LeftChild().Element() << std::endl;
                      }
                      else {
                        std::cout << std::endl <<"Non esiste figlio sinistro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 3:
                      if (node->HasRightChild()) {
                        std::cout << std::endl << "Il figlio destro è: " << node->RightChild().Element() << std::endl;
                      }
                      else {
                        std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 4:
                      float x;
                      std::cout << std::endl << "Quale elemento vuoi inserire come figlio sinistro?   ";
                      std::cin >> x;
                      link.AddLeftChild (*node, x);
                      break;

                    case 5:
                      float y;
                      std::cout << std::endl << "Quale elemento vuoi inserire come figlio destro?   " ;
                      std::cin >> y;
                      link.AddRightChild (*node, y);
                      break;

                    case 6:
                      if (node->HasLeftChild()) {
                        link.RemoveLeftChild (*node);
                        std::cout << std::endl << "Il filgio sinistro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                      }
                      else {
                        std::cout << std::endl << "Non esiste figlio sinistro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 7:
                      if (node->HasRightChild()) {
                        link.RemoveRightChild (*node);
                        std::cout << std::endl <<"Il filgio destro (ed eventuale sotto albero) è stato rimosso. " <<std::endl;
                      }
                      else {
                        std::cout << std::endl << "Non esiste figlio destro di: " << node->Element() << std::endl;
                      }
                      break;

                    case 8:
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                      break;

                    default:
                      std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                    }
                } while (op != 8);

            }
            else {
              std::cout << "L'elemento inserito non è presente all'interno dell'albero" << std::endl;
            }

            //Funzione effettua il cubo del valore degli elementi
            std::cout << std::endl << "Gli elementi dell'albero elevati al cubo sono: " << std::endl;
            link.MapBreadth (&MapCube, nullptr);
            link.MapBreadth (MapView<float>, nullptr);
            std::cout << std::endl;

            break;
            }

            case 300: {

              std::cout << "Terminazione del programma." << std::endl;
              return;

            }

            default:
            std::cout << "La scelta del tipo di dato non è corretta, riprova" << std::endl;
            break;
          }
        } while ((choiceData != 100) && (choiceData != 200));

        break;

      case 3:
        std::cout << "Terminazione del programma." << std::endl;
        break;

      default:
        std::cout << "La scelta inserita non è corretta, riprova" << std::endl;
        break;
      }
    } while( (choiceStruct != 1) && (choiceStruct !=2) && (choiceStruct !=3) );
}
