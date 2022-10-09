#include "zmytest/test.hpp"
#include "zlasdtest/test.hpp"
#include <iostream>


int main()
{
  ushort tes;

  do {
    std::cout << std::endl << "Scelta del test." << std::endl;
    std::cout << "Inserire 1 per utilizzare il test del prof. (zlasdtest)" << std::endl;
    std::cout << "Inserire 2 per utilizzare zmytest " << std::endl;
    std::cout << "Inserire 3 per terminare il programma:    ";
    std::cin >> tes;

    switch (tes) {
      case 1:
        std::cout << "Hai scelto il test del prof. (zlasdtest)" << std::endl;
        test();
      break;

      case 2:
        std::cout << "Hai scelto il test dello studente (zmytest)" << std::endl;
        libraryTest ();
      break;

      case 3:
        std::cout << "Terminazione del programma" << std::endl;
        return 0;

      default:
      std::cout << "La scelta inserita non è corretta, riprova" << std::endl;
      }
    } while (tes != 1 && tes != 2);

  return 0;
}
