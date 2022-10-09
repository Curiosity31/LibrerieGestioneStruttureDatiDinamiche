#include "test.hpp"
#include <iostream>
#include <random>
#include <string>
/* ************************************************************************** */

#include "../container/container.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

/* ************************************************************************** */

//Funzione per visualizzare la lista tramite MAP
template <typename Data>
void MapView (Data& stampa, void * par) {
  std::cout << stampa << " ";
}

//Funzione che rappoddia il valore degli elementi tramite map
void MapRaddoppia (int& elem, void * par) {
  elem = elem * 2 ;
}


//Funzione somma interi minori di n tramite Fold
void FoldSommaMinN (const int& dat, const void * n, void * somma){
  if (dat < *((int*) n))
  {
    *((int*) somma) += dat;
  }
}


//Funzione prodotto per reali maggiore di n tramite Fold
void FoldProdottoMaggN (const float& dat, const void * n, void * prodotto){
  if (dat > *((float*) n))
  {
    *((float*) prodotto) = (*((float*) prodotto) * dat);
  }
}

//Funzione di concatenazione per stringhe con lunghezza minore o uguale di n tramite Fold
void FoldConcat (const std::string& dat, const void * n, void * conc){
  if (dat.size() <= *((int*) n))
  {
    *((std::string *) conc) = (*((std::string*) conc) +  dat);
  }
}


//Funzione che rappoddia il valore degli elementi tramite map
void MapQuadrato (float& elem, void * par) {
  elem = elem * elem ;
}


//Funzione che effettua l'uppercase degli elementi
void MapUpCase (std::string& elem, void * par) {
  for (ulong i=0; i<elem.size(); ++i)
    elem[i] = toupper (elem[i]);
  }



void libraryTest () {
  ushort choiceStruct, choiceData ;
  do {
    std::cout << std::endl << "Scelta struttura dati." << std::endl;
    std::cout << "Inserire 1 per utilizzare la struttura dati di tipo vettore" << std::endl;
    std::cout << "Inserire 2 per utilizzare la struttura dati di tipo lista" << std::endl;
    std::cout << "Inserire 3 per terminare il programma:   ";
    std::cin >> choiceStruct;

    switch (choiceStruct) {
      case 1:
        std::cout << std::endl << "La struttura dati scelta è: vettore." << std::endl;
        do {
          std::cout << std::endl << "Scelta del tipo di dato per il vettore." << std::endl;
          std::cout << "Inserire 10 per utilizzare dati di tipo int" << std::endl;
          std::cout << "Inserire 20 per utilizzare dati di tipo float" << std::endl;
          std::cout << "Inserire 30 per utilizzare dati di tipo string" << std::endl;
          std::cout << "Inserire 40 per terminare il programma:   ";
          std::cin >> choiceData;
          switch (choiceData) {
            case 10: {
              std::cout << std::endl << "Il tipo di dato scelto per il vettore è: int." << std::endl;
              uint n, indice;
              int exis, m, somma=0;

              std::cout << std::endl << "Inserire il numero degli elementi del vettore: ";
              std::cin >> n;
              lasd::Vector<int> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,100);

              for(ulong i = 0; i < n; ++i)
              {
                vect[i] = distribution(generator);
              }

              //Visualizzazione dell'elemento iniziale
              std::cout << std::endl << "L'elemento iniziale del vettore è: " << vect.Front() << std::endl;
              //Visualizzazione dell'elemento finale
              std::cout << "L'elemento finale del vettore è: " << vect.Back() << std::endl;
              //Visualizzazione dell'elemento avente uno specifico indice
              std::cout << std::endl << "Quale indice del vettore desideri visualizzare?  (Da 0 ad " << n-1 <<") : ";
              std::cin >> indice;
              std::cout << "L'elemento " << indice << " del vettore è: " << vect[indice] << std::endl;

              //visualizzazione di tutti gli elementi del vettore tramite funzione map
              std::cout << std::endl << "Gli elementi del vettore di tipo int (visualizzazione sinistra verso detra) sono: "<< std::endl;
              vect.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi del vettore di tipo int (visualizzazione destra verso sinistra) sono: "<< std::endl;
              vect.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nel vettore: ";
              std::cin >> exis;
              if (vect.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Somma degli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare la somma degli elementi minori di esso: ";
              std::cin >> m;
              vect.FoldPreOrder (&FoldSommaMinN, &m, &somma);
              std::cout << "La somma degli interi minori di "<< m <<" è: " << somma << std::endl;

              //Funzione che raddoppia il valore degli elementi del vettore
              std::cout << std::endl << "Moltiplico gli elementi del vettore x2" << std::endl;
              vect.MapPreOrder (MapRaddoppia, nullptr);
              vect.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              break;
            }
            case 20: {
              std::cout << std::endl << "Il tipo di dato scelto per il vettore  è: float." << std::endl;
              uint n, indice;
              float exis, m, ins, prodotto=1;

              std::cout << std::endl << "Inserire il numero degli elementi del vettore: " ;
              std::cin >> n;
              lasd::Vector <float> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_real_distribution<float> distribution(1,100);

              for(ulong i = 0; i < n; ++i)
              {
                ins = distribution(generator);
                ins = ((float )((int)(ins * 1000.0f)))/1000.0f;
                vect[i] = ins;
              }

              //Visualizzazione dell'elemento iniziale
              std::cout << std::endl << "L'elemento iniziale del vettore è: " << vect.Front() << std::endl;
              //Visualizzazione dell'elemento finale
              std::cout << "L'elemento finale del vettore è: " << vect.Back() << std::endl;
              //Visualizzazione dell'elemento avente uno specifico indice
              std::cout << std::endl << "Quale indice del vettore desideri visualizzare?  (Da 0 ad " << n-1 <<") : ";
              std::cin >> indice;
              std::cout << "L'elemento " << indice << " del vettore è: " << vect[indice] << std::endl;

              //visualizzazione di tutti gli elementi del vettore tramite funzione map
              std::cout << std::endl << "Gli elementi del vettore di tipo float (visualizzazione sinistra verso detra) sono: "<< std::endl;
              vect.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi del vettore di tipo float (visualizzazione destra verso sinistra) sono: "<< std::endl;
              vect.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nel vettore:   ";
              std::cin >> exis;
              if (vect.Exists(exis)) {
                std::cout <<"L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Prodotto dei reali maggiori di N
              std::cout << std::endl << "Inserisci un reale per effettuare il prodotto degli elementi maggiori di esso: ";
              std::cin >> m;
              vect.FoldPreOrder (&FoldProdottoMaggN, &m, &prodotto);
              if (prodotto != 1) {
                std::cout << "Il prodotto dei numeri reale maggiori di "<< m <<" è: " << prodotto << std::endl;
              }
              else {
                std::cout << "Non esistono numeri reali maggiori di "<< m << std::endl;
              }

              //Funzione che effettua il quadrato degli elementi del vettore
              std::cout << std::endl << "Effettuo il quadrato degli elementi del vettore" << std::endl;
              vect.MapPreOrder (MapQuadrato, nullptr);
              vect.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              break;
            }
           case 30: {
              std::cout << std::endl << "Il tipo di dato scelto per il vettore  è: string." << std::endl;
              int n;
              uint indice, lung, m;
              std::string exis, conc="";

              std::cout << std::endl << "Inserire il numero degli elementi del vettore: " ;
              std::cin >> n;
              lasd::Vector <std::string> vect(n);

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,10);
              std::uniform_int_distribution<int> distr(97,122);

              for(ulong i = 0; i < n; ++i)
              {
                lung = distribution(generator);
                char * str = new char [lung];
                for(ulong j = 0; j < lung; ++j)  {
                  str[j] = distr(generator);
                }
                vect[i] = str;
              }

              //Visualizzazione dell'elemento iniziale
              std::cout << std::endl << "L'elemento iniziale del vettore è: " << vect.Front() << std::endl;
              //Visualizzazione dell'elemento finale
              std::cout << "L'elemento finale del vettore è: " << vect.Back() << std::endl;
              //Visualizzazione dell'elemento avente uno specifico indice
              std::cout << std::endl << "Quale indice del vettore desideri visualizzare?  (Da 0 ad " << n-1 <<") : ";
              std::cin >> indice;
              std::cout << "L'elemento " << indice << " del vettore è: " << vect[indice] << std::endl;

              //visualizzazione di tutti gli elementi del vettore tramite funzione map
              std::cout << std::endl << "Gli elementi del vettore di tipo string (visualizzazione sinistra verso detra) sono: "<< std::endl;
              vect.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              std::cout <<  std::endl <<"Gli elementi del vettore di tipo string (visualizzazione destra verso sinistra) sono: "<< std::endl;
              vect.MapPostOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nel vettore:   ";
              std::cin >> exis;
              if (vect.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nel vettore. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nel vettore. " << std::endl;
              }

              //Concatenazione di stringhe con lunghezza minore o uguale ad N
              std::cout << std::endl << "Inserisci un intero 'N' per effettuare la concatenazione delle stringhe con lunghezza <= N: ";
              std::cin >> m;
              vect.FoldPreOrder (&FoldConcat, &m, &conc);
              std::cout << "La stringa creata dalla concatenazione è:   ";
              std::cout << conc << std::endl;

              //Funzione che effettua l'uppercase degli elementi del vettore
              std::cout << std::endl << "Effettuo l'uppercase degli elementi del vettore" << std::endl;
              vect.MapPreOrder (MapUpCase, nullptr);
              vect.MapPreOrder (MapView<std::string>, nullptr);
              std::cout << std::endl;

              break;
            }

            case 40: {

              std::cout << "Terminazione del programma." << std::endl;
              return;

            }
            default:
              std::cout << "La scelta del tipo di dato non è corretta, riprova" << std::endl;
              break;
            }
          } while ((choiceData != 10) && (choiceData != 20) && (choiceData != 30));

      break;

      case 2:
        std::cout << std::endl <<"La struttura dati scelta è: lista." << std::endl;
        do {
          std::cout << std::endl << "Scelta del tipo di dato per la lista." << std::endl;
          std::cout << "Inserire 100 per utilizzare dati di tipo int" << std::endl;
          std::cout << "Inserire 200 per utilizzare dati di tipo float" << std::endl;
          std::cout << "Inserire 300 per utilizzare dati di tipo string" << std::endl;
          std::cout << "Inserire 400 per per terminare il programma:   ";

          std::cin >> choiceData;
          switch (choiceData) {
            case 100: {
              std::cout << std::endl << "Il tipo di dato scelto per la lista è: int." << std::endl;
              uint selezione, n, indice;
              int exis, m, somma=0;
              lasd::List<int> lista;

              std::cout << std::endl << "Inserire il numero degli elementi della lista: ";
              std::cin >> n;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,100);

              do {
                std::cout << std::endl << "Inserire 1 se si vuole inserire in testa." << std::endl;
                std::cout << "Inserire 2 se si vuole inserire in coda."<< std::endl;
                std::cout << "Inserire 3 per terminare il programma:    ";
                std::cin >> selezione ;

                if (selezione == 1) {
                  for (ulong i=0; i<n; ++i) {
                    lista.InsertAtFront (distribution(generator));
                  }
                } else if (selezione == 2) {
                    for (ulong i=0; i<n; ++i) {
                      lista.InsertAtBack (distribution(generator));
                    }
                } else if (selezione == 3) {
                    std::cout << "Terminazione del programma." << std::endl;
                    return;
                } else {
                      std::cout << "La scelta inserita non è corretta, ripetere!" << std::endl;
                  }
              } while (selezione != 1 && selezione != 2);

              //Visualizzazione dell'elemento iniziale
              std::cout << std::endl << "L'elemento iniziale della lista è: " << lista.Front() << std::endl;
              //Visualizzazione dell'elemento finale
              std::cout << "L'elemento finale della lista è: " << lista.Back() << std::endl;
              //Visualizzazione dell'elemento avente uno specifico indice
              std::cout << std::endl << "Quale elemento della lista desideri visualizzare? (Da 0 ad " << n-1 <<") : ";
              std::cin >> indice;
              std::cout << "L'elemento " << indice  << " della lista è: " << lista[indice] << std::endl;

              //visualizzazione di tutti gli elementi della lista tramite funzione map
              std::cout << std::endl << "Gli elementi della lista di tipo int (visualizzazione sinistra verso detra) sono: "<< std::endl;
              lista.MapPreOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              std::cout << std::endl << "Gli elementi della lista di tipo int (visualizzazione destra verso sinistra) sono: "<< std::endl;
              lista.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl << "Inserire un elemento per verificare se è presente nella lista: ";
              std::cin >> exis;
              if (lista.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nella lista. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nella lista. " << std::endl;
              }

              //Somma degli interi minori di N
              std::cout << std::endl << "Inserisci un intero per effettuare la somma degli elementi minori di esso: ";
              std::cin >> m;
              lista.FoldPreOrder (&FoldSommaMinN, &m, &somma);
              std::cout << std::endl << "La somma degli interi minori di "<< m <<" è: " << somma << std::endl;

              //Funzione che raddoppia il valore degli elementi della lista
              std::cout<< std::endl << "Moltiplico gli elementi della lista x2" << std::endl;
              lista.MapPreOrder (MapRaddoppia, nullptr);
              lista.MapPostOrder (MapView<int>, nullptr);
              std::cout << std::endl;

              break;
            }
            case 200: {
              std::cout << std::endl << "Il tipo di dato scelto per la lista  è: float." << std::endl;
              uint selezione, n, indice;
              float exis, m, ins, prodotto = 1;
              lasd::List<float> lista;

              std::cout << std::endl << "Inserire il numero degli elementi della lista: ";
              std::cin >> n;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_real_distribution<float> distribution(1,100);

              do {
                std::cout << std::endl << "Inserire 1 se si vuole inserire in testa."<< std::endl;
                std::cout << "Inserire 2 se si vuole inserire in coda."<< std::endl;
                std::cout << "Inserire 3 per terminare il programma:    ";
                std::cin >> selezione ;

                //Selezione tipo di inserimento
                if (selezione == 1) {
                  for (ulong i=0; i<n; ++i) {
                    ins = distribution(generator);
                    ins = ((float )((int)(ins * 1000.0f)))/1000.0f;
                    lista.InsertAtFront (ins);
                  }
                } else if (selezione == 2) {
                    for (ulong i=0; i<n; ++i) {
                      ins = distribution(generator);
                      ins = ((float )((int)(ins * 1000.0f)))/1000.0f;
                      lista.InsertAtBack (ins);
                    }
                  } else if (selezione == 3) {
                      std::cout << "Terminazione del programma." << std::endl;
                      return;
                  } else {
                    std::cout << "La scelta inserita non è corretta, ripetere!" << std::endl;
                  }
              } while (selezione != 1 && selezione != 2);

              //Visualizzazione dell'elemento iniziale
              std::cout << std::endl << "L'elemento iniziale della lista è: " << lista.Front() << std::endl;
              //Visualizzazione dell'elemento finale
              std::cout << "L'elemento finale della lista è: " << lista.Back() << std::endl;
              //Visualizzazione dell'elemento avente uno specifico indice
              std::cout << std::endl << "Quale elemento della lista desideri visualizzare?  (Da 0 ad " << n-1 <<") : ";
              std::cin >> indice;
              std::cout << "L'elemento " << indice << " della lista è: " << lista[indice] << std::endl;

              //visualizzazione di tutti gli elementi della lista tramite funzione map
              std::cout<< std::endl << "Gli elementi della lista di tipo float (visualizzazione sinistra verso detra) sono: "<< std::endl;
              lista.MapPreOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              std::cout<< std::endl << "Gli elementi della lista di tipo float (visualizzazione destra verso sinistra) sono: "<< std::endl;
              lista.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;

              //Test Funzione EXISTS
              std::cout << std::endl<< "Inserire un elemento per verificare se è presente nella lista:   ";
              std::cin >> exis;
              if (lista.Exists(exis)) {
                std::cout << "L'elemento " << exis << " è presente nella lista. " << std::endl;
              }
              else {
                std::cout << "L'elemento " << exis << " non è presente nella lista. " << std::endl;
              }

              //Prodotto dei reali maggiori di N
              std::cout<< std::endl << "Inserire un reale per effettuare il prodotto degli elementi maggiori di esso: ";
              std::cin >> m;
              lista.FoldPreOrder (&FoldProdottoMaggN, &m, &prodotto);
              if (prodotto != 1) {
                std::cout << "Il prodotto dei numeri reale maggiori di "<< m <<" è: " << prodotto << std::endl;
              }
              else {
                std::cout << "Non esistono numeri reali maggiori di "<< m << std::endl;
              }

              //Funzione che effettua il quadrato degli elementi della lista
              std::cout << std::endl << "Effettuo il quadrato degli elementi della lista" << std::endl;
              lista.MapPreOrder (MapQuadrato, nullptr);
              lista.MapPostOrder (MapView<float>, nullptr);
              std::cout << std::endl;


              break;
              }
              case 300: {
                std::cout << std::endl << "Il tipo di dato scelto per la lista  è: string." << std::endl;
                int n;
                uint indice, lung, selezione, m;
                std::string exis, conc="";

                std::cout << std::endl << "Inserire il numero degli elementi della lista: " ;
                std::cin >> n;
                lasd::List <std::string> lista;

                std::default_random_engine generator (std::random_device{}());
                std::uniform_int_distribution<int> distribution(1,10);
                std::uniform_int_distribution<int> distr(97,122);

                do {
                  std::cout<< std::endl << "Inserire 1 se si vuole inserire in testa."<< std::endl;
                  std::cout << "Inserire 2 se si vuole inserire in coda."<< std::endl;
                  std::cout << "Inserire 3 per terminare il programma:    ";
                  std::cin >> selezione ;

                  //Selezione tipo di inserimento
                  if (selezione == 1) {
                    for (ulong i=0; i<n; ++i) {
                      lung = distribution(generator);
                      char * str = new char [lung];
                      for(ulong j = 0; j < lung; ++j)  {
                        str[j] = distr(generator);
                      }
                      lista.InsertAtFront (str);
                    }
                    std::cout << std::endl;
                    } else if (selezione == 2) {
                        for (ulong i=0; i<n; ++i) {
                            lung = distribution(generator);
                            char * str = new char [lung];
                            for(ulong j = 0; j < lung; ++j)  {
                                str[j] = distr(generator);
                            }
                            lista.InsertAtFront (str);
                        }
                    } else if (selezione == 3) {
                        std::cout << "Terminazione del programma." << std::endl;
                        return;
                    } else {
                      std::cout << "La scelta inserita non è corretta, ripetere!" << std::endl;
                    }
                } while (selezione != 1 && selezione != 2);

                //Visualizzazione dell'elemento iniziale
                std::cout << std::endl << "L'elemento iniziale della lista è: " << lista.Front() << std::endl;
                //Visualizzazione dell'elemento finale
                std::cout << "L'elemento finale della lista è: " << lista.Back() << std::endl;
                //Visualizzazione dell'elemento avente uno specifico indice
                std::cout << std::endl << "Quale indice della lista desideri visualizzare?  (Da 0 ad " << n-1 <<") : ";
                std::cin >> indice;
                std::cout << "L'elemento " << indice << " della lista è: " << lista[indice] << std::endl;

                //visualizzazione di tutti gli elementi della lista tramite funzione map
                std::cout << std::endl << "Gli elementi della lista di tipo string (visualizzazione sinistra verso detra) sono: "<< std::endl;
                lista.MapPreOrder (MapView<std::string>, nullptr);
                std::cout << std::endl;

                std::cout << std::endl << "Gli elementi della lista di tipo string (visualizzazione destra verso sinistra) sono: "<< std::endl;
                lista.MapPostOrder (MapView<std::string>, nullptr);
                std::cout << std::endl;

                //Test Funzione EXISTS
                std::cout << std::endl << "Inserire una stringa per verificare se è presente nella lista: " ;
                std::cin >> exis;
                if (lista.Exists(exis)) {
                  std::cout << "L'elemento " << exis << " è presente nella lista. " << std::endl;
                }
                else {
                  std::cout << "L'elemento " << exis << " non è presente nella lista. " << std::endl;
                }
                std::cout << std::endl;

                //Concatenazione di stringhe con lunghezza minore o uguale ad N
                std::cout << "Inserire un intero 'N' per effettuare la concatenazione delle stringhe con lunghezza <= N: ";
                std::cin >> m;
                lista.FoldPreOrder (&FoldConcat, &m, &conc);
                if (conc != "") {
                  std::cout << "La stringa creata dalla concatenazione è:   " << conc << std::endl;
                } else {
                  std::cout << "Non esistono stringhe con lunghezza <=" << m << std::endl;
                }
                std::cout << std::endl;

                //Funzione che effettua l'uppercase degli elementi della lista
                std::cout << "Effettuo l'uppercase degli elementi della lista" << std::endl;
                lista.MapPreOrder (MapUpCase, nullptr);
                lista.MapPreOrder (MapView<std::string>, nullptr);
                std::cout << std::endl;

                break;
              }

              case 400: {

                std::cout << "Terminazione del programma." << std::endl;
                return;

              }

              default:
              std::cout << "La scelta del tipo di dato non è corretta, riprova" << std::endl;
              break;
            }
          } while ((choiceData != 100) && (choiceData != 200) && (choiceData != 300));

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
