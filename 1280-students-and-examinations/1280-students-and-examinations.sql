select s1.student_id, s1.student_name, s2.subject_name, count(e1.student_id) as attended_exams from students s1
join subjects s2
left join examinations e1
on s1.student_id=e1.student_id and e1.subject_name=s2.subject_name
group by s1.student_id, s2.subject_name
order by s1.student_id, s2.subject_name


