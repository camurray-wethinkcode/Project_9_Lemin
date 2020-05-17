#!/bin/bash

make && \
cp lem-in resources/tests && \
cd resources/tests && \
if [ "$1" == "debug" ]; then \
	sh autolemin_debug.sh; \
else \
	sh autolemin.sh; \
fi && \
rm -f lem-in
