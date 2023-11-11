$ADT_PATH = "..\..\adt\input\charmachine.c"
$ADT_PATH2 = "..\..\adt\input\wordmachine.c"

gcc -c $ADT_PATH -o charmachine.o
gcc -c $ADT_PATH2 -o wordmachine.o

gcc -I..\..\adt\input charmachine.o wordmachine.o driver_wordmachine.c -o driver

.\driver.exe

# Cleanup: Remove the object file and the compiled executable
Remove-Item charmachine.o, driver -ErrorAction SilentlyContinue
