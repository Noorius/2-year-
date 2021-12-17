import java.util.Random;

class Client {
    private String name;
    private String phone; // 8(777)123-12-12
    private String id;

    Client(String name, String phone, String id) {
        this.name = name;
        this.phone = phone;
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String newName) {
        this.name = newName;
    }

    public String getId() {
        return this.id;
    }

    public String getPhone() {
        return this.phone;
    }

    public void setPhone(String newPhone) {
        this.phone = newPhone;
    }
}

class BankAccount {
    private String number;
    private String status; // active deleted banned
    private Client owner;

    BankAccount(String number, String status, Client client) {
        this.number = number;
        this.status = status;
        this.owner = client;
    }

    public String getNumber() {
        return this.number;
    }

    public String getStatus() {
        return this.status;
    }

    public Client getClient() {
        return this.owner;
    }

    public void setStatus(String newStatus) {
        this.status = newStatus;
    }
}

class Bank {
    private String name;
    private Client[] clients;
    private BankAccount[] accounts;
    private int accountsCount;
    private int clientsCount;
    private int n = 18000000; // KZ population

    Bank(String name) {
        this.name = name;
        this.clients = new Client[n];
        this.accounts = new BankAccount[n];
    }

    public void createClient(Client client) {
        if (this.clientsCount < this.n) {
            this.clients[this.clientsCount] = client;
            clientsCount++;
        } else {
            System.out.println("Bank has too many clients");
        }
    }

    public void createBankAccount(BankAccount bankAccount) {
        if (this.accountsCount < this.n) {
            this.accounts[this.accountsCount] = bankAccount;
            this.accountsCount++;
        } else {
            System.out.println("Bank has too many accounts");
        }
    }

    public String makeReport() {
        String report = getName() + "\nTotally " + countClients() + " and " + countAccounts() + "\n";
        for (int i = 0; i < this.accountsCount; i++) {
            BankAccount bA = this.accounts[i];
            Client cl = bA.getClient();
            report += cl.getId() + " " + cl.getName() + " has " + bA.getStatus() + " account number " + bA.getNumber()
                    + " contact by tel.: " + cl.getPhone() + "\n";
        }
        return report;
    }

    void setName(String newName) {
        this.name = newName;
    }

    String getName() {
        return "Name of the bank is " + this.name;
    }

    private String countAccounts() {
        return "Accounts count: " + this.accountsCount;
    }

    private String countClients() {
        return "Clients count: " + this.clientsCount;
    }
}

public class Week6 {

    public static void main(String[] args) {
        Client firstClient = new Client("Aibek", "8(777)123-12-12", "011501887210");
        Client secondClient = new Client("Aibol", "8(777)234-13-13", "022004295643");

        BankAccount firstClientAccount = new BankAccount("1234-1234-1234-1234", "active", firstClient);
        BankAccount secondClientAccount = new BankAccount("1235-1235-1235-1235", "active", secondClient);
        secondClientAccount.setStatus("blocked");

        Bank bank1 = new Bank("KazKom");
        bank1.setName("NurBank");

        bank1.createBankAccount(firstClientAccount);
        bank1.createClient(firstClient);
        bank1.createBankAccount(secondClientAccount);
        bank1.createClient(secondClient);

        System.out.println(bank1.makeReport());

    }
}
