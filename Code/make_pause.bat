Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o stuff/main.o main.c

Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wf-ba0 -c -o stuff/bank_0.o bank_0.c
Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wf-bo1 -Wf-ba1 -c -o stuff/bank_1.o bank_1.c
Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -Wf-ba2 -c -o stuff/bank_2.o bank_2.c
Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wf-bo3 -Wf-ba3 -c -o stuff/bank_3.o bank_3.c

Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o stuff/gbt_player.o ../Plugins/gbt_player.s
Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o stuff/gbt_player_bank1.o ../Plugins/gbt_player_bank1.s

Q:\MULTIMEDIA\SOFTWARE\GBDK2020\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt2 -Wl-yo4 -Wl-ya4 -o RomTitle.gb stuff/main.o stuff/bank_0.o stuff/bank_1.o stuff/bank_2.o stuff/bank_3.o stuff/gbt_player.o stuff/gbt_player_bank1.o

pause