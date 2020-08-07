# arduino-music
Code that makes an arduino play music easily. Plus it's easy to program for anyone !

What do you need ?

An arduino, wires, a breadboard and a piezo buzzer (one that can vibrate to certain frequencies to make sounds).

1st step :
Using wires, link the + and - to your 5v and Ground respectively.

2nd step :
Add the piezzo buzzer on the breadboard. The buzzer's input needs to be linked to the 8th pin (otherwise you'll need to change the buzPin variable to the pin of your choice). The buzzer's output needs to be linked to the ground.

3rd step :
Put the code on the arduino using the Arduino IDE.

Final step :
Listen to "At Doom's Gate"'s intro. The boot sounds are from the GameBoy's and Master System's, if you don't want them, delete from line 30 to 39.

How do I add new musics ?

You can modify the array called sheet\[] :
The first digit indicates the octave, then the rest indicates the note.
Do/C = 1
Do#/C# = 2
Re/D = 3
Re#/D# = 4
Mi/E = 5
Fa/F = 6
Fa#/F# = 7
Sol/G = 8
Sol#/G# = 9
La/A = 10
La#/A# = 11
Si/B = 12

So La/A in the 2nd octave will be 211 as 2 for the octave and 11 for the note value.
The notes will be played one after an other. If you want a silence, just type 1. If you want to hold the note, just type 0.

What are the available options for me ?

sheetSpeed is 1 by default. It's a coeficient that indicates how fast it should be played. 0.65 is best for the sample track but you can change it to whatever you want.

octave is 0 by default but if you change it, it will add that value to all the notes that will be read. If you have a La/A on the 1st octave, and octave's value is 2, the note will be played at the octave (1+2=)3.

The play() function has 2 parameters : Note and length. The note is in the same format as the notes in the sheet array and length is an integer that represents the length in milliseconds of the note.
