# pirma užduotis (v0.1)
[atgal į master](https://github.com/auteea/Obj_programavimas/tree/main)

## užduotis
- Parašykite programą, kuri nuskaito šiuos studentų duomenis:
- vardą ir pavardę
- atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino rezultatą.
- Tuomet iš šių duomenų, suskaičiuoja galutinį balą :  
`galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas`
 - Duomenys pateikiami į ekraną tokiu ar panašiu pavidalu (kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu):
``` 
Pavardė     Vardas       Galutinis (Vid.) / Galutinis (Med.)
-----------------------------------------------------------
Arvydas     Sabonis      x.xx               x.xx
Rimas       Kurtinaitis  y.yy               y.yy
...
```
## programos komentaras
- įvedus norimą studentų skaičių, nebus galima jo keisti. Vadinasi negalima viduryje duomenų įvedimo persigalvoti ir nebevesti arba vesti daugiau nei galima studentų duomenų.
- kiekvienam studentui yra galimybė duomenis arba rašyti pačiam arba kad jie būtų generuojami atsitiktinai (išskyrus studento vardą ir pavardę).
- visų studentū namų darbų kiekis yra ribotas iki 30 namų darbų, tačiau gali būti ir mažiau. Nėra prašoma įvesti namų darbų kiekio, vedama tol kol yra noro.
- kiekvienam studentui yra galimybė pasirinkti ar galutinis balas bus skaičiuojamas su mediana ar su vidurkiu.

### programa veikia tiek kaupiant namų darbus į masyvą (vektoriai su masyvais) tiek į vektorių (vektoriai su vektoriais)
