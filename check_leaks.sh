#!/bin/bash

# With leaks
./lem-in < resources/tests/maps/europe & leaks lem-in ; \
killall -9 lem-in
