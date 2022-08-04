SELECT DISTINCT(name) FROM movies, stars, people
WHERE stars.movie_id = movies.id AND stars.person_id = people.id AND year = 2004
ORDER BY birth;