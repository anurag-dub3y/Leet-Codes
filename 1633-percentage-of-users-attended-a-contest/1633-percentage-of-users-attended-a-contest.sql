# Write your MySQL query statement below
# select contest_id, round((count(users.user_id)/(select distinct count(*) from users group by user_id)),2) from register
select contest_id, round(count(distinct user_id)*100/(select count(user_id) from users),2) as percentage from register 
group by contest_id
order by percentage desc, contest_id asc
