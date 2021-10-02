--a
SELECT * from course where credits>3;
--b
SELECT room_number,building from classroom where building='Packard' or building='Watson'; --1 b)
--c
SELECT * from course where dept_name='Comp. Sci.';
--d
SELECT section.course_id,title,semester from section,course where course.course_id=section.course_id and semester='Fall';
--e
SELECT id,name,tot_cred from student where tot_cred BETWEEN 45 and 90;

--f(1) одно решение
SELECT * from student where name like '%a' or name like'%e' or name like '%i' or name like '%o' or name like '%u';

--f(2) другое решение
SELECT * from student where name in (ARRAY ['%a','%e','%i','%o','%u']);

--g
SELECT course_id,main_title,prereq_id,sec_title
from
    (SELECT course.course_id,title as main_title,prereq_id from course,prereq where course.course_id=prereq.course_id) as p1,
    (SELECT title as sec_title,prereq.course_id as sec_id from course,prereq where prereq_id=course.course_id) as p2
where course_id=sec_id and prereq_id='CS-101';
