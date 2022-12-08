# v1.0
[atgal į master](https://github.com/auteea/Obj_programavimas)
## Veikimas
Programa atlieką tuos pačius skaičiavimus kaip ir praeitoje versijoje, tik skirtingais būdais:
 - naudojant vektorius, skirstant studentus į du naujai sukuriamus vektorius
 - naudojant listus, skstant studentus į du naujai sukuriamus vekktorius
 - naudojant vektorius, kuriant tik vieną naują "Vargšiukų" vektorių ir tuos "Vargšiukus" pašalinant iš pradinio vektoriaus, taip pradinis vektorius tampa "Galvočiai"
 - naudojant listus, kuriant tik vieną naują "Vargšiukų" listą ir tuos "Vargšiukus" pašalinant iš pradinio listo, taip pradinis listas tampa "Galvočiai"
 ## Instrukcijos
 
-Vartotojo paklausiama ar jis nori duomenų file sukurti, ar naudoti jau esamą.
 
-Jei pasirinkta file sukurti iš naujo, reikia pasirinkti kokį kiekį duomenų norima kurti.

-Kai pasirinkta duomenis nuskaityti iš failo, duomenys bus nuskaityti iš failo "kursiokai.txt"

-Tada programa atliks vektorių testavimą dviem būdais. 1) Skaidant konteinerį į du to paties tipo "Galvočių" ir "Vargšelių" konteinerius. 2) Skaidant konteineį panaudojant tik vieną "Galvočių" konteinerį. Tokiu būdu protinguoliai liks pradiniame konteineryje. Skaidant konteinerį panaudojant remove_if algoritmas.

 ## Testavimo rezultatai
 - 1000 duomenų
 ![alt text](Sparta_strategija_1000.png)
  - 10,000 duomenų
 ![alt text](Sparta_strategija_10000.png)
  - 100,000 duomenų
 ![alt text](Sparta_strategija_100000.png)
  - 1,000,000 duomenų
 ![alt text](Sparta_strategija_1000000.png)
  
 ## Išvados
 
 -Naudojant 2 strategija programa užtrunka ilgiau
 -Programa prasčiau (ilgiau) tvarkosi su vectoriais
