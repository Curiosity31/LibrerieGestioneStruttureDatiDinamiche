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
#include "../bst/bst.hpp"
#include "../bst/avl/avl.hpp"
#include "../bst/rb/rb.hpp"


/* ************************************************************************** */

//Funzione per visualizzare la lista tramite MAP
template <typename Data>
void MapView (Data& stampa, void * par) {
  std::cout << stampa << " ";
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



/* ************************************************************************** */


void libraryTest () {

  ushort choiceStruct, choiceData, op;

  do {
    std::cout << std::endl << "Scelta della struttura dati." << std::endl;
    std::cout << "Inserire 1 per utilizzare la struttura dati albero BST" << std::endl;
    std::cout << "Inserire 2 per utilizzare la struttura dati albero AVL " << std::endl;
    std::cout << "Inserire 3 per utilizzare la struttura dati albero RB " << std::endl;
    std::cout << "Inserire 4 per terminare il programma:    ";
    std::cin >> choiceStruct;
    switch (choiceStruct) {

      case 1: {

        std::cout << std::endl << "La struttura dati scelta è: albero BST." << std::endl;
        do {
          std::cout << std::endl << "Scelta del tipo di dato." << std::endl;
          std::cout << "Inserire 10 per utilizzare dati di tipo int" << std::endl;
          std::cout << "Inserire 20 per utilizzare dati di tipo float" << std::endl;
          std::cout << "Inserire 30 per utilizzare dati di tipo string" << std::endl;
          std::cout << "Inserire 40 per terminare il programma:   ";
          std::cin >> choiceData;
          switch (choiceData) {

            case 10: {

              std::cout << std::endl << "Il tipo di dato scelto è: int." << std::endl;
              uint n, m;
              int exis, prodotto = 1 ;

              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::BST<int> tree;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution (1,100);

              for(ulong i = 0; i < n; ++i)
              {
                tree.Insert (distribution(generator));
              }

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare il prodotto degli elementi minori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPreOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldPostOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPostOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldInOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldInOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldBreadth (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldBreadth) è: " << prodotto << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      int n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    int n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    int n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    int n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<int>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);

            break;
            }

            case 20: {

              std::cout << std::endl << "Il tipo di dato scelto è: float." << std::endl;
              uint n;
              float exis, m, somma = 0;


              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::BST<float> tree;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_real_distribution<float> distribution (1,100);

              for(ulong i = 0; i < n; ++i)
              {
                tree.Insert (((float )((int)(distribution(generator) * 1000.0f)))/1000.0f);
              }

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare la somma degli elementi maggiori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldPreOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldPostOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldPostOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldInOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldInOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldBreadth (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldBreadth) è: " << somma << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      float n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    float n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    float n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    float n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);



            break;
            }

            case 30: {

              std::cout << std::endl << "Il tipo di dato scelto è: string." << std::endl;
              uint n,m,lung;
              std::string exis, conc = "";

              std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
              std::cin >> n;
              lasd::BST <std::string> tree;

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
                tree.Insert(str);
              }


              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
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

              conc= "";

              tree.FoldInOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldInOrder) è:   ";
              std::cout << conc << std::endl;

              conc= "";

              tree.FoldBreadth (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldBreadthOrder) è:   ";
              std::cout << conc << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      std::string n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    std::string n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    std::string n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    std::string n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);



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
      }

      case 2: {

        std::cout << std::endl << "La struttura dati scelta è: albero AVL." << std::endl;
        do {
          std::cout << std::endl << "Scelta del tipo di dato." << std::endl;
          std::cout << "Inserire 10 per utilizzare dati di tipo int" << std::endl;
          std::cout << "Inserire 20 per utilizzare dati di tipo float" << std::endl;
          std::cout << "Inserire 30 per utilizzare dati di tipo string" << std::endl;
          std::cout << "Inserire 40 per terminare il programma:   ";
          std::cin >> choiceData;
          switch (choiceData) {

            case 10: {

              std::cout << std::endl << "Il tipo di dato scelto è: int." << std::endl;
              uint n, m, op;
              int exis, prodotto = 1 ;

              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::AVL<int> tree;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution (1,100);

              for(ulong i = 0; i < n; ++i)
              {
                tree.Insert (distribution(generator));
              }

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare il prodotto degli elementi minori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPreOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldPostOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPostOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldInOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldInOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldBreadth (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldBreadth) è: " << prodotto << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      int n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    int n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    int n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    int n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<int>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);


            break;
            }

            case 20: {

              std::cout << std::endl << "Il tipo di dato scelto è: float." << std::endl;
              uint n;
              float exis, m, somma = 0;


              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::AVL<float> tree;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_real_distribution<float> distribution (1,100);

              for(ulong i = 0; i < n; ++i)
              {
                tree.Insert (((float )((int)(distribution(generator) * 1000.0f)))/1000.0f);
              }

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare la somma degli elementi maggiori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldPreOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldPostOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldPostOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldInOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldInOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldBreadth (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldBreadth) è: " << somma << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      float n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    float n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    float n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    float n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);


            break;
            }

            case 30: {

              std::cout << std::endl << "Il tipo di dato scelto è: string." << std::endl;
              uint n,m,lung;
              std::string exis, conc = "";

              std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
              std::cin >> n;
              lasd::AVL <std::string> tree;

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
                tree.Insert(str);
              }


              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
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

              conc= "";

              tree.FoldInOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldInOrder) è:   ";
              std::cout << conc << std::endl;

              conc= "";

              tree.FoldBreadth (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldBreadthOrder) è:   ";
              std::cout << conc << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      std::string n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    std::string n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    std::string n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    std::string n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);



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
      }

      case 3: {

        std::cout << std::endl << "La struttura dati scelta è: albero RB." << std::endl;
        do {
          std::cout << std::endl << "Scelta del tipo di dato." << std::endl;
          std::cout << "Inserire 10 per utilizzare dati di tipo int" << std::endl;
          std::cout << "Inserire 20 per utilizzare dati di tipo float" << std::endl;
          std::cout << "Inserire 30 per utilizzare dati di tipo string" << std::endl;
          std::cout << "Inserire 40 per terminare il programma:   ";
          std::cin >> choiceData;
          switch (choiceData) {

            case 10: {

              std::cout << std::endl << "Il tipo di dato scelto è: int." << std::endl;
              uint n, m, op;
              int exis, prodotto = 1;

              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::RB<int> tree;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution (1,100);

              for(ulong i = 0; i < n; ++i)
              {
                tree.Insert (distribution(generator));
              }

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare il prodotto degli elementi minori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPreOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldPostOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldPostOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldInOrder (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldInOrder) è: " << prodotto << std::endl;

              prodotto = 1;
              tree.FoldBreadth (&FoldProdMinN, &m, &prodotto);
              std::cout << "Il prodotto dei numeri interi minori di "<< m <<" (tramite FoldBreadth) è: " << prodotto << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      int n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    int n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    int n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    int n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<int>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<int>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    int n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);



            break;
            }

            case 20: {

              std::cout << std::endl << "Il tipo di dato scelto è: float." << std::endl;
              uint n;
              float exis, m, somma = 0;


              //Creazione albero con valori Random
              std::cout << std::endl << "Inserire il numero degli elementi della struttura: ";
              std::cin >> n;
              lasd::RB<float> tree;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_real_distribution<float> distribution (1,100);

              for(ulong i = 0; i < n; ++i)
              {
                tree.Insert (((float )((int)(distribution(generator) * 1000.0f)))/1000.0f);
              }

              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
              }

              //Prodotto per gli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare la somma degli elementi maggiori di esso: ";
              std::cin >> m;
              tree.FoldPreOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldPreOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldPostOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldPostOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldInOrder (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldInOrder) è: " << somma << std::endl;

              somma = 0;
              tree.FoldBreadth (&FoldSommaMaggN, &m, &somma);
              std::cout << "La somma dei numeri interi maggiori di "<< m <<" (tramite FoldBreadth) è: " << somma << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      float n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    float n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    float n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    float n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<float>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<float>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    float n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);



            break;
            }

            case 30: {

              std::cout << std::endl << "Il tipo di dato scelto è: string." << std::endl;
              uint n,m,lung;
              std::string exis, conc = "";

              std::cout << std::endl << "Inserire il numero degli elementi della struttura: " ;
              std::cin >> n;
              lasd::RB <std::string> tree;

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
                tree.Insert(str);
              }


              //visualizzazione di tutti gli elementi della struttura tramite funzione map
              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione PreOrder) sono: "<< std::endl;
              tree.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi dell'albero (visualizzazione PostOrder) sono: "<< std::endl;
              tree.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione InOrder) sono: "<< std::endl;
              tree.MapInOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi dell'albero (visualizzazione Breadth) sono: "<< std::endl;
              tree.MapInOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella struttura: ";
              std::cin >> exis;
              if (tree.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nell'albero. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nell'albero. " << std::endl;
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

              conc= "";

              tree.FoldInOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldInOrder) è:   ";
              std::cout << conc << std::endl;

              conc= "";

              tree.FoldBreadth (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione (tramite FoldBreadthOrder) è:   ";
              std::cout << conc << std::endl;

              do {
                std::cout << std::endl << "Menù." << std::endl;
                std::cout << "Digitare 1 per effettuare un inserimento." << std::endl;
                std::cout << "Digitare 2 per effettuare una rimozione." << std::endl;
                std::cout << "Digitare 3 per effettuare una lettura non distruttiva del minimo." << std::endl;
                std::cout << "Digitare 4 per effettuare una lettura non distruttiva del massimo." << std::endl;
                std::cout << "Digitare 5 per effettuare una lettura non distruttiva del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 6 per effettuare una lettura non distruttiva del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 7 per effettuare una rimozione senza lettura del minimo." << std::endl;
                std::cout << "Digitare 8 per effettuare una rimozione senza lettura del massimo." << std::endl;
                std::cout << "Digitare 9 per effettuare una rimozione senza lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 10 per effettuare una rimozione senza lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 11 per effettuare una rimozione con lettura del minimo." << std::endl;
                std::cout << "Digitare 12 per effettuare una rimozione con lettura del massimo." << std::endl;
                std::cout << "Digitare 13 per effettuare una rimozione con lettura del predecessore di un dato elemento." << std::endl;
                std::cout << "Digitare 14 per effettuare una rimozione con lettura del successore di un dato elemento." << std::endl;
                std::cout << "Digitare 15 per Terminare il programma:   " ;

                std::cin >> op;

                switch (op) {
                  case 1: {
                      std::string n;
                      std::cout << std::endl << "Quale elemento desideri inserire?   " ;
                      std:: cin >> n;
                      tree.Insert(n);
                      std::cout << std::endl << "L'albero dopo l'inserimento è:" << std::endl;
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    break;
                  }

                  case 2: {
                    std::string n;
                    std::cout << std::endl <<  "Quale elemento desideri eliminare?   " ;
                    std:: cin >> n;
                    tree.Remove(n);
                    std::cout << std::endl << "L'albero dopo la rimozione è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 3: {
                      std::cout << std::endl <<  "L'elemento minimo della struttura è:   " << tree.Min() << std::endl;
                  break;
                  }

                  case 4: {
                    std::cout << std::endl <<  "L'elemento massimo della struttura è:   " << tree.Max() << std::endl;
                  break;
                  }

                  case 5: {
                    std::string n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo predecessore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore di " << n << " è:   " << tree.Predecessor(n) << std::endl;
                  break;
                  }

                  case 6: {
                    std::string n;
                    std::cout << std::endl <<  "Inserisci un intero per leggere il suo successore:   " << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore di " << n << " è:   " << tree.Successor(n) << std::endl;
                    break;
                  }

                  case 7: {
                      tree.RemoveMin();
                      std::cout << std::endl << "L'albero dopo la rimozione del minimo è:" << std::endl;
                      if (!(tree.Empty())) {
                        tree.MapPreOrder (MapView<std::string>, nullptr);
                        std::cout << std::endl;
                      }
                  break;
                  }

                  case 8: {
                    tree.RemoveMax();
                    std::cout << std::endl << "L'albero dopo la rimozione del massimo è:" << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 9: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    tree.RemovePredecessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del predecessore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 10: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione senza lettura del suo successore" << std::endl;
                    std::cin >> n;
                    tree.RemoveSuccessor(n);
                    std::cout << std::endl << "L'albero dopo la rimozione del successore di " << n << " è:   " << std::endl;
                    if (!(tree.Empty())) {
                      tree.MapPreOrder (MapView<std::string>, nullptr);
                      std::cout << std::endl;
                    }
                  break;
                  }

                  case 11: {
                    std::cout << std::endl << "Il minimo rimosso è: " << tree.MinNRemove() << std::endl;
                  break;
                  }

                  case 12: {
                    std::cout << std::endl << "Il massimo rimosso è: " << tree.MaxNRemove() << std::endl;
                  break;
                  }

                  case 13: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo predecessore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il predecessore rimosso di " << n << " è: " << tree.PredecessorNRemove(n) << std::endl;
                  break;
                  }

                  case 14: {
                    std::string n;
                    std::cout << std::endl << "Inserire un elemento per effettuare una rimozione con lettura del suo successore" << std::endl;
                    std::cin >> n;
                    std::cout << "Il successore rimosso di " << n << " è: " << tree.SuccessorNRemove(n) << std::endl;
                  break;
                  }

                  case 15: {
                      std::cout << std::endl << "Terminazione del programma." << std::endl;
                  break;
                  }

                  default:
                    std::cout << std::endl << "La scelta inserita non è corretta, riprova" << std::endl;
                  }
              } while (op != 15);



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
      }

      case 4:
        std::cout << "Terminazione del programma" << std::endl;
      break;

      default:
        std::cout << "La scelta inserita non è corretta, riprova" << std::endl;

    }
  } while (choiceStruct != 1 && choiceStruct != 2 && choiceStruct != 3 && choiceStruct != 4) ;

}
