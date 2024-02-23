#include "Yilan.h"


Yilan::Yilan()
{
    m_alinanMesafe = 0.0f;
    m_ilkYon = HucreYon::Sag;

}

void Yilan::ciz(Pencere& pencere)
{
    m_yem.ciz(pencere);
    for(auto& siradaki: m_hucreler)
    {
        siradaki.ciz(pencere);
    }
}

void Yilan::YilanEkle()
{
    if(m_hucreler.size())
    {
        Hucre YeniHucre = m_hucreler.back().hucreUret();

        YeniHucre.boyutAta(m_hucreBoyut);

        YeniHucre.renkAta(sf::Color::Red);

        m_hucreler.push_back(YeniHucre);
    }
    else
    {
        m_hucreler.push_back(Hucre());
    }

}

void Yilan::yilanHareket()
{
    if(!yilanSinirIcindeMi())
        return;
    if(kendiniYediMi())
        return;

    for(auto& siradaki: m_hucreler)
    {
        siradaki.hareket();
    }

    m_alinanMesafe += m_hucreler[0].hizGetir();
    if(m_alinanMesafe == m_hucreler[0].boyutGetir())
    {
        yemKontrol();
        for(int i= m_hucreler.size()-1 ; i>0 ; i--)
        {
            m_hucreler[i].yonAta(m_hucreler[i-1].yonGetir());
        }
        m_hucreler[0].yonAta(m_ilkYon);
        m_alinanMesafe = 0.0f;
    }

}

void Yilan::YonAta(HucreYon yenYon)
{
    if(yenYon == HucreYon::Sol && m_hucreler[0].yonGetir() == HucreYon::Sag) return;
    if(yenYon == HucreYon::Sag && m_hucreler[0].yonGetir() == HucreYon::Sol) return;
    if(yenYon == HucreYon::Yukari && m_hucreler[0].yonGetir() == HucreYon::Assagi) return;
    if(yenYon == HucreYon::Assagi && m_hucreler[0].yonGetir() == HucreYon::Yukari) return;

    m_ilkYon = yenYon;
}

void Yilan::yemYenile()
{
    int sutunSayisi = m_pencereYukseklik /    m_hucreBoyut;
    int satirSayisi = m_pencereGenislik /     m_hucreBoyut;

    float x = rand() %sutunSayisi * m_hucreBoyut;
    float y = rand() %satirSayisi * m_hucreBoyut;

    m_yem.konumAta(sf::Vector2f (x,y));
    m_yem.boyutAta(m_hucreBoyut);
    m_yem.renkAta(sf::Color::Blue);
}

void Yilan::ayarla(float hucreBoyut, float pencreGenislik , float pencereYukseklik)
{
    m_hucreBoyut      = hucreBoyut;
    m_pencereGenislik  = pencreGenislik;
    m_pencereYukseklik = pencereYukseklik;

    yemYenile();

    YilanEkle();
    YilanEkle();
    YilanEkle();
    YilanEkle();


}

void Yilan::yemKontrol()
{
    if(m_hucreler[0].konumGetir() == m_yem.konumGetir())
    {
        yemYenile();
        YilanEkle();
    }

    bool carpismaOlduMu;

    do
    {
        carpismaOlduMu = false;

        for(auto& siradaki : m_hucreler)
        {
            if(siradaki.konumGetir() == m_yem.konumGetir())
            {
                yemYenile();
                carpismaOlduMu = true;
                break;
            }
        }

    }while(carpismaOlduMu);

}

bool Yilan::yilanSinirIcindeMi()
{
    if(m_hucreler[0].konumGetir().x < 0 ||
       m_hucreler[0].konumGetir().x + m_hucreBoyut > m_pencereGenislik ||
       m_hucreler[0].konumGetir().y < 0 ||
       m_hucreler[0].konumGetir().y + m_hucreBoyut > m_pencereYukseklik) return false;

    return true;
}

bool Yilan::kendiniYediMi()
{
    int hucreSayisi = m_hucreler.size();

    for(int i = 2; i < hucreSayisi ; i++)
    {
        if(m_hucreler[0].konumGetir() == m_hucreler[i].konumGetir())
            return true;
    }

    return false;
}


