package Task7;
import java.math.BigDecimal;

public class PremiumAccount extends Account {

	public PremiumAccount(String number, String status, Client owner, BigDecimal balance) {
		super(number, status, owner, balance);
	}

	public void debit(BigDecimal amount) {
		BigDecimal newBalance = balance.subtract(amount);

        if (newBalance.compareTo(BigDecimal.ZERO) < 0) {
        	throw new IllegalStateException("Not enough cash");
        }

        newBalance = newBalance.add(new BigDecimal("150.00"));

        balance = newBalance;

        operations[opIndex] = "Debit " + amount.toString();
		opIndex++;
	}

	public void paymentForService() {
		BigDecimal newBalance = balance.subtract(new BigDecimal("4000.00"));
        balance = newBalance;
	}

	protected String balanceBuilder() {
		return "@@@@Your premium account balance is " + balance.toString() + "@@@@@";
	}


}