# Blockchain-pratybos
## v1.0 pakeitimai:

- Ištrinta funkcija converttoacs() ir pertvarkyta funkcija myHash(), kad pagreitintų veikimą ir pagerintų myHash veikimą(funkcija konstitucijos testą atlieka per ~1ms, anksčiau testas užtrukdavo ~250ms)
- Sukurta testavimo funkcija, kuri tikrina skirtumus tarp hashų bitų ir hexų lygmenį
- Sutvarkyta problema su funkcija readfromfile(), dėl kurios tuščias failas nebūdava hash'uojamas

## Analizė ir išvados

Rezultatai:

1. Hash kodas susideda iš šių simbolių '0123456789abcdef'
2. Hash yra fiksuoto dydžio(64 hex'as)
3. Hash funkcija deterministė pvz: įvestis 'ab' visada išves 'c5118c7ab65683f4c016b7ee64b285cf16b2b1315f2e90fd99d94e608683b929'
4. Lietuvos konstituciją hash'uojant po vieną eilutė užtrunka ~1ms
5. Hash'uojant **100000** atsitiktinai sugeneruotų simbolių eilučių iš failo "testcase5.1.txt" randamas **31** kolizijų atvėjų. pasikartojantys hash'ai saugomi faile "repeatinghashcodes.txt"
6. ### skirtingumas:
Skirtingumas ištirtas hash'uojant 100000 atsitiktinai sugeneruotas string 1000 simbolių ilgio  poras, kurios skiriasi vienu simboliu.
Hash'uojami stringai laikomi failuose "testcase6a.txt" ir "testcase6b.txt"
Suhash'uotos poros išvedamos į failą "testcase6hashes.txt"
skirtingumas| max | min | average
------------ | ------------- | ------------- | -------------
bitų lygmenį| 161 | 93 | 128.004
hex'ų lygmenį| 64 | 50 | 60.0001

## Išvados:

1. Veikimo greitis galėtų būti geresnis, tačiau nepavyko sumažinti veikimo greičio nepaveikus kitų hash funkcijos savybių neigiamai
2. Pasitaiko kolizijų 0.031%, nepavyko visiškai eliminuoti kolizijos atvėjų
3. Bitų lygmenį vieno simbolio pakeitimas vidutiniškai pakeičia 50% hash'o bitų, tai parodo, kad hash funkcija turi avalanche efektą 
