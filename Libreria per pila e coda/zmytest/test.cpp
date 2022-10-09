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


/* ************************************************************************** */

void libraryTest () {

  ushort choiceStruct;

  do {
    std::cout << std::endl << "Scelta del tipo di struttura." << std::endl;
    std::cout << "Inserire 1 per utilizzare una struttura dati di tipo pila" << std::endl;
    std::cout << "Inserire 2 per utilizzare una struttura dati di tipo coda" << std::endl;
    std::cout << "Inserire 3 per terminare il programma:   ";
    std::cin >> choiceStruct;

    switch (choiceStruct) {
      case 1: {
        std::cout << std::endl << "Il tipo di struttura dati scelta è: pila." << std::endl;
        ushort choiceImplem;

        do {
          std::cout << std::endl << "Scelta dell'implementazione della pila." << std::endl;
          std::cout << "Inserire 10 per implementare la pila attraverso un vettore" << std::endl;
          std::cout << "Inserire 20 per implementare la pila attraverso una lista" << std::endl;
          std::cout << "Inserire 30 per terminare il programma:   ";
          std::cin >> choiceImplem;

          switch (choiceImplem) {
            case 10: {
              ulong n;
              ushort op;

              std::cout << std::endl << "L'implementazione scelta della pila è mediante vettore." << std::endl;

              std::cout << std::endl << "Inserire il numero degli elementi del vettore: ";
              std::cin >> n;
              lasd::StackVec<int> stackvec;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,100);

              for(ulong i = 0; i < n; ++i)
              {
                stackvec.Push (distribution(generator));
              }
              std::cout << "Sono stati inseriti " << n << " elementi random nella struttura."  << std::endl;

              do {
                std::cout << std::endl << "Scelta delle operazioni da effettuare." << std::endl;
                std::cout << "Inserire 100 per effettuare un inserimento." << std::endl;
                std::cout << "Inserire 200 per rimuovere un elemento." << std::endl;
                std::cout << "Inserire 300 per effettuare una rimozione con lettura." << std::endl;
                std::cout << "Inserire 400 per effettuare una lettura non distruttiva." << std::endl;
                std::cout << "Inserire 500 per effettuare il test di vuotezza." << std::endl;
                std::cout << "Inserire 600 per la lettura della dimensione." << std::endl;
                std::cout << "Inserire 700 per effettuare lo svuotamento della struttura." << std::endl;
                std::cout << "Inserire 800 per terminare il programma:   ";
                std::cin >> op;

                switch (op) {
                  case 100:
                    int elem;
                    std::cout << std::endl <<  "Hai scelto di effettuare un inserimento." << std::endl;
                    std::cout << "Inserisci un intero:   ";
                    std::cin >> elem;
                    stackvec.Push(elem);
                    std::cout << "L'elemento è stato inserito." << std::endl;
                  break;

                  case 200:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione." << std::endl;
                    stackvec.Pop();
                    std::cout << "L'elemento è stato rimosso." << std::endl;
                  break;

                  case 300:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione con lettura." << std::endl;
                    std::cout << "L'elemento rimosso è:   " << stackvec.TopNPop() << std::endl ;
                  break;

                  case 400:
                    std::cout << std::endl << "Hai scelto di effettuare una lettura non distruttiva." << std::endl;
                    std::cout << "L'intero è:   " << stackvec.Top() << std::endl ;
                  break;

                  case 500:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare il test di vuotezza." << std::endl;
                    if (stackvec.Empty()){
                      std::cout << "La struttura è vuota!" << std::endl;
                    }
                    else {
                      std::cout << "La struttura non è vuota!" << std::endl;
                    }
                  break;

                  case 600:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare la lettura della dimensione." << std::endl;
                    std::cout << "Dimensione:   " << stackvec.Size()<< std::endl ;
                  break;

                  case 700:
                    std::cout << std::endl << "Hai scelto di effettuare lo svuotamento della struttura." << std::endl;
                    stackvec.Clear();
                    std::cout << "Struttura svuotata!" << std::endl;
                  break;

                  case 800:
                    std::cout << "Terminazione del programma." << std::endl;
                  break;

                  default:
                  std::cout << "La scelta inserita non è corretta, riprova." << std::endl;
                  }
                } while (op != 800);

              break;
            }

            case 20: {
              ulong n;
              ushort op;
              lasd::StackLst<int> stacklista;

              std::cout << std::endl << "L'implementazione scelta della pila è mediante lista." << std::endl;

              std::cout << std::endl << "Inserire il numero degli elementi della lista: ";
              std::cin >> n;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,100);

              for (ulong i=0; i<n; ++i) {
                stacklista.Push (distribution(generator));
              }
              std::cout << "Sono stati inseriti " << n << " elementi random nella struttura."  << std::endl;

              do {
                std::cout << std::endl << "Scelta delle operazioni da effettuare." << std::endl;
                std::cout << "Inserire 100 per effettuare un inserimento." << std::endl;
                std::cout << "Inserire 200 per rimuovere un elemento." << std::endl;
                std::cout << "Inserire 300 per effettuare una rimozione con lettura." << std::endl;
                std::cout << "Inserire 400 per effettuare una lettura non distruttiva." << std::endl;
                std::cout << "Inserire 500 per effettuare il test di vuotezza." << std::endl;
                std::cout << "Inserire 600 per la lettura della dimensione." << std::endl;
                std::cout << "Inserire 700 per effettuare lo svuotamento della struttura." << std::endl;
                std::cout << "Inserire 800 per terminare il programma:   ";
                std::cin >> op;

                switch (op) {
                  case 100:
                    int elem;
                    std::cout << std::endl <<  "Hai scelto di effettuare un inserimento." << std::endl;
                    std::cout << "Inserisci un intero:   ";
                    std::cin >> elem;
                    stacklista.Push(elem);
                    std::cout << "L'elemento è stato inserito." << std::endl;
                  break;

                  case 200:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione." << std::endl;
                    stacklista.Pop();
                    std::cout << "L'elemento è stato rimosso." << std::endl;
                  break;

                  case 300:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione con lettura." << std::endl;
                    std::cout << "L'elemento rimosso è:   " << stacklista.TopNPop() << std::endl ;
                  break;

                  case 400:
                    std::cout << std::endl << "Hai scelto di effettuare una lettura non distruttiva." << std::endl;
                    std::cout << "L'intero è:   " << stacklista.Top() << std::endl ;
                  break;

                  case 500:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare il test di vuotezza." << std::endl;
                    if (stacklista.Empty()){
                      std::cout << "La struttura è vuota!" << std::endl;
                    }
                    else {
                      std::cout << "La struttura non è vuota!" << std::endl;
                    }
                  break;

                  case 600:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare la lettura della dimensione." << std::endl;
                    std::cout << "Dimensione:   " << stacklista.Size()<< std::endl ;
                  break;

                  case 700:
                    std::cout << std::endl << "Hai scelto di effettuare lo svuotamento della struttura." << std::endl;
                    stacklista.Clear();
                    std::cout << "Struttura svuotata!" << std::endl;
                  break;

                  case 800:
                    std::cout << "Terminazione del programma." << std::endl;
                  break;

                  default:
                  std::cout << "La scelta inserita non è corretta, riprova." << std::endl;
                  }
                } while (op != 800);

              break;
            }

           case 30: {
             std::cout << "Terminazione del programma." << std::endl;
             return;

              break;
            }

            default:
              std::cout << "La scelta inserita non è corretta, riprova" << std::endl;
              break;
            }
          } while ((choiceImplem != 10) && (choiceImplem != 20));

          break;
        }

      case 2: {
        std::cout << std::endl << "Il tipo di struttura dati scelta è: coda." << std::endl;
        ushort choiceImplem;

        do {
          std::cout << std::endl << "Scelta dell'implementazione della coda." << std::endl;
          std::cout << "Inserire 10 per implementare la coda attraverso un vettore" << std::endl;
          std::cout << "Inserire 20 per implementare la coda attraverso una lista" << std::endl;
          std::cout << "Inserire 30 per terminare il programma:   ";
          std::cin >> choiceImplem;

          switch (choiceImplem) {
            case 10: {
              ulong n;
              ushort op;

              std::cout << std::endl << "L'implementazione scelta della coda è mediante vettore." << std::endl;

              std::cout << std::endl << "Inserire il numero degli elementi del vettore: ";
              std::cin >> n;
              lasd::QueueVec<int> queuevec;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,100);

              for(ulong i = 0; i < n; ++i)
              {
                queuevec.Enqueue (distribution(generator));
              }
              std::cout << "Sono stati inseriti " << n << " elementi random nella struttura."  << std::endl;

              do {
                std::cout << std::endl << "Scelta delle operazioni da effettuare." << std::endl;
                std::cout << "Inserire 100 per effettuare un inserimento." << std::endl;
                std::cout << "Inserire 200 per rimuovere un elemento." << std::endl;
                std::cout << "Inserire 300 per effettuare una rimozione con lettura." << std::endl;
                std::cout << "Inserire 400 per effettuare una lettura non distruttiva." << std::endl;
                std::cout << "Inserire 500 per effettuare il test di vuotezza." << std::endl;
                std::cout << "Inserire 600 per la lettura della dimensione." << std::endl;
                std::cout << "Inserire 700 per effettuare lo svuotamento della struttura." << std::endl;
                std::cout << "Inserire 800 per terminare il programma:   ";
                std::cin >> op;

                switch (op) {
                  case 100:
                    int elem;
                    std::cout << std::endl <<  "Hai scelto di effettuare un inserimento." << std::endl;
                    std::cout << "Inserisci un intero:   ";
                    std::cin >> elem;
                    queuevec.Enqueue(elem);
                    std::cout << "L'elemento è stato inserito." << std::endl;
                  break;

                  case 200:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione." << std::endl;
                    queuevec.Dequeue();
                    std::cout << "L'elemento è stato rimosso." << std::endl;
                  break;

                  case 300:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione con lettura." << std::endl;
                    std::cout << "L'elemento rimosso è:   " << queuevec.HeadNDequeue()<< std::endl ;
                  break;

                  case 400:
                    std::cout << std::endl << "Hai scelto di effettuare una lettura non distruttiva." << std::endl;
                    std::cout << "L'intero è:   " << queuevec.Head() << std::endl ;
                  break;

                  case 500:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare il test di vuotezza." << std::endl;
                    if (queuevec.Empty()){
                      std::cout << "La struttura è vuota!" << std::endl;
                    }
                    else {
                      std::cout << "La struttura non è vuota!" << std::endl;
                    }
                  break;

                  case 600:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare la lettura della dimensione." << std::endl;
                    std::cout << "Dimensione:   " << queuevec.Size()<< std::endl ;
                  break;

                  case 700:
                    std::cout << std::endl << "Hai scelto di effettuare lo svuotamento della struttura." << std::endl;
                    queuevec.Clear();
                    std::cout << "Struttura svuotata!" << std::endl;
                  break;

                  case 800:
                    std::cout << "Terminazione del programma." << std::endl;
                  break;

                  default:
                  std::cout << "La scelta inserita non è corretta, riprova." << std::endl;
                  }
                } while (op != 800);

              break;
            }

            case 20: {
              ulong n;
              ushort op;
              lasd::QueueLst<int> queuelista;

              std::cout << std::endl << "L'implementazione scelta della coda è mediante lista." << std::endl;

              std::cout << std::endl << "Inserire il numero degli elementi della lista: ";
              std::cin >> n;

              std::default_random_engine generator (std::random_device{}());
              std::uniform_int_distribution<int> distribution(1,100);

              for (ulong i=0; i<n; ++i) {
                queuelista.Enqueue (distribution(generator));
              }
              std::cout << "Sono stati inseriti " << n << " elementi random nella struttura."  << std::endl;

              do {
                std::cout << std::endl << "Scelta delle operazioni da effettuare." << std::endl;
                std::cout << "Inserire 100 per effettuare un inserimento." << std::endl;
                std::cout << "Inserire 200 per rimuovere un elemento." << std::endl;
                std::cout << "Inserire 300 per effettuare una rimozione con lettura." << std::endl;
                std::cout << "Inserire 400 per effettuare una lettura non distruttiva." << std::endl;
                std::cout << "Inserire 500 per effettuare il test di vuotezza." << std::endl;
                std::cout << "Inserire 600 per la lettura della dimensione." << std::endl;
                std::cout << "Inserire 700 per effettuare lo svuotamento della struttura." << std::endl;
                std::cout << "Inserire 800 per terminare il programma:   ";
                std::cin >> op;

                switch (op) {
                  case 100:
                    int elem;
                    std::cout << std::endl <<  "Hai scelto di effettuare un inserimento." << std::endl;
                    std::cout << "Inserisci un intero:   ";
                    std::cin >> elem;
                    queuelista.Enqueue(elem);
                    std::cout << "L'elemento è stato inserito." << std::endl;
                    break;

                  case 200:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione." << std::endl;
                    queuelista.Dequeue();
                    std::cout << "L'elemento è stato rimosso." << std::endl;
                    break;

                  case 300:
                    std::cout << std::endl <<  "Hai scelto di effettuare una rimozione con lettura." << std::endl;
                    std::cout << "L'elemento rimosso è:   " << queuelista.HeadNDequeue()<< std::endl ;
                    break;

                  case 400:
                    std::cout << std::endl << "Hai scelto di effettuare una lettura non distruttiva." << std::endl;
                    std::cout << "L'intero è:   " << queuelista.Head() << std::endl ;
                    break;

                  case 500:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare il test di vuotezza." << std::endl;
                    if (queuelista.Empty()){
                      std::cout << "La struttura è vuota!" << std::endl;
                    }
                    else {
                      std::cout << "La struttura non è vuota!" << std::endl;
                    }
                    break;

                  case 600:
                    std::cout << std::endl << "Hai scelto di effettuare effettuare la lettura della dimensione." << std::endl;
                    std::cout << "Dimensione:   " << queuelista.Size()<< std::endl ;
                    break;

                  case 700:
                    std::cout << std::endl << "Hai scelto di effettuare lo svuotamento della struttura." << std::endl;
                    queuelista.Clear();
                    std::cout << "Struttura svuotata!" << std::endl;
                    break;

                  case 800:
                    std::cout << "Terminazione del programma." << std::endl;
                    break;

                  default:
                    std::cout << "La scelta inserita non è corretta, riprova." << std::endl;
                  }
                } while (op != 800);

                break;
            }

           case 30: {
             std::cout << "Terminazione del programma." << std::endl;
             return;

            }

            default:
              std::cout << "La scelta inserita non è corretta, riprova" << std::endl;
              break;
            }
          } while ((choiceImplem != 10) && (choiceImplem != 20));

      break;
      }

      case 3: {
        std::cout << "Terminazione del programma." << std::endl;
        return;

      break;
      }

      default:
        std::cout << "La scelta inserita non è corretta, riprova" << std::endl;
        break;
      }

    } while ((choiceStruct != 1) && (choiceStruct != 2));
}
