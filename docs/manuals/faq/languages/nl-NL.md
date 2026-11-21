# Woonkamermodule - veelgestelde vragen

## 1. Wat meet de woonkamermodule?

Elke 10 minuten:

- de CO₂-concentratie;
- de temperatuur;
- de luchtvochtigheid;
- hoeveel aangemelde smartphones thuis zijn (zie vraag 4).

Daarnaast de batterijspanning, om te zien of de voeding aangesloten is.

## 2. Wat staat er op het scherm?

- **Bovenaan**: wifi, de datum en de batterij (een bliksem: op de voeding).
- **Midden**: de CO₂-concentratie in ppm; daaronder temperatuur, luchtvochtigheid en het aantal aanwezigen.
- **Onderaan**: een wolkje met vinkje en de tijd waarop de laatste metingen zijn verstuurd. Een doorgestreept wolkje met *N metingen* betekent dat die metingen nog niet verstuurd zijn; de module bewaart ze en verstuurt ze later.

Het scherm ververst bij elke meting, dus de getallen zijn hooguit 10 minuten oud.

## 3. Hoe koppel ik de module opnieuw met wifi?

Bijvoorbeeld bij een nieuwe router of een nieuw wifiwachtwoord:

1. Druk het wieltje aan de zijkant in, kies **Wifi opnieuw** en daarna **Ja, wifi vergeten**. (Werkt het scherm niet, houd dan de knop bovenop de module 10 seconden ingedrukt, tot het groene lampje 5 keer knippert.)
2. De module start opnieuw en toont de QR-code met **Scan met app**.
3. Scan die QR-code in de NeedForHeat-app en volg de app.

Uw eerdere metingen blijven bewaard.

## 4. Hoe laat ik smartphones meetellen?

De module telt aanwezigen door te kijken welke aangemelde smartphones in de buurt zijn. Meld daarom aan het begin uw eigen smartphone en die van elke huisgenoot één keer aan; de telefoons van de buren tellen zo niet mee.

1. Druk het zwarte wieltje aan de zijkant in, kies **Smartphones** en druk weer in. U ziet **SMARTPHONES:**.
2. Kies **+ toevoegen** en druk het wieltje in.
3. Ga op de smartphone naar **Instellingen > Bluetooth**, zet Bluetooth aan en tik op **NeedForHeat_OK** zodra die in de lijst staat.
4. Een piep bevestigt de koppeling; de naam van de smartphone komt in de lijst op het scherm.

Lukt het niet meteen, probeer het dan nog een keer.

Een smartphone verwijderen: blader met het wieltje naar de naam, druk in en bevestig. Met **terug** gaat u terug naar het menu; na 2 minuten zonder wieltje gaat de module vanzelf terug naar de metingen.

## 5. Moet Bluetooth aan blijven?

Ja, op de aangemelde smartphones de hele meetperiode. Verder hoeft u niets te doen: de smartphone blijft niet verbonden, de module ziet hem ook zo. Bluetooth kost tegenwoordig nauwelijks batterij.

Hoe dat werkt: de module stuurt af en toe een [Bluetooth-naamverzoek](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/src/presence_detection/README.md#general-info) naar de aangemelde smartphones.

## 6. Het scherm heeft lichte of donkere vlekken

Dat komt door zonlicht of fel licht op het e-inkscherm. Druk het wieltje in en kies **Scherm verversen**: het scherm wordt dan volledig opnieuw getekend. Reageert het scherm helemaal niet meer, houd het wieltje dan 10 seconden ingedrukt: na twee piepjes start de module opnieuw.

## 7. Het scherm zegt *Batterij bijna leeg* of *laad nu op*

De USB-voeding is los of de adapter zit niet in het stopcontact. Sluit hem weer aan; de module meet gewoon verder. Bij *Batterij leeg* stopt de module tot de voeding weer aangesloten is. Hoe vol de batterij is en hoe lang hij nog meegaat, ziet u in het menu onder **Batterij**.

## 8. Het scherm toont weer de QR-code met *Scan met app*

De module is zijn koppeling kwijt, bijvoorbeeld na een wifi-reset (vraag 3) of omdat de onderzoeker hem heeft vrijgegeven. Scan de QR-code opnieuw in de app, of neem contact op als u dat niet verwachtte.

## 9. Hoe kalibreer ik de CO₂-sensor?

Alleen als de onderzoeker daarom vraagt, vóór het koppelen, en één keer:

1. Leg de module buiten in de open lucht, zonder USB-kabel, terwijl het scherm de QR-code toont.
2. Houd het wieltje 5 seconden ingedrukt. Het scherm vraagt *Ligt de module buiten, in de open lucht?*
3. Draai het wieltje binnen 30 seconden omlaag. Na een piep meet de module minstens 8 minuten (hooguit een half uur); laat hem liggen tot het scherm *Gekalibreerd* meldt.

## 10. Wat staat er in het menu?

Druk het wieltje aan de zijkant in. Met het wieltje omhoog en omlaag kiest u, met indrukken opent u:

- **Smartphones**: telefoons aanmelden of verwijderen (vraag 4).
- **Status**: naam en versie van de module, het wifinetwerk, wanneer er voor het laatst is verstuurd, hoeveel metingen nog wachten, en de CO₂-kalibratie.
- **Batterij**: spanning, lading, of de voeding is aangesloten en hoe lang de batterij nog meegaat.
- **Nu meten**: de module meet en verstuurt meteen, bijvoorbeeld na een wijziging van het wifinetwerk.
- **Scherm verversen**: tekent het scherm volledig opnieuw (vraag 6).
- **Info**: een QR-code naar deze handleiding.
- **Wifi opnieuw**: de module vergeet het wifinetwerk en toont de QR-code (vraag 3). U moet dit bevestigen.
- **Herstarten**: de module start opnieuw. U moet dit bevestigen.
- **terug**: terug naar de metingen. Dat gebeurt ook vanzelf na 2 minuten.

## 11. Waar vind ik technische informatie?

De broncode staat op GitHub: [needforheat-living-room-module-firmware](https://github.com/energiegedrag-nl/needforheat-living-room-module-firmware).

## Andere vragen?

Neem contact op met de organisatie die uw meetcampagne uitvoert; de contactgegevens staan onder **Info** in de NeedForHeat-app.
