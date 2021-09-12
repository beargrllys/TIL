reg add "hkcu\control panel\desktop" /v WallpaperStyle /t REG_SZ /d 6 /f
RUNDLL32.EXE user32.dll, UpdatePerUserSystemParameters ,1 ,True