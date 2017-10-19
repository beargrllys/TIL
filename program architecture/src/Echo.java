public class Echo { 
   public static void main(String[] args) { 
      System.out.print("입력한 문자는 : "); 
      for(int i=0;i<args.length;i++) { 
         System.out.print(args[i]+" "); 
      } 
      System.out.println(); 
   } 
} 