# Przeplyw programu dla 3, 4, 5 i wiekszej liczby elementow

To jest opis roboczy, zeby bylo widac przez jakie funkcje przelatuje program w kazdym przypadku.

## 1. Wspolny start

Dla kazdego poprawnego wejscia program idzie mniej wiecej tak samo:

```text
main
-> parse_args_to_stack
-> check_dupli
-> is_sorted
-> assign_indexes
-> choose_sort
```

Jesli na ktoryms etapie jest blad, program wypisuje `Error` i sprzata pamiec.

## 2. Przypadek dla 3 liczb

Przyklad: `3 1 2`

```text
main
-> parse_args_to_stack
-> check_dupli
-> is_sorted
-> assign_indexes
-> choose_sort
   -> sort_three
   -> jedna z operacji: sa / ra / rra / sa+ra
```

### Co robi `sort_three`

`sort_three` patrzy tylko na trzy pierwsze elementy stosu A i porownuje ich wartosci.
W zaleznosci od ukladu robi jedna lub dwie operacje, np.:

- `sa` gdy trzeba zamienic dwa pierwsze elementy
- `ra` gdy trzeba obrocic w gore
- `rra` gdy trzeba obrocic w dol
- `sa` + `ra` albo `sa` + `rra` w trudniejszych ukladach

### Czyli w praktyce

Nadpisujesz tylko maly fragment stosu i nie uzywasz stosu B.

## 3. Przypadek dla 4 liczb

Przyklad: `4 2 5 1`

```text
main
-> parse_args_to_stack
-> check_dupli
-> is_sorted
-> assign_indexes
-> choose_sort
   -> sort_small
      -> sort_four
         -> push_lowest
            -> find_lowest_pos
            -> ra albo rra
            -> pb
         -> sort_three
         -> pa
```

### Co dzieje sie po kolei

1. `sort_small` widzi, ze stos ma 4 elementy.
2. `sort_four` uruchamia `push_lowest`.
3. `push_lowest` szuka najmniejszego elementu po `index`.
4. `find_lowest_pos` zwraca jego pozycje.
5. `push_lowest` wybiera szybsza droge:
   - `ra`, gdy najmniejszy element jest blizej gory
   - `rra`, gdy blizej dolu
6. Najmniejszy element trafia na stos B przez `pb`.
7. Na A zostaja 3 liczby, wiec `sort_three` uklada je lokalnie.
8. Na koncu `pa` przywraca najmniejszy element na A.

### Co to daje

To jest lepsze niz radix dla 4 liczb, bo najpierw wyrzucasz tylko jeden najmniejszy element, a potem korzystasz z prostej logiki dla trzech elementow.

## 4. Przypadek dla 5 liczb

Przyklad: `3 5 1 4 2`

```text
main
-> parse_args_to_stack
-> check_dupli
-> is_sorted
-> assign_indexes
-> choose_sort
   -> sort_small
      -> sort_five
         -> push_lowest
            -> find_lowest_pos
            -> ra albo rra
            -> pb
         -> push_lowest
            -> find_lowest_pos
            -> ra albo rra
            -> pb
         -> sort_three
         -> pa
         -> pa
```

### Co dzieje sie po kolei

1. `sort_small` widzi, ze stos ma 5 elementow.
2. `sort_five` uruchamia `push_lowest` dwa razy.
3. Za kazdym razem szuka aktualnie najmniejszego elementu w pozostalej czesci A.
4. Za kazdym razem robi `ra` albo `rra`, zeby dojsc do tego elementu najmniejsza liczba ruchow.
5. Po `pb` na B laduja dwa najmniejsze elementy.
6. Na A zostaja 3 liczby, wiec `sort_three` uklada reszte.
7. Dwa razy `pa` oddaje elementy z B z powrotem na A.

### Dlaczego to dziala

Po wyjeciu 2 najmniejszych elementow zostaje trojka, ktora da sie ustawic bardzo prostym sorterem. Potem najmniejsze elementy wracaja na gore w poprawnej kolejnosci.

## 5. Przypadek dla wiecej niz 5 liczb

Przyklad: `8 3 7 1 6 2`

```text
main
-> parse_args_to_stack
-> check_dupli
-> is_sorted
-> assign_indexes
-> choose_sort
   -> radix_sort
      -> liczba bitow
      -> petla po kolejnych bitach
      -> dla kazdego elementu: ra albo pb
      -> zwrot elementow z B przez pa
```

### Co robi `radix_sort`

`radix_sort` patrzy na `index` kazdego elementu i sortuje po bitach.
Na kazdym bicie:

- jesli bit ma wartosc `1`, robi `ra`
- jesli bit ma wartosc `0`, robi `pb`
- potem wszystko z B wraca przez `pa`

To trwa dluzej niz sortowanie malych przypadkow, ale jest stabilne i dobre dla wiekszych wejsc.

## 6. Najkrotsze podsumowanie

- `3 liczby` -> `choose_sort` -> `sort_three`
- `4 liczby` -> `choose_sort` -> `sort_small` -> `sort_four`
- `5 liczb` -> `choose_sort` -> `sort_small` -> `sort_five`
- `wiecej niz 5` -> `choose_sort` -> `radix_sort`

## 7. Kluczowa roznica miedzy malymi i duzymi przypadkami

Przy 3, 4 i 5 liczbach program probuje zrobic jak najmniej ruchow lokalnie, bez pelnego radixa.
Przy wiekszych wejsciach przechodzi na algorytm bitowy, bo tam prosty trik z najmniejszym elementem juz nie wystarcza.