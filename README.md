# NeedForHeat Living Room Module Firmware for the M5CoreInk and SCD41
This repository contains source code and binary releases for firmware for an M5Stack CoreInk device that measures CO₂ concentration, temperature and relative humidity via a connected Sensirion SCD41 sensor and occupancy (i.e. the number of smartphones of participating subjects) via Bluetooth name requests.

> **Own deployment.** This repository is maintained by [energiegedrag-nl](https://github.com/energiegedrag-nl) and deployed under `energiegedrag.nl`. To run your own instance, replace `energiegedrag-nl` by your GitHub organisation and `energiegedrag.nl` by your domain (hosts used: `api.<domain>`, `manuals.<domain>`), consistently in configuration and build settings.

![NeedForHeat Living Room Module hardware installed](./docs/manuals/installation/assets/device-installed.jpg)

## Table of contents
* [General info](#general-info)
* [Measurements](#measurements)
* [Deploying](#deploying)
* [Developing](#developing)
* [Required hardware](#required-hardware) 
* [Supported devices](#supported-devices)
* [Features](#features)
* [Status](#status)
* [License](#license)
* [Citation](#citation)
* [Credits](#credits)

## General info
This measurement device can be seen as a followup and combination of two devices that were developed earlier in the Twomes project:
- [twomes-temp-monitor-hardware](https://github.com/energietransitie/twomes-temp-monitor-hardware) with [twomes-co2-monitor-hardware](https://github.com/energietransitie/twomes-co2-monitor-hardware) running  [twomes-room-monitor-firmware](https://github.com/energietransitie/twomes-room-monitor-firmware);
* [twomes-opentherm-monitor-firmware](https://github.com/energiegedrag-nl/twomes-opentherm-monitor-firmware) running [twomes-opentherm-monitor-firmware](https://github.com/energiegedrag-nl/twomes-opentherm-monitor-firmware), with presence detection enabled.

For the Brains4Buildings project, we developed an integrated solution that was used for measurements in utility buildings. For the REDUCEDHEATCARB project, we finetuned this solution for measurements in residential buildings.
 
 ## Measurements
 The NeedForHeat Living Room Module, in addition to [generic data sent by any NeedForHeat measurement device](https://github.com/energiegedrag-nl/needforheat-generic-firmware#readme), sends data about the following additional properties via the [NeedForHeat API]([https://github.com/energiegedrag-nl/needforheat-server-api](https://github.com/energiegedrag-nl/needforheat-server-api)) to a NeedForHeat server:

| Sensor | Property           | Unit | [Printf format](https://en.wikipedia.org/wiki/Printf_format_string) | Default measurement interval \[h:mm:ss\] | Description                            |
|--------|--------------------|------|--------|-------------------|----------------------------------------|
| [SCD41](https://sensirion.com/products/catalog/SCD41/)  | `co2__ppm` | ppm  | %u     | 0:10:00           | CO₂ concentration                      |
| [SCD41](https://sensirion.com/products/catalog/SCD41/)  | `rel_humidity__0` | RH  | %.3f   | 0:10:00           | Relative humidity (1.00 = 100%)                      |
| [SCD41](https://sensirion.com/products/catalog/SCD41/)  | `temp_in__degC`         | °C   | %.1f   | 0:10:00           | Air temperature                        |
| Bluetooth  | `occupancy__p`         | [-]   | %u   | 0:10:00           | number of smartphones responding to Bluetooth name request                        |

This data can be analyzed to determine changes in the ventilation ratio of a room, which enables research into the accuracy of learning the thermal characteristics of residential buildings via a dynamic heat balance model.

## Deploying
To deploy this software, see the [deploying section in the needforheat-generic-firmware library documentation](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/docs/deploying/prerequisites.md). The firmware needed can be found as a [release from this repository](https://github.com/energiegedrag-nl/needforheat-living-room-module-firmware/releases).

## Developing
To develop software for, or based on this software, see the [developing section in the needforheat-generic-firmware library documentation](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/docs/starting/prerequisites.md)

### Required hardware
You need:
* an [ESP32](https://en.wikipedia.org/wiki/ESP32) device.
* an [SCD41 sensor](https://sensirion.com/products/catalog/SCD41/) connected as follows:
    
    | ESP32 device    | SCD41 sensor |
    |-----------------|--------------|
    | GND             | GND          |
    | 5V out          | VCC          |
    | G25             | SDA          |
    | G26             | SCL          |

## Supported devices
This firmware was developed for and tested on the following devices.

For the [ESP32](https://en.wikipedia.org/wiki/ESP32) device:

- [M5Stack CoreInk](https://github.com/m5stack/M5-CoreInk)

For the [SCD41 sensor](https://sensirion.com/products/catalog/SCD41/):

- [Seeed Grove SCD41 module](https://www.seeedstudio.com/Grove-CO2-Temperature-Humidity-Sensor-SCD41-p-5025.html) mounted inside a an [M5Stack Proto HAT](https://docs.m5stack.com/en/hat/hat-proto), 
- [M5Stack CO2L unit (SCD41)](https://docs.m5stack.com/en/unit/co2l)


## Features

Ready:
* Measure and upload properties according to the to the [table above](#general-info).
* support the [M5Stack CO2L unit (SCD41)](https://docs.m5stack.com/en/unit/co2l) or the [Seeed Grove SCD41 module](https://www.seeedstudio.com/Grove-CO2-Temperature-Humidity-Sensor-SCD41-p-5025.html), connected via the [CoreInk-HY2.0 4P Port](https://docs.m5stack.com/en/core/coreink).

## Status
Project is: _in progress_

## License
This software is available under the [Apache 2.0 license](./LICENSE), Copyright 2022 [Research group Energy Transition, Windesheim University of Applied Sciences](https://windesheim.nl/energietransitie) 

## Citation

If you use this repository in your research or work, please cite the following pre-print, which describes the overall NeedForHeat DataGear system of which this repository is a part:

> Ter Hofte, H., & van Ravenzwaaij, N. (2025). *NeedForHeat DataGear: An Open Monitoring System to Accelerate the Residential Heating Transition*. arXiv preprint arXiv:2509.06927. https://doi.org/10.48550/arXiv.2509.06927

**Note:** This is a pre-print submitted on 8 Sep 2025 and has not yet been peer-reviewed. For the full paper, see [https://arxiv.org/abs/2509.06927](https://arxiv.org/abs/2509.06927).

## Credits
Author:
* Henri ter Hofte · [@henriterhofte](https://github.com/henriterhofte)

This repository continues [energietransitie/needforheat-living-room-module-firmware](https://github.com/energietransitie/needforheat-living-room-module-firmware), made by the Research group Energy Transition at Windesheim University of Applied Sciences.
Thanks to the authors and contributors of the original:
* Nick van Ravenzwaaij · [@n-vr](https://github.com/n-vr)
* Sjors Smit ·  [@Shorts1999](https://github.com/Shorts1999)
* Maarten Vermeulen · [@m44rtn](https://github.com/m44rtn)
* Tristan Jongedijk · [@tristanjongedijk](https://github.com/tristanjongedijk)
* Laurens de Boer · [@Laurenz02](https://github.com/Laurenz02)
* Marco Winkelman · [@MarcoW71](https://github.com/MarcoW71)

We use and gratefully acknowlegde the efforts of the makers of the following source code and libraries:
* [ESP-IDF](https://github.com/espressif/esp-idf), by Espressif Systems, licensed under [Apache License 2.0](https://github.com/espressif/esp-idf/blob/9d34a1cd42f6f63b3c699c3fe8ec7216dd56f36a/LICENSE)
* [needforheat-generic-firmware](https://github.com/energiegedrag-nl/needforheat-generic-firmware), by [Research group Energy Transition, Windesheim University of Applied Sciences](https://windesheim.nl/energietransitie), licensed under [Apache License 2.0](https://github.com/energiegedrag-nl/needforheat-generic-firmware/blob/main/LICENSE.md)

### AI assistance

Since November 2026, parts of the maintenance of this repository have been done with [Claude Code](https://claude.com/claude-code) (Anthropic), under the author's direction and review. Commits made this way carry a `Co-Authored-By: Claude …` trailer. The author remains responsible for all content.
