#include <vector>
#include "PENCERE.h"
#include <functional>
#include <SFML/Graphics.hpp>

typedef std::function<void(sf::Keyboard::Key)>                      klavyeFonksiyonu;
typedef std::vector<klavyeFonksiyonu>                               klavyeFonksiyonlari;

typedef std::function<void(sf::Event::MouseMoveEvent)>              fareHareketFonksiyonu;
typedef std::vector<fareHareketFonksiyonu>                          fareHareketFonksiyonlari;

typedef std::function<void(sf::Event::MouseButtonEvent)>            fareOlayFonksiyonu;
typedef std::vector<fareOlayFonksiyonu>                             fareOlayFonksiyonlari;

