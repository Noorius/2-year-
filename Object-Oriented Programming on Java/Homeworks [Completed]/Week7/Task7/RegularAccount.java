package Task7;
import java.math.BigDecimal;

public class RegularAccount extends Account {

	public RegularAccount(String number, String status, Client owner, BigDecimal balance) {
		super(number, status, owner, balance);
	}

	public void debit(BigDecimal amount) {
		BigDecimal newBalance = balance.subtract(amount);

		if (newBalance.compareTo(BigDecimal.ZERO) < 0) {
			throw new IllegalStateException("Not enough cash");
		}

		newBalance = newBalance.subtract(new BigDecimal("30.00"));

		if (newBalance.compareTo(BigDecimal.ZERO) < 0) {
			throw new IllegalStateException("Not enough cash");
		}

		// DRY ~ Dont Repeat Yourself
		
		balance = newBalance;

		operations[opIndex] = "Debit " + amount.toString();
		opIndex++;
	}

}