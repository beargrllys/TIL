
public class Coin2 {
	public static void main(String[] args) {
		int quarters = 9;
		int dimes = 2;
		int nickels = 7;
		int pennies = 6;
		System.out.println("For these quantities of coin: ");
		System.out.print("Quarters = ");
		System.out.println(quarters);
		System.out.print("dimes = ");
		System.out.println(dimes);
		System.out.print("nickels = ");
		System.out.println(nickels);
		System.out.print("pennies = ");
		System.out.println(pennies);
		System.out.print("The total is ");
		int total = +((quarters*25)+(dimes*10)+(nickels*5)+(pennies*1));
		System.out.println(total);
		System.out.print("The total is $");
		System.out.println(total /100);
		System.out.println(".");
		System.out.println(total % 100);
	}

}
