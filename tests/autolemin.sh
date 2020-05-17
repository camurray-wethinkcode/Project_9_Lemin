working()
{
	for map in "directlink2end" "simple" "roundmap" "input2" "duplicatepipe1" "input3" "underflow" "invalidcommand" "comments" "diamond" "simple1" "overflow" "loop" "hardmap" "map10" "pentagram" "input1" "in0" "map14" "map42" "input0" "maptest" "triforce" "shortest" "Chloe" "multiplewaysmap" "europe" "42";
	do
	header;
	echo "\x1B[35m***********INPUT FILE************\x1B[0m";
	echo $map;
	echo "\x1B[35m*********************************\x1B[0m";

	echo "\x1B[32m***********CAT INPUT************\x1B[0m";
	cat -e ./maps/$map;
	echo "\x1B[32m********************************\x1B[0m";

	echo "\x1B[36m*********LEM-IN RESULT**********\x1B[0m";
	./lem-in < ./maps/$map;
	echo "\x1B[36m********************************\x1B[0m";

	read;
done;
}


unvalid()
{
	for map in "empty" "no_rooms" "startisend" "nopath" "no_tubes" "multiends" "nostart" "noend" "no_ants" "noants" "bad_rooms" "invalidcommand1" "whitespaces" "illegalname1" "illegalname" "space_room" "space_room_2" "loop1" "test2commentary" "comments2" "map4" "simple2" "test1" "input4" "haaaaaaaaaaaaaaaaaaaardtest";
	do

	header;
	echo "\x1B[35m***********INPUT FILE************\x1B[0m";
	echo $map;
	echo "\x1B[35m*********************************\x1B[0m";

	echo "\x1B[32m***********CAT INPUT************\x1B[0m";
	cat -e ./maps/$map;
	echo "\x1B[32m********************************\x1B[0m";

	echo "\x1B[36m*********LEM-IN RESULT**********\x1B[0m";
	./lem-in < ./maps/$map;
	echo "\x1B[36m********************************\x1B[0m";

	read;
	done;
}


printf "Working or Unworking maps (w/u) ? ";
read response;

if [ $response = "u" ]
	then	unvalid

elif [ $response = "w" ]
	then	working
else
	exit
fi

exit;
