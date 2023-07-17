# select distinct s1.num, (
#         select s2.num, s3.num from Logs s2, Logs s3
#         where s1.num=s2.num and s2.num=s3.num and s1.id=s2.id+1 and s2.id=s3.id+1
#     ) as 'ConsecutiveNums' from Logs s1

# select distinct s1.num, s1.id as 'ConsectiveNums' from Logs s1, s2.num, s2.id from Logs s2, s3.num, s3.id from Logs s3
# where s1.id+1=s2.id and s2.id+1=s3.id and s1.num=s2.num and s2.num=s3.num

select distinct s1.num as 'ConsecutiveNums' from logs s1, logs s2, logs s3
where s1.id+1=s2.id and s2.id+1=s3.id and s1.num=s2.num and s3.num=s2.num