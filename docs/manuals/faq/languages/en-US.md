# Living room module - frequently asked questions

## 1. What does the living room module measure?

Every 10 minutes:

- the CO₂ concentration;
- the temperature;
- the humidity;
- how many registered smartphones are at home (see question 4).

It also reports the battery voltage, to see whether the power supply is connected.

## 2. What is on the screen?

- **Top**: Wi-Fi, the date and the battery (a lightning bolt: on power).
- **Middle**: the CO₂ concentration in ppm; below it temperature, humidity and the number of people present.
- **Bottom**: a cloud with a tick and the time the latest measurements were sent. A crossed-out cloud with *N metingen* means those measurements have not been sent yet; the module keeps them and sends them later.

The screen refreshes with every measurement, so the numbers are at most 10 minutes old.

## 3. How do I connect the module to Wi-Fi again?

For example after a new router or a new Wi-Fi password:

1. Hold the button on top of the module for 10 seconds, until the green light blinks 5 times.
2. Release it. The module restarts and shows the QR code with **Scan met app**.
3. Scan that QR code in the NeedForHeat app and follow the app.

Earlier measurements are kept.

## 4. How do I make smartphones count?

The module counts people by checking which registered smartphones are nearby. At the start, register your own smartphone and that of each housemate once; the neighbours' phones then do not count.

1. Press the black dial on the side. You see **SMARTPHONES:**.
2. Choose **+ toevoegen** and press the dial.
3. On the smartphone, go to **Settings > Bluetooth**, switch Bluetooth on and tap **NeedForHeat_OK** as soon as it appears.
4. A beep confirms the pairing; the smartphone's name appears in the list on the screen.

If it does not work at once, try again.

To remove a smartphone: scroll to its name with the dial, press and confirm. **terug** leaves the menu; after 2 minutes without using the dial the module returns to the measurements by itself.

## 5. Does Bluetooth have to stay on?

Yes, on the registered smartphones, for the whole measurement period. Nothing else is needed: the smartphone does not stay connected, the module sees it anyway. Bluetooth hardly uses any battery nowadays.

How it works: now and then the module sends a [Bluetooth name request](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/src/presence_detection/README.md#general-info) to the registered smartphones.

## 6. The screen has light or dark marks

That is caused by sunlight or bright light on the e-ink screen. Press the dial and choose **terug**: the screen is then fully redrawn.

## 7. The screen says *Batterij bijna leeg* or *laad nu op*

The USB power is disconnected or the adapter is not in the socket. Connect it again; the module keeps measuring. With *Batterij leeg* the module stops until power is connected again.

## 8. The screen shows the QR code with *Scan met app* again

The module has lost its pairing, for example after a Wi-Fi reset (question 3) or because the researcher released it. Scan the QR code again in the app, or contact us if you did not expect this.

## 9. How do I calibrate the CO₂ sensor?

Only when the researcher asks for it, before pairing, and once:

1. Put the module outside in the open air, without the USB cable, while the screen shows the QR code.
2. Hold the dial pressed for 5 seconds. The screen asks *Ligt de module buiten, in de open lucht?*
3. Turn the dial down within 30 seconds. After a beep the module measures for at least 8 minutes (at most half an hour); leave it until the screen reports *Gekalibreerd*.

## 10. Where can I find technical information?

The source code is on GitHub: [needforheat-living-room-module-firmware](https://github.com/energiegedrag-nl/needforheat-living-room-module-firmware).

## Other questions?

Contact the organisation that runs your measurement campaign; the contact details are under **Info** in the NeedForHeat app.
