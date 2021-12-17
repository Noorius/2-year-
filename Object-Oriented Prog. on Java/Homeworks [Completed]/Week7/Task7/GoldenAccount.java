package Task7;
import java.math.BigDecimal;

//System.print.out("(Week 7 task) Student Zhetessov Nur M.");

public class GoldenAccount extends Account {

	BigDecimal maintenance; //Easier to change these numbers,
	BigDecimal cashback;	// instead of changing everywhere later

	public GoldenAccount(String number, String status, Client owner, BigDecimal balance) {
		super(number, status, owner, balance);

		this.maintenance = new BigDecimal("3000.00");
		this.cashback = new BigDecimal("100.00");
	}

	 public void debit(BigDecimal amount) {
		BigDecimal newBalance = balance.subtract(amount);

        if (newBalance.compareTo(BigDecimal.ZERO) < 0) {
        	throw new IllegalStateException("Please top up your balance");
        }

        newBalance = newBalance.add(this.cashback);

        balance = newBalance;

        operations[opIndex++] = "Debit -" + amount.toString();
		operations[opIndex++] = "Cashback +" + this.cashback.toString();
	 }

	 public void paymentForService() {
		BigDecimal newBalance = balance.subtract(this.maintenance);
        balance = newBalance;
		operations[opIndex++] = "Card maintainance -" + this.maintenance.toString();
	 }

	 protected String balanceBuilder() {
		return "$$$ Your golden account balance is " + balance.toString() + " $$$";

	 }


}