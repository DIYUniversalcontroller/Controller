==========Universal-Controller
==========

Anleitung und Troubleshooting:

1. Funkfernbedienung testen:
	Die Funkfernbedienung wird getestet über das Programm Test_RC_Switch. Dieser Sketch ist mit dem entsprechenden Pin vordefiniert,
	mit dem auf dem Universalboard über ein RC-Link Sender Funksteckdosen gesteuert werden.
	Derzeit Wird eine Funksteckdose gesteuert, die dafür zuständig ist die Temperatur im Auquarium zwischen einer Min- und Max-Temperatur zu halten.
	Ein ungeregelter Heistab wird einfach an diese Funksteckdose eingesteckt und schaltet sich an und aus.
	
	Die default-Codierung lautet 1 0 0 0 0   5

				d.h. 1 0 0 0 0   0 0 0 0 1
				     A B C D E   1 2 3 4 5

	Dieser Code muss zuerst an der Funksteckdose genauso mit den Dip-Schaltern konfiguriert werden.
	Eine entsprechende Umcodierung muss dann im Test-Programm sowie im Universalplatinen-Sketch vorgenommen werden.

2. LCD-Adressierung:
	Die 2- oder 4-zeiligen LCDs haben vom Werk aus eine I2C-Adresse. In der Regel ist das 0x27 oder 0x3F.
	Wenn also beim anschließen des LCD und dem hochgeladenen Sketch nur ein leuchtendes Display zu erkennen ist,
	ist es oftmals ein Indiz dafür, dass die Andere Adresse verwendet werden muss.
	Hierfür bitte im Sketch nach einer der beiden Adressen suchen und gegen die jeweils andere Andresse tauschen.
	Abspeichern nicht vergessen und Sketch neu hochladen.

3. EEPROM-Clear:
	Es wird empfohlen einmal den EEPROM-Clear-Sketch hochzuladen und anschließend den Sketch hochladen. Es kann vorkommen, dass manche Register
	falsch zugeordnet werden und somit fehlerhafte Daten im Display anzeigen, die auch nicht mit dem Keybuttons geändert werden können

4. Lüfteraktivität:
	Die Lüfteraktivität kann entweder für die Temperatursteuerung des Wassers oder der LED-Lampe verwendet werden. Beides zusammen geht nicht.
	Wenn die eine Funktion aktiviert wird, wird automatisch die jeweils andere deaktiviert!

5. Anschluss der LED-Lampe:
	Um eine LED-Lampe betreiben zu können werden zusätzlich sog. Konstantstromquellen (KSQ) benötigt. Die KSQ gibt es in unterschiedlichen maximalen
	konstanten Strömen, je nachdem wieviel die verwendeten LEDs vertragen
	Die (dimmbaren) KSQ besitzen in der Regel 5 Anschlüsse: 2 Stück für den Eingang (wird mit dem Netzteil verbunden),
								2 Stück für den Ausgang (wird mit der LED verbunden),
								1 Stück für den Dim-Port (wird mit dem PWM-/Dim- Kanal der Universalplatine verbunden).

	Wichtig hierbei ist, dass die Platine mit (Ground/GND) jeweils mit selbigem Netzteil verbunden ist, damit die Dimmung funktioniert.
	In der Regel geschieht das mit der Stromversorgung der Platine (VIn), weil die ja über selbiges Netzteil verbunden ist.
	Werden mehrere Netzteile als Dimmcomputer verwendet, müssen die jeweils über Ground miteinander verbunden werden

6. Dosierpumpe:
	Die Dosierpumpenfunktionalität erlaubt maximal 8 Dosierpumpen. 4 Dosierpumpen (Kanal 1-4) werden direkt über das Board gesteuert.
	Wenn man weitere 4 Dosierpumpen (5-8) verwenden möchte, dann kann optional ein Motor-Driver Shield (Version 1) huckepack auf die Platine
	gesteckt werden auf dem wiederum weitere 4 Anschlüsse für Dosierpumpen vorhanden sind.