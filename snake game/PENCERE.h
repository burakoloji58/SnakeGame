#ifndef _PENCERE_H_
#define _PENCERE_H_
#include <string>
#include "FONKSIYONTURLERI.h"
#include <functional>
#include <SFML/Graphics.hpp>


class Pencere{

private:

    sf::RenderWindow                    m_pencere;

    klavyeFonksiyonlari                 m_tusaBasFonklari;
    klavyeFonksiyonlari                 m_tusBirakFonklari;

    fareHareketFonksiyonlari            m_fareHareketFonklari;

    fareOlayFonksiyonlari               m_fareBasFonklari;
    fareOlayFonksiyonlari               m_fareBirakFonklari;


public:

    void cerceveOlustur(unsigned int , unsigned int,const sf::String& baslik ="SFML");

    void olaylariIsle();

    bool cerceveAcikMi();

    void temizle();

    void goster();

    void sekilciz(sf::Drawable&);

    void TusaBasFonkEkle(klavyeFonksiyonu);

    void TusBirakFonkEkle(klavyeFonksiyonu);

    void MouseHareketFonkEkle(fareHareketFonksiyonu);

    void MouseBasFonkEkle(fareOlayFonksiyonu);

    void MouseBirakFonkEkle(fareOlayFonksiyonu);

};


#endif // _PENCERE_H_
