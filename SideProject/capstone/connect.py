import mariadb
import sys
import datetime

# Connect to MariaDB Platform
try:
    conn = mariadb.connect(
        user="raspi_user",
        password="wlgkcjf21gh",
        host="112.170.208.72",
        port=20,
        database="rasp_db"

    )
except mariadb.Error as e:
    print(f"Error connecting to MariaDB Platform: {e}")
    sys.exit(1)

# Get Cursor
cur = conn.cursor()
#some_name = "Georgi"
#cur.execute("SELECT sensor,PW FROM TESTTABLE WHERE NAME=?", (some_name,))

# for first_name, last_name in cur:
#    print(f"NAME: {first_name}, PW: {last_name}")

# insert information
try:
    cur.execute("INSERT INTO collect_data (sensor,collect_time,value1, value2) VALUES (?,?,?,?)",
                ("testSensor", datetime.datetime.now(), "0.1", "2.1"))
except mariadb.Error as e:
    print(f"Error: {e}")

conn.commit()
print(f"Last Inserted ID: {cur.lastrowid}")

conn.close()
