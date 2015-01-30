Zadanie 3: zamiana koloru na skalę szarości 
=============
(Assignment 3: Convert colorful image to monochrome one)

Dany jest obrazek w postaci matrycy pikseli. Kolor każdego piksela zapisany jest na 24 bitach, po 8 bitów dla każdego koloru (RGB). Napiszemy procedurę w asemblerze dla procesora ARM, dokonującą konwersji obrazu na skalę szarości przez policzenie średniej ważonej.

Ponieważ oko ludzkie niejednakowo reaguje na kolory (najsilniej na zielony), współczynniki dla poszczególnych składowych nie mogą być jednakowe, zwykle przyjmuje się:

77 dla koloru czerwonego,
151 dla koloru zielonego i
28 dla koloru niebieskiego.

Podane współczynniki sumują się do 256, co ułatwi dzielenie.
Argumentami procedury powinny być:

adres matrycy: zapis zapewne wierszami, trzeba będzie wybrać sobie format odpowiedni do konwersji z formatu graficznego;
rozmiary matrycy: liczba wierszy i kolumn.
Miło byłoby umożliwić zmienianie wartości współczynników z programu głównego.

Dodatkowo należy napisać program główny (w C lub tp.), który pobierze (jako argument) nazwę pliku graficznego (w formacie PPM, kto nie zna niech spyta Ciocię Wikipedię) i zamieni go na matrycę (można funkcją z jakiejś biblioteki), po czym wywoła naszą procedurę. Otrzymaną matrycę należy z powrotem zamienić na plik graficzny (ten sam lub inny). Całość powinna działać pod emulatorem QEMU dostępnym na stronie.
