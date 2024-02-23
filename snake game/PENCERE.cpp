#include "PENCERE.h"


void Pencere::cerceveOlustur(unsigned int genislik , unsigned int yukseklik , const sf::String& baslik)
{
    m_pencere.create(sf::VideoMode(genislik,yukseklik),baslik);
}

bool Pencere::cerceveAcikMi()
{
     return m_pencere.isOpen();
}

void Pencere::temizle()
{
    m_pencere.clear();
}

void Pencere::goster()
{
    m_pencere.display();
}

void Pencere::olaylariIsle()
{
    sf::Event event;

    while(m_pencere.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_pencere.close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            for(auto secilen:m_tusaBasFonklari)
                secilen(event.key.code);
        }
        if(event.type == sf::Event::KeyReleased)
        {
            for(auto secilen:m_tusBirakFonklari)
                secilen(event.key.code);
        }
        if(event.type == sf::Event::MouseMoved)
        {
            for(auto secilen:m_fareHareketFonklari)
                secilen(event.mouseMove);
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            for(auto secilen:m_fareBasFonklari)
                secilen(event.mouseButton);
        }
        if(event.type == sf::Event::MouseButtonReleased)
        {
            for(auto secilen : m_fareBirakFonklari)
                secilen(event.mouseButton);
        }

    }

}

void Pencere::sekilciz(sf::Drawable& sekil)
{
    m_pencere.draw(sekil);
}

void Pencere::TusaBasFonkEkle(klavyeFonksiyonu yeniFonksiyon)
{

    m_tusaBasFonklari.push_back(yeniFonksiyon);
}

void Pencere::TusBirakFonkEkle(klavyeFonksiyonu yeniFonksiyon)
{
    m_tusBirakFonklari.push_back(yeniFonksiyon);
}

void Pencere::MouseHareketFonkEkle(fareHareketFonksiyonu yeniFonksiyon)
{
    m_fareHareketFonklari.push_back(yeniFonksiyon);
}

void Pencere::MouseBasFonkEkle(fareOlayFonksiyonu yeniFonksiyon)
{
    m_fareBasFonklari.push_back(yeniFonksiyon);
}

void Pencere::MouseBirakFonkEkle(fareOlayFonksiyonu yeniFonksiyon)
{
    m_fareBirakFonklari.push_back(yeniFonksiyon);
}
