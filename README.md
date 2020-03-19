# BankApp
### Autorzy Projektu: </br>
* [Stanisław Czembor](https://github.com/sczembor)</br>
* [Tomasz Knura](https://github.com/tknura)</br>
#### Grupa 5 Sekcja 2</br>

## Szkic interfejsu wykonany w AdobeXD:
![Ui_conspect](https://user-images.githubusercontent.com/43812114/77059095-b04d5f80-69d6-11ea-90c3-da04596518ec.png)

## Diagram klas:
![Main](https://user-images.githubusercontent.com/43812114/76738993-e4711800-676b-11ea-8c51-cc78d090ceda.jpg)</br>

## Kluczowe klasy
* **User** </br>
dziedziczy po klasie LogInData
Klasa odpowiedzialna za przechowywanie unikalnych danych użytkownika takich jak lista kont (w postaci Stringow po których będzie przeszukiwana mapa w klasie Bank) czy lista przyjaciół (lista obiektów typu PaymentRetriever).

* **Account** </br>
klasa, bazowa dla wszystkich rodzajów kont. Obiekty tej klasy będą przechowywane w mapie w klasie Bank oraz w liście w klasie User. 

* **Bank** </br>
klasa nie dziedziczy i nie jest dziedziczona. Zawiera pole User oraz przechowuje mapę wszystkich kont z pliku JSON. 

* **JsonManager** </br>
	klasa odpowiedzialna za obsługę plików JSON. Współpracuje z klasą Bank.

* **Payment** </br>
klasa obsługuje wszystkie przelewy w banku.

* **Card** </br>
klasa bazowa dla wszystkich rodzajów kart.

* **Fund** </br>
klasa bazowa dla wszystkich rodzajów funduszy.

* **History** </br>
klasa przechowująca listę wszystkich płatności. Jest kluczowa przy wyświetlaniu historii transakcji użytkownika. Klasa udostępnia publiczne metody Sort(), pozwalające posortować listę według różnych kryterium.

* **Config** </br>
klasa wczytuję nazwy plików oraz inne niezbędne dane z pliku config.txt.

## Pliki
* **LogInData.txt** </br>
plik przechowuję zaszyfrowane dane logowania w formacie: login haslo id np. superman trudnehaslo22 235865
* **AccountData.json** </br>
przechowuje dane dotyczące kont oraz kart. Głównymi obiektami w pliku są konta. 
* **FriendsData.json** </br>
plik przechowuje dane dotyczące listy znajomych użytkownika. Pogrupowane według ID użytkownika.
* **FundsData.json** </br>
plik z danymi dotyczącymi funduszy. Pogrupowany funduszami.
* **ConfigFile.txt** </br>
plik z nazwami i ścieżkami do wszystkich plików.

## Przykładowy funkcjonalności programu
* **Logowanie** </br>
W klasie UI tworzymy obiekt *LogInData* na podstawie danych wprowadzonych przez użytkownika. Obiekt jest przekazywany do statycznej klasy *Authorization*, która sprawdza czy w pliku LogInData.txt istnieje użytkownik. Następnie jest on przekazywany do metody LogIn() w klasie *Bank*, która będzie tworzyć obiekt klasy *User*. </br>
* **Wczytywanie danych z plików** </br>
W klasie *Bank* tworzona jest mapa przechowująca obiekty klasy *Account*, które są tworzone na podstawie danych z pliku AccountData.json. Plik jest obsługiwany przez klasę *JsonManager*.  </br>
* **Przelew** </br>
Na rzecz *User* wywołana jest metoda MakePayment(), która tworzy obiekt klasy *Payment*. Jeżeli wprowadzone dane są poprawne, płatność zostaje zaksięgowana poprzez wywołanie metody AddNewRecord() w klasie *History* oraz zaktualizowane zostają konta w mapie w klasie *Bank*. </br>
* **Wyświetlanie historii** </br>
Klasa *History* zwraca listę obiektów payment posortowaną według podanego klucza. </br>
* **Wylogowanie** </br>
Przy wylogowywaniu mapa kont z klasy *Bank* zostaje przekazana do klasy *JsonManager*, która nadpisuje plik AccountData.json. </br>

## Zagadnienia z zajęć laboratoryjnych
1. Regex
2. Inteligentne wskaźniki
3. RTTI
4. Kontenery STL
5. Algorytmy i iteratory STL
6. Mechanizm wyjątków

## Zewnętrzne biblioteki
1. nlohmann JSON
2. Biblioteki QT
