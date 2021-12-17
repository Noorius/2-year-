

public class Week3b{
    public static void main(String[] args){
        Student s1 = new Student();
        s1.genID();
    }  
}

class Student{
    static String university;
    String id;
    String name;
    float gpa;
    int TotalNumberOfStudents = 0;

    Student(){
        
    }

    Student(String u, String n, float g){
        university = u;
        id = genID();
        name = n;
        gpa = g;
        TotalNumberOfStudents++;
    }

    void show(){
        System.out.println(university+id+gpa);
    }

    void changeUniversity(String u){
        this.university = u;
    }

    void showTotalNumberOfStudents(){
        System.out.println(this.TotalNumberOfStudents);
    }

    String genID(){
        //java.util.Calendar calendar = new GregorianCalendar();
        String tempID = Integer.toString(java.util.Calendar.YEAR);
        System.out.println(tempID);
        return tempID;
    }
}

    // TASK-1: Add at least one more instance data field; done

	// TASK-2: Add at least one more instance method;	done

	// TASK-3: Create a method showTotalNumberOfStudents();

	// TASK-4: Generate IDs automatically.

