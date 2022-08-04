SELECT DISTINCT(name) FROM people JOIN stars
WHERE people.id = stars.person_id AND movie_id IN (SELECT movie_id FROM stars JOIN people
WHERE stars.person_id = people.id AND name = 'Kevin Bacon' AND birth = 1958)
AND name != 'Kevin Bacon';