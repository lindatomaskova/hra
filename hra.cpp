#include <iostream>
#include <ctime>
using namespace std;

void souboj(int &hrac_zivoty, int &hrac_max_zivoty, int hrac_utok){
    int boss_zivoty = 30;
    bool mraziva_past = false;
    bool hrac_zmrzne = false;
    bool hadi_past = false;
    bool hrac_usknuti = false;
    bool mlsna_past = false;

    cout << "=== SOUBOJ S BOSSEM - Mystifex ===";

    while (hrac_zivoty > 0 && boss_zivoty > 0){
        cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_max_zivoty << endl;
        cout << "Mystifexovo HP je: ???" << endl;

        cout << "Ted je na tahu Mystifex!" << endl;

        int past = rand() % 3;
        if (past == 0){
            cout << "Mystifex poklada mrazivou past!" << endl;
            mraziva_past = true;
        }else if (past == 1){
            cout << "Mystifex poklada hadi past!" << endl;
            hadi_past = true;
        }else{
            cout << "Mystifex poklada mlsnou past!" << endl;
            mlsna_past = true;
        }
        int bonus;
        int nahoda = rand() % 4;
        if (nahoda == 0)
            bonus = 2;
        else if (nahoda == 1)
            bonus = 4;
        else if (nahoda == 2)
            bonus = 6;
        else
            bonus = 1;

        int damage = 5 + bonus;
        hrac_zivoty -= damage;

        cout << "Mystifex utoci za " << damage << " damage" << endl;
        if (hrac_zivoty <= 0) break;

        cout << "Ted jsi na tahu ty! " << endl;

        if (hrac_zmrzne){
            cout << "Jsi zmrazen. Tvuj tah se rusi." << endl;
            hrac_zmrzne = false;
        }if (mlsna_past){
            int volba;
            cout << "Chces snist dobrutky? (1 ano / 0 ne): ";
            cin >> volba;

            if (volba == 1){
                hrac_zivoty += 10;
                hrac_max_zivoty -= 10;

                if (hrac_zivoty > hrac_max_zivoty)
                    hrac_zivoty = hrac_max_zivoty;

                cout << "Snedl jsi dobrutky a diky tomu ziskas 10 HP ale mas -10 max HP." << endl;
                mlsna_past = false;
            }else{
                cout << "Past nevyuzivas, ale Mystifex ziskava 10 HP." << endl;
                boss_zivoty += 10;
            }
        }
    }if (hadi_past){
        if (rand() % 2 == 0){
            cout << "Byl jsi ustknut hadem!" << endl;
            hrac_usknuti = true;
            hadi_past = false;
        }
    }



}
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
