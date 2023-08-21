# Write your MySQL query statement below
SELECT distinct
    s.user_id,
    coalesce(ROUND(
        (
            SELECT COUNT(action)
            FROM confirmations c1
            WHERE c1.user_id = s.user_id AND c1.action = 'confirmed'
        ) /
        (
            SELECT COUNT(action)
            FROM confirmations c2
            WHERE c2.user_id = s.user_id
        ),
        2
    ),0.00) AS confirmation_rate
FROM
    signups s
LEFT JOIN
    confirmations c 
ON 
    s.user_id = c.user_id;
