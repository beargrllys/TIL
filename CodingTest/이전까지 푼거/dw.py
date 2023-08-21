from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager 
import urllib.request
import time
from datetime import datetime

options = webdriver.ChromeOptions()
options.add_experimental_option("excludeSwitches", ["enable-logging"])
#driver = webdriver.Chrome(options = options)
driver = webdriver.Chrome(ChromeDriverManager().install())
driver = webdriver.Chrome(executable_path = 'C:/Users/js774/Desktop/TIL/SideProject/WeatherWallpaper/chromedriver')
driver.get("https://www.weather.go.kr/w/image/chart/analysis.do" )
time.sleep(3)

images = driver.find_elements_by_xpath('//*[@id="image-player-wrapper"]/form/div[2]/div[1]/img')

img_url = []

for image in images :
    url = image.get_attribute('src')
    print("Check!" + url)
    img_url.append(url)


import os 

img_folder = "C:/Users/js774/Downloads/WeatherWallpaper/"
d = datetime.today()
ds = datetime.strftime(d,"%Y%m%d")+'.jpg'

if not os.path.isdir(img_folder) : # 없으면 새로 생성하는 조건문 
    os.mkdir(img_folder)
    
for index, link in enumerate(img_url) :
#     start = link.rfind('.')
#     end = link.rfind('&')
#     filetype = link[start:end]
    urllib.request.urlretrieve(link, img_folder+ds)


os.system("reg add \"hkcu\control panel\desktop\" /v wallpaper /t REG_SZ /d \""+img_folder+ds+"\" /f ")
os.system("echo 패치시작")
time.sleep(2)
os.system("reg add \"hkcu\control panel\desktop\" /v WallpaperStyle /t REG_SZ /d 6 /f")
os.system("echo 설정완료")
time.sleep(2)
os.system("RUNDLL32.EXE user32.dll, UpdatePerUserSystemParameters ,1 ,True")
os.system("echo 마무리중")
time.sleep(3)
os.system("C:/Users/js774/Desktop/TIL/SideProject/WeatherWallpaper/updatee.bat")
time.sleep(2)
os.system("echo 끝")
#os.system("cd C:/Users/js774/Desktop/TIL/SideProject/WeatherWallpaper && updatee.bat")