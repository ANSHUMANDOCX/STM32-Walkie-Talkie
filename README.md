
# STM32 LoRa Walkie-Talkie

A custom walkie-talkie built on a bare STM32F411RET6 microcontroller and SX1278 LoRa radio module, designed from scratch in KiCad with a fully custom PCB.

---
## Inspiration
I made this STM32 Walkie Talkie to learn about STM32 since i have never worked with The ST chips and LoRa hence i though of it as a good opportunity for me to learn about these and make a good project out of it too. Also it gives me a chance to perfect wireless radio skills.
## Hardware 

| Component | Part | Purpose |
|---|---|---|
| MCU | STM32F411RET6 (LQFP-64) | Main processor |
| LoRa radio | Ra-02 (SX1278, 433 MHz) | Wireless communication |
| Mic amp | MAX9814 | Electret microphone amplifier with AGC |
| Speaker amp | MAX98357A | I2S class-D speaker amplifier |
| Display | Nokia 5110 (PCD8544) | Status display |
| LDO | MIC5219-3.3 | 3.3V regulation |
| Charger | TP4056 | Li-Ion battery charging |
| Protection | DW01A + AO3401A + FS8205 | Battery over/under voltage protection and Load sharing |
| Battery | 18650 Li-Ion (2500mAh) | Power source |

---

## Features

- Push-to-talk (PTT) voice transmission over LoRa
- Nokia 5110 display showing TX/RX status, RSSI, battery %, charging state
- LED indicators for TX and RX
- PWM buzzer with distinct tones for PTT, incoming call, low battery, charging complete etc
- Battery percentage via voltage divider on ADC
- Load sharing circuit — runs on USB power while charging battery
- TP4056 charging status readable by firmware
- SWD debug header for ST-Link V2 programming
- When USB is connected the system runs off USB directly and the battery charges independently. When USB is removed the load sharing circuit seamlessly switches to battery power.

---
Firmware us teseted and works fine
## Build 

Demo Links -
https://youtu.be/u5zcdfWUoc0?si=na0F3SUNMQuTFcsV
https://youtube.com/shorts/hGkoWbwqjJw?si=Fj_72HcpeDVytp3i
https://youtube.com/shorts/hm_hJY4Z-SY?si=CA80bZE5GAXgrqjr
https://youtu.be/_cB_pIMBPP0?si=Omx-B7MlO4rouQgG
https://youtu.be/SAzjPhdUsmI?si=3dBDZw_p-0JPJG1Q

<img width="3456" height="4608" alt="IMG_20260625_101636" src="https://github.com/user-attachments/assets/df3d3397-d68b-4416-8dab-bfe9c90557e1" />
<img width="4608" height="3456" alt="IMG_20260625_101016" src="https://github.com/user-attachments/assets/68a22f2d-6d18-470e-9d6f-a26c0279cde0" />
<img width="4608" height="3456" alt="IMG_20260625_101017" src="https://github.com/user-attachments/assets/04d49105-2259-4b49-82de-13e13cfc0c0e" />
<img width="4608" height="3456" alt="IMG_20260625_101018" src="https://github.com/user-attachments/assets/2ec3a8c0-af16-486f-b0e4-2601123c00bf" />
<img width="4608" height="3456" alt="IMG_20260625_101032" src="https://github.com/user-attachments/assets/9037975f-5230-4d70-ad04-1fb7487007c4" />
<img width="4608" height="3456" alt="IMG_20260625_101032_1" src="https://github.com/user-attachments/assets/a8e3b9c6-5a67-461a-8229-d762ec640cdb" />
<img width="3456" height="4608" alt="IMG_20260625_101624" src="https://github.com/user-attachments/assets/8cef2daf-2d98-4504-a609-c03277f2a032" />
<img width="3456" height="4608" alt="IMG_20260625_101626" src="https://github.com/user-attachments/assets/4545f5ae-e259-4455-9ae3-875ae953e1c7" />
<img width="3456" height="4608" alt="IMG_20260625_101628" src="https://github.com/user-attachments/assets/00244cd5-1544-423f-a682-78349dd33bfe" />
<img width="3456" height="4608" alt="IMG_20260625_101637" src="https://github.com/user-attachments/assets/bb8f1e0c-af1d-48e3-83c4-d24f31d7f35e" />


## Schematic PCB and CAD

<img width="1208" height="822" alt="Screenshot 2026-04-30 003322" src="https://github.com/user-attachments/assets/c65cc2bd-f71e-4ee8-b58e-ab76edce7230" />

<img width="1029" height="843" alt="Screenshot 2026-05-01 000935" src="https://github.com/user-attachments/assets/9bbbd3f1-566b-4bb3-9077-8e2804468dda" />

<img width="1131" height="753" alt="Screenshot 2026-05-03 001440" src="https://github.com/user-attachments/assets/4f0b5166-7114-4b6e-94d1-cec0e3c91082" />

## BOM

| Product Name       | Part / Model         | Qty | Unit Price ($) | Total ($) | Vendor  | Link |
|-------------------|----------------------|-----|----------------|-----------|---------|------|
| 8MHz SMD Crystal  | X32258MOB4SI         | 2   | 0.08           | 0.15      | ROBU    | https://robu.in/product/x32258mob4si-yxc-crystal-oscillators-8mhz-surface-mount-crystal-12pf-%c2%b110ppm-%c2%b120ppm-smd3225-4p-crystals-rohs |
| STM32 MCU         | STM32F411RET6        | 2   | 2.88           | 5.76      | ROBU    | https://robu.in/product/stm32f411ret6-stmicroelectronics-3-6v-32-bit-risc-512kb-flash-arm-cortex-m4-mcu-dsp-fpu-art-accelerator-64-pin-lqfp |
| Push Button       | DS-316 SPST          | 2   | 0.12           | 0.24      | ROBU    | https://robu.in/product/ds-316-mini-push-button-switch-spst-2pinoff-on |
| IPEX to SMA Cable | RG178 15cm           | 2   | 1.60           | 3.20      | ROBU    | https://robu.in/product/15cm-ipex1-to-sma-female-connector-cable-11mm-rg178 |
| Mic Amplifier     | MAX9814ETDT          | 2   | 2.87           | 5.74      | ROBU    | https://robu.in/product/max9814etdt-analog-devices-microphone-amplifier-2-7-v-to-5-5-v-supply-1-ma-out-40-db-50db-60db-gain-tdfn-14 |
| Speaker AMP       | MAX98357A            | 2   | 2.37           | 4.73      | ROBU    | https://robu.in/product/1-month-warranty-560 |
| LoRa Module       | SX1278 RA-02         | 2   | 3.74           | 7.48      | ROBU    | https://robu.in/product/sx1278-lora-module-ra-02-433mhz-wireless-spread-spectrum-transmission |
| JST Connector     | 8-pin XH 2.54mm      | 2   | 0.77           | 1.55      | ROBU    | https://robu.in/product/8-pin-jst-xh-2-54mm-pitch-plug-and-socket-with-cable-3pcs |
| Speaker           | 8Ω Small Speaker     | 2   | 0.75           | 1.51      | Generic | https://sharvielectronics.com/product/speaker-8-ohm-trumpet-diameter-40mm-2-watt/ |
| Microphone        | Electret Mic Capsule | 2   | 0.11           | 0.22      | Generic | https://inkocean.in/products/microphones-9767-9-7-electret-microphone-a-microphone-with-pins-sensitivity-58 |
| Display           | Nokia 5110 LCD       | 2   | 3.01           | 6.02      | Generic | https://inkocean.in/products/nokia-5110-lcd-red-screen-blue-lcd-screen-module |
|HeatSet Insert Attatchment||1|6.2|6.2|Amazon|https://www.amazon.in/amiciTools-Heat-Insert-Soldering-Printing/dp/B0GFDZ5GL9/ref=asc_df_B0GFDZ5GL9?mcid=fe31e451fd45349b9016d36cd31d3876&hvadid=709875643605&hvpos=&hvnetw=g&hvrand=10961091970810594313&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1007828&hvtargid=pla-2466325763035&psc=1&hvocijid=10961091970810594313-B0GFDZ5GL9-&hvexpln=0|
| Passives          | SMD passives         | 1   | 5.38           | 5.38      | —       | — |
| PCB               | —                    | 1   | 3.00           | 3.00      | ALLPCB  | — |
| **TOTAL** |  |  |  | **44.98** |  |  |
