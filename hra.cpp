#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int hrac_zivoty;
    int hrac_maximalni_pocet_zivotu;
    int cena_za_leceni_ve_vesnici1;
    int cena_za_leceni_ve_vesnici2;
    int cena_za_dovednosti_ve_vesnici1;
    int cena_za_dovednosti_ve_vesnici2;
    int cena_za_vylepseni_utoku_ve_vesnici1;
    int cena_za_vylepseni_utoku_ve_vesnici2;
    int cena_za_vylepseni_energie_ve_vesnici1;
    int cena_za_vylepseni_energie_ve_vesnici2;
    int pocet_zlata;
    int odmena_zlato;
    int monstrum_zivoty;
    int mini_boss_zivoty;
    int boss_zivoty;
    int pocet_nepratel_v_suboji;
    int vyber_classy;
    int zacatek_1;
    char dalsi;

    cout << "===VITEJ VE HRE!===" << endl;
    cout << "Tvym ukolem je prezit proti bossum a monstrum." << endl;
    cout << "\nCo vsechno ve hre muzes najit: " << endl;
    cout << "1) Monstra - budes proti nim muset bojovat, aby jsi dostal zkusenosti." << endl;
    cout << "2) Vesnice - zde si budes moc kupovat spoustu potrebnych veci a taky to slouzi jako takove tvoje 'bezpecne' misto." << endl;
    cout << "\nCo muzes delat ve vesnici: " << endl;
    cout << "1) doplnit si zivoty." << endl;
    cout << "2) zvysit svuj maximalni pocet zivotu." << endl;
    cout << "3) vylepsit si svoje schopnosti nebo utok." << endl;
    cout << "\nJak funguji souboje: " << endl;
    cout << "1) pokud budes bojovat proti monstrum, jsi na tahu prvni." << endl;
    cout << "2) pokud budes bojovat proti mini-bossum nebo proti hlavnimu bossu, je na tahu prvni vzdycky on." << endl;
    cout << "Takze si vzdycky dobre rozmysli, co chces udelat, protoze jakmile ztratis vsechny zivoty HRA KONCI. " << endl;
    cout << "\nTvuj hlavni cil je: PORAZIT HLAVNIHO BOSSE." << endl;

    do{
    cout << "Zmacni 1 pro pokracovani: ";
    cin >> zacatek_1;

    if (zacatek_1 != 1)
        cout << "Spatna volba, zkus to znova." << endl;
    }while (zacatek_1 != 1);

    cout << "\nNa zacatku hry si vyber clasu: " << endl;
    cout << "1) Paladin:" << endl;
    cout << "   - max. pocet zivotu: " << endl;
    cout << "   - aktualni zivoty: " << endl;
    cout << "   - max. energie: " << endl;
    cout << "   - aktualni energie: " << endl;
    cout << "   - pocet zlatych minci: " << endl;
    cout << "   - level: " << endl;
    cout << "   - zkusenosti: " << endl;
    cout << "   - utok: " << endl;
    cout << "   - schopnosti: " << endl;
    cout << "Pro dalsi classu zmacni 'd': ";
    cin >> dalsi;

    if (dalsi == 'd'){
    cout << "2) Lovec:" << endl;
    cout << "   - max. pocet zivotu: " << endl;
    cout << "   - aktualni zivoty: " << endl;
    cout << "   - max. energie: " << endl;
    cout << "   - aktualni energie: " << endl;
    cout << "   - pocet zlatych minci: " << endl;
    cout << "   - level: " << endl;
    cout << "   - zkusenosti: " << endl;
    cout << "   - utok: " << endl;
    cout << "   - schopnosti: " << endl;
    cout << "Pro dalsi classu zmacni 'd': ";
    cin >> dalsi;
    }
    
    if (dalsi == 'd'){
    cout << "3) Mag:" << endl;
    cout << "   - max. pocet zivotu: " << endl;
    cout << "   - aktualni zivoty: " << endl;
    cout << "   - max. energie: " << endl;
    cout << "   - aktualni energie: " << endl;
    cout << "   - pocet zlatych minci: " << endl;
    cout << "   - level: " << endl;
    cout << "   - zkusenosti: " << endl;
    cout << "   - utok: " << endl;
    cout << "   - schopnosti: " << endl;
    cout << "Pro dalsi classu zmacni 'd': ";
    cin >> dalsi;
    }

    if (dalsi == 'd'){
    cout << "4) Warlock:" << endl;
    cout << "   - max. pocet zivotu: " << endl;
    cout << "   - aktualni zivoty: " << endl;
    cout << "   - max. energie: " << endl;
    cout << "   - aktualni energie: " << endl;
    cout << "   - pocet zlatych minci: " << endl;
    cout << "   - level: " << endl;
    cout << "   - zkusenosti: " << endl;
    cout << "   - utok: " << endl;
    cout << "   - schopnosti: " << endl;
    }
    
    do{
    cout << "Napis svuj vyber: ";
    cin >> vyber_classy;
        if (vyber_classy == 1)
            cout << "Vyborne! Vybral sis Paladina.";
        else if (vyber_classy == 2)
            cout << "Vyborne! Vybral sis Lovce.";
        else if (vyber_classy == 3)
            cout << "Vyborne! Vybral sis Maga.";
        else if (vyber_classy == 4)
            cout << "Vyborne! Vybral sis Warlocka.";
        else
            cout << "Spatna volba, vyber si znova." << endl;
    }while(vyber_classy < 1 || vyber_classy > 4);

    }
