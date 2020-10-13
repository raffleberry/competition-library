[build-menu]
FT_00_LB=_Compile
FT_00_CM=g++ -g -std=c++14 "%f" && gnome-terminal -- bash -c "gdb ./a.out"
FT_00_WD=%d
FT_01_LB=_Build
FT_01_CM=g++ -O2 -std=c++14 -DLOCAL -o "%e.out" "%f"
FT_01_WD=%d
EX_00_LB=_Execute
EX_00_CM="./%e.out" < input.txt
EX_00_WD=%d
EX_01_LB=Manual Execute
EX_01_CM="./%e.out" 
EX_01_WD=%d
FT_02_LB=_Build With Debug
FT_02_CM=g++ -std=c++14 -Wshadow -Wall -o "%e.out" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
FT_02_WD=
