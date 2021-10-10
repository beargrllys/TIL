import mariadb
import sys
import datetime
import threading

#화분 내부 네트워크 코드입니다.

class NetworkSession:
    conn = mariadb
    #
    def __init__(self):# 네트워크를 초기화합니다.
        # Connect to MariaDB Platform
        try:
            self.conn = mariadb.connect(
                user="raspi_user",
                password="wlgkcjf21gh",
                host="112.170.208.72",
                port=20,
                database="rasp_db"
                )
            print("DataBase Connected")
        except mariadb.Error as e:
            print(f"Error connecting to MariaDB Platform: {e}")
            sys.exit(1)

    def __del__(self):
        self.conn.close()
        print("DataBase Session Closed")
    
    def insert_DB(self, plantID ,plantName, Temper , Humid ,waterLevel , waterSpeed ,soil, CDS):#화분에 수집된 센서 값을 데이터베이스에 올립니다.
        # Get Cursor
        cur = self.conn.cursor()

        try:
            cur.execute("INSERT INTO collect_data (plantID ,plantName,collect_time, Temper , Humid ,waterLevel , waterSpeed ,soil, CDS) VALUES (?,?,?,?,?,?,?,?,?)",
                        (plantID ,plantName, datetime.datetime.now(), Temper , Humid ,waterLevel , waterSpeed ,soil, CDS))
        except mariadb.Error as e:
            print(f"Error: {e}")

        self.conn.commit()
        threading.Timer(5, self.insert_DB(plantID ,plantName, Temper , Humid ,waterLevel , waterSpeed ,soil, CDS))

    def get_OrderData(self, Order):#화분에 내릴 명령을 구분합니다.
        cur = self.conn.cursor()

        some_name = "Georgi"
        cur.execute("SELECT sensor,PW FROM TESTTABLE WHERE NAME=?", (some_name,))

        for first_name, last_name in cur:
            print(f"NAME: {first_name}, PW: {last_name}")





