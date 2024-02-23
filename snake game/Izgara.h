#include "Cizilebilir.h"

class Izgara : public Cizilebilir
{
public:
    Izgara();
    void ayarla(float uzunluk, float aralik);

    virtual void ciz(Pencere& pencere) override;

private:

    sf::RectangleShape m_yatayCizgi;
    sf::RectangleShape m_dikeyCizgi;

    float m_uzunluk;
    float m_aralik;

    int m_cizgiSayisi;


};
