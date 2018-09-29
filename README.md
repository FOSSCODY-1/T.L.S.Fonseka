# T.L.S.Fonseka
Car Park System


A car park has a single lane that holds up to certain fixed number of vehicles.(here I’ve only created three spaces for simplicity).
vehicles arrive from east gate and leave from west gate. 
Since there’s only one lane, if a car in the middle takes out, vehicles in front should move out and after it leaves vehicles move back.
When a car arrives, system first checks for an empty space.
If there’s no space, car should wait for a space to clear. 
When an empty spot arise, waiting list automatically moves forward and fills the spot.

Arrival of a vehicle

https://github.com/FOSSCODY-1/T.L.S.Fonseka/blob/master/Capture.PNG
    
show the list of vehicles in the car park

https://github.com/FOSSCODY-1/T.L.S.Fonseka/blob/master/Capture2.PNG

leaving of the westmost vehicle(the one on the front). System always shows how many positions a car moved at a departure.

https://github.com/FOSSCODY-1/T.L.S.Fonseka/blob/master/Capture3.PNG

When a car at the middle leaves first, the cars infront should move out and put in a stack. After the departure the cars pop from the stack and put back in the previous order.

https://github.com/FOSSCODY-1/T.L.S.Fonseka/blob/master/Capture4.PNG

When the car park is full, vehicle next should wait. They put into a new queue.

https://github.com/FOSSCODY-1/T.L.S.Fonseka/blob/master/Capture5.PNG

When a car leaves, system automatically moves the waiting list and fillup the empty space.

https://github.com/FOSSCODY-1/T.L.S.Fonseka/blob/master/Capture6.PNG
