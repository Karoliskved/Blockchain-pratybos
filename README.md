# Blockchain-pratybos
## v1.0 pakeitimai:

- Ištrinta funkcija converttoacs() ir pertvarkyta funkcija myHash(), kad pagreitintų veikimą ir pagerintų myHash veikimą(funkcija konstitucijos testą atlieka per ~1ms, anksčiau testas užtrukdavo ~250ms)
- Sukurta testavimo funkcija, kuri tikrina skirtumus tarp hashų bitų ir hexų lygmenį
- Sutvarkyta problema su funkcija readfromfile(), dėl kurios tuščias failas nebūdava hash'uojamas

## Analizės išvados

Rezultatai:

1. hash kodas susideda iš šių simbolių '0123456789abcdef'
2.  hash yra fiksuoto dydžio(64 hex'as)
3. hash funkcija deterministė pvz: įvestis 'ab' visada išves 'c5118c7ab65683f4c016b7ee64b285cf16b2b1315f2e90fd99d94e608683b929'
4. Lietuvos konstituciją hash'uojant po vieną eilutė užtrunka ~1ms
5. hash'uojant **100000** atsitiktinai sugeneruotų simbolių eilučių iš failo "testcase5.1.txt" randamas **31** kolizijų atvėjų. pasikartojantys hash'ai saugomi faile "repeatinghashcodes.txt"
6. skirtingumas:
  * stuff
