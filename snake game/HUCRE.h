#include <SFML/Graphics.hpp>
#include "Cizilebilir.h"

enum class HucreYon{

    Sol,
    Sag,
    Yukari,
    Assagi

};

class Pencere;

class Hucre : public Cizilebilir
{

public:

    Hucre();

    Hucre       hucreUret();

    void        ciz(Pencere& pencere) override;

    void        yonAta(HucreYon yon);
    HucreYon    yonGetir();

    float       boyutGetir();
    void        boyutAta(float boyut);
    void        hizAta(float hiz);
    float       hizGetir();

    void        hareket();
    void        renkAta(sf::Color renk);


private:

    HucreYon             m_yon;
    sf::RectangleShape   m_sekil;
    float                m_boyut;
    float                m_hiz;

};
