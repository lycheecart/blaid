# blaid
binary literacy aid
  
Use at your own risk. 
  
Here is a ncurses program that accepts a decimal number from keyboard input, then displays it in octal, hexadecimal, and binary (most significant bit first).  
It also displays the ascii character assigned to this number, and the shift-jis character assigned to this number.  
  
This program is for a terminal with UTF-8 encoding.  
It will display wide characters, but I cannot currently make this work with inputs consisting of "full width" decimal numbers, like inputting a '２' instead of a '2'.  
I also have an issue where mvprintw doesn't work but mvaddwstr does.  
  
To compile this with wide character support, I included test.priv.h and ncurses_cfg.h, which I got from https://invisible-island.net/ncurses/ncurses-examples.html.  
(I have the ncursesw6 package on ubuntu 22).   
  
I used this gcc invocation:  
  
gcc -g -o blaid -I. -DHAVE_CONFIG_H -DDATA_DIR=\"/usr/local/share\" -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600 -D_XOPEN_SOURCE_EXTENDED blaid.c -DNCURSES_STATIC -lformw -lmenuw -lpanelw -lncursesw -ltinfo -lutil -lm  
