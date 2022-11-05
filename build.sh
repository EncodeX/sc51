cd $1
sdcc --std-c11 -mmcs51 main.c
stcgal -P stc89 -p /dev/$2 ./main.ihx
