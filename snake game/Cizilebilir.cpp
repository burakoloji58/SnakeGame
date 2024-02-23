#include "Cizilebilir.h"


void Cizilebilir::ciz(Pencere& pencre)
{

}

sf::Vector2f Cizilebilir::konumGetir()
{
    return m_konum;
}

void Cizilebilir::konumAta(const sf::Vector2f& konum)
{
    m_konum = konum;
}

Cizilebilir::Cizilebilir()
{
    m_cizilecekMi = true;
}
