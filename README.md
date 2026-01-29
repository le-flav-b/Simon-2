<h1 align="center">
    <br>
    <img src="https://raw.githubusercontent.com/le-flav-b/Simon²/master/logo.png" alt="Simon²" width="150">
    <br><br>

    🎮 Simon² 🎮
</h1>


<h3 align="center">An electronic side project inspired by the memory game Simon.</h3>

<br>

<p align="center">
        <a href="#features"=>Features</a> ·
        <a href="#project-tree"=>Project Tree</a>
</p>

![Screenshots](https://raw.githubusercontent.com/le-flav-b/Simon²/master/photos/playing.mp4)
<br>
<br>

This small project includes an ESP8266, two shift registers, a buzzer, a 4x4 LED matrix, a 4x4 button matrix, and a button to reset the EEPROM.
It made me understand the importance of pin management.

<br>


## Features

* Random sequences
* Different sound for each LED
* Best score stored in non-volatile memory

<br>


## Project Tree

📁 Simon²<br>
├─📁 firmware<br>
│ ├─📁 main<br>
│ │ └─📄 main.ino<br>
│ └─📁 poc<br>
│   ├─📁 buttons<br>
│   │ └─📄 buttons.ino<br>
│   ├─📁 buzzer<br>
│   │ └─📄 buzzer.ino<br>
│   ├─📁 eeprom<br>
│   │ └─📄 eeprom.ino<br>
│   └─📁 leds<br>
│     └─📄 leds.ino<br>
├─📄 logo.png<br>
├─📁 mechanical<br>
│ ├─📄 case.stl<br>
│ ├─📄 design.png<br>
│ ├─📄 render.png<br>
│ └─📄 Simon².f3d<br>
├─📁 photos<br>
│ ├─📄 back.jpg<br>
│ ├─📄 breadboard.jpg<br>
│ ├─📄 front.jpg<br>
│ ├─📄 pcb.jpg<br>
│ └─📄 playing.mp4<br>
└─📄 pinout.txt

<br>


---

<h4 align="center">
    Website : <a href="https://www.le-flav-b.fr">le-flav-b.fr</a> &nbsp&nbsp · &nbsp&nbsp
    GitHub :  <a href="https://github.com/le-flav-b">@le-flav-b</a>
</h4>
