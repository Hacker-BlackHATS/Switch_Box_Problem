-----------------------------------------------------------------------------------------------------------------------------------
SWITCH BOX ROUTING PROBLEM  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------------------------------------------------------------------------------
PROBLEM STATEMENT :: 
___________________________________________________________________________________________________________________________________

[+]In the switch box routing problem, we are given a rectangular routing region with pins at the periphery. Pairs of pins are to
be connected together by laying a metal path between the two pins. This path is confined to the routing region and is called a 
wire. If two wires intersect, an electrical short occurs. So wire intersections are forbidden. Each pair of pins that is to be 
connected is called a net. We are to determine whether the given nets can be routed with no intersections.

(*)(In practice, we also require a minimum separation between adjacent wires. We ignore this additional requirement here.)
Our problem is to input a switch box routing instance and determine whether it is routable.

<*>In this program i had assumed that the number of pins is even and that each pin has only one net number.

___________________________________________________________________________________________________________________________________
SOLUTION STRATEGY ::::
-----------------------------------------------------------------------------------------------------------------------------------
To solve the switch box routing problem, we note that when a net is connected,
the wire partitions the routing region into two regions. The pins that fall on the
boundary of a partition do not depend on the wire path, but only on the pins of the
net that was routed. For instance, when net (1, 4) is routed, we get two regions.

One contains the pins 2 and 3, and the other contains the pine 5 through 8. If
there is now a net with one pin in one region and the other in a different region,
this new net cannot be routed and the routing instance is unroutable. If there is no
net with this property, then since the wires cannot cross between regions, we can
attempt to determine whether each region is independently routable. To make this
determination, we pick a net in one of the regions; this net partitions its region into
two regions, and none of the remaining nets should have a pin in one partition and
another in the other partition.

We can implement this strategy by moving around the periphery of the switch
box in either clockwise or counterclockwise order, beginning at any pin.
