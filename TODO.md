# TODO – needforheat-living-room-module-firmware

Open work for this repository, distilled from the old NeedForHeat Trello board, including the discussions on the cards (paraphrased and regrouped) and from the 2026 maintenance review.

Items that touch several repositories are written out in full in one *lead* repository; the others list them with a link (→). Keep the details up to date in the lead repository only.

## Now: needed to run at home this winter

- [ ] <a id="hwtest"></a>**Hardware test of v3.4.0 on the living room module.** Erase and flash over USB (new partition table), install the new APK, scan the `NFH:` QR code, choose test or production server, and check: provisioning steps on screen, activation, uploads, the overview screen after the first measurement, the presence menu (no ghosting when scrolling), a readable screen after power-off, and the buffer (unplug network for hours). Then mark generic #16 ready, tag v3.4.0 and point living room #8 to that tag. Also affects: needforheat-generic-firmware, needforheat-gearup-app.
- [ ] → Release workflow without the Windesheim signing key — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#unsigned) *(Trello #480)*
- [ ] → Recover cleanly when activation fails — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#actfail) *(Trello #837)*

## Soon: robustness and correctness

- [ ] <a id="rhswap"></a>**Check humidity and temperature property mapping.** Values of `relativeHumidity` and `roomTempCO2` looked swapped in earlier data. Check the mapping in the firmware and fix it if needed. If old data is affected, correct it during preprocessing rather than in the stored data. *(Trello #283)*
- [ ] <a id="lrmgaps"></a>**Investigate data gaps of the living room module.** Some modules had gaps or a clock that did not sync with NTP. Re-check with v3.3.0 (no reboot on outage, plausible timestamps). Known causes: 1970 timestamps when NTP fails, 2036 when the RTC lost all power. Also affects: needforheat-generic-firmware. *(Trello #1024)*
- [ ] → Make OTA updates trustworthy and staged — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#ota) *(Trello #347, #770)*
- [ ] → Upgrade to ESP-IDF 5.5 (WPA3, Wi-Fi 6) — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#idf) *(Trello #806)*
- [ ] → Let generic and device-specific code share buttons — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#buttons) *(Trello #833)*
- [ ] → Provisioning after a Wi-Fi reset fails if a measurement interrupts it — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#provint) *(Trello #891)*
- [ ] → Show device status on the e-ink screen — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#einkstatus) *(Trello #303, #867, #1218, #499)*
- [ ] → Stable Bluetooth presence detection — see [needforheat-presence-detector-firmware](https://github.com/energiegedrag-nl/needforheat-presence-detector-firmware/blob/main/TODO.md#btstab) *(Trello #222, #769)*
- [ ] → Use the ESP-IDF certificate bundle — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#crtbundle)

## Later: features and ideas

- [ ] <a id="scd41"></a>**SCD41 improvements.** Detect automatically whether the SCD41 is on a CO2L unit or a Proto HAT; consider single-shot or always-on mode; save energy on battery by sleeping between measurements and switching Wi-Fi on only to upload (mains power remains the recommendation). *(Trello #802, #411, #362)*
- [ ] → E-ink screen glitches — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#einkfix) *(Trello #860, #862, #870, #686, #996, #822, #363)*
- [ ] → Finish the rename from Twomes to NeedForHeat — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#rename) *(Trello #1030)*
- [ ] → CONTRIBUTING.md with the branching workflow — see [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/TODO.md#contrib) *(Trello #394, #1032)*
- [ ] → Register phones for presence detection — see [needforheat-server-api](https://github.com/energiegedrag-nl/needforheat-server-api/blob/main/TODO.md#bt) *(Trello #104, #117, #863, #576)*
- [ ] → Fix links and errors in device manuals — see [needforheat-manuals](https://github.com/energiegedrag-nl/needforheat-manuals/blob/prd/TODO.md#manlinks) *(Trello #718, #995, #719)*

## Recently done

- [x] Persistent buffer partition and server choice, built against generic v3.4.0-rc (#7)
