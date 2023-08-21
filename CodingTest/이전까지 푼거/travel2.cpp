using System.Collections;
using UnityEngine;
using System;
using System.IO;
using UnityEngine.Networking;
using System.Data;
using Mono.Data.SqliteClient;
using UnityEngine.SceneManagement;



public class dbScript : MonoBehaviour
{
    void Awake(){
      StartCoroutine(DBCreate());
    }

    void Start(){
        DBConnectionCheck();
    }

    string GetDBFilePath(){
      String str = string.Empty;
      if (Application.platfrorm == RuntimePlatformAndroid)
        {
         str = "URl=file:" +  Application.persistentDataPath + "/LoginDB.db";//Path to database.
      }
      else
        {
         str = "URl=file:" + Application.dataPath + "/LoginDB.db";
      }
      return str;
    }

    void DBcDBConnectionCheck()
    {
        try
        {
        IDBConnection dBConnection = new sqliteConnection(GetDBFilePath());
        dbconn.Open();

        if (dBConnection.State == ConnectionState.open)
            {
            Text1.text = "DB 연결 성공";
            }
        else
            {
            Text1.text = "DB 연결 실패(에러)";

        }
        }
        catch(Exception e)
        {
        Debug.LOg(e);
        }
        DatabaseRead("SELECT* FROM Login");
    }

   /*void Start()
        {
         DatabaseRead("SELECT* FROM Login");
        }*/

   void DataBaseRead(string query)
    {
         IDbconnection dbconnection = new sqliteConnection(GetDBFilepath());
         dbconnection.open();
         IDbCommand.dbcommand = dbconnection.CreateCommand();
         dbCommand.CommandText = query;
         IDataReader dataReader = dbCommand.ExecuteReader();
         while(dataReader. Read())
            {
            Debug.Log(dataReader.Getint32(0)+","+ dataReader.Getint32(0) + ","+ dataReader.Getstring32(1) + ","+ dataReader.Getstring32(2) + ","+ dataReader.Getstring32(3));
         }
      // Closed Db
      dataReader.Dispose();
      dataReader = null;
      dataCommand.Dispose();
      dataCommand = null;
      dataConnection.Close();
      dataConnection = null;
    }

    /*void Start()
        {
         DataBaseInsert("Insert into Login(ID,Name,Age,Password)");
         DataBaseRead("Select * from Login");
        }*/

   void Datanaseinsert(string query)
        {
         IDbconnection dbconnection = new sqliteConnection(GetDBFilepath());
         dbconnection.open();
         IDbCommand.dbcommand = dbconnection.CreateCommand();

         dbCommand.CommandText = query;
         dbCommand.ExecuteReader();


         dataCommand.Dispose();
         dataCommand = null;
         dataConnection.Close();
         dataConnection = null;
      }

    void ChangeScene1()
    {
        SceneManager.LoadScene("Login");
    }

    void ChangeScene2()
    {
        SceneManager.LoadScene("Resister");
    }

    void ChangeScene3()
    {
        SceneManager.LoadScene("main");
    }

    IEnumerator DBCreate()
   {
      string filepath = string.Empty; //파일 경로
      if (Application.platfrorm == RuntimePlatformAndroid)
      {
         filepath = application.dataPath + "/Login.db";
         if (!File.Exists(filepath))//파일이 없을때
         {
            UnityWebRequest UnityWebRequest = UnityWebRequest.Get("jar:file://" + Application.dataPath + "!/assets/Login.db");
            UnityWebRequest.downloadedBytes.Tosting();
            yield return UnityWebRequest.SendWebRequst().isDone;


         }

      }
      else
      {
         filepath = application.dataPath + "/Login.db";
         if (!File.Exists(filepath))//파일이 없을때
         {
            File.Copy(Application.streamingAssetspath +  "/login.db".filepath); //경로로 파일 복사
         }
      }
   }
}

