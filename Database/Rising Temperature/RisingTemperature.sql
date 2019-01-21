Select w1.Id from Weather w1, weather w2 where datediff(w1.recorddate, w2.recorddate) = 1 and w1.temperature > w2.temperature
