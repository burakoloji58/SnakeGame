#ifndef UYGULAMA_H_
#define UYGULAMA_H_
#include "PENCERE.h"

class Uygulama{

private:

    void sahneGuncelle();
    void ekranaciz();
    void cerceveOlustur();

    Pencere     m_pencere;

    sf::Clock   m_saat;
    sf::Time    m_cerceveSuresi;
    sf::Time    m_gecenSure;


    void tusBasildi(sf::Keyboard::Key tus);
    void tusBirakildi(sf::Keyboard::Key tus);
    void mouseHareket(sf::Event::MouseMoveEvent mouse);
    void mouseBasildi(sf::Event::MouseButtonEvent fareOlayi);
    void mouseBirakildi(sf::Event::MouseButtonEvent fareOlayi);

public:

    Uygulama();

    void insaEt(unsigned int , unsigned int);

    void baslat(int fps=60);



};

#endif // UYGULAMA_H_

