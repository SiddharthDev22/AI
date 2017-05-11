source("util.R")

main <- function() {

	trainingSetMat = matrix(data = as.matrix( read.table("dataset/problem3.dat") ), nrow = 5, ncol = 300, byrow = TRUE)

	samplesCount = ncol(trainingSetMat)
	featuresCount = nrow(trainingSetMat)

	jpeg('plot/problem3.jpg')
	layout(mat = rbind( 1:5, 6:10, 11:15, 16:20, 21:25 ) )
	par(mar = c(0.3, 0.3, 0.3, 0.3), oma = c(1, 1, 1, 1), xaxt='n', yaxt='n' )

	bestLinePair.correlation = bestLinePair.x = bestLinePair.y = 0
	CorrelationMat = matrix(nrow = 5, ncol = 5, byrow = TRUE)

	for (i in 1 : featuresCount) {
		for (j in 1 : featuresCount) {
			
			# skip all the ones on the diagonal
			if (i == j) {
				plot(0, type='n', axes = FALSE, ann = FALSE)
				next
			}

			Feature.X = trainingSetMat[i, ]
			Feature.Y = trainingSetMat[j, ]
			
			correlationCoefficient = m.Correlation(Feature.X, Feature.Y)
			# pick a color depending on the correlation
			if (correlationCoefficient > 0 ) color = "darkgreen" else color = "darkmagenta"
			# draw one of the diagrams
			plot(Feature.Y, Feature.X, las = 1, col=color)
			# find the higest correlation
			if (abs(correlationCoefficient) > bestLinePair.correlation) {
				bestLinePair.correlation = abs(correlationCoefficient)
				bestLinePair.x = i;
				bestLinePair.y = j;
			}
			CorrelationMat[i, j] = correlationCoefficient
			
		}
	}
	cat("------------------------------------------------------------------\n")
	print(CorrelationMat)
	cat("------------------------------------------------------------------\n")
	# Which pair, of the 10 pairs, can be represented by a line?
	## It's the pair that has the highest correlation coefficient rho magnitude
	cat(paste("Feature (", bestLinePair.x, ",", bestLinePair.y, ") are the best to represent a line with a correlation of", bestLinePair.correlation))
}
main()