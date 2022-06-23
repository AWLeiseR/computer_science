/* = = = BEAZLEY'S LAST STATEMENT = = = */

/*SELECT BLOCK*/
SELECT first_name, last_name, last_statement FROM executions LIMIT 3

/*FROM BLOCK*/
SELECT first_name FROM executions LIMIT 3

/* 50 / 2 */
SELECT 50 / 2

/* 51 / 2 */
SELECT 51 / 2

/*WHERE BLOCK*/
SELECT first_name, last_name, age FROM executions  WHERE age <= 25
SELECT first_name, last_name, ex_age FROM executions  WHERE ex_age <= 25

/*LIKE*/
SELECT first_name, last_name, ex_number FROM execution WHERE first_name = 'Raymond' AND last_name = '%Landry%'
SELECT first_name, last_name, ex_number FROM executions WHERE first_name = 'Raymond' AND last_name LIKE '%Landry%'

/*PARENTHESIS*/
SELECT 0 AND ( 0 OR 1 )

/*NAPOLEON BEAZLEY'S LAST STATEMENT*/
SELECT last_statement FROM executions WHERE last_name = '%beazley%'
SELECT last_statement FROM executions WHERE first_name = 'Napoleon' AND last_name = 'Beazley'

/* = = = CLAIMS OF INNOCENCE = = = */

/*COUNT FUNCTION*/
SELECT COUNT(last_statement) FROM execution
SELECT COUNT(last_statement) FROM executions

/*NUMBER OF EXECUTIONS*/
SELECT COUNT(first_name) FROM executions

/* HARRIS AND BEXAR EXECUTIONS*/
SELECT
    COUNT(CASE WHEN county='Harris' THEN 1
        ELSE NULL END),
    COUNT(CASE WHEN county='Bexar' THEN 1
        ELSE NULL END)
FROM executions

/*PRACTICE*/

/*AGE > 50*/
SELECT COUNT(*) FROM executions WHERE ex_age > 50

/*LAST_STATEMENT NULL*/
SELECT COUNT(*) FROM executions WHERE last_statement = NULL
SELECT COUNT(*) FROM executions WHERE last_statement IS NULL

SELECT COUNT(CASE WHEN last_statement = NULL THEN 1 ELSE NULL END ) FROM executions 
SELECT COUNT(CASE WHEN last_statement IS NULL THEN 1 ELSE NULL END ) FROM executions

SELECT COUNT(*) - COUNT(last_statement) FROM executions

/*MIN, MAX AND AVG AGE*/
SELECT MIN ex_age , MAX ex_age , AVG ex_age FROM executions
SELECT MIN(ex_age), MAX(ex_age), AVG(ex_age) FROM executions

/*AVG LENGTH LAST_STATEMENT*/
SELECT AVG(length(last_statement)) FROM executions

/*DISTINCT COUNTY*/
SELECT DISTINCT county from executions

/*CONCLUSION AND RECAP*/
SELECT COUNT(CASE WHEN last_statement LIKE '%innocent%' THEN 1 ELSE NULL END) /  1.0 * COUNT (*)  FROM executions
SELECT COUNT(CASE WHEN last_statement LIKE '%innocent%' THEN 1 ELSE NULL END) / ( 1.0 * COUNT (*) ) FROM executions

/* = = = THE LONG TAIL = = = */

/*GROUP BY*/
SELECT county, last_statement IS NOT NULL AS has_last_statement, COUNT(*) FROM executions GROUP BY county, has_last_statement

/*HAVING BLOCK*/
SELECT county, COUNT(*) FROM executions WHERE ex_age >= 50
SELECT county, COUNT(*) FROM executions WHERE ex_age >= 50 GROUP BY county

SELECT county FROM executions WHERE ex_age >= 50 GROUP BY county HAVING COUNT(*) > 2

/*PRACTICE*/
SELECT county FROM executions GROUP BY county

/*MAX LENGTH LAST STATEMENT*/
SELECT first_name, last_name FROM executions WHERE LENGTH(last_statement) = (SELECT MAX(LENGTH(last_statement)) FROM executions)

/*PERCENTAGE OF EXECUTIONS FROM EACH COUNTY*/
SELECT  county, COUNT(*) / (SELECT COUNT(*) FROM executions) AS percentage FROM executions GROUP BY county ORDER BY percentage DESC
SELECT  county, 100.0 * COUNT(*) / (SELECT COUNT(*) FROM executions) AS percentage FROM executions GROUP BY county ORDER BY percentage DESC

/*EXECUTION HIATUSES*/

/*NUMBER OF DAYS*/
SELECT julianday('1993-08-10') - julianday('1989-07-07') AS differenca

/*PREVIOUS TABLE*/
SELECT ex_number + 1 AS ex_number, ex_date AS last_ex_date FROM executions WHERE ex_number < 553

/*TEMPLATE QUERY*/
SELECT last_ex_date AS start, ex_date AS end, JULIANDAY(ex_date) - JULIANDAY(last_ex_date) AS diferenca FROM executions JOIN (SELECT ex_number + 1 AS ex_number, ex_date AS last_ex_date FROM executions WHERE ex_number < 553) previous ON executions.ex_number = previous.ex_number ORDER BY diferenca DESC LIMIT 10

/*JOIN ON*/
SELECT previous.ex_date AS inicio, executions.ex_date AS fim, JULIANDAY(executions.ex_date) - JULIANDAY(previous.ex_date) AS diferenca FROM executions JOIN executions previous ON executions.ex_number = previous.ex_number  ORDER BY diferenca LIMIT 10
SELECT previous.ex_date AS inicio, executions.ex_date AS fim, JULIANDAY(executions.ex_date) - JULIANDAY(previous.ex_date) AS diferenca FROM executions JOIN executions previous ON executions.ex_number = previous.ex_number + 1 ORDER BY diferenca DESC LIMIT 10

/* = = = CLOSIMG REMARKS = = =  */
WITH mutuals AS (
  SELECT DISTINCT
    c1.sponsor_name AS senator,
    c2.sponsor_name AS senator2
  FROM cosponsors c1
  JOIN cosponsors c2
    ON c1.sponsor_name = c2.cosponsor_name
    AND c2.sponsor_name = c1.cosponsor_name
)

SELECT senator, COUNT(*) AS mutual_count
FROM mutuals
GROUP BY senator
ORDER BY mutual_count DESC
LIMIT 1 


WITH mutual_counts AS (
  SELECT
    senator, state, COUNT(*) AS mutual_count
  FROM (
    SELECT DISTINCT
      c1.sponsor_name AS senator,
      c1.sponsor_state AS state,
      c2.sponsor_name AS senator2
    FROM cosponsors c1
    JOIN cosponsors c2
      ON c1.sponsor_name = c2.cosponsor_name
      AND c2.sponsor_name = c1.cosponsor_name
    )
  GROUP BY senator, state
),

state_max AS (
  SELECT
    state,
    MAX(mutual_count) AS max_mutual_count
  FROM mutual_counts
  GROUP BY state
)

SELECT
  mutual_counts.state,
  mutual_counts.senator,
  mutual_counts.mutual_count
FROM mutual_counts
JOIN state_max
  ON mutual_counts.state = state_max.state
  AND mutual_counts.mutual_count = state_max.max_mutual_count


SELECT DISTINCT c1.cosponsor_name
FROM cosponsors c1
LEFT JOIN cosponsors c2
 ON c1.cosponsor_name = c2.sponsor_name
WHERE c2.sponsor_name IS NULL



/* = = = MURDER MYSTERY = = = */

SELECT transcript, person.name, check_in_date 
from interview, person, get_fit_now_member AS fit, get_fit_now_check_in
WHERE transcript LIKE '%kill%'
AND interview.person_id = person.id 
AND fit.person_id=person.id 
AND membership_id = fit.id

SELECT person.name, person.id AS suspect_id FROM get_fit_now_member as fit, get_fit_now_check_in, person
WHERE check_in_date = '20180109' 
AND fit.id=membership_id 
AND person.id=person_id

SELECT * FROM (SELECT person.name, person.id AS suspect_id FROM get_fit_now_member as fit, get_fit_now_check_in, person
WHERE check_in_date = '20180109' 
AND fit.id=membership_id 
AND person.id=person_id), interview
where suspect_id = person_id

SELECT * FROM
    (SELECT id,name FROM 
        (SELECT id AS dl_id FROM drivers_license 
            WHERE car_make = 'Tesla'
            AND gender = 'female' 
            AND car_model = 'Model S' 
            AND hair_color = 'red' 
            AND height >= 65 AND height <= 67)
            ,person 
        WHERE dl_id =  license_id )
        ,facebook_event_checkin
WHERE id = person_id

INSERT INTO solution VALUES (1, 'Miranda Priestly');
SELECT value FROM solution;