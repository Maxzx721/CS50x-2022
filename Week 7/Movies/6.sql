SELECT AVG(rating) FROM movies, ratings
WHERE ratings.movie_id = movies.id AND year = 2012;