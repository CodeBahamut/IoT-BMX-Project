# Weather proofing

## Reasoning

As the device needs to be usable outside, we want to make sure the device can withstand all weathersituations that can occur there. To do this we first need to do a deskresearch to research what type of weather can affect our product and what to do against that. After that research we can make a decision on the casing of our product.  

So, as the location is in the east of the Netherlands, the temperatures are more extreme than in the east. Due to the fact that this location is further from open waters, but these temperatures are still not that high to really affect our product, provided we set it up in the shadows. However, it is still the Netherlands, so that means that **rain** and **heavy wind** will still be a big factor. Next to that we always need to be aware of **lightning**, as that can affect any electronic device heavily and can even destroy it up until no repair is possible.

## Prevention

Now that we know what can affect our product, we must research how to prevent these weathereffects from having negative effects on our product.

### Rain

Making the product waterproof is practically impossible, as you need to be able to connect the wires from the wemos to a device, however making it water-resistant is definitely possible. This makes it practically impossible for rain to get into the device. To do this, we could make a casing for the device, with **rubber rings** around the openings, this way the rubber can catch the water comming through the holes. However, this would give us a problem regarding heat, as if it gets warm weather the heat would then make the casing expand, which would allow water to find its way to the board anyway.
Apart from that, we could also use some other methods, one of which is using **nailpolish**, which would could also make the board resistant to water, but it would not be able to protect the usb port, nor would it be able to protect the pins.  
Another option would be to use **silicone** or **potting compound**. We can dip the board in there and make a brick of silicone with the board in there, which would actually make the device as waterresistant as possible and would even make it function completely underwater. The problem with this however, is that we need to be able to access the usb port of the board, which would be inaccessible. Modifying the board afterwards would also be impossible.

### Wind

Making the device resistant to wind is simply making a good enclosure and finding a way for the wind sensors to stand upright without the risk of it falling over. The average windspeed at our location is during the winter (the wind is stronger during the winter) around 13 to 16 km/h, which is not all that much. but gusts can get to 75 and even 100 km/h. The base of the windsensors is made of metal, which I'm sure can hold against such windspeeds. The bigger problem is actually attaching this base to the ground/track in a strong enough way that it stays attached and upright. This would also have to keep in mind that the other parts of the device would also need to be attached to it.

### Lightning

Making it resistant to lightning would be very difficult, as a lightning bolt would completely destroy the device. However, the device is already sort of protected against lightning, as the top part of the wind sensor is made of plastic, which does not conduct electricity. In addition to that, we should make sure the device is not the highest point in the nearby area, which would make it highly unlikely to be struck by lightning.  
There are ways to also protect the device if it still gets struck by lightning, however it is definitely not easy. To do this we'd need to lower the current gotten from the lightning and also move the extra voltage down to earth. Due to the low voltage of the arduino and wemos, the latter can only be done using a gas tube surge arrester. This moves the extra voltage and current to earth. However, this can only work with a full heavy duty grounding system, which would need a lot to be set up. Then, we also need to move the extra voltage down to earth. The most common way to do this is by running a ground wire from the top of the antenna, but this wire would need to have a braided metal strap and be at least 5cm (2 inches) wide to make sure it at least has a chance of not evaporating from the impact.

## Result

As it turns out we cannot realy prevent everything, but we can at least try to make the chance of it occuring as small as possible. For lightning this means putting the device lower than the highest part in the near area, also the highest part of our device should be made of a material which does not conduct.  
For wind we need to make sure to attach the device tightly to make sure it won't break or fall due to the wind. For this we have metal straps with which we can attach the device to something else.  
For rain we have multiple options as described before, realistically we could buy a watertight casing, using cable glands for the wiring, or we could use nail polish to make the mini-computer itself resistant to water.

## Our choice

The only choice we really had to make was how we wanted to make the device waterresistant. Eventually we decided on making our own casing using 3d printing. Apparently PLA is pretty waterresistant and thus can be used for this, altough PETG would be the ideal material to use for this, but we sadly did not have access to this. It would be ideal because it is even more waterresistant and it can also withstand the heat, making temperature way less of a problem. But for us PLA works fine and we designed our own casing. This can be found [here](https://iot.dev.hihva.nl/2021-2022-feb-jun/group-project/teamnl-bmx-windspeed-logging/iot-bmx-team-nl/Daily-documentation/#day-3-thursday).
