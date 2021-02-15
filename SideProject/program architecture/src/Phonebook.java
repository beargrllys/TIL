

import java.util.Scanner;

class Phone {
   private String name;
   private String tel;
   
   public Phone() {
      this.name=getName();
      this.tel=getTel();
   }
   
   public String getName() { 
      return name;
   }

   public String getTel() { 
      return tel;
   }
   
   public void set(String names, String tels) {
	   this.name = names;
	   this.tel=tels;
   }

}

public class Phonebook {
   private Scanner scanner;
   private int num;
   private Phone [] pArray;
   
   public Phonebook() { 
      this.pArray=new Phone[num];
      for (int i=0;i<pArray.length;i++) {
         pArray[i] = new Phone();
         }



   }

   void read() {  
      System.out.println("인원수>>");
      int num = scanner.nextInt();
      System.out.println("이름과 전화번호(이름과 번호는 빈 칸없이 입력)>>");
      String name = scanner.next();
      String tel = scanner.next();
      num--;
      pArray[i].set(name,tel);
   }
      System.out.println("저장되었습니다...");      
   
   String search(String name) {





      }
      return null;
      }
   
   void run() {
      System.out.println("이번달 스케쥴 관리 프로그램.");

      while(true) {
         System.out.print("검색할 이름>>");
         int menu = scanner.nextInt();
         switch(menu) {
         case 1: input(); break;
         case 2: view(); break;
         case 3: finish(); return;
         default : 
            System.out.println("잘못입력하였습니다.");
         }
         System.out.println();
      }      
   }
   
   public static void main(String[] args) {





   }
}