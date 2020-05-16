# Project_9_Lemin
A "Hex" simulator. Lemin is a program that prints the quickest way to get n ants across the farm. To be the first to arrive, ants will need to take the shortest path.

 Flags       | Description                                                                      
--ant (-a)   | Colour the total number of ants.                                                 
--debug (-d) | Prints step by step where the ants are moving, ant the number of moves required.             
--help (-h)  | Display a message on how to use lemin, and the available parameters.            
--man (-m)   | Shows the lem-in man page                                                       
--path (-p)  | Color the paths from the map.                                                   
--room (-r)  | Color the rooms from the map.                                                   

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and program:
	- `make fclean`
* To re-compile:
	- `make re`

To run the program:

`./lemin < path/to/map.txt`
