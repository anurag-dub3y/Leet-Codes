select activity_date as day, count(distinct user_id) as active_users 
from activity
where DATEDIFF('2019-07-27', activity_date) < 30 AND DATEDIFF('2019-07-27', activity_date)>=0 
group by 1