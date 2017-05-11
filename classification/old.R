m.Variance <- function(data) {
	count = NROW(data) # number of rows
	mean = mMean(data)

	total = 0
	for (i in 1:count) {
		# Subtract the mean from each value in the data Square each of these distances. (valMoinMean^2) mainly just to remove the -
		total = total + ( (data[i] - mean) ^ 2)
	}

	return( total / count) # Divide the sum of the squares by the number of values in the data set.
}


m.Covariance <- function(feature1, feature2) {
      count = NROW(feature1)
      feature1Mean = m.Mean(feature1)
      feature2Mean = m.Mean(feature2)
      
      sum = 0
      for (i in 1:count) {
        product = (feature1[i] - feature1Mean) * (feature2[i] - feature2Mean)
        sum = sum + product
      }
      
      return(sum / (count - 1))
}

m.Correlation <- function(feature1, feature2) {
  
  correlationCoefficient <- m.Covariance(feature1, feature2) / (sqrt(m.Variance(feature1)) * sqrt(m.Variance(feature2)))
  return(correlationCoefficient)
}