package Task7;
import java.math.BigDecimal;
import Task7.*;
import Task7.Client;
import Task7.GoldenAccount;
import Task7.Account;


public class Application {
	static Account regAcc;
	static Account premAcc;
	static Account goldAcc;
	public static void main(String[] args) {
		Client client = new Client("John", "+727277272", "912312121212");

		//regAcc = new RegularAccount("44001110", "1", client, new BigDecimal("10000.00"));
		//premAcc = new PremiumAccount("44001111", "1", client, new BigDecimal("10000.00"));
		goldAcc = new GoldenAccount("4400********1112", "1", client, new BigDecimal("10000.00"));
		System.out.println(client.getName());

		/* Bank bank = new Bank("AnyBank");
		System.out.println(bank.createClient(client));
		System.out.println(bank.createAccount(premAcc));
		// System.out.println(bank.createAccount(goldAcc));
		System.out.println(bank.createAccount(regAcc)); 

		System.out.println(bank.makeReport());

		balancePrinter();

		regAcc.credit(new BigDecimal("1000.00"));
		premAcc.credit(new BigDecimal("1000.00")); */
		goldAcc.balanceBuilder();

		goldAcc.credit(new BigDecimal("1000.00"));

		goldAcc.balanceBuilder();

		//regAcc.debit(new BigDecimal("1000.00"));
		//premAcc.debit(new BigDecimal("1000.00"));
		goldAcc.debit(new BigDecimal("1000.00"));

		balancePrinter();

		regAcc.paymentForService();
		premAcc.paymentForService();
		// goldAcc.paymentForService();

		balancePrinter();

		//regAcc.getStatement();
		//premAcc.getStatement();
		goldAcc.getStatement();

	}

	public static void balancePrinter() {
		System.out.println(regAcc.getBalance());
		System.out.println(premAcc.getBalance());
		// System.out.println(goldAcc.getBalance());
		System.out.println();
	}
}