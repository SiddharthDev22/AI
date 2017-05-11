source("util.R")

## The number of features is 20 So, the size of the covariance matrix will be  20 x 20

### calcualte the covariance of every feature with each other. Including with itself AKA the variance of the feature.
#### The variances appear along the diagonal and covariances appear in the off-diagonal elements.
#### That's why it is sometimes called "The Variance-Covariance Matrix".

##Example: The Variance-Covariance Matrix looks like this:

### cov (F1 & F1), cov (F1 & F2), cov (F1 & F3) ... cov (F1 & F20)
### cov (F2 & F1), cov (F2 & F2), cov (F2 & F3) ... cov (F2 & F20)
### cov (F3 & F1), cov (F3 & F2), cov (F3 & F3) ... cov (F3 & F20)
###		.				.				.				.
###		.				.				.				.
###		.				.				.				.
### cov (F20 & F1), cov (F20 & F2), cov (F20 & F3) ... cov (F20 & F20)

## cov (F1 & F1) = variance(F1)

main <- function() {
	
	dataSetMatrix <- as.matrix( read.table("dataset/problem2.dat") )
	trainingSetMatrix = matrix(data = dataSetMatrix, nrow = 20, ncol = 300, byrow = TRUE)

	featuresCount = nrow(trainingSetMatrix)
	samplesCount = ncol(trainingSetMatrix)

	covarianceMatrixM = matrix(nrow = 20, ncol = 20) # build a 20x20 matrix to hold the values (As the shape of the above example).

	for (i in 1:featuresCount) {
		for (j in 1:featuresCount) {
			feature.x = trainingSetMatrix[i, ]
			feature.y = trainingSetMatrix[j, ]
			covarianceMatrixM[i, j] = m.Covariance(feature.x, feature.y)
		}
	}

	covarianceMatrixR <- cov(t(trainingSetMatrix))

	print(covarianceMatrixM)
}
main()