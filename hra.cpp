#include <iostream>
#include <ctime>
using namespace std;

void schopnost (string classa, int &hrac_zivoty, int hrac_utok, int &nepritelovo_hp){
    if (classa == "Paladin"){
        hrac_zivoty += 10;
        if (hrac_zivoty > 50)
            hrac_zivoty = 50;
        cout << "Paladin se vylecil o 10 HP" << endl;
    }else if (classa == "Lovec"){
        nepritelovo_hp -= hrac_utok * 2;
        cout << "Mas zdvojnasobeny vystrel" << endl;
    }else if (classa == "Mag"){
        nepritelovo_hp -= 8;
        cout << "Ohniva koule za 8 damage" << endl;
    }else if (classa == "Warlock"){
        nepritelovo_hp -= 5;
        hrac_zivoty += 5;
        cout << "Vysati zivota" << endl;
    }
}
void souboj(string hrac_classa, int &hrac_zivoty, int &hrac_max_zivoty, int hrac_utok){
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
        int vyber_souboj;
        cout << "Ted jsi na tahu ty! " << endl;
        cout << "1) Utok" << endl;
        cout << "2) Schopnost" << endl;
        cout << "Vyber si: ";
        cin >> vyber_souboj;
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
        if (vyber_souboj == 2){
            schopnost(hrac_classa, hrac_zivoty, hrac_utok, boss_zivoty);
        }else{
            cout << "Utocis za " << utok_hrace << " HP" << endl;
            boss_zivoty -= utok_hrace;
        }

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

        cout << "Napis svoji volbu: ";
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
    int monstrum_hp = 13;
    int monstrum_utok = 4;

    cout << "\nNarazil jsi na monstrum." << endl;

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
void level_up (int &xp, int &level, int &max_hp, int &utok){
    while (xp >= level * 20){
        xp -= level * 20;
        level++;
        max_hp += 5;
        utok += 1;

        cout << "\nNOVY LEVEL" << endl;
        cout << "Level je: " << level << endl;
        cout << "Max HP +5" << endl;
        cout << "Utok +1" << endl;
    }
}
void miniboss (int &hrac_hp, int hrac_utok, int &xp, int &zlato){
    int miniboss_hp = 30;
    int miniboss_utok = 8;

    cout << "\nNarazil jsi na mini-bosse" << endl;

    while (hrac_hp > 0 && miniboss_hp > 0){
        cout << "Mini-bossovo hp: " << miniboss_hp << endl;
        miniboss_hp -= hrac_utok;

        if (miniboss_hp <= 0){
            cout << "Porazil jsi mini-bosse" << endl;
            xp += 30;

            int odmena = 10;
            zlato += odmena;

            cout << "Ziskal jsi " << odmena << " zlata" << endl;
            break;
        }
        cout << "Mini-boss utoci za " << miniboss_utok << endl;
        hrac_hp -= miniboss_utok;

        if (hrac_hp <= 0){
            hrac_hp = 0;
            cout << "Mini-boss te zabil" << endl;
        }
    }
}
void boj_dve_monstra (int &hrac_zivoty, int hrac_utok, int &hrac_xp, int &hrac_zlato){
    cout << "\nNarazil jsi na 2 monstra" << endl;
    int monstrum_c1_hp = 15;
    int monstrum_c2_hp = 15;
    int monstrum_utok = 5;

    while (hrac_zivoty > 0 && (monstrum_c1_hp > 0 || monstrum_c2_hp > 0)){
        cout << "\nTvoje HP je: " << hrac_zivoty << endl;
        cout << "Prvni monstrum ma " << monstrum_c1_hp << " HP" << endl;
        cout << "Druhe monstrum ma " << monstrum_c2_hp << " HP" << endl;

            int volba2;
            do{
                cout << "Na ktere monstrum chces zautocit jako prvni? (1 nebo 2): ";
                cin >> volba2;
            }while (volba2 != 1 && volba2 != 2);

            if (volba2 == 1 && monstrum_c1_hp > 0){
                monstrum_c1_hp -= hrac_utok;
                cout << "Utocis na prvni monstrum za " << hrac_utok << " damage." << endl;
            }else if (volba2 == 2 && monstrum_c2_hp > 0){
                monstrum_c2_hp -= hrac_utok;
                cout << "Utocis na druhe monstrum za " << hrac_utok << " damage." << endl;
            }else{
                cout << "Toto monstrum je jiz mrtve." << endl;
            }

            if (monstrum_c1_hp <= 0 && monstrum_c2_hp <= 0 ){
                cout << "Porazil jsi obe dve monstra" << endl;
                hrac_xp += 20;

                if (rand() % 100 < 50){
                    hrac_zlato += 15;
                    cout << "Vybojoval jsi 15 zlata" << endl;
                }else{
                    cout << "Za tento souboj nemas zadne zlato" << endl;
                }
                break;
            }
            if (monstrum_c1_hp > 0){
                cout << "Prvni monstrum utoci za " << monstrum_utok << endl;
                hrac_zivoty -= monstrum_utok;
            }
            if (monstrum_c2_hp > 0){
                cout << "Druhe monstrum utoci za " << monstrum_utok << endl;
                hrac_zivoty -= monstrum_utok;
            }
            if (hrac_zivoty <= 0){
                hrac_zivoty = 0;
                cout << "Zemrel jsi" << endl;
            }
    }
}
void boj_tri_monstra (int &hrac_zivoty, int hrac_utok, int &hrac_xp, int &hrac_zlato){
    int monstrum_c1_hp = 15;
    int monstrum_c2_hp = 15;
    int monstrum_c3_hp = 15;
    int monstrum_utok = 5;

    cout << "\nNarazil jsi na tri monstra." << endl;

    while (hrac_zivoty > 0 && (monstrum_c1_hp > 0 || monstrum_c2_hp > 0 || monstrum_c3_hp > 0)){
        cout << "\nTvoje HP je: " << hrac_zivoty << endl;
        cout << "Prvni monstrum ma " << monstrum_c1_hp << " HP" << endl;
        cout << "Druhe monstrum ma " << monstrum_c2_hp << " HP" << endl;
        cout << "Treti monstrum ma " << monstrum_c3_hp << " HP" << endl;

        int volba3;
        do{
            cout << "Vyber na ktere monstrum chces zautocit? (1, 2 nebo 3): ";
            cin >> volba3;
        }while (volba3 < 1 || volba3 > 3);

        if (volba3 == 1 && monstrum_c1_hp > 0){
            monstrum_c1_hp -= hrac_utok;
            cout << "Utocis na prvni monstrum za " << hrac_utok << " damage" << endl;
        }else if (volba3 == 2 && monstrum_c2_hp > 0){
            monstrum_c2_hp -= hrac_utok;
            cout << "Utocis na druhe monstrum za " << hrac_utok << " damage" << endl;
        }else if (volba3 == 3 && monstrum_c3_hp > 0){
            monstrum_c3_hp -= hrac_utok;
            cout << "Utocis na treti monstrum za " << hrac_utok << " damage" << endl;
        }else{
            cout << "Toto monstrum je jiz mrtve " << endl;
        }

        if (monstrum_c1_hp <= 0 && monstrum_c2_hp <= 0 && monstrum_c3_hp <= 0){
                cout << "Porazil jsi vsechna monstra" << endl;
                hrac_xp += 30;

                if (rand() % 100 < 50){
                    hrac_zlato += 15;
                    cout << "Vybojoval jsi 15 zlata" << endl;
                }else{
                    cout << "Za tento souboj nemas zadne zlato" << endl;
                }
                break;
            }
            if (monstrum_c1_hp > 0){
                cout << "Prvni monstrum utoci za " << monstrum_utok << endl;
                hrac_zivoty -= monstrum_utok;
            }
            if (monstrum_c2_hp > 0){
                cout << "Druhe monstrum utoci za " << monstrum_utok << endl;
                hrac_zivoty -= monstrum_utok;
            }
            if (monstrum_c3_hp > 0){
                cout << "Treti monstrum utoci za " << monstrum_utok << endl;
                hrac_zivoty -= monstrum_utok;
            }
            if (hrac_zivoty <= 0){
                hrac_zivoty = 0;
                cout << "Zemrel jsi" << endl;
            }
    }
}

int main(){
    srand(time(0));
    string hrac_classa;
    int hrac_max_energie;
    int hrac_energie;
    int hrac_utok;
    int hrac_zivoty;
    int hrac_maximalni_pocet_zivotu;
    int hrac_level = 1;
    int hrac_xp = 0;
    int hrac_zlato = 20;

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
    cout << "   - schopnosti: Paladin se vyleci o 10 HP" << endl;
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
    cout << "   - schopnosti: Lovec ma zdvojnasobeny vystrel" << endl;
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
    cout << "   - schopnosti: Mag ma ohnivou kouli za 8 damage" << endl;
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
    cout << "   - schopnosti: Warlock ma vysati zivota o 5" << endl;
    }

    do{
    cout << "Napis svuj vyber: ";
    cin >> vyber_classy;
        if (vyber_classy == 1){
            hrac_classa = "Paladin";

            cout << "Vyborne! Vybral sis Paladina." << endl;

            hrac_maximalni_pocet_zivotu = 25;
            hrac_zivoty = 25;
            hrac_max_energie = 10;
            hrac_energie = 10;
            hrac_utok = 3;

        }else if (vyber_classy == 2){
            hrac_classa = "Lovec";

            cout << "Vyborne! Vybral sis Lovce." << endl;

            hrac_maximalni_pocet_zivotu = 20;
            hrac_zivoty = 20;
            hrac_max_energie = 12;
            hrac_energie = 12;
            hrac_utok = 4;

        }else if (vyber_classy == 3){
            hrac_classa = "Mag";

            cout << "Vyborne! Vybral sis Maga." << endl;

            hrac_maximalni_pocet_zivotu = 19;
            hrac_zivoty = 19;
            hrac_max_energie = 12;
            hrac_energie = 12;
            hrac_utok = 5;

        }else if (vyber_classy == 4){
            hrac_classa = "Warlock";

            cout << "Vyborne! Vybral sis Warlocka." << endl;

            hrac_maximalni_pocet_zivotu = 18;
            hrac_zivoty = 18;
            hrac_max_energie = 15;
            hrac_energie = 15;
            hrac_utok = 6;

        }else
            cout << "Spatna volba, vyber si znova." << endl;

    }while(vyber_classy < 1 || vyber_classy > 4);

    cout << "\n===STATISTIKY===" << endl;
    cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_maximalni_pocet_zivotu << endl;
    cout << "Tvoje energie je: " << hrac_energie << "/" << hrac_max_energie << endl;
    cout << "Tvuj level je: " << hrac_level << endl;
    cout << "Tvoje xp je: " << hrac_xp << endl;
    cout << "Mas " << hrac_zlato << " zlata" << endl;

    vesnice (hrac_zivoty, hrac_energie, hrac_utok, hrac_zlato, hrac_maximalni_pocet_zivotu, hrac_max_energie);
    boj_monstrum ( hrac_zivoty,  hrac_utok,hrac_xp, hrac_zlato);
    if (hrac_zivoty <= 0){
        cout << "Zemrel jsi, je konec hry" << endl;
        return 0;
    }
    cout << "\n===STATISTIKY===" << endl;
    cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_maximalni_pocet_zivotu << endl;
    cout << "Tvoje energie je: " << hrac_energie << "/" << hrac_max_energie << endl;
    cout << "Tvuj level je: " << hrac_level << endl;
    cout << "Tvoje xp je: " << hrac_xp << endl;
    cout << "Mas " << hrac_zlato << " zlata" << endl;

    level_up(hrac_xp, hrac_level, hrac_maximalni_pocet_zivotu, hrac_utok);
    vesnice (hrac_zivoty, hrac_energie, hrac_utok, hrac_zlato, hrac_maximalni_pocet_zivotu, hrac_max_energie);
    boj_monstrum(hrac_zivoty, hrac_utok, hrac_xp, hrac_zlato);
    if (hrac_zivoty <= 0){
        cout << "Zemrel jsi, je konec hry" << endl;
        return 0;
    }
    cout << "\n===STATISTIKY===" << endl;
    cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_maximalni_pocet_zivotu << endl;
    cout << "Tvoje energie je: " << hrac_energie << "/" << hrac_max_energie << endl;
    cout << "Tvuj level je: " << hrac_level << endl;
    cout << "Tvoje xp je: " << hrac_xp << endl;
    cout << "Mas " << hrac_zlato << " zlata" << endl;

    level_up(hrac_xp, hrac_level, hrac_maximalni_pocet_zivotu, hrac_utok);
    boj_dve_monstra(hrac_zivoty, hrac_utok, hrac_xp, hrac_zlato);
    if (hrac_zivoty <= 0){
        cout << "Zemrel jsi, je konec hry" << endl;
        return 0;
    }
    cout << "\n===STATISTIKY===" << endl;
    cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_maximalni_pocet_zivotu << endl;
    cout << "Tvoje energie je: " << hrac_energie << "/" << hrac_max_energie << endl;
    cout << "Tvuj level je: " << hrac_level << endl;
    cout << "Tvoje xp je: " << hrac_xp << endl;
    cout << "Mas " << hrac_zlato << " zlata" << endl;

    level_up(hrac_xp, hrac_level, hrac_maximalni_pocet_zivotu, hrac_utok);
    vesnice (hrac_zivoty, hrac_energie, hrac_utok, hrac_zlato, hrac_maximalni_pocet_zivotu, hrac_max_energie);
    miniboss(hrac_zivoty, hrac_utok, hrac_xp, hrac_zlato);
    if (hrac_zivoty <= 0){
        cout << "Zemrel jsi, je konec hry" << endl;
        return 0;
    }
    cout << "\n===STATISTIKY===" << endl;
    cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_maximalni_pocet_zivotu << endl;
    cout << "Tvoje energie je: " << hrac_energie << "/" << hrac_max_energie << endl;
    cout << "Tvuj level je: " << hrac_level << endl;
    cout << "Tvoje xp je: " << hrac_xp << endl;
    cout << "Mas " << hrac_zlato << " zlata" << endl;

    level_up(hrac_xp, hrac_level, hrac_maximalni_pocet_zivotu, hrac_utok);
    vesnice (hrac_zivoty, hrac_energie, hrac_utok, hrac_zlato, hrac_maximalni_pocet_zivotu, hrac_max_energie);
    boj_dve_monstra(hrac_zivoty, hrac_utok, hrac_xp, hrac_zlato);
    if (hrac_zivoty <= 0){
        cout << "Zemrel jsi, je konec hry" << endl;
        return 0;
    }
    cout << "\n===STATISTIKY===" << endl;
    cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_maximalni_pocet_zivotu << endl;
    cout << "Tvoje energie je: " << hrac_energie << "/" << hrac_max_energie << endl;
    cout << "Tvuj level je: " << hrac_level << endl;
    cout << "Tvoje xp je: " << hrac_xp << endl;
    cout << "Mas " << hrac_zlato << " zlata" << endl;

    miniboss(hrac_zivoty, hrac_utok, hrac_xp, hrac_zlato);
    if (hrac_zivoty <= 0){
        cout << "Zemrel jsi, je konec hry" << endl;
        return 0;
    }

    boj_tri_monstra(hrac_zivoty, hrac_utok, hrac_xp, hrac_zlato);
    if (hrac_zivoty <= 0){
        cout << "Zemrel jsi, je konec hry" << endl;
        return 0;
    }
    cout << "\n===STATISTIKY===" << endl;
    cout << "Tvoje HP je: " << hrac_zivoty << "/" << hrac_maximalni_pocet_zivotu << endl;
    cout << "Tvoje energie je: " << hrac_energie << "/" << hrac_max_energie << endl;
    cout << "Tvuj level je: " << hrac_level << endl;
    cout << "Tvoje xp je: " << hrac_xp << endl;
    cout << "Mas " << hrac_zlato << " zlata" << endl;
    vesnice (hrac_zivoty, hrac_energie, hrac_utok, hrac_zlato, hrac_maximalni_pocet_zivotu, hrac_max_energie);

    cout << "\nDorazil jsi k Mystifexovi" << endl;
    souboj(hrac_classa, hrac_zivoty, hrac_maximalni_pocet_zivotu, hrac_utok);
}


