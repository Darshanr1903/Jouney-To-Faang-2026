with Student as
(
    select s.student_id ,s.student_name,s1.subject_name
    from Students s
    cross join Subjects s1
)
select s.student_id,s.student_name,s.subject_name, count(e.subject_name) as attended_exams
from Student s
left join Examinations e
on s.student_id=e.student_id and s.subject_name=e.subject_name
group by  s.student_id,s.subject_name
order by s.student_id,s.subject_name