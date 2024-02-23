#ifndef CIZILEBILIR_H_
#define CIZILEBILIR_H_

#include "UYGULAMA.h"
#include <SFML/Graphics.hpp>

class Pencere;
class Cizilebilir{

public:

    Cizilebilir();

    virtual void ciz(Pencere& pencre) = 0;

    sf::Vector2f konumGetir();

    void konumAta(const sf::Vector2f&);


protected:

    sf::Vector2f m_konum;

    bool m_cizilecekMi;

};


#endif // C

