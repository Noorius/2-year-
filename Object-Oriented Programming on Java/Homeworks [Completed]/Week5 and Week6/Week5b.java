import java.util.Scanner;

/*
 * TASK-1: Create two groups of students (2 arrays), and initialize them;
 * TASK-2: Create a static method that compares two student arrays, and returns how many students from 2 have the same name; 
 * TASK-3: Modify the Student to make it an immutable class; 
 * TASK-4: Create the Classes Course and Faculty, and demonstrate their relationships to the Student class like in the lecture slides.
 */

class Faculty { // Faculty
	private int st_ind, cr_ind;
	public Student[] st;
	public Course[] cr;

	Faculty() {
		Student[] st = new Student[200];
		Course[] cr = new Course[10];
	}

	public void add_course(String id, String courseName, int credits) {
		cr[cr_ind] = new Course(id, courseName, credits);
		cr_ind++;
	}

	public void add_Student(String studentName) {
		st[st_ind] = new Student(studentName);
		st_ind++;
	}

	public int num_of_students() {
		return st.length;
	}

	Course getCourse(int index) {
		return cr[index];
	}

	Student getStudent(int index) {
		return st[index];
	}
}

class Course { // Course
	public String name;
	public int credits;
	private String c_id;

	Course(String c_id, String newName, int credits) {
		this.name = newName;
		this.credits = credits;
		this.c_id = c_id;
	}
}

final class Student { // Immutable Student
	private String name;
	private String id;
	private double gpa;
	private String specialty;
	private static String university;
	private int age;
	private Course[] takes;
	private int cr_ind = 0;

	Student(String newName) {
		name = newName;
	}

	public String getName() {
		return this.name;
	}

	public double getGPA() {
		return this.gpa;
	}

	public int getAge() {
		return this.age;
	}

	public String getSpecialty() {
		return this.specialty;
	}

	// public void setGPA(double g){gpa = g;}
	public void happyBirthday() {
		this.age++;
	}

	public static void universityRename(String newName) {
		university = newName;
	}

	public void learn_course(Course newCourse) {
		takes[cr_ind] = newCourse;
		cr_ind++;
	}
}

/*
 * TASK-1: Create two groups of students (2 arrays), and initialize them;
 * TASK-2: Create a static method that compares two student arrays, and returns
 * how many students from 2 have the same name; TASK-3: Modify the Student to
 * make it an immutable class; TASK-4: Create the Classes Course and Faculty,
 * and demonstrate their relationships to the Student class like in the lecture
 * slides.
 */

public class Week5b {
	public static int compare_arrays(Student[] s1, Student[] s2) {
		int cnt = 0;
		for (int i = 0; i < s1.length; i++) {
			for (int j = 0; j < s2.length; j++) {
				if (s1[i].getName().equals(s2[j].getName()))
					cnt++;
			}
		}
		return cnt;
	}

	public static void main(String[] args) { // Main
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt(); // Number of students in each group
		Faculty FIT = new Faculty();
		Student[] st1 = new Student[n]; // Group 1 initialization
		Student[] st2 = new Student[n]; // Group 2 initialization

		for (int i = 0; i < n; i++) {
			String name = scan.next();

			st1[i] = new Student(name); // Group 1 filling
		}
		for (int j = 0; j < n; j++) {
			String name = scan.next();
			st2[j] = new Student(name); // Group 2 filling
		}

		System.out.println(compare_arrays(st1, st2)); // static method to compare

	}
}
/*
 * TASK-1: Create two groups of students (2 arrays), and initialize them;
 * TASK-2: Create a static method that compares two student arrays, and returns
 * how many students from 2 have the same name; TASK-3: Modify the Student to
 * make it an immutable class; TASK-4: Create the Classes Course and Faculty,
 * and demonstrate their relationships to the Student class like in the lecture
 * slides.
 */