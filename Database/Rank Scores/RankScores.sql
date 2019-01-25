SELECT Score, DENSE_RANK() OVER(ORDER BY score desc) as Rank from SCORES
