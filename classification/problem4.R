library("MASS")
source("util.R")

main <- function() {
	
	trainingSetMat = matrix(data = as.matrix( read.table("dataset/problem3.dat") ), nrow = 5, ncol = 300, byrow = TRUE)
	labelSetMat = matrix(data = as.matrix( read.table("dataset/problem4.dat") ), nrow = 1, ncol = 300)

	trainingSetFrame = as.data.frame(t(trainingSetMat))

	samplesCount = ncol(trainingSetMat)
	featuresCount = nrow(trainingSetMat)

	jpeg('plot/problem4.jpg')
	layout(mat = rbind( 1:5, 6:10, 11:15, 16:20, 21:25 ) )
	par(mar = c(0.3, 0.3, 0.3, 0.3), oma = c(1, 1, 1, 1), xaxt='n', yaxt='n' )
	
	# plot the diagram
	for (i in 1 : featuresCount) { # start from 2 to skip label
		for (j in 1 : featuresCount) { # start from 2 to skip label

			# skip all the ones on the diagonal
			if (i == j) {
				plot(0, type='n', axes = FALSE, ann = FALSE)
				next
			}

			Feature.X = trainingSetMat[i, ]
			Feature.Y = trainingSetMat[j, ] 
			
			plot(Feature.Y, Feature.X, las = 1, col = ifelse(labelSetMat == "R", "red", "blue"))
		}
	}

	# QDA on each pair
	for (i in 1 : (featuresCount - 1)) {
		for (j in (i + 1) : featuresCount) {
			cat("--------------------------------------------------------------------------\n")
			cat(paste("                             QDA (", i, ",", j, ")\n"))
			cat("--------------------------------------------------------------------------\n")
			qdaModel = qda(trainingSetFrame[, c(i, j)], grouping = labelSetMat)
			print(qdaModel)
		}
	}
	cat("--------------------------------------------------------------------------\n")
	cat("                           QDA FOR ALL FEATURES                           \n")
	cat("--------------------------------------------------------------------------\n")
	# QDA on all 5 features
	qdaModel = qda(trainingSetFrame, grouping = labelSetMat)
	print(qdaModel)
	#dev.off()
}
main()