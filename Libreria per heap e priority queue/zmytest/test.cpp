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
#include "../heap/heap.hpp"
#include "../priorityqueue/priorityqueue.hpp"


/* ************************************************************************** */

//Funzione per visualizzare la lista tramite MAP
template <typename Data>
void MapView (Data& stampa, void * par) {
  std::cout << stampa << " ";
}

//Funzione che trasforma gli elementi dispari della struttura negli elementi opposti
void MapOddReverse (int& dat, void * par) {
  if (dat % 2 == 1) {
    dat = -dat;
  }
}

//Funzione che trasforma gli elementi della struttura negli elementi opposti
void MapReverse (float& dat, void * par) {
  dat = -dat;
}

//Funzione che concatena in testa una specifica stringa passata dall'utente
void MapConcStr (std::string& dat, void * par) {
  dat = (*((std::string*) par)) + dat;
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


//Funzione di concatenazione per stringhe con lunghezza minore o uguale di n tramite Fold
void FoldConcat (const std::string& dat, const void * n, void * conc){
  if (dat.size() <= *((int*) n))
  {
    *((std::string *) conc) = (*((std::string*) conc) +  dat);
  }
}

//Ricerca del nodo
typename lasd:: BinaryTreeVec <int> :: NodeVec* SearchElemInt(lasd::BinaryTreeVec<int>:: NodeVec* node){
  if (node != nullptr) {
    ushort x;
    std::cout << "Inserire 1 se si vuole cambiare priorità al nodo avente elemento " << node->Element() << std::endl;
    std::cout << "Inserire qualsiasi altro intero per continuare nella ricerca:   ";
    std::cin >> x;
    if (x == 1){
      return node;
    }
    else {
      if (node->HasLeftChild()) {
        lasd::BinaryTreeVec<int>:: NodeVec* temp = SearchElemInt (&node->LeftChild());
        if (temp != nullptr) {
          return temp;
        }
      }
      if (node->HasRightChild()) {
        return SearchElemInt (&node->RightChild());
      }
    }
  }
  return nullptr;
}


//Ricerca del nodo
typename lasd:: BinaryTreeVec <float> :: NodeVec* SearchElemFloat(lasd::BinaryTreeVec<float>:: NodeVec* node){
  if (node != nullptr) {
    ushort x;
    std::cout << "Inserire 1 se si vuole cambiare priorità al nodo avente elemento " << node->Element() << std::endl;
    std::cout << "Inserire qualsiasi altro intero per continuare nella ricerca:   ";
    std::cin >> x;
    if (x == 1){
      return node;
    }
    else {
      if (node->HasLeftChild()) {
        lasd::BinaryTreeVec<float>:: NodeVec* temp = SearchElemFloat (&node->LeftChild());
        if (temp != nullptr) {
          return temp;
        }
      }
      if (node->HasRightChild()) {
        return SearchElemFloat (&node->RightChild());
      }
    }
  }
  return nullptr;
}



//Ricerca del nodo
typename lasd:: BinaryTreeVec <std::string> :: NodeVec* SearchElemString(lasd::BinaryTreeVec<std::string>:: NodeVec* node){
  if (node != nullptr) {
    ushort x;
    std::cout << "Inserire 1 se si vuole cambiare priorità al nodo avente elemento " << node->Element() << std::endl;
    std::cout << "Inserire qualsiasi altro intero per continuare nella ricerca:   " ;
    std::cin >> x;
    if (x == 1){
      return node;
    }
    else {
      if (node->HasLeftChild()) {
        lasd::BinaryTreeVec<std::string>:: NodeVec* temp = SearchElemString (&node->LeftChild());
        if (temp != nullptr) {
          return temp;
        }
      }
      if (node->HasRightChild()) {
        return SearchElemString (&node->RightChild());
      }
    }
  }
  return nullptr;
}


/* ************************************************************************** */


void libraryTest () {


ushort choiceStruct, choiceData;

  do {
    std::cout << std::endl << "Scelta della struttura dati." << std::endl;
    std::cout << "Inserire 1 per utilizzare la struttura dati albero heap" << std::endl;
    std::cout << "Inserire 2 per utilizzare la struttura dati priority queue " << std::endl;
    std::cout << "Inserire 3 per terminare il programma:    ";
    std::cin >> choiceStruct;
    switch (choiceStruct) {
      case 1: {
        std::cout << std::endl << "La struttura dati scelta è: albero heap." << std::endl;
        do {
          std::cout << std::endl << "Scelta del tipo di dato." << std::endl;
          std::cout << "Inserire 10 per utilizzare dati di tipo int" << std::endl;
          std::cout << "Inserire 20 per utilizzare dati di tipo float" << std::endl;
          std::cout << "Inserire 30 per utilizzare dati di tipo string" << std::endl;
          std::cout << "Inserire 40 per terminare il programma:   ";
          std::cin >> choiceData;
          switch (choiceData) {

            case 10: {
              std::cout << std::endl << "Il tipo di dato scelto int." << std::endl;
              uint n, m, ordina;
              int exis,prodotto = 1;

              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::Vector<int> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution (1,100);

              for(ulong i = 0; i < n; ++i)
              {
                vect[i] = distribution(generator);
              }

              lasd::Heap<int> tree(vect);

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione sinistra verso detra) sono: "<< std::endl;
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione destra verso sinistra) sono: "<< std::endl;
              tree.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare il prodotto degli elementi minori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPreOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldPreOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPostOrder) è: " << prodotto << std::endl;

              //Visualizzazione dell'albero

              std::cout << std::endl << "Visualizzazione in Pre ordine:   ";
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Visualizzazione in Post ordine:   ";
              tree.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Funzione che trasforma gli elementi dispari della struttura negli elementi opposti
              std::cout << std::endl << "Gli elementi dell'albero dopo l'applicazione di MapOddReverse sono:   ";
              tree.MapPreOrder (MapOddReverse, nullptr);
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Inserire 1 se desidere effettuare l'ordinamento degli elementi della struttura: ";
              std::cin >> ordina;
              if (ordina == 1) {
                tree.Sort();
                tree.MapPreOrder (MapView<int>, nullptr);
                std::cout << std::endl;
              }

              break;
           }

           case 20: {
              std::cout << std::endl << "Il tipo di dato scelto è: float." << std::endl;
              uint n, ordina;
              float exis, m, somma = 0;

              std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
              std::cin >> n;

              lasd::Vector <float> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_real_distribution<float> distribution(1,100);

              for(ulong i = 0; i < n; ++i)
              {
                vect[i] = ((float )((int)(distribution(generator) * 1000.0f)))/1000.0f;;
              }

              lasd::Heap<float> tree(vect);

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione sinistra verso detra) sono: "<< std::endl;
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione destra verso sinistra) sono: "<< std::endl;
              tree.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Somma dei reali maggiori di N
              std::cout << std::endl << "Inserisci un reale per effettuare la somma degli elementi maggiori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma degli elementi maggiori di "<< m <<" (tramite FoldPreOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldPreOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma degli elementi maggiori di "<< m <<" (tramite FoldPostOrder) è: " << somma << std::endl;

              //Visualizzazione dell'albero
              std::cout << std::endl << "Visualizzazione in Pre ordine:   ";
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Visualizzazione in Post ordine:   ";
              tree.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Funzione che trasforma gli elementi della struttura negli elementi opposti
              std::cout << std::endl << "Gli elementi dell'albero dopo l'applicazione di MapReverse sono:   ";
              tree.MapPreOrder (MapReverse, nullptr);
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Inserire 1 se desidere effettuare l'ordinamento degli elementi della struttura: ";
              std::cin >> ordina;
              if (ordina == 1) {
                tree.Sort();
                tree.MapPreOrder (MapView<float>, nullptr);
                std::cout << std::endl;
              }

              break;
           }

           case 30: {
              std::cout << std::endl << "Il tipo di dato scelto è: string." << std::endl;
              uint n, lung, m, ordina;
              std::string exis, str, conc = "";

              std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
              std::cin >> n;
              lasd::Vector <std::string> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,10);
              std::uniform_int_distribution<int> distr(97,122);

              for(ulong i = 0; i < n; ++i)
              {
                lung = distribution (generator);
                char * str = new char [lung];
                for(ulong j = 0; j < lung; ++j)  {
                  str[j] = distr(generator);
                }
                vect[i] = str;
              }

              lasd::Heap<std::string> tree(vect);

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione sinistra verso detra) sono: "<< std::endl;
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione destra verso sinistra) sono: "<< std::endl;
              tree.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Concatenazione di stringhe con lunghezza minore o uguale ad N
              std::cout << std::endl << "Inserisci un intero 'N' per effettuare la concatenazione delle stringhe con lunghezza <= N: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldPreOrder) è:   ";
              std::cout << conc << std::endl;

              conc = "";

              tree.FoldPostOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldPostOrder) è:   ";
              std::cout << conc << std::endl;

              //Visualizzazione dell'albero

              std::cout << std::endl << "Visualizzazione in Pre ordine:   ";
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Visualizzazione in Post ordine:   ";
              tree.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Funzione che concatena in testa una specifica stringa passata dall'utente
              std::cout << std::endl << "Inserisci una stringa per concatenarla in testa ad ogni elemento della struttura: ";
              std::cin >> str;
              std::cout << std::endl << "Gli elementi dell'albero dopo l'applicazione di MapReverse sono:   ";
              tree.MapPreOrder (MapConcStr, &str);
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Inserire 1 se desidere effettuare l'ordinamento degli elementi della struttura: ";
              std::cin >> ordina;
              if (ordina == 1) {
                tree.Sort();
                tree.MapPreOrder (MapView<std::string>, nullptr);
                std::cout << std::endl;
              }

              break;
           }

           case 40:

              std::cout << "Terminazione del programma." << std::endl;
              return;

            default:
              std::cout << "La scelta del tipo di dato non è corretta, riprova" << std::endl;
              break;
            }
          } while ((choiceData != 10) && (choiceData != 20) && (choiceData != 30) );

            break;

        break;
      }
      case 2: {
        std::cout << std::endl << "La struttura dati scelta è: priority queue" << std::endl;

        do {
          std::cout << std::endl << "Scelta del tipo di dato." << std::endl;
          std::cout << "Inserire 100 per utilizzare dati di tipo int" << std::endl;
          std::cout << "Inserire 200 per utilizzare dati di tipo float" << std::endl;
          std::cout << "Inserire 300 per utilizzare dati di tipo string" << std::endl;
          std::cout << "Inserire 400 per terminare il programma:   ";
          std::cin >> choiceData;
          switch (choiceData) {

            case 100: {
              std::cout << std::endl << "Il tipo di dato scelto int." << std::endl;
              uint n, m, ordina, selezione, op;
              int exis, x, prior, prodotto = 1;
              lasd::BinaryTreeVec<int>::NodeVec * temp = nullptr;

              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::List<int> list;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution (1,100);

              do {
                std::cout << std::endl << "Inserire 1 se si vuole inserire in testa." << std::endl;
                std::cout << "Inserire 2 se si vuole inserire in coda."<< std::endl;
                std::cout << "Inserire 3 per terminare il programma:    ";
                std::cin >> selezione ;

                if (selezione == 1) {
                  for (ulong i=0; i<n; ++i) {
                    list.InsertAtFront (distribution(generator));
                  }
                } else if (selezione == 2) {
                    for (ulong i=0; i<n; ++i) {
                      list.InsertAtBack (distribution(generator));
                    }
                } else if (selezione == 3) {
                    std::cout << "Terminazione del programma." << std::endl;
                    return;
                } else {
                      std::cout << "La scelta inserita non è corretta, ripetere!" << std::endl;
                  }
              } while (selezione != 1 && selezione != 2);


              lasd::PriorityQueue<int> tree(list);

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione sinistra verso detra) sono: "<< std::endl;
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione destra verso sinistra) sono: "<< std::endl;
              tree.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare il prodotto degli elementi minori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPreOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldPreOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPostOrder) è: " << prodotto << std::endl;

              //Visualizzazione dell'albero

              std::cout << std::endl << "Visualizzazione in Pre ordine:   ";
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Visualizzazione in Post ordine:   ";
              tree.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Funzione che trasforma gli elementi dispari della struttura negli elementi opposti
              std::cout << std::endl << "Gli elementi dell'albero dopo l'applicazione di MapOddReverse sono:   ";
              tree.MapPreOrder (MapOddReverse, nullptr);
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              do {
                  std::cout << std::endl << "Menù." << std::endl;
                  std::cout << "Digitare 1 per effettuare l'ordinamento." << std::endl;
                  std::cout << "Digitare 2 per effettuare un inserimento." << std::endl;
                  std::cout << "Digitare 3 per effettuare una rimozione." << std::endl;
                  std::cout << "Digitare 4 per effettuare una rimozione con lettura." << std::endl;
                  std::cout << "Digitare 5 per effettuare una lettura non distruttiva (all'elemento immediatamente accessibile)." << std::endl;
                  std::cout << "Digitare 6 per effettuare un cambio di priorità." << std::endl;
                  std::cout << "Digitare 7 per Terminare il programma:   " ;

                  std::cin >> op;

                  switch (op) {
                    case 1:
                        std::cout << "Gli elementi ordinati sono:   " ;
                        tree.Sort();
                        tree.MapPreOrder (MapView<int>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 2:
                        std::cout << "Digitare l'elemento da inserire nelle priority queue:   " ;
                        std::cin >> x;
                        tree.Insert (x);
                        std::cout << "Gli elementi della struttura dopo l'inserimento sono:   " ;
                        tree.MapPreOrder (MapView<int>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 3:
                        tree.RemoveTip();
                        std::cout << "Gli elementi della struttura dopo la rimozione sono:   " ;
                        tree.MapPreOrder (MapView<int>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 4:
                        std::cout << "L'elemeto rimosso è: " << tree.TipNRemove() << std::endl;
                        std::cout << "Gli elementi della struttura dopo la rimozione sono:   " ;
                        tree.MapPreOrder (MapView<int>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 5:
                        std::cout << "L'elemeto in testa è: " << tree.Tip() << std::endl;
                        std::cout << std::endl;
                      break;

                    case 6:
                        std::cout << std::endl;
                        temp = SearchElemInt (&tree.Root());
                        if (temp != nullptr) {
                          std::cout << "Con quale priorità desidera cambiare?   ";
                          std::cin >> prior;
                          tree.ChangePriority (*temp, prior);
                          std::cout << "La struttura dopo il cambiamento di priorità è:   ";
                          tree.MapPreOrder (MapView<int>, nullptr);
                          std::cout << std::endl;
                        }
                        else {
                          std::cout << "Nessun elemento è stato cambaito" << std::endl;
                        }

                      break;

                    case 7:
                        std::cout << std::endl << "Terminazione del programma." << std::endl;
                      break;

                    default:
                      std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                    }
                } while (op != 7);

              break;
            }

            case 200: {
              std::cout << std::endl << "Il tipo di dato scelto è: float." << std::endl;
              uint n, ordina, op;
              float exis, m, prior, somma = 0;
              lasd::BinaryTreeVec<float>::NodeVec * temp = nullptr;

              std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
              std::cin >> n;

              lasd::Vector <float> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_real_distribution<float> distribution(1,100);

              for(ulong i = 0; i < n; ++i)
              {
                vect[i] = ((float )((int)(distribution(generator) * 1000.0f)))/1000.0f;;
              }

              lasd::PriorityQueue<float> tree(vect);

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione sinistra verso detra) sono: "<< std::endl;
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione destra verso sinistra) sono: "<< std::endl;
              tree.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Somma dei reali maggiori di N
              std::cout << std::endl << "Inserisci un reale per effettuare la somma degli elementi maggiori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma degli elementi maggiori di "<< m <<" (tramite FoldPreOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldPreOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma degli elementi maggiori di "<< m <<" (tramite FoldPostOrder) è: " << somma << std::endl;

              //Visualizzazione dell'albero
              std::cout << std::endl << "Visualizzazione in Pre ordine:   ";
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Visualizzazione in Post ordine:   ";
              tree.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Funzione che trasforma gli elementi della struttura negli elementi opposti
              std::cout << std::endl << "Gli elementi dell'albero dopo l'applicazione di MapReverse sono:   ";
              tree.MapPreOrder (MapReverse, nullptr);
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              do {
                  std::cout << std::endl << "Menù." << std::endl;
                  std::cout << "Digitare 1 per effettuare l'ordinamento." << std::endl;
                  std::cout << "Digitare 2 per effettuare un inserimento." << std::endl;
                  std::cout << "Digitare 3 per effettuare una rimozione." << std::endl;
                  std::cout << "Digitare 4 per effettuare una rimozione con lettura." << std::endl;
                  std::cout << "Digitare 5 per effettuare una lettura non distruttiva (all'elemento immediatamente accessibile)." << std::endl;
                  std::cout << "Digitare 6 per effettuare un cambio di priorità." << std::endl;
                  std::cout << "Digitare 7 per Terminare il programma:   " ;

                  std::cin >> op;

                  switch (op) {
                    case 1:
                        std::cout << "Gli elementi ordinati sono:   " ;
                        tree.Sort();
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 2:
                      float y;
                        std::cout << "Digitare l'elemento da inserire nelle priority queue:   " ;
                        std::cin >> y;
                        tree.Insert (y);
                        std::cout << "Gli elementi della struttura dopo l'inserimento sono:   " ;
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 3:
                        tree.RemoveTip();
                        std::cout << "Gli elementi della struttura dopo la rimozione sono:   " ;
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 4:
                        std::cout << "L'elemeto rimosso è: " << tree.TipNRemove() << std::endl;
                        std::cout << "Gli elementi della struttura dopo la rimozione sono:   " ;
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 5:
                        std::cout << "L'elemeto in testa è: " << tree.Tip() << std::endl;
                        std::cout << std::endl;
                      break;

                    case 6:

                      std::cout << std::endl;
                      temp = SearchElemFloat (&tree.Root());
                      if (temp != nullptr) {
                        std::cout << "Con quale priorità desidera cambiare?   ";
                        std::cin >> prior;
                        tree.ChangePriority (*temp, prior);
                        std::cout << "La struttura dopo il cambiamento di priorità è:   ";
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      }
                      else {
                        std::cout << "Nessun elemento è stato cambaito" << std::endl;
                      }

                      break;

                    case 7:
                        std::cout << std::endl << "Terminazione del programma." << std::endl;
                      break;

                    default:
                        std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                    }
                } while (op != 7);


              break;
            }

            case 300: {
              std::cout << std::endl << "Il tipo di dato scelto è: string." << std::endl;
              uint n, lung, m, ordina, op;
              std::string exis, str, z, prior, conc = "";
              lasd::BinaryTreeVec<std::string>::NodeVec * temp = nullptr;

              std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
              std::cin >> n;
              lasd::Vector <std::string> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,10);
              std::uniform_int_distribution<int> distr(97,122);

              for(ulong i = 0; i < n; ++i)
              {
                lung = distribution (generator);
                char * str = new char [lung];
                for(ulong j = 0; j < lung; ++j)  {
                  str[j] = distr(generator);
                }
                vect[i] = str;
              }

              lasd::PriorityQueue <std::string> tree(vect);

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione sinistra verso detra) sono: "<< std::endl;
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione destra verso sinistra) sono: "<< std::endl;
              tree.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Concatenazione di stringhe con lunghezza minore o uguale ad N
              std::cout << std::endl << "Inserisci un intero 'N' per effettuare la concatenazione delle stringhe con lunghezza <= N: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldPreOrder) è:   ";
              std::cout << conc << std::endl;

              conc = "";

              tree.FoldPostOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldPostOrder) è:   ";
              std::cout << conc << std::endl;

              //Visualizzazione dell'albero

              std::cout << std::endl << "Visualizzazione in Pre ordine:   ";
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Visualizzazione in Post ordine:   ";
              tree.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Funzione che concatena in testa una specifica stringa passata dall'utente
              std::cout << std::endl << "Inserisci una stringa per concatenarla in testa ad ogni elemento della struttura: ";
              std::cin >> str;
              std::cout << std::endl << "Gli elementi dell'albero dopo l'applicazione di MapReverse sono:   ";
              tree.MapPreOrder (MapConcStr, &str);
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              do {
                  std::cout << std::endl << "Menù." << std::endl;
                  std::cout << "Digitare 1 per effettuare l'ordinamento." << std::endl;
                  std::cout << "Digitare 2 per effettuare un inserimento." << std::endl;
                  std::cout << "Digitare 3 per effettuare una rimozione." << std::endl;
                  std::cout << "Digitare 4 per effettuare una rimozione con lettura." << std::endl;
                  std::cout << "Digitare 5 per effettuare una lettura non distruttiva (all'elemento immediatamente accessibile)." << std::endl;
                  std::cout << "Digitare 6 per effettuare un cambio di priorità." << std::endl;
                  std::cout << "Digitare 7 per Terminare il programma:   " ;

                  std::cin >> op;

                  switch (op) {
                    case 1:
                        std::cout << "Gli elementi ordinati sono:   " ;
                        tree.Sort();
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 2:
                        std::cout << "Digitare l'elemento da inserire nelle priority queue:   " ;
                        std::cin >> z;
                        tree.Insert(z);
                        std::cout << "Gli elementi della struttura dopo l'inserimento sono:   " ;
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 3:
                        tree.RemoveTip();
                        std::cout << "Gli elementi della struttura dopo la rimozione sono:   " ;
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 4:
                        std::cout << "L'elemeto rimosso è: " << tree.TipNRemove() << std::endl;
                        std::cout << "Gli elementi della struttura dopo la rimozione sono:   " ;
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      break;

                    case 5:
                        std::cout << "L'elemeto in testa è: " << tree.Tip() << std::endl;
                        std::cout << std::endl;
                      break;

                    case 6:

                      std::cout << std::endl;
                      temp = SearchElemString (&tree.Root());
                      if (temp != nullptr) {
                        std::cout << "Con quale priorità desidera cambiare?   ";
                        std::cin >> prior;
                        tree.ChangePriority (*temp, prior);
                        std::cout << "La struttura dopo il cambiamento di priorità è:   ";
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      }
                      else {
                        std::cout << "Nessun elemento è stato cambaito" << std::endl;
                      }

                      break;

                    case 7:
                        std::cout << std::endl << "Terminazione del programma." << std::endl;
                      break;

                    default:
                        std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                    }
                } while (op != 7);


              break;
            }

            case 400:

              std::cout << "Terminazione del programma." << std::endl;
              return;



            default:
              std::cout << "La scelta del tipo di dato non è corretta, riprova" << std::endl;
              break;
            }
          } while ((choiceData != 100) && (choiceData != 200) && (choiceData != 300) );

        break;
      }
      case 3:
        std::cout << "Terminazione del programma" << std::endl;
        break;

      default:
        std::cout << "La scelta inserita non è corretta, riprova" << std::endl;
      }
    } while (choiceStruct != 1 && choiceStruct != 2 && choiceStruct != 3) ;
}
