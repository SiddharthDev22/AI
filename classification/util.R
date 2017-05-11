

m.Sum <- function(data) {
	count <- NROW(data) # number of rows
	total <- 0
	for (i in 1:count) {
		total <- total + data[i]
	}
	return (total)
}


# find the mean of the data set
m.Mean <- function(data) {
	return(m.Sum(data) / NROW(data))
}


# Find the variance
# The variance is a measure of how far each value in the data set is from the mean. Here is how it is defined:
### Subtract the mean from each value in the data. This gives you a measure of the distance of each value from the mean.
### Square each of these distances (so that they are all positive values), and add all of the squares together.
### Divide the sum of the squares by the number of values in the data set.
m.Variance <- function(data) {
	count = NROW(data)
	return ( ( m.Sum(data ^2) / count ) - m.Mean(data) ^2)
}


# Find the standard deviation
## By far the most common measure of variation for numerical data in statistics is the standard deviation.
## The standard deviation measures how concentrated the data are around the mean. (Exactly as the variance)
## The variance is another way to measure variation in a data set.
## Its downside is that it's in in square units.
## If your data are in dollars, for example, the variance would be in square dollars, which makes no sense.
## That's why we Take the square root of the variance to get the standard deviation.
m.StdDeviation <- function(data) {
	vari = m.Variance(data)
	return( sqrt(vari) ) # Divide the sum of the squares by the number of values in the data set.
}


# The covariance of two variables (matrix/vector/sample) x and y in a data set measures how the two are linearly related.
# A positive covariance would indicate a positive linear relationship between the variables,
# and a negative covariance would indicate the opposite.
m.Covariance <- function(featureX, featureY) {
	XY = featureX * featureY
	meanXY = m.Mean(featureX) * m.Mean(featureY)
	count = NROW(XY)
	return ( (m.Sum(XY) - count * meanXY ) / (count -1) )
}


## correlationCoefficient
m.Correlation <- function(featureX, featureY) {
	return( m.Covariance(featureX, featureY) / (m.StdDeviation(featureX) * m.StdDeviation(featureY)) )
}