SELECT DISTINCT(name) FROM people JOIN directors
WHERE people.id = directors.person_id
AND movie_id IN (SELECT movie_id FROM ratings JOIN movies
WHERE ratings.movie_id = movies.id
AND rating >=9.0);