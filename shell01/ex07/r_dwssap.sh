#!/bin/bash
cat /etc/passwd | grep -v ^# | awk 'NR % 2 == 0' | cut -d ':' -f 1 | rev | sort -r | awk 'ENVIRON["FT_LINE1"]<=NR && NR<=ENVIRON["FT_LINE2"]' | paste -s -d ',' - | sed 's/,/, /g' | sed 's/$/./'
