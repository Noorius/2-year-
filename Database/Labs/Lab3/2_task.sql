--a
SELECT dept_name,avg(salary)
FROM instructor
GROUP BY dept_name
ORDER BY avg(salary) ASC ;

--b
SELECT DISTINCT building,count(course_id)
from (SELECT DISTINCT building,course_id FROM section) as foo
GROUP BY building
ORDER BY count(course_id) DESC LIMIT 1;

--c
SELECT department.dept_name,count(course_id) FROM course,department
WHERE department.dept_name=course.dept_name
GROUP BY dept_name
ORDER BY count(course_id) LIMIT 5;

--d
SELECT takes.id,name,count(course_id)
from takes,student
WHERE takes.id=student.id and course_id LIKE 'CS%'
GROUP BY takes.id, name
HAVING count(course_id)>3;

--e
SELECT *
from instructor
WHERE dept_name LIKE ANY(ARRAY['Biology','Philosophy','Music']);

--f
SELECT teaches.id,name,year
from instructor,teaches
WHERE teaches.id=instructor.id and year=2018 and year!=2017;
