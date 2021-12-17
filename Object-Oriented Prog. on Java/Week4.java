import java.util.Scanner;

class Student{
	public String name;
	public String id;
	private double gpa;
	String specialty;
    static String university;
    private int age;

	Student(String newName){
        name = newName;
    }

	public double getGPA(){return gpa;}
	public void setGPA(double g){gpa = g;}
    public int happyBirthday() {this.age++; return age;}
    public static void universityRename(String newName){ university = newName; }
}

class University{
    Student[] studentArray;
    int numOfStudents;
    int index;
    University(int numberOfStudents){
        numOfStudents = numberOfStudents;
        studentArray = new Student[numberOfStudents];
    }
    public void addStudent(Student s){
        studentArray[index] = s;
        index++;
    }

}

public class Week4{
	public static void main(String[] args) {
		//System.out.println(s1.happyBirthday());
        //System.out.println(Student.university);
        //Student.universityRename("KBTU");
        //System.out.println(s1.university);



        University kbtu = new University(100);

        Scanner in = new Scanner(System.in);
        for(int i=0; i<100; i++){
            String name = in.nextLine();
            Student s = new Student(name);
            kbtu.addStudent(s);
            System.out.println(kbtu.studentArray[i].name);
        }
	}
}

/*
TASK-1: Add at least 2 more data fields with different access modifiers
TASK-2: Add at least 2 more methods with different access modifiers
TASK-3: Create a class University that includes Student as a data field (group of students, if possible)
*/