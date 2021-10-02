--a
SELECT student.id,name,dept_name,grade
from student, takes
WHERE student.id=takes.id and dept_name='Comp. Sci.' and (grade='A' or grade='A-')
ORDER BY name;

--b
SELECT i_id,name,s_id, grade
from takes, advisor, instructor
WHERE i_id=instructor.id and s_id=takes.id
GROUP BY i_id,name,s_id,grade
HAVING grade>'B' and grade!='B+';

--c
SELECT dept_name
from student, takes
where student.id=takes.id
GROUP BY dept_name

EXCEPT

SELECT dept_name
from student, takes
where student.id=takes.id and grade LIKE ANY(ARRAY['C','F'])
GROUP BY dept_name;

--d(1) одно решение, те кто не давал оценку А
SELECT DISTINCT teaches.id,name
from teaches,instructor,takes,section
WHERE teaches.id=instructor.id and
      takes.course_id=section.course_id and
      teaches.course_id=section.course_id and
      takes.sec_id=teaches.sec_id and
      takes.semester=teaches.semester and takes.year=teaches.year

EXCEPT

SELECT DISTINCT teaches.id,name
from teaches,instructor,takes,section
WHERE teaches.id=instructor.id and
      takes.course_id=teaches.course_id and
      takes.sec_id=teaches.sec_id and
      takes.semester=teaches.semester and
      takes.year=teaches.year and
      grade='A';

--d(2) второе решение, те кто не давал оценку А и вообще не преподавал, технически попадают под условие
(SELECT DISTINCT teaches.id,name --учителя которые не давали оценку А
FROM teaches,instructor,takes,section
WHERE teaches.id=instructor.id and
      takes.course_id=section.course_id and
      teaches.course_id=section.course_id and
      takes.sec_id=teaches.sec_id and
      takes.semester=teaches.semester and
      takes.year=teaches.year

EXCEPT

SELECT DISTINCT teaches.id,name
FROM teaches,instructor,takes,section
WHERE teaches.id=instructor.id and
      takes.course_id=teaches.course_id and
      takes.sec_id=teaches.sec_id and
      takes.semester=teaches.semester and
      takes.year=teaches.year and
      grade='A')

UNION --Объединение сетов

(SELECT id, name --учителя которые не учили вообще
FROM instructor

EXCEPT

SELECT DISTINCT teaches.id,name
from teaches,takes,instructor
WHERE teaches.id=instructor.id and
      takes.course_id=teaches.course_id and
      takes.sec_id=teaches.sec_id and
      takes.semester=teaches.semester and
      takes.year=teaches.year
GROUP BY teaches.id,name,grade);

--e
SELECT course.course_id,title,start_hr,start_min
from section, time_slot,course
WHERE section.time_slot_id=time_slot.time_slot_id and
      start_hr<13 and
      section.course_id=course.course_id;


