package Task7;

public class Bank {
	private Client[] clients;
	private int countClients;
	private Account[] accounts;
	private int countAccounts;
	private String name;
	

	public Bank(String name) {
		if (name == null) {
			throw new IllegalArgumentException("Name can not be empty!");
		}
		this.name = name;
		accounts = new Account[100];
		clients = new Client[100];
	}

	public boolean createAccount(Account account) {
		if (accounts.length == countAccounts || account == null) {
			return false;
		}
		accounts[countAccounts] = account;
		countAccounts++;
		return true;
	}

	public boolean createClient(Client client) {
		if (clients.length == countClients || client == null) {
			return false;
		}
		clients[countClients] = client;
		countClients++;
		return true;
	}

	public String makeReport() {
		return "{Clients:" + countClients() + " Accounts:" + countAccounts() + "}"; 
	}

	private int countClients() {
		return countClients;
	}

	private int countAccounts() {
		return countAccounts;
	}

}