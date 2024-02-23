#include "UYGULAMA.h"
#include <iostream>
#include "Yilan.h"
#include "Izgara.h"

Yilan       m_yilan;
Izgara      m_izgara;

Uygulama::Uygulama()
{

}

void Uygulama::insaEt(unsigned int genislik,unsigned int yukseklik)
{
    m_pencere.cerceveOlustur(genislik,yukseklik);
    m_izgara.ayarla(genislik,30);
    m_yilan.ayarla(30,genislik,yukseklik);

    m_pencere.MouseBasFonkEkle(std::bind(&Uygulama::mouseBasildi,this,std::placeholders::_1));
    m_pencere.MouseBirakFonkEkle(std::bind(&Uygulama::mouseBirakildi,this,std::placeholders::_1));
    m_pencere.MouseHareketFonkEkle(std::bind(&Uygulama::mouseHareket,this,std::placeholders::_1));
    m_pencere.TusaBasFonkEkle(std::bind(&Uygulama::tusBasildi,this,std::placeholders::_1));
    m_pencere.TusBirakFonkEkle(std::bind(&Uygulama::tusBirakildi,this,std::placeholders::_1));
}

void Uygulama::ekranaciz()
{
    m_pencere.temizle();
    m_yilan.ciz(m_pencere);
    m_izgara.ciz(m_pencere);
    m_pencere.goster();
}

void Uygulama::baslat(int fps)
{
    float cercFps = 1.0f/fps;

    m_cerceveSuresi = sf::seconds(cercFps);

    m_gecenSure = m_saat.restart();

    while(m_pencere.cerceveAcikMi())
    {
        m_pencere.olaylariIsle();


        m_gecenSure = m_saat.getElapsedTime();

        if(m_gecenSure >= m_cerceveSuresi)
        {
            cerceveOlustur();

            m_saat.restart();
            m_gecenSure -= m_cerceveSuresi;
        }
        else
        {
            sf::sleep(m_gecenSure - m_cerceveSuresi);
        }

    }

}

void Uygulama::tusBasildi(sf::Keyboard::Key tus)
{

        if(tus == sf::Keyboard::Left)
            m_yilan.YonAta(HucreYon::Sol);
        if(tus == sf::Keyboard::Right)
            m_yilan.YonAta(HucreYon::Sag);
        if(tus == sf::Keyboard::Up)
            m_yilan.YonAta(HucreYon::Yukari);
        if(tus == sf::Keyboard::Down)
            m_yilan.YonAta(HucreYon::Assagi);
        if(tus == sf::Keyboard::Space)
            m_yilan.YilanEkle();

}
void Uygulama::tusBirakildi(sf::Keyboard::Key tus)
{

}
void Uygulama::mouseBasildi(sf::Event::MouseButtonEvent fareOlayi)
{

}
void Uygulama::mouseBirakildi(sf::Event::MouseButtonEvent fareOlayi)
{

}
void Uygulama::mouseHareket(sf::Event::MouseMoveEvent mouse)
{

}

void Uygulama::sahneGuncelle()
{
    m_yilan.yilanHareket();

}
void Uygulama::cerceveOlustur()
{
    sahneGuncelle();
    ekranaciz();
}


