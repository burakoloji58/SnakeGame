#include "HUCRE.h"


class Yilan :public Cizilebilir{

private:

    std::vector<Hucre> m_hucreler;

    float        m_alinanMesafe;

    HucreYon     m_ilkYon;

    Hucre        m_yem;

    void yemYenile();

    void yemKontrol();

    float        m_hucreBoyut;
    float        m_pencereGenislik;
    float        m_pencereYukseklik;

    bool         yilanSinirIcindeMi();
    bool         kendiniYediMi();

public:

    Yilan();

    void YilanEkle();

    void ciz(Pencere& pencere) override;

    void yilanHareket();

    void YonAta(HucreYon yenYon);

    void ayarla(float hucreBoyut, float pencreGenislik, float pencereYukseklik);




};

