import random
import time
import connect
import threading

val = 0
randchk = True

plantName ="DongJin's plant"
plantID = 1
Temper = 0
Humid = 0
waterLevel = 0
waterSpeed = 0
soil = 0
CDS = 0

def randSenseVal():
    while randchk:
        Temper=random.randint(0, 30)
        Humid=random.randint(0, 100)
        waterLevel=random.randint(0, 255)
        waterSpeed=random.randint(0, 10)
        soil=random.randint(0, 100)
        CDS=random.randint(0, 255)

def Interface():
    input("get OR set")
    


t = threading.Timer(1,randSenseVal())
t.start()

session = connect.NetworkSession()
session.insert_DB(plantID ,plantName, Temper , Humid ,waterLevel , waterSpeed ,soil, CDS).start()



