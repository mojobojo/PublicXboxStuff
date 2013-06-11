:: For taking all the xex files in the same directory and dumping them for loading in IDA
@echo off
for %%X in (*.xex) do xextool -b %%~nX.exe -i %%~nX.idc %%X > %%~nX_load_info.txt
