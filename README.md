# lego-palace-cinema-lights

A Arduino Light control program for the Lego Cinema 10232 set's marquee.  It just runs different patterns in a loop.

This was inspired by a project I saw on Reddit (links below).  I don't have a background in electronics, so that portion of the project was a learning experince for me. I made notes here for anyone who comes after me.  Please take this with a grain of salt, there's probably better ways to do all of this.

* [Another implementation found on Reddit](https://www.reddit.com/r/lego/comments/m4bvcy/im_in_the_process_of_lighting_up_my_modular/) ([more](https://www.reddit.com/r/lego/comments/m52l1z/some_more_details_on_the_palace_cinema_marquee/)) - this is the project that inspired me to try this for myself.

## Supplies

* [Palace Cinema 10232](https://www.lego.com/en-us/product/palace-cinema-10232)
* [LEDs](https://www.amazon.com/gp/product/B07DW65QMM/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1) (came with resistors)
* [Arduino Nano](https://store.arduino.cc/usa/arduino-nano)
* 5v power supply - usb works, but I repurposed an plug from an old dead Roku because the cord was light and flexable.

## Wiring

The original post I was copying said that the Arduino would fit in the base of the marquee.  It might have for him, but couldn't by the time I got done with it. The Arduino I used had GPIO pins soldered in place, which makes prototyping easy, but takes up a bit more space. I also used traditional resistors attached to the pin connectors rather than SMD resistors. There were probably many ways to make this smaller. I just let it hang for the first floor ceiling of the theater.

The first major problem I ran into was that there are 16 lights on the marquee and far fewer on the Arduino. That was a new problem for me, which I found a solution for in [this article on Multiplexing](https://siytek.com/how-many-leds-can-an-arduino-control/).  I ended up using 8 pins.  Essentially you use 4 for input, 4 for output and arrange the lights as a grid (4 rows of 4).  Of course you can only address one light in any row or column at a time.  Thats solved in software by only lighting each light for a few milliseconds and cylcing them real quickly. 

## Software

My experience in C is limited to a 6 month project and a class, both over 20 years ago, so please keep that in mind when browsing the code (in this project). 
