# STM32 Walkie Talkie

This is a STM32 Walkie Talkie made using LoRa along with a display

# 2026-05-02: more cad

**Total time spent: 0.5 hours**

Added hte cutouts for putting the LEDs for getting all the status clearly
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MzIwLCJwdXIiOiJibG9iX2lkIn19--cb2877efad6f3c85d140dd76ba6f487f26922dc4/image.png)

# 2026-05-02: CAD part 3

**Total time spent: 0.5 hours**

Added the cutouts for the PTT button Antenna along with the charging with type C. Also added chamfers for using counter sunk scrw to make it look better from the outside 
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MzA0LCJwdXIiOiJibG9iX2lkIn19--a069c0b1916eed69457d3b73362f87485fbcc3ec/image.png)![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MzA1LCJwdXIiOiJibG9iX2lkIn19--1354063101c8a5d7106b949f3b19e6aa7cb90e47/image.png)![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MzA2LCJwdXIiOiJibG9iX2lkIn19--0064ca3ff7e57f4b0bb9c3e609cac14caefc82e1/image.png)

# 2026-05-02: Cad part 2

**Total time spent: 2 hours**

designed the top portion of the design i designed a mesh for the speaker also perfecting the positioning such that everything fits together took some time but eventually got to it 
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6Mjk4LCJwdXIiOiJibG9iX2lkIn19--324c5273a79421210ac8b8c21765c2db7dccd145/image.png)

# 2026-05-01: CAD work

**Total time spent: 3 hours**

Starte out by figuring out how the actual thing is gonna look and came up with the initial cad desogn and will work my self up setting this as the base line
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjkwLCJwdXIiOiJibG9iX2lkIn19--f4153ed5a81993464a97de2619febfe7b249c4a0/image.png)

# 2026-04-30: More changes on PCB

**Total time spent: 1 hour**

Added the Silkscreen for the connectors status leds and etc along with resolving all the DRC errors
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjgwLCJwdXIiOiJibG9iX2lkIn19--94f75c27be6a845da8cda52f943355bf772054d1/image.png)

# 2026-04-30: Designed the Layout

**Total time spent: 2 hours**

Completed the first phase of routing all the traces i am trying to stick to 2 layers only to keep the costs down.
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6Mjc0LCJwdXIiOiJibG9iX2lkIn19--f29126752e2a9376d48f84a24a23a6e2c15fe2a6/image.png)

# 2026-04-29: PCB step 1

**Total time spent: 2 hours**

Assigned all the components with their respective footprints along with arranging the components to on board to their respective position for the current best wirings might change in the future but i have arranges it such that i can have all the other components as detachable so i had to place the JST pins at the edge of the case i currently am using the 6p variant of the type c connector but in the future i might change it to make the usb port more accessible in case i face some difficulty designing the body of the walkie
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjU4LCJwdXIiOiJibG9iX2lkIn19--843bb19db429465e1e24f31a1698e55f2544bc71/image.png)

# 2026-04-29: Schematic changes 

**Total time spent: 1 hour**

I added a few more pins for push to talk and a voltage divider for reading the battery level and display it so i had to once again modify the stm32 cube mx by defining more pins along with cleaning up the schematic and make it look better and pretty so its clearer to read and understand.
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjU2LCJwdXIiOiJibG9iX2lkIn19--df4501b1c9841fc123f8b732c61e52d71085478c/image.png)![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjU3LCJwdXIiOiJibG9iX2lkIn19--274c3aa27cb4171f26f51c50c5fd48b4eba83b09/image.png)

# 2026-04-29: Power Circuit

**Total time spent: 0.5 hours**

Made the Power circuit of the Board added the tp4056 along with the connection of the rest of hte protection circuit along with adding the 3.3v regulator ic 
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjUyLCJwdXIiOiJibG9iX2lkIn19--aab2177dc5f25cc59a0ea28ef71851f0c0d66874/image.png)

# 2026-04-29: Pin Assignment and more

**Total time spent: 2 hours**

I modified the STM32 pin configurations for my purposes along with adding the crystal Oscillator circuit along with some change of plans of using teh mcp73831 ic for charging i will using the good old TP4056 since i would like to have 2 output pins from the charging IC to display on the LCD about the status however will continue the wiring later
also completed the wiring to crystal oscillator by reading the AN2867 refence sheet by ST
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjExLCJwdXIiOiJibG9iX2lkIn19--a07354728b19d6410020249359c24fd5f2ee50aa/image.png)![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjEyLCJwdXIiOiJibG9iX2lkIn19--85aeb3f791800a299fceb15ba1d0a3cac3a51285/image.png)

# 2026-04-28: working more on the system

**Total time spent: 1.5 hours**

made a symbol for the LCD module along with figuring out the power requirements of the walkie talkie
i will be using 1s li-ion battery to power the circuit of 2500mah capacity and it will give a total of about 20 hrs of backup and the power regulation will be done using MIC5219 3.3 and the battery ill be charged using MCP73831 and paired with the usual FS8205A along with DW01A ic 
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTkwLCJwdXIiOiJibG9iX2lkIn19--0802b2c4557f4832d05d18bd75f8f9d43b389c94/image.png)![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTkxLCJwdXIiOiJibG9iX2lkIn19--df3757ff8c7353ecaa466b4d54936a34169b9a5b/image.png)![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTkyLCJwdXIiOiJibG9iX2lkIn19--27a81be4344ea885c239ac13614bcba6f8591bac/image.png)

# 2026-04-28: Made the Basic Required for peripherals 

**Total time spent: 1.5 hours**

Made the Basic and required circuit for both the mic and Speaker Amp along with pin assignment of the lora module had to read the data sheet of the MAx9814 and Max98357a ics and make the circuit
![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTg0LCJwdXIiOiJibG9iX2lkIn19--f8316d8fe49fd1cabeb46f21a9176d2c96b1c279/image.png)

# 2026-04-27: Completed peripheral assignment

**Total time spent: 1.5 hours**

Used STM32CubeMX to assign the peripheral and update the schematic according to that 
![Screenshot 2026-04-28 011553.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTY1LCJwdXIiOiJibG9iX2lkIn19--5df627cbfd1ac3f2331aa5e6ae83c7c5453ebee0/Screenshot%202026-04-28%20011553.png)![Screenshot 2026-04-28 010639.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTY2LCJwdXIiOiJibG9iX2lkIn19--9673506119dfeda0bb3510e6c9680ae893de0c5f/Screenshot%202026-04-28%20010639.png)

# 2026-04-27: Started Out with the Schematic

**Total time spent: 8 hours**

So its my first time working with STM32 so i had to learn a lot about everything as how it work what it is etc along with what is the minimum circuit and everything else and completely understand what is needed to be done exactly so it went on a number of days few hours each and finally after watching videos and tutorials i came up with this basic circuit to atleast get the board booted up 
I didnt want to randomly get make a circuit by copying a circuit online i wanted to learn so i could make anything i want without any problem also my first chip that i chose to work on is STM32F411RET6 its just the best combo of powerful enough for a walkie talkie and at the same time cheap next up i will be working on the peripherals i need to add to it using stm32cubemx

another thing done is to plan out exactly what i need in my walkie talkie here is what i will use 
- STM32 as the main brain
- SX1278 as the radio module
- MAX9814 as the mic amp 
- MAX98357A as the speaker amp

![image.png](https://forge.hackclub.com/rails/active_storage/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTYzLCJwdXIiOiJibG9iX2lkIn19--63c6e5980db1f56fbe2206d75914813ed2708efc/image.png)

