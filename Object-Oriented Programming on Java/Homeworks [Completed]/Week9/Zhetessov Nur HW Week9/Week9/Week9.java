package Week9;

import java.util.Date;
import java.util.regex.Pattern;
import java.io.*;

abstract class User_Errors {

    public void Report_Error(Exception e) {
        try {
            FileWriter output = new FileWriter("Week9/report.txt", true);
            output.append("[" + new Date() + "]: " + " " + e.fillInStackTrace() + "\n");
            output.close();
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public String check_iin(String iin) throws Exception {
        if (!Pattern.matches("^\\d{12}$", iin)) {
            throw new Exception("Wrong IIN formate");
        }
        return iin;
    }

    public String check_phone(String ph) throws Exception {
        if (!Pattern.matches("^((8|\\+7)[\\- ]?)?(\\(?\\d{3}\\)?[\\- ]?)?[\\d\\- ]{7,10}$", ph)) {
            throw new Exception("Wrong phone number formate");
        }
        return ph;
    }
}

class User extends User_Errors {
    private String name;
    private String IIN;
    private String phone;

    public User(String newName, String newIIN, String newPhone) {
        try {
            this.name = newName;
            this.IIN = super.check_iin(newIIN);
            this.phone = super.check_phone(newPhone);
        } catch (Exception e) {
            super.Report_Error(e);
            System.out.println(e.fillInStackTrace());
        }
    }

}

public class Week9 {
    public static void main(String[] args) {
        User n = new User("Daulet", "090215880250", "+79261234567"); // This is OK
        User m = new User("Asem", "MOI_IIN", "+78001214569"); // Throws Error of IIN format
        User l = new User("Bakhyt", "029215350120", "+792312313123123123132234567"); // Throws Error of phone formate

    }
}
// javac Week9/*.java
// java Week9/Week9

// Создать абстрактный класс для записи ошибок в файлы -> [дата]: ОШИБКА

// Создать класс для пользователя с полями [имя, ИИН, номер телефона] и
// наследовать от класса для записи ошибок

// и провести проверку полей ИИН, номер телефона если проверка не пройдет
// записать
// в файл + вывести ошибку в консоль