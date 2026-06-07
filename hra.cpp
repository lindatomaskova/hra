#include <iostream>
#include <ctime>
using namespace std;

void souboj(int &hrac_zivoty, int &hrac_max_zivoty, int hrac_utok){
    int boss_zivoty = 40;
    bool mraziva_past = false;
    bool hadi_past = false;
    bool hrac_usknuti = false;
    bool mlsna_past = false;

    cout << "=== SOUBOJ S BOSSEM - Mystifex ===" << endl;

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
        if (hrac_zivoty <= 0){
            cout << "Nemas zivoty, prohral jsi." << endl;
            break;
        }
        cout << "Ted jsi na tahu ty! " << endl;
        int utok_hrace = hrac_utok;

        if (mraziva_past){
            cout << "Jsi v mrazive pasti a zmrzl jsi." << endl;
            mraziva_past = false;
            cout << "Tvuj utok se zrusi." << endl;
            continue;
        }else if (mlsna_past){
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
                mlsna_past = false;
            }
        }else if (hadi_past){
            if (rand() % 2 == 0){
                cout << "Byl jsi ustknut hadem!" << endl;
                hrac_usknuti = true;
                hadi_past = false;
            }else
                cout << "Had te minul." << endl;
        }if (hrac_usknuti){
            cout << "Byl jsi usknut hadem a tak mas utok jenom 1." << endl;
            utok_hrace = 1;
            hrac_usknuti = false;
        }
        cout << "Utocis za " << utok_hrace << " HP" << endl;
        boss_zivoty -= utok_hrace;

        if (boss_zivoty <= 0){
            cout << "Porazil jsi bosse Mystifexe!" << endl;
            break;
        }
    }



}
void vesnice (int &hrac_zivoty, int &hrac_energie, int &hrac_utok, int &hrac_zlato, int &hrac_max_zivoty, int &hrac_max_energie){
    int volba;
    do{
        cout << "===VESNICE===" << endl;
        cout << "Toto jsou tvoje statistiky: " << endl;
        cout << "Tvoje HP je: " << hrac_zivoty << endl;
        cout << "Tvoje energie je: " << hrac_energie << endl;
        cout << "Tvuj utok je: " << hrac_utok << endl;
        cout << "Pocet zlata: " << hrac_zlato << endl;

        cout << "\nCo chces delat?" << endl;
        cout << "1) Doplneni plneho poctu zivotu - 10 zlata" << endl;
        cout << "2) Zvyseni maximalnich zivotu o 5 - 15 zlata" << endl;
        cout << "3) Zvyseni maximalni energie o 5 - 20 zlata" << endl;
        cout << "4) Zvyseni utoku o 2 - 25 zlata" << endl;
        cout << "5) Nic - odejit z vesnice" << endl;

        cout << "Napis svoji volbu: " << endl;
        cin >> volba;

        if (volba == 1){
            if (hrac_zlato >= 10){
                hrac_zlato -= 10;
                hrac_zivoty = hrac_max_zivoty;
                cout << "Mas plne doplnene zivoty." << endl;
            }else
                cout << "Nemas dostatek zlata." << endl;

        }else if (volba == 2){
            if (hrac_zlato >= 15){
                hrac_zlato -= 15;
                hrac_max_zivoty += 5;
                cout << "Zvysil se tvuj maximalni pocet zivotu." << endl;
            }else
                cout << "Nesmas dostatek zlata." << endl;

        }else if (volba == 3){
            if (hrac_zlato >= 20){
                hrac_zlato -= 20;
                hrac_max_energie += 5;
                cout << "Zvysil se tvuj maximalni pocet energie." << endl;
            }else
                cout << "Nemas dostatek zlata." << endl;

        }else if (volba == 4){
            if (hrac_zlato >= 25){
                hrac_zlato -= 25;
                hrac_utok += 2;
                cout << "Zvysil se tvuj utok." << endl;
            }else
                cout << "Nemas dostatek zlata." << endl;

        }else if (volba == 5){
            cout << "Odchazis z vesnice." << endl;

        }else
            cout << "Spatne zadana volba." << endl;
    }while (volba != 5);
}
void boj_monstrum (int &hrac_zivoty, int hrac_utok, int &hrac_xp, int &hrac_zlato){
    int monstrum_hp = 15;
    int monstrum_utok = 5;

    cout << "Narazil jsi na monstrum." << endl;

    while(hrac_zivoty > 0 && monstrum_hp > 0){
        cout << "Tvoje HP je: " << hrac_zivoty << endl;
        cout << "Monstrovo HP je: " << monstrum_hp << endl;

        monstrum_hp -= hrac_utok;
        cout << "Utocis za " << hrac_utok << endl;

        if (monstrum_hp <= 0){
            cout << "Monstrum je porazeno." << endl;
            hrac_xp += 10;

        if (rand() % 2 == 0){
            int zlato = 10 + rand() % 11;
            hrac_zlato += zlato;
            cout << "Ziskal jsi " << zlato << " zlata." << endl;
        }
        break;
        }
        cout << "Monstrum utoci za " << monstrum_utok << endl;
        hrac_zivoty -= monstrum_utok;

        if (hrac_zivoty <= 0){
            hrac_zivoty = 0;
            cout << "Zemrel jsi." << endl;
        }
    }
}
int main(){
    srand(time(0));
    int hrac_max_energie;
    int hrac_energie;
    int hrac_utok;
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
    cout << "   - max. pocet zivotu: 20" << endl;
    cout << "   - aktualni zivoty: 20" << endl;
    cout << "   - max. energie: 10" << endl;
    cout << "   - aktualni energie: 10" << endl;
    cout << "   - pocet zlatych minci: 0" << endl;
    cout << "   - level: 1" << endl;
    cout << "   - zkusenosti: 0" << endl;
    cout << "   - utok: 3" << endl;
    cout << "   - schopnosti: " << endl;
    cout << "Pro dalsi classu zmacni 'd': ";
    cin >> dalsi;

    if (dalsi == 'd'){
    cout << "2) Lovec:" << endl;
    cout << "   - max. pocet zivotu: 15" << endl;
    cout << "   - aktualni zivoty: 15" << endl;
    cout << "   - max. energie: 12" << endl;
    cout << "   - aktualni energie: 12" << endl;
    cout << "   - pocet zlatych minci: 0" << endl;
    cout << "   - level: 1" << endl;
    cout << "   - zkusenosti: 0" << endl;
    cout << "   - utok: 4" << endl;
    cout << "   - schopnosti: " << endl;
    cout << "Pro dalsi classu zmacni 'd': ";
    cin >> dalsi;
    }

    if (dalsi == 'd'){
    cout << "3) Mag:" << endl;
    cout << "   - max. pocet zivotu: 17" << endl;
    cout << "   - aktualni zivoty: 17" << endl;
    cout << "   - max. energie: 12" << endl;
    cout << "   - aktualni energie: 12" << endl;
    cout << "   - pocet zlatych minci: 0" << endl;
    cout << "   - level: 1" << endl;
    cout << "   - zkusenosti: 0" << endl;
    cout << "   - utok: 5" << endl;
    cout << "   - schopnosti: " << endl;
    cout << "Pro dalsi classu zmacni 'd': ";
    cin >> dalsi;
    }

    if (dalsi == 'd'){
    cout << "4) Warlock:" << endl;
    cout << "   - max. pocet zivotu: 19" << endl;
    cout << "   - aktualni zivoty: 19" << endl;
    cout << "   - max. energie: 15" << endl;
    cout << "   - aktualni energie: 15" << endl;
    cout << "   - pocet zlatych minci: 0" << endl;
    cout << "   - level: 1" << endl;
    cout << "   - zkusenosti: 0" << endl;
    cout << "   - utok: 6" << endl;
    cout << "   - schopnosti: " << endl;
    }

    do{
    cout << "Napis svuj vyber: ";
    cin >> vyber_classy;
        if (vyber_classy == 1){
            cout << "Vyborne! Vybral sis Paladina." << endl;
            hrac_maximalni_pocet_zivotu = 20;
            hrac_zivoty = 20;
            hrac_max_energie = 10;
            hrac_energie = 10;
            hrac_utok = 3;
        }else if (vyber_classy == 2){
            cout << "Vyborne! Vybral sis Lovce." << endl;
            hrac_maximalni_pocet_zivotu = 15;
            hrac_zivoty = 15;
            hrac_max_energie = 12;
            hrac_energie = 12;
            hrac_utok = 4;
        }else if (vyber_classy == 3){
            cout << "Vyborne! Vybral sis Maga." << endl;
            hrac_maximalni_pocet_zivotu = 17;
            hrac_zivoty = 17;
            hrac_max_energie = 12;
            hrac_energie = 12;
            hrac_utok = 5;
        }else if (vyber_classy == 4){
            cout << "Vyborne! Vybral sis Warlocka." << endl;
            hrac_maximalni_pocet_zivotu = 19;
            hrac_zivoty = 19;
            hrac_max_energie = 15;
            hrac_energie = 15;
            hrac_utok = 6;
        }else{
            cout << "Spatna volba, vyber si znova." << endl;
            hrac_maximalni_pocet_zivotu = 19;
            hrac_zivoty = 19;
            hrac_max_energie = 15;
            hrac_energie = 15;
            hrac_utok = 6;
        }
    }while(vyber_classy < 1 || vyber_classy > 4);

    hrac_utok = 5;
    cout << "Tvuj prvni utok" << endl;
    souboj(hrac_zivoty, hrac_maximalni_pocet_zivotu, hrac_utok);

}

