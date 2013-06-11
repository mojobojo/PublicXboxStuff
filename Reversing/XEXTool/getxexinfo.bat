:: For taking all the xex files in the same directory and dumping the info on them into a seperate text file
@echo off
for %%X in (*.xex) do xextool -l %%X > %%~nX_info.txt
