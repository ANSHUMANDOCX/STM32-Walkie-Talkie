# STM32 Walkie Talkie

This is a STM32 Walkie Talkie made using LoRa along with a display

# 2026-06-25: Finally Finished the Build 

**Total time spent: 2 hours**

Completed everything and got it to working tbh the audio was a real pain in the ass but unfortuanatley i couldnt document most of it since lapse didnt work for me so here are the images for teh final build along with videos 
![IMG_20260625_101636.jpg](https://cdn.hackclub.com/019efef0-a1de-7cb9-9977-019797b8d593/IMG_20260625_101636.jpg)![upload failed]()
![IMG_20260625_101015.jpg](https://cdn.hackclub.com/019efef1-44fb-7912-b808-6aeaea748026/IMG_20260625_1![IMG_20260625_101032.jpg](https://cdn.hackclub.com/019efef1-67ae-757e-be40-d37db09e74fb/IMG_20260625_101032.jpg)01015.jpg)![IMG_20260625_101032_1.jpg](https://cdn.hackclub.com/019efef1-7dc6-7ecc-8164-b41faeb04c72/IMG_20260625_101032_1.jpg)
![IMG_20260625_101637.jpg](https://cdn.hackclub.com/019efef2-2612-7659-9ff6-af80baee3c83/IMG_20260625_101637.jpg)


https://youtube.com/shorts/hm_hJY4Z-SY
https://youtu.be/u5zcdfWUoc0
https://youtu.be/_cB_pIMBPP0
https://youtu.be/SAzjPhdUsmI

# 2026-06-15: Fixed something

**Total time spent: 2 hours**

So turns out that i mistakenly connected the SD_MODE pin to gnd which makes me unable to use the max98357a chip since it puts it in shutdown mode hence i was not able to get audio from the board so i had to fix it 
![WhatsApp Image 2026-06-13 at 3.41.24 AM.jpeg](https://cdn.hackclub.com/019ebde4-9a22-729f-9c7a-af567911dc4c/WhatsApp%20Image%202026-06-13%20at%203.41.24%20AM.jpeg)

https://drive.google.com/file/d/1RYz1zenMPdUlElBWGs8loo9nA_OZWOdw/view?usp=sharing
https://drive.google.com/file/d/1XLs72No94m9BtLRIj_NSfTIpqdl90QST/view?usp=sharing
https://drive.google.com/file/d/1As7aIU_MWxT8NN-wxcKUihXpjubRkdP7/view?usp=sharing
https://drive.google.com/file/d/17ajN9sY42p0L8XeJT29g89JmJUFEaXck/view?usp=sharing
https://drive.google.com/file/d/1ncQTPaGTxEyMPp-1-ogzvb6ysDnspMs6/view?usp=sharing
https://drive.google.com/file/d/1AObo_ik-ZW1c3DhkKxW510I5hENpIdJg/view?usp=sharing

here is some footage from my microscope of me trying to fix it by bypassing the gnd and connecting it back to 

# 2026-06-15: Got The LoRa working 

**Total time spent: 0.5 hours**

Got the two boards to communicate with each other a simple sending hello to the other board along with reading the rssi value which shows the strength of the connection 
![WhatsApp Image 2026-06-12 at 8.41.43 AM (2).jpeg](https://cdn.hackclub.com/019eb9e0-1e78-7c94-ac46-41209ad215c9/WhatsApp%20Image%202026-06-12%20at%208.41.43%20AM%20(2).jpeg)![WhatsApp Image 2026-06-12 at 8.41.43 AM (1).jpeg](https://cdn.hackclub.com/019eb9e0-2fa2-7c40-b4f7-9866548befb3/WhatsApp%20Image%202026-06-12%20at%208.41.43%20AM%20(1).jpeg)

# 2026-06-15: More on the hardware part

**Total time spent: 0.5 hours**

Connected everything hardware with the Board had to make a few just connectors for everything it was my first time crimping jst pins initially crimping it properly was a bit of a challenge. but got over it finally 
![WhatsApp Image 2026-06-12 at 8.41.44 AM.jpeg](https://cdn.hackclub.com/019eb9d9-fcd7-78e0-9b0c-89fc9021efb3/WhatsApp%20Image%202026-06-12%20at%208.41.44%20AM.jpeg)![WhatsApp Image 2026-06-12 at 8.41.43 AM.jpeg](https://cdn.hackclub.com/019eb9da-07f3-7a5a-bb36-7211d973835c/WhatsApp%20Image%202026-06-12%20at%208.41.43%20AM.jpeg)

# 2026-06-15: Got the LED to Blink and LCD test

**Total time spent: 1 hour**

Finally got the LED to blink turnsout there was a project error in the IDE since i was opening the code from CubeMX in an already existing project so i couldnt upload and got the LED to blink also i interfaced the LCD and got it to write a message too. 
![IMG_20260606_233744.jpg](https://cdn.hackclub.com/019ea054-7c09-702f-8028-7a6d7c42d304/IMG_20260606_233744.jpg)
![IMG_20260606_233745.jpg](https://cdn.hackclub.com/019ea054-6c45-7640-b266-fdfa493bc09c/IMG_20260606_233745.jpg)
![IMG_20260607_005715.jpg](https://cdn.hackclub.com/019ea058-1e1b-7251-ae72-6b415c8527c7/IMG_20260607_005715.jpg)

# 2026-06-15: Completed PCB Assembly 

**Total time spent: 7 hours**

Completed the pcb messed up mid way but fianlly got it to work 

1. Setting up the Stencil - 20min

Not very difficult just the usual masking tape multiple pcbs center alignment etc had to do for 2 boards since its a walkie - talkie 
![IMG_20260606_112105.jpg](https://cdn.hackclub.com/019e9d15-4d81-7bcf-8656-9cf1a1fdc279/IMG_20260606_112105.jpg)
![IMG_20260606_112323.jpg](https://cdn.hackclub.com/019e9d15-3683-7a2a-ae35-35b38d42a4d4/IMG_20260606_112323.jpg)
![IMG_20260606_112329.jpg](https://cdn.hackclub.com/019e9d15-0922-7244-ad2d-b74aafd703ca/IMG_20260606_112329.jpg)

2. Paste application - 10min

Applied the paste the usual 90 degree 45 degree and a pvc card 
![IMG_20260606_142705.jpg](https://cdn.hackclub.com/019e9d16-7faa-7101-a7f2-2dfe94c1b61a/IMG_20260606_142705.jpg)

3. Component placement + Reflow + Touchups + Cleanup - 2.5hr

this part is the most lengthy and tedious one more over i had to do it for 2 boards so it took twice as long as it should have 
![IMG_20260606_142750.jpg](https://cdn.hackclub.com/019e9d19-efab-7226-967f-50e080b59502/IMG_20260606_142750.jpg)![IMG_20260606_142730.jpg](https://cdn.hackclub.com/019e9d19-f960-7ae4-adf0-613c628aa383/IMG_20260606_142730.jpg)![IMG_20260606_142739.jpg](https://cdn.hackclub.com/019e9d19-ff94-7ccb-a00d-19dc841b0d6c/IMG_20260606_142739.jpg)

4. Place the THT parts the sockets - 30mins

placed and soldered all the THT headers and the JST connectors 
![IMG_20260606_145338.jpg](https://cdn.hackclub.com/019e9d1a-bab9-7bb9-a13d-ea6cf0f4881e/IMG_20260606_145338.jpg)

5. Found out the fuckup -1.5hr 

so after all this i went to stm32 cube ide to check if everything is in order and upload a blink sketch and it showed that no device is connected so i took out my multimeter and tried checking every voltage pin boot pin to check whats wrong didnt find anything wrong nor was the chip heating up so i knew it wasn't fried atleast that gave me some relief then i looked at the chip and found out that i placed it the wrong way turns out the smaller dimple notch is pin one actualyl there were 2 so i got confused and put the chip in the orientation when the text was up it was pin 1 but it wasn't here is the error that i was getting 
![image.png](https://cdn.hackclub.com/019e9d20-7e70-7f45-b819-9682988e72a6/image.png)

5. rotating the chip+ cleanup the board  - 2 hr 

since i had alr placed the tht components i couldnt use my hot plate i had to use my hot air station and chage its orientation which it self was a pain in the ass since dureing the process the pins of one of the chip got bent so i had to remove it cleanup then use 

If you look carefully look out for the notches on the previous image and this one you will it get where i went wrong i was just lucky that the chip didnt get fried 

![IMG_20260606_175029.jpg](https://cdn.hackclub.com/019e9d24-463f-75fe-adbe-a27ac9b0ddea/IMG_20260606_175029.jpg)![IMG_20260606_175031.jpg](https://cdn.hackclub.com/019e9d24-57e6-7e3d-9e1f-9a33c5821d04/IMG_20260606_175031.jpg)
![IMG_20260606_175031.jpg](https://cdn.hackclub.com/019e9d24-59fc-75d1-aa8d-ea2596cb152e/IMG_20260606_175031.jpg)

6. finally !!

now the board was getting detected in the ide however i couldnt get the led to blink no sure why and i dodnt bother to check it then since i was very tired of doing this and my head was aching so decided to do it some other time getting it to work was the major task i would say 90% of the job. 


# 2026-06-15: lcd work

**Total time spent: 0.5 hours**

Connected the 8 pin jst to the LCD and attached it to case too my measurements were off had to file the enclosure to make the LCD fit![IMG_20260530_224443.jpg](https://cdn.hackclub.com/019e7a1d-c00b-7f3a-8577-5fe01b4aa0d7/IMG_20260530_224443.jpg)![IMG_20260530_224331.jpg](https://cdn.hackclub.com/019e7a1d-cf10-79ff-b4aa-f8c8f6d00ac0/IMG_20260530_224331.jpg)

# 2026-06-15: Got the parts and started the assembly

**Total time spent: 1 hour**

got all the parts of the walkie talkie and just assembled the hardware ones which go directly into the case. also fixed all the heatset inserts in the body messed up one of the slots but ig it will be fine.
![IMG_20260525_124738.jpg](https://cdn.hackclub.com/019e5f7b-24cc-7a93-850c-bb474b247d75/IMG_20260525_124738.jpg)
![IMG_20260525_124726.jpg](https://cdn.hackclub.com/019e5f7b-3b13-7844-bca5-33cc31bd523b/IMG_20260525_124726.jpg)
![IMG_20260525_124615.jpg](https://cdn.hackclub.com/019e5f7b-529e-751d-af1d-24d4395babe9/IMG_20260525_124615.jpg)
![IMG_20260525_124602.jpg](https://cdn.hackclub.com/019e5f7b-7b11-70d8-88bb-0a71400ac432/IMG_20260525_124602.jpg)


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

